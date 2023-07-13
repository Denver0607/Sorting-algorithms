#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char **argv)
{
    string algorithm_name_1, algorithm_name_2;
    int input_size;
    string mode;
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
                }
                else {
                    input_size = stoi(argv[idx_argv++]);
                    output_parameter = argv[idx_argv++];
                    cout << 3 << " " << mode << " " << algorithm_name_1 << " " << input_size << " " << output_parameter << endl;
                }
            }
            else {
                input_size = stoi(argv[idx_argv++]);
                input_order = argv[idx_argv++];
                output_parameter = argv[idx_argv++];
                cout << 2 << " " << mode << " " << algorithm_name_1 << " " << input_size << " " <<  input_order << " " << output_parameter << endl;
            }
        }   
        else if (mode == "-c") {
            algorithm_name_1 = argv[idx_argv++];
            algorithm_name_2 = argv[idx_argv++];
            if(argc == 5) {
                input_file_name = argv[idx_argv++];
                cout << 4 << " " << mode << " " << algorithm_name_1 << " " << algorithm_name_2 << " " << input_file_name << endl;
            }
            else {
                input_size = stoi(argv[idx_argv++]);
                input_order = argv[idx_argv++];
                cout << 5 << " " << mode << " " << algorithm_name_1 << " " << algorithm_name_2 << " " << input_size << " " << input_order << endl;
            }
        }
    }
    return 0;
}