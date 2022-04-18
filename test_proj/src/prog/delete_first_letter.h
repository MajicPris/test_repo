#include <iostream>
#include <vector>
#include<iomanip>
#include <fstream>
#include<conio.h>
#include <string>
using namespace std;


int main()
{
    cout<<"Enter the string and finish it with point: "<<endl;
    char buf[50];
    char buf1[50];
    char b;
    int count=0;
    int d=1;
    int n=0;
    do
    {
        b=getchar();
        buf[n]=b;
        ++n;
    } while(b!='.');
    --n;
    for(int i=0;i<n;++i)
    {
        if(d)
        {
            buf[i]=0;
            d=0;
            continue;
        }
        if(buf[i]==' ')
        {
            d=1;
        }
        if(buf[i]!='0')
        {
            buf1[count]=buf[i];
            ++count;
        }
    }

    for(int i=0;i<count;++i)
        cout<<buf1[i];
    return 0;
}
