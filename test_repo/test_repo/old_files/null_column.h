#include <iostream>
#include <vector>
#include<iomanip>
#include <fstream>
#include<conio.h>
#include <string>
using namespace std;

int zeroFunc(int **array1,int row, int column)
{
    for(int i=0;i<row;i++)
    {
        array1[i][column-1]=0;
    }
    return 0;
}
int main()
{
   cout<<"enter rows: "<<endl;
   int rows,column;
   cin>>rows;
   cout<<"enter column: "<<endl;
   cin>>column;
   int **array = new int* [rows];
   for(int i=0;i<rows;i++)
   {
       array[i]=new int [column];
   }
   for(int i=0;i<rows;i++)
   {
       for(int j=0;j<column;j++)
       {
           array[i][j]=rand()%40;
           cout<<setw(4)<<array[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
   zeroFunc(array, rows, 4);
   zeroFunc(array,rows, 2);
   for(int i=0; i<rows; i++)
   {
       for(int j=0;j<column; j++)
       {
           cout<<setw(4)<<array[i][j]<<" ";
       }
       cout<<endl;
   }
   return 0;
}
