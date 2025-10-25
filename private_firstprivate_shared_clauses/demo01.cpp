#include <iostream>
#include <omp.h>
#include <string>

using namespace std;

int main()
{
    string a = "x";
    string b = "y";
    int c = 3;

    //private（生成一个未初始化的副本）意味着a,c被私有化声明，但没有初始值
    #pragma omp parallel private(a,c) shared(b) num_threads(2)
    {
        a += "k";//比较是否是无初始化
        c += 7;

        printf("a become %s,b is %s\n",a.c_str(),b.c_str());

    }
    
    //firstprivate就是有初始值，shared就是共享
    #pragma omp parallel firstprivate(a,c) shared(b) num_threads(2)
    {
        a += "k";//比较是否是无初始化
        c += 7;

        printf("a become %s,b is %s\n",a.c_str(),b.c_str());
    }

    return 0;
}