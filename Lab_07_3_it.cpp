// Lab_07_3_it.cpp
// < Бабич Олексій >
// Лабораторна робота No 7.3.1
// Опрацювання динамічних багатовимірних масивів. Ітераційний спосіб.
// Варіант 1

#include <iostream>
#include <time.h>

using namespace std;

void createArray (int** array, const int rowCount, const int colCount, const int Low, const int High)
{
 for (int i = 0; i < rowCount; i++)
 for (int j = 0; j < colCount; j++)
 array[i][j] = Low + rand() % (High-Low+1);
}

void printArray(int** array, const int rowCount, const int colCount)
{
 cout << endl;
 for (int i = 0; i < rowCount; i++)
 {
 for (int j = 0; j < colCount; j++)
 cout << array[i][j] << "  ";
 cout << endl;
 }
 cout << endl;
}

void maxElementOfTheMatrix(int** array, const int rowCount, const int colCount)
{
    int count = 0;
    int maxElement= array[0][0];


    for(int i = 0; i < rowCount; i++)
    {
        count = 0;
        for(int j = 0; j < colCount; j++)
        {
            if(array[i][j] > maxElement)
                {
                   maxElement = array[i][j];
                }
            if(maxElement == array[i][j])
            {
                count++;
            }
        }
    }

    cout<< "Найбільший елемент: " <<maxElement<<endl;

}

int countRow(int** array, const int rowCount , const int colCount)
{
    
    int count = 0;
    for(int i = 0; i < rowCount; i++)
    {
        for(int j = 0; j < colCount; j++)
        {
           if(array[i][j] != 0)
           {
               count = 0;
           }
            else
                count++;
        }
    }
    
    return count;
}

int main()
{
    srand((unsigned)time(NULL));
 
    int Low = 0;
    int High = 9;
    int rowCount = 4;
    int colCount = 4;
    int **arr = new int*[rowCount];
    
    for (int i = 0; i<rowCount; i++)
        
    arr[i] = new int[colCount];

    createArray(arr, rowCount, colCount, Low, High);
    maxElementOfTheMatrix(arr, rowCount, colCount);
    cout<< countRow(arr, rowCount, colCount);
    printArray(arr, rowCount, colCount);
    
    for (int i = 0; i<rowCount; i++)
        
    delete [] arr[i];
    delete [] arr;
    
    return 0;

}
