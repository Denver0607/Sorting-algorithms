#include "heapSort.cpp"

int* read_file(string filename, int &input_size) {
    ifstream is(filename);
    is >> input_size;
    int *arr = new int[input_size];
    for(int i = 0; i < input_size; i++)
        is >> arr[i];
    is.close();
    return arr;
}

void Analysis(void(*funcPointerRunTime)(int *&, int), void(*funcPointerCompare)(int *&, int, int&), int *&arr, int input_size, string output_parameter, double &time, int &count_comparison)
{
    if(output_parameter == "-time") {
        // Runtime
        //funcPointerRunTime(arr, input_size);
    } else if (output_parameter == "-both") {
        //Runtime
        int *temp = new int[input_size];
        for(int i = 0; i < input_size; i++)
            temp[i] = arr[i];
        funcPointerRunTime(temp, input_size);

        //Compare
        funcPointerCompare(arr, input_size, count_comparison);
        delete []temp;
    } else if (output_parameter == "-comp") {
        funcPointerCompare(arr, input_size, count_comparison);
    }
}

// THIS FUNCTION NEEDS TO COMPLETE
void findAlgorithm(void(*&funcPointerRunTime)(int *&, int), void(*&funcPointerCompare)(int *&, int, int &), string algorithm_name)
{
    if(algorithm_name == "heap-sort") {
        funcPointerRunTime = heapSortRunTime;
        funcPointerCompare = heapSortCompare;
    }
}

void Generate(string input_order, int *&arr, int input_size)
{
    if(input_order == "-rand") {
        GenerateRandomData(arr, input_size);
    } else if(input_order == "-nsorted") {
        GenerateNearlySortedData(arr, input_size);
    } else if(input_order == "-sorted") {
        GenerateSortedData(arr, input_size);
    } else if(input_order == "-rev") {
        GenerateReverseData(arr, input_size);
    }
}

void write_file(string file_name, int *arr, int input_size)
{
    ofstream os(file_name);
    os << input_size << endl;
    for(int i = 0; i < input_size; i++)
        os << arr[i] << " ";
    os.close();
}
void execute_1(string algorithm_name_1, int &input_size, string input_file_name, string output_parameter) {
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm_name_1 << endl;
    cout << "Input file: " << input_file_name << endl;
    cout << "--------------------------" << endl;

    int *arr = read_file(input_file_name, input_size);
    void(*funcPointerRunTime)(int *&, int);
    void(*funcPointerCompare)(int *&, int, int&);
    
    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);
    
    double time = -1;
    int count = -1; 
    Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
    write_file("output.txt", arr, input_size);

    if(time > 0)
        cout << "Running time: " << time << endl;
    if(count > 0)
        cout << "Comparisons: " << count << endl;
    delete []arr;
}

void execute_2(string algorithm_name_1, int input_size, string input_order, string output_parameter)
{
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm_name_1 << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl;
    cout << "--------------------------" << endl;

    int *arr = new int[input_size];

    Generate(input_order, arr, input_size);
    
    write_file("input.txt", arr, input_size);

    void(*funcPointerRunTime)(int *&, int);
    void(*funcPointerCompare)(int *&, int, int&);

    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);
    
    double time = -1;
    int count = -1; 
    Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
    write_file("output.txt", arr, input_size);

    if(time > 0)
        cout << "Running time: " << time << endl;
    if(count > 0)
        cout << "Comparisons: " << count << endl;

    delete []arr;
}

void execute_3(string algorithm_name_1, int input_size, string output_parameter) {
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm_name_1 << endl;
    cout << "Input size: " << input_size << endl << endl;

    void(*funcPointerRunTime)(int *&, int);
    void(*funcPointerCompare)(int *&, int, int&);
    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);

    int *arr = new int[input_size];
    cout << "Input order: Randomize" << endl;
    cout << "--------------------------" << endl;
    GenerateRandomData(arr, input_size);
    write_file("input_1.txt", arr, input_size);

    double time = -1;
    int count = -1; 
    Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);

    if(time > 0)
        cout << "Running time: " << time << endl;
    if(count > 0)
        cout << "Comparisons: " << count << endl;    
        
    cout << endl;

    cout << "Input order: Nearly Sorted" << endl;
    cout << "--------------------------" << endl;
    GenerateNearlySortedData(arr, input_size);
    write_file("input_2.txt", arr, input_size);

    time = -1;
    count = -1; 
    Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);

    if(time > 0)
        cout << "Running time: " << time << endl;
    if(count > 0)
        cout << "Comparisons: " << count << endl;    
        
    cout << endl;

    cout << "Input order: Sorted" << endl;
    cout << "--------------------------" << endl;
    GenerateSortedData(arr, input_size);
    write_file("input_3.txt", arr, input_size);

    time = -1;
    count = -1; 
    Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);

    if(time > 0)
        cout << "Running time: " << time << endl;
    if(count > 0)
        cout << "Comparisons: " << count << endl;    
        
    cout << endl;

    cout << "Input order: Reversed" << endl;
    cout << "--------------------------" << endl;
    GenerateReverseData(arr, input_size);
    write_file("input_4.txt", arr, input_size);

    time = -1;
    count = -1; 
    Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);

    if(time > 0)
        cout << "Running time: " << time << endl;
    if(count > 0)
        cout << "Comparisons: " << count << endl;    
        
    cout << endl;
    delete []arr;
}

