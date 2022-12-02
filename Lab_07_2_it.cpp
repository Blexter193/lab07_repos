// Lab_7_2_1.cpp
// < Бабич Олексій >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 1

#include <iostream>
using namespace std;

void print (int** array, size_t n, size_t m)
{
  for(size_t i = 0; i < n; i++)
  {
    for(size_t j = 0; j < m; j++)
    {
      cout << array[i][j] << " ";
    }
      cout << endl << endl;
  }
}

int** alloc_matrix (size_t n, size_t m)
{
  int **array = new int*[n];
  for (size_t i = 0; i < n; ++i)
  {
    array[i] = new int [m];
  }
  return array;
}

void free_matrix(int **array, size_t n, size_t m)
{
  for (size_t i = 0; i < n; ++i)
  {
    delete[] array[i];
  }
  delete[] array;
}

int main()
{
  size_t n = 5, m = 6;

  int **source = alloc_matrix(n, m);
  int **transposed = alloc_matrix(m, n);
    
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      source[i][j] = i * n +j;
    }
  }

  cout << "Початкова матриця: " << endl << endl;
  print(source, n, m);
  cout << endl;

  for(size_t i = 0; i < n; i++)
    for(size_t j = 0; j < m; j++)
      transposed[j][i] = source[i][j];
    
  cout << "Транспонована матриця: " << endl << endl;
  print(transposed, m, n);
  cout << endl;
    
  free_matrix(source, n, m);
  free_matrix(transposed, m, n);
}
