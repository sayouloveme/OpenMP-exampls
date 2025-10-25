#include <iostream>
#include <omp.h>

using namespace std;

int main()
{

    int x = 0;
    int val = 0;
    int expr = 5;

    #pragma omp parallel
    {
        #pragma omp atomic read
        val = x;
    }

    #pragma omp parallel
    {
        #pragma omp atomic write
        x = expr;
    }

    #pragma omp parallel
    {   
        for(int n = 0;n<100;n++)
        {
        //更新（自增，加法），不会返回旧值
        #pragma omp atomic update
        x += expr;
        }
    }

    #pragma omp parallel
    {
        //读取当前值，并更新，且可以赋给其他变量
        #pragma omp atomic capture
        val = x++;
    }

    printf("final x is %d\n",x);
    printf("final val is %d\n",val);


    return 0;
}