void execute_4(string algorithm_name_1, string algorithm_name_2, int &input_size, string input_file_name)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algorithm_name_1 << " | " << algorithm_name_2 << endl;
    cout << "Input file: " << input_file_name << endl;

    int *arr = read_file(input_file_name, input_size);
    cout << "Input size: " << input_size << endl;
    cout << "--------------------------" << endl;

    void(*funcPointerRunTime_1)(int *&, int);
    void(*funcPointerCompare_1)(int *&, int, int&);

    void(*funcPointerRunTime_2)(int *&, int);
    void(*funcPointerCompare_2)(int *&, int, int&);
    
    findAlgorithm(funcPointerRunTime_1, funcPointerCompare_1, algorithm_name_1);
    findAlgorithm(funcPointerRunTime_2, funcPointerCompare_2, algorithm_name_2);

    double time_1 = -1, time_2 = -1;
    int count_1 = -1, count_2 = -1;
    Analysis(funcPointerRunTime_1, funcPointerCompare_1, arr, input_size, "-comp", time_1, count_1);
    Analysis(funcPointerRunTime_2, funcPointerCompare_2, arr, input_size, "-comp", time_1, count_2);

    cout << "Running time: " << time_1 << " | " << time_2 << endl;
    cout << "Comparisons: " << count_1 << " | " << count_2 << endl;

    delete []arr;
}

void execute_5(string algorithm_name_1, string algorithm_name_2, int input_size, string input_order)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algorithm_name_1 << " | " << algorithm_name_2 << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl;

    int *arr = new int[input_size];
    Generate(input_order, arr, input_size);
    write_file("input.txt", arr, input_size);

    void(*funcPointerRunTime_1)(int *&, int);
    void(*funcPointerCompare_1)(int *&, int, int&);

    void(*funcPointerRunTime_2)(int *&, int);
    void(*funcPointerCompare_2)(int *&, int, int&);
    
    findAlgorithm(funcPointerRunTime_1, funcPointerCompare_1, algorithm_name_1);
    findAlgorithm(funcPointerRunTime_2, funcPointerCompare_2, algorithm_name_2);

    double time_1 = -1, time_2 = -1;
    int count_1 = -1, count_2 = -1;
    Analysis(funcPointerRunTime_1, funcPointerCompare_1, arr, input_size, "-comp", time_1, count_1);
    Analysis(funcPointerRunTime_2, funcPointerCompare_2, arr, input_size, "-comp", time_1, count_2);

    cout << "Running time: " << time_1 << " | " << time_2 << endl;
    cout << "Comparisons: " << count_1 << " | " << count_2 << endl;
    delete []arr;
}
int main(int argc, char **argv) {
    string mode;
    string algorithm_name_1, algorithm_name_2;
    int input_size;
    string input_file_name;
    string output_parameter;
    string input_order;
    if(argc == 1){
        cout << "5 options" << endl;
    }
    else{
        int idx_argv = 1;
        mode = argv[idx_argv++];
        if(mode == "-a"){
            algorithm_name_1 = argv[idx_argv++];
            if(argc == 5) {
                if(!isdigit(argv[idx_argv][0])) {
                    input_file_name = argv[idx_argv++];
                    output_parameter = argv[idx_argv++];
                    cout << 1 << " " << mode << " " << algorithm_name_1 << " " << input_file_name << " " << output_parameter << endl;
                    execute_1(algorithm_name_1, input_size, input_file_name, output_parameter);
                }
                else {
                    input_size = stoi(argv[idx_argv++]);
                    output_parameter = argv[idx_argv++];
                    cout << 3 << " " << mode << " " << algorithm_name_1 << " " << input_size << " " << output_parameter << endl;
                    execute_3(algorithm_name_1, input_size, output_parameter);
                }
            }
            else {
                input_size = stoi(argv[idx_argv++]);
                input_order = argv[idx_argv++];
                output_parameter = argv[idx_argv++];
                cout << 2 << " " << mode << " " << algorithm_name_1 << " " << input_size << " " <<  input_order << " " << output_parameter << endl;
                execute_2(algorithm_name_1, input_size, input_order, output_parameter);
            }
        }   
        else if (mode == "-c") {
            algorithm_name_1 = argv[idx_argv++];
            algorithm_name_2 = argv[idx_argv++];
            if(argc == 5) {
                input_file_name = argv[idx_argv++];
                cout << 4 << " " << mode << " " << algorithm_name_1 << " " << algorithm_name_2 << " " << input_file_name << endl;
                execute_4(algorithm_name_1, algorithm_name_2, input_size, input_file_name);
            }
            else {
                input_size = stoi(argv[idx_argv++]);
                input_order = argv[idx_argv++];
                cout << 5 << " " << mode << " " << algorithm_name_1 << " " << algorithm_name_2 << " " << input_size << " " << input_order << endl;
                execute_5(algorithm_name_1, algorithm_name_2, input_size, input_order);
            }
        }
    }
    return 0;
}