#include "header.h"
#include "sorting-algorithm/bubbleSort.cpp"
#include "sorting-algorithm/countingSort.cpp"
#include "sorting-algorithm/flashSort.cpp"
#include "sorting-algorithm/heapSort.cpp"
#include "sorting-algorithm/insertionSort.cpp"
#include "sorting-algorithm/mergeSort.cpp"
#include "sorting-algorithm/quickSort.cpp"
#include "sorting-algorithm/radixSort.cpp"
#include "sorting-algorithm/selectionSort.cpp"
#include "sorting-algorithm/shakerSort.cpp"
#include "sorting-algorithm/shellSort.cpp"

int *read_file(string filename, int &input_size)
{
    filename = "data/" + filename;
    ifstream is(filename);
    if (!is)
    {
        cout << "Can not open file to read." << endl;
        return NULL;
    }
    is >> input_size;
    int *arr = new int[input_size];
    for (int i = 0; i < input_size; i++)
        is >> arr[i];
    is.close();
    return arr;
}

void write_file(string file_name, int *arr, int input_size)
{
    file_name = "data/" + file_name;
    ofstream os(file_name);
    if (!os)
    {
        cout << "Can't not open file to write." << endl;
        return;
    }
    os << input_size << endl;
    for (int i = 0; i < input_size; i++)
        os << arr[i] << " ";
    os.close();
}

void printOptions()
{
    cout << "Command 1: [Execution file] -a [Algorithm] [Given input] [Output parameters(s)]" << endl;
    cout << "Command 2: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameters(s)]" << endl;
    cout << "Command 3: [Execution file] -a [Algorithm] [Input size] [Output parameters(s)]" << endl;
    cout << "Command 4: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]" << endl;
    cout << "Command 5: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
}

void Analysis(void (*funcPointerRunTime)(int *&, int, long long &), void (*funcPointerCompare)(int *&, int, long long &), int *&arr, int input_size, string output_parameter, long long &time, long long &count_comparison)
{
    if (output_parameter == "-time")
    {
        // Runtime
        funcPointerRunTime(arr, input_size, time);
    }
    else if (output_parameter == "-both")
    {
        // Runtime
        int *temp = new int[input_size];
        for (int i = 0; i < input_size; i++)
            temp[i] = arr[i];

        funcPointerRunTime(temp, input_size, time);
        // Compare
        funcPointerCompare(arr, input_size, count_comparison);
        delete[] temp;
    }
    else if (output_parameter == "-comp")
    {
        funcPointerCompare(arr, input_size, count_comparison);
    }
}

// THIS FUNCTION NEEDS TO COMPLETE
void findAlgorithm(void (*&funcPointerRunTime)(int *&, int, long long &), void (*&funcPointerCompare)(int *&, int, long long &), string algorithm_name)
{
    if (algorithm_name == "bubble-sort")
    {
        funcPointerCompare = bubbleSortCompare;
        funcPointerRunTime = bubbleSortRunTime;
    }
    if (algorithm_name == "counting-sort")
    {
        funcPointerRunTime = countingSortRunTime;
        funcPointerCompare = countingSortCompare;
    }
    if (algorithm_name == "flash-sort")
    {
        funcPointerCompare = flashSortCompare;
        funcPointerRunTime = flashSortRunTime;
    }
    if (algorithm_name == "heap-sort")
    {
        funcPointerRunTime = heapSortRunTime;
        funcPointerCompare = heapSortCompare;
    }
    if (algorithm_name == "insertion-sort")
    {
        funcPointerRunTime = insertionSortRunTime;
        funcPointerCompare = insertionSortCompare;
    }
    if (algorithm_name == "merge-sort")
    {
        funcPointerRunTime = mergeSortRunTime;
        funcPointerCompare = mergeSortCompare;
    }
    if (algorithm_name == "quick-sort")
    {
        funcPointerCompare = quickSortCompare;
        funcPointerRunTime = quickSortRunTime;
    }
    if (algorithm_name == "radix-sort")
    {
        funcPointerCompare = radixSortCompare;
        funcPointerRunTime = radixSortRunTime;
    }
    if (algorithm_name == "selection-sort")
    {
        funcPointerCompare = selectionSortCompare;
        funcPointerRunTime = selectionSortRunTime;
    }
    if (algorithm_name == "shaker-sort")
    {
        funcPointerRunTime = shakerSortRunTime;
        funcPointerCompare = shakerSortCompare;
    }
    if (algorithm_name == "shell-sort")
    {
        funcPointerRunTime = shellSortRunTime;
        funcPointerCompare = shellSortCompare;
    }
}

void Generate(string input_order, int *&arr, int input_size)
{
    if (input_order == "-rand")
    {
        GenerateRandomData(arr, input_size);
    }
    else if (input_order == "-nsorted")
    {
        GenerateNearlySortedData(arr, input_size);
    }
    else if (input_order == "-sorted")
    {
        GenerateSortedData(arr, input_size);
    }
    else if (input_order == "-rev")
    {
        GenerateReverseData(arr, input_size);
    }
}

