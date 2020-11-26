#include <iostream>

using namespace std;

int** matrix_rotation(int**, int, bool);
void print_matrix(int**, int);

int main()
{
    int matrix_size = 6;

    int **matrix = new int* [matrix_size];
    for(int i = 0; i < matrix_size; i++)
    {
        matrix[i] = new int [matrix_size];
    }

    int num = 9;
    for(int i = 0; i < matrix_size; i++)
    {
        for(int j = 0; j < matrix_size; j++)
        {
            num += 1;
            matrix[i][j] = num;
        }
    }

    cout << "INPUT MATRIX:" << endl << endl;
    print_matrix(matrix, matrix_size);

    cout << "TURN CLOCKWISE:" << endl << endl;
    matrix = matrix_rotation(matrix, matrix_size, true);
    print_matrix(matrix, matrix_size);

    cout << "TURN COUNTERCLOCKWISE:" << endl << endl;
    matrix = matrix_rotation(matrix, matrix_size, false);
    print_matrix(matrix, matrix_size);

    for (int i = 0; i < matrix_size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

int** matrix_rotation(int** matrix, int matrix_size, bool orientation)
{
    int i = 0;
    int j = matrix_size-1;

    while(j - i >= 1)
    {
        if(orientation == false)
        {
            for(int k = 0; k < j-i; k++)
            {
                swap(matrix[i][i+k], matrix[j-k][i]);
                swap(matrix[i][i+k], matrix[j][j-k]);
                swap(matrix[i][i+k], matrix[i+k][j]);
            }
        }
        else
        {
            for(int k = 0; k < j-i; k++)
            {
                swap(matrix[i][i+k], matrix[i+k][j]);
                swap(matrix[i][i+k], matrix[j][j-k]);
                swap(matrix[i][i+k], matrix[j-k][i]);
            }
        }
        i += 1;
        j -= 1;
    }

    return matrix;
}

void print_matrix(int** matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
