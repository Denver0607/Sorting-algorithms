#include <iostream>
using namespace std;

int ***generate_3D_matrix(int a, int b, int c)
{
    int ***arr = new int **[a];
    for (int i = 0; i < a; i++)
    {
        arr[i] = new int *[b];
        for (int j = 0; j < b; j++)
        {
            arr[i][j] = new int[c];
            for (int k = 0; k < c; k++)
            {
                arr[i][j][k] = 0;
            }
        }
    }
    return arr;
}

void input_3D_matrix(int ***&arr, int a, int b, int c)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << "arr[" << i << "][" << j << "][" << k << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }
}

void print_3D_matrix(int ***arr, int a, int b, int c)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    int ***arr;
    int a, b, c;
    cout << "Size = ";
    cin >> a >> b >> c;
    arr = generate_3D_matrix(a, b, c);
    input_3D_matrix(arr, a, b, c);
    print_3D_matrix(arr, a, b, c);
    return 0;
}