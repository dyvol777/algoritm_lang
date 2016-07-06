#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main()
{
//1031*2017=2079527
//2076480
//9973 1740637
    string a;
    fstream f0("0.txt");
    fstream f1("1.txt");
    fstream f2("2.txt");
    fstream f3("3.txt");
    f1.clear();
    f2.clear();
    f3.clear();
    int z=0;
    while(!f0.eof())
    {
        getline(f0,a);
        for (int i=0;i<a.size();i++)
        {
        if ((a[i]=='0')||(a[i]=='1')||(a[i]=='2')||(a[i]=='3')||(a[i]=='4')||(a[i]=='5')||(a[i]=='6')||(a[i]=='7')||(a[i]=='8')||(a[i]=='9')||(a[i]=='0'))
        f1<<a[i];
        };
        f1<<endl;
    }
    long long int b,c,d,e;

    f1.seekg(0);
    while(!f1.eof())
    {
    getline(f1,a);
    d=(long long int)atoll(a.c_str())/1000000;
    cout<<d<<' ';
    b=1;
    for (int i = 0; i<9973; i++)
    {
    b=(b*d)%2079527;
    };
    b=b%2079527;
    if (b!=0)
    f2<<b<<' ';

    e=(long long int)atoll(a.c_str())%1000000;
    cout<<e<<' ';
    b=1;
    for (int i = 0; i<9973; i++)
    {
    b=(b*e)%2079527;
    };
    b=b%2079527;
    if (b!=0)
    f2<<b<<endl;
    }

    f2.seekg(0);
    while(!f2.eof())
    {
    f2>>d;
    cout<<d<<' ';
    c=1;
    for (int i = 0; i<1740637; i++)
    {
    c=(c*d)%2079527;
    };
    c=c%2079527;
    if (c!=0) f3<<c;

    f2>>e;
    cout<<e<<' ';
    c=1;
    for (int i = 0; i<1740637; i++)
    {
    c=(c*e)%2079527;
    };
    c=c%2079527;
    if (c!=0) f3<<c<<endl;
    }

    f0.close();
    f1.close();
    f2.close();
    f3.close();
    return 0;
}

