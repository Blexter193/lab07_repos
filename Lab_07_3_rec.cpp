// Lab_07_3_rec.cpp
// < Бабич Олексій >
// Лабораторна робота No 7.3.2
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 1

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void createArray(int** array, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    array[i][j] = Low + rand() % (High-Low+1);

    if(j < colCount-1)
    {
        createArray(array, rowCount, colCount, Low,High, i, j+1);
    }
        if(i < rowCount-1)
        {
            createArray(array, rowCount, colCount, Low, High, i+1, 0);
        }

}

void printArray(int** array, const int rowCount, const int colCount, int i, int j)
{
    cout<< setw(4) << array[i][j];
    if(j < colCount-1)
    {
        printArray(array, rowCount, colCount, i, j+1);
    }
    else
    if(i < rowCount-1)
    {
        cout << endl;
        printArray(array, rowCount, colCount, i+1, 0);
    }
    else
        cout << endl << endl;

}

void maxElementOfTheMatrix(int** array, const int rowCount, const int colCount, int i,int j)
{
    int count = 0;
    int maxElement = array[0][0];

        if(array[i][j] > maxElement)
        {
            maxElement = array[i][j];
        }
        if(maxElement == array[i][j])
        {
            count++;
        }
    if(j < colCount-1)
    {
        maxElementOfTheMatrix(array, rowCount, colCount, i, j+1);
    }
    else
        if(i < rowCount-1)
        {
            maxElementOfTheMatrix(array, rowCount, colCount, i+1, 0);
        }
    
    else
        cout << "Найбільший елемент: " << maxElement << endl;
    
}

int countRow(int** array, const int rowCount , const int colCount,int i,int j)
{
    int count = 0;
    if(array[i][j] ==0)
    {
        count++;
    }
    if(j<colCount-1)
    {
        maxElementOfTheMatrix(array, rowCount, colCount, i, j+1);
    }
    else
        if(i<rowCount-1)
        {
            maxElementOfTheMatrix(array, rowCount, colCount, i+1, 0);
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
    
    for (int i=0; i<rowCount; i++)
        
    arr[i] = new int[colCount];

    createArray(arr, rowCount, colCount, Low, High,0,0);
    maxElementOfTheMatrix(arr, rowCount, colCount,0,0);
    cout<< countRow(arr, rowCount, colCount,0,0);
    printArray(arr, rowCount, colCount,0,0);
    
    for (int i=0; i<rowCount; i++)
        
    delete [] arr[i];
    delete [] arr;
    
    return 0;

}

