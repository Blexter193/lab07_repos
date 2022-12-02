// Lab_7_2_2.cpp
// < Бабич Олексій >
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 1

#include <iostream>
using namespace std;

void print (int** array, size_t n, size_t m, int i)
{
    for(size_t j = 0; j < m; j++)
    {
      cout << array[i][j] << " ";
    }
      cout << endl << endl;
    
    if(i < n - 1)
    {
        print(array, n, m, i + 1);
    }
}

int** alloc_matrix (size_t n, size_t m, int i)
{
    int **array = new int*[n];
    
    if(i < n - 1)
    {
        alloc_matrix(n, m, i + 1);
    }
    else
        array[i] = new int [m];
    return array;
}

void free_matrix(int **array, size_t n, size_t m, int i)
{
    delete[] array[i];
    
    if(i < n - 1)
    {
        free_matrix(array, n, m, i + 1);
    }
    else
        delete[] array;
}

int main()
{
  size_t n = 5, m = 6;

  int **source = alloc_matrix(n, m, 0);
  int **transposed = alloc_matrix(m, n, 0);
    
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      source[i][j] = i * n +j;
    }
  }

  cout << "Початкова матриця: " << endl << endl;
  print(source, n, m, 0);
  cout << endl;

  for(size_t i = 0; i < n; i++)
    for(size_t j = 0; j < m; j++)
      transposed[j][i] = source[i][j];
    
  cout << "Транспонована матриця: " << endl << endl;
  print(transposed, m, n, 0);
  cout << endl;
    
  free_matrix(source, n, m, 0);
  free_matrix(transposed, m, n, 0);
}
