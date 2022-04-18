#include <iostream>
#include <vector>
#include<iomanip>
#include <fstream>
#include<conio.h>
#include <string>
using namespace std;

int countNum(int n, int k)
{
    int s_n=n;
    int count=0;
    while(s_n)
    {
        s_n/=10;
        count++;
    }

    for(int i=0;i<count-k;i++)
    {
        n/=10;
    }
    return n;
}
int main()
{
    int chislo, razr;
    cout<<"enter number: "<<endl;
    cin>>chislo;
    cout<<"enter razryad: "<<endl;
    cin>>razr;
    cout<<countNum(chislo,razr)<<endl;
    return 0;
}
