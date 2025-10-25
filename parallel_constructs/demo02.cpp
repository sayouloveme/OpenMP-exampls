#include <iostream>
#include <omp.h>
//OpenMP的并行输出是无序的
using namespace std;

int parallelism_enabled = 1;//全局变量的声明

void handle(int c)
{
    cout << "thread from " << omp_get_num_threads() << "idx " << c << endl;
}


int main()
{
    int n = 10;

    #pragma omp parallel for if(parallelism_enabled)
    //if条件下多线程，else单线程
    for(int c = 0;c<n;c++)
    {
        handle(c);
    }

    return 0;
}