void execute_1(string algorithm_name_1, int &input_size, string input_file_name, string output_parameter)
{
    int *arr = read_file(input_file_name, input_size);

    if (arr != NULL)
    {
        void (*funcPointerRunTime)(int *&, int, long long &) = NULL;
        void (*funcPointerCompare)(int *&, int, long long &) = NULL;

        findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);
        if (funcPointerCompare != NULL && funcPointerRunTime != NULL)
        {
            long long time = -1, count = -1;
            Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
            write_file("output.txt", arr, input_size);

            cout << "ALGORITHM MODE" << endl;
            cout << "Algorithm: " << algorithm_name_1 << endl;
            cout << "Input file: " << input_file_name << endl;
            cout << "--------------------------" << endl;
            if (time >= 0)
                cout << "Running time: " << time << endl;
            if (count > 0)
                cout << "Comparisons: " << count << endl;
        }
        else
        {
            cout << "Algorithm isn't exist." << endl;
        }
    }
    delete[] arr;
}

void execute_2(string algorithm_name_1, int input_size, string input_order, string output_parameter)
{
    int *arr = new int[input_size];

    Generate(input_order, arr, input_size);

    write_file("input.txt", arr, input_size);

    void (*funcPointerRunTime)(int *&, int, long long &) = NULL;
    void (*funcPointerCompare)(int *&, int, long long &) = NULL;

    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);

    if (funcPointerCompare && funcPointerRunTime)
    {
        cout << "ALGORITHM MODE" << endl;
        cout << "Algorithm: " << algorithm_name_1 << endl;
        cout << "Input size: " << input_size << endl;
        cout << "Input order: " << input_order << endl;
        cout << "--------------------------" << endl;
        long long time = -1, count = -1;
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
        write_file("output.txt", arr, input_size);

        if (time >= 0)
            cout << "Running time: " << time << endl;
        if (count > 0)
            cout << "Comparisons: " << count << endl;
    }
    else
    {
        cout << "Algorithm isn't exist." << endl;
    }
    delete[] arr;
}

void execute_3(string algorithm_name_1, int input_size, string output_parameter)
{

    int *arr = new int[input_size];

    void (*funcPointerRunTime)(int *&, int, long long &) = NULL;
    void (*funcPointerCompare)(int *&, int, long long &) = NULL;
    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);

    if (funcPointerCompare && funcPointerRunTime)
    {
        cout << "ALGORITHM MODE" << endl;
        cout << "Algorithm: " << algorithm_name_1 << endl;
        cout << "Input size: " << input_size << endl
             << endl;
        cout << "Input order: Randomize" << endl;
        cout << "--------------------------" << endl;
        GenerateRandomData(arr, input_size);
        write_file("input_1.txt", arr, input_size);
        long long time = -1, count = -1;
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
        if (time >= 0)
            cout << "Running time: " << time << endl;
        if (count > 0)
            cout << "Comparisons: " << count << endl;
        cout << endl;

        cout << "Input order: Nearly Sorted" << endl;
        cout << "--------------------------" << endl;
        GenerateNearlySortedData(arr, input_size);
        write_file("input_2.txt", arr, input_size);
        time = -1, count = -1;
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
        if (time >= 0)
            cout << "Running time: " << time << endl;
        if (count > 0)
            cout << "Comparisons: " << count << endl;
        cout << endl;

        cout << "Input order: Sorted" << endl;
        cout << "--------------------------" << endl;
        GenerateSortedData(arr, input_size);
        write_file("input_3.txt", arr, input_size);
        time = -1, count = -1;
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
        if (time >= 0)
            cout << "Running time: " << time << endl;
        if (count > 0)
            cout << "Comparisons: " << count << endl;
        cout << endl;

        cout << "Input order: Reversed" << endl;
        cout << "--------------------------" << endl;
        GenerateReverseData(arr, input_size);
        write_file("input_4.txt", arr, input_size);
        time = -1, count = -1;
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, output_parameter, time, count);
        if (time >= 0)
            cout << "Running time: " << time << endl;
        if (count > 0)
            cout << "Comparisons: " << count << endl;
        cout << endl;
    }
    else
    {
        cout << "Algorithm isn't exist." << endl;
    }
    delete[] arr;
}

