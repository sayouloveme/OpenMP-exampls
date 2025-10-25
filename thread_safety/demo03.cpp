//flush
/*
线程在执行操作的时候没有马上放回主内存而是放入寄存器缓存区，
导致其他线程拿到的数据是旧的，
两者的数据是不一致的，
而flush可以强制让主内存的变量更新
*/
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int a = 0,b = 0;
    #pragma omp parallel num_threads(2) shared(a,b)
    {
        int tid = omp_get_thread_num();
        if(tid == 0)
        {
            b = 1;
            #pragma omp flush(a,b)
            if(a==0)
            {
                printf("other thread changed a %d\n",a);
            }
        }
        else if(tid == 1)
        {
            a = 2;
            #pragma omp flush(a,b)
            if(b==0)
            {
                printf("other thread changed b %d\n",b);
            }
        }

    }

    printf("end of a is %d, b is %d\n",a,b);

    return 0;
}