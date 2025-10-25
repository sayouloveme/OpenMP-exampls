#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    //指定线程数量
    #pragma omp parallel num_threads(3)
    {
        #pragma omp for
        for(int n = 0;n<10;n++)
        {
            printf("thread%d\n",n);
        }

    }

    return 0;
}