#include <iostream>
#include <vector>
#include<iomanip>
#include <fstream>
#include<conio.h>
#include <string>
using namespace std;

void erase(int *array,int &len, int id)
{

    for(int i=id-1;i<len-1;i++)
    {
        array[i]=array[i+1];
    }
    len--;
}

int main()
{
    int lenght;
    cout<<"enter size of array: "<<endl;
    cin>>lenght;
    int *array = new int[lenght];
    for(int i=0;i<lenght;i++)
    {
       array[i]=rand()%30;
       cout<<array[i]<<" ";
    }
    int id_;
    cout<<endl;
    cout<<"enter id: ";
    cin>>id_;
    erase(array,lenght, id_);
    for(int i=0;i<lenght;i++)
    {
        cout<<array[i]<<" ";
    }
    delete[]array;
    return 0;
}