void execute_4(string algorithm_name_1, string algorithm_name_2, int &input_size, string input_file_name)
{
    int *arr = read_file(input_file_name, input_size);

    if (arr)
    {
        void (*funcPointerRunTime)(int *&, int, long long &) = NULL;
        void (*funcPointerCompare)(int *&, int, long long &) = NULL;
        long long time_1 = -1, time_2 = -1, count_1 = -1, count_2 = -1;

        findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);
        if (funcPointerCompare && funcPointerRunTime)
        {
            Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, "-both", time_1, count_1);
        }
        else
        {
            cout << "Algorithm 1 isn't exist." << endl;
            delete[] arr;
            return;
        }

        funcPointerCompare = NULL;
        funcPointerRunTime = NULL;

        findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_2);
        if (funcPointerCompare && funcPointerRunTime)
        {
            Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, "-both", time_2, count_2);
        }
        else
        {
            cout << "Algorithm 2 isn't exist." << endl;
            delete[] arr;
            return;
        }
        cout << "COMPARE MODE" << endl;
        cout << "Algorithm: " << algorithm_name_1 << " | " << algorithm_name_2 << endl;
        cout << "Input file: " << input_file_name << endl;
        cout << "Input size: " << input_size << endl;
        cout << "--------------------------" << endl;
        cout << "Running time: " << time_1 << " | " << time_2 << endl;
        cout << "Comparisons: " << count_1 << " | " << count_2 << endl;
    }
    delete[] arr;
}

void execute_5(string algorithm_name_1, string algorithm_name_2, int input_size, string input_order)
{
    int *arr = new int[input_size];
    Generate(input_order, arr, input_size);
    write_file("input.txt", arr, input_size);

    void (*funcPointerRunTime)(int *&, int, long long &) = NULL;
    void (*funcPointerCompare)(int *&, int, long long &) = NULL;
    long long time_1 = -1, time_2 = -1, count_1 = -1, count_2 = -1;

    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_1);
    if (funcPointerCompare && funcPointerRunTime)
    {
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, "-both", time_1, count_1);
    }
    else
    {
        cout << "Algorithm 1 isn't exist." << endl;
        delete[] arr;
        return;
    }

    funcPointerCompare = NULL;
    funcPointerRunTime = NULL;

    findAlgorithm(funcPointerRunTime, funcPointerCompare, algorithm_name_2);
    if (funcPointerCompare && funcPointerRunTime)
    {
        Analysis(funcPointerRunTime, funcPointerCompare, arr, input_size, "-both", time_2, count_2);
    }
    else
    {
        cout << "Algorithm 2 isn't exist." << endl;
        delete[] arr;
        return;
    }
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algorithm_name_1 << " | " << algorithm_name_2 << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << input_order << endl;
    cout << "Running time: " << time_1 << " | " << time_2 << endl;
    cout << "Comparisons: " << count_1 << " | " << count_2 << endl;
    delete[] arr;
}

int main(int argc, char **argv)
{
    string mode;
    string algorithm_name_1, algorithm_name_2;
    int input_size;
    string input_file_name;
    string output_parameter;
    string input_order;
    if (argc == 5 || argc == 6)
    {
        int idx_argv = 1;
        mode = argv[idx_argv++];
        if (mode == "-a")
        {
            algorithm_name_1 = argv[idx_argv++];
            if (argc == 5)
            {
                if (!isdigit(argv[idx_argv][0]))
                {
                    input_file_name = argv[idx_argv++];
                    output_parameter = argv[idx_argv++];
                    cout << 1 << " " << mode << " " << algorithm_name_1 << " " << input_file_name << " " << output_parameter << endl;
                    execute_1(algorithm_name_1, input_size, input_file_name, output_parameter);
                }
                else
                {
                    input_size = stoi(argv[idx_argv++]);
                    output_parameter = argv[idx_argv++];
                    cout << 3 << " " << mode << " " << algorithm_name_1 << " " << input_size << " " << output_parameter << endl;
                    execute_3(algorithm_name_1, input_size, output_parameter);
                }
            }
            else
            {
                input_size = stoi(argv[idx_argv++]);
                input_order = argv[idx_argv++];
                output_parameter = argv[idx_argv++];
                cout << 2 << " " << mode << " " << algorithm_name_1 << " " << input_size << " " << input_order << " " << output_parameter << endl;
                execute_2(algorithm_name_1, input_size, input_order, output_parameter);
            }
        }
        else if (mode == "-c")
        {
            algorithm_name_1 = argv[idx_argv++];
            algorithm_name_2 = argv[idx_argv++];
            if (argc == 5)
            {
                input_file_name = argv[idx_argv++];
                cout << 4 << " " << mode << " " << algorithm_name_1 << " " << algorithm_name_2 << " " << input_file_name << endl;
                execute_4(algorithm_name_1, algorithm_name_2, input_size, input_file_name);
            }
            else
            {
                input_size = stoi(argv[idx_argv++]);
                input_order = argv[idx_argv++];
                cout << 5 << " " << mode << " " << algorithm_name_1 << " " << algorithm_name_2 << " " << input_size << " " << input_order << endl;
                execute_5(algorithm_name_1, algorithm_name_2, input_size, input_order);
            }
        }
    }
    else
    {
    }
    system("pause");
    return 0;
}
