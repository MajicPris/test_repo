#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;


int main()
{
    cout<<"enter rows: "<<endl;
    int rows;
    cin>>rows;
    cout<<"enter column: "<<endl;
    int column;
    cin>>column;
    int **array = new int* [rows];
    for(int i=0;i<rows;i++)
    {
        array[i]=new int[column];
    }
    for(int i=0;i<rows; i++)
    {
        for(int j=0;j<column;j++)
        {
            array[i][j]=rand()%10-2;
            cout<<setw(4)<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    int *arr = new int[rows];
    for(int j=0;j<rows;j++)
    {
        arr[j]=0;
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(array[i][j]>=0)
            {
               arr[i]+=array[i][j];
            }
            else
            {
                arr[i]=0;
                break;
            }
        }
    }
    for(int j =0;j<rows;j++)
    {
        if(arr[j]!=0)
            cout<<arr[j]<<" ";
        else
            cout<<" ";
    }
    return 0;
}
