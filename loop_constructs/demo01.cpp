#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    //启动并行区域
    #pragma omp parallel
    {
        //loop constructs
        #pragma omp for
        for(int n = 0;n<10;n++)
        {
            //cout << n << endl;不用是因为cout会导致线程不安全
            printf("%d",n);
        }

        //同步操作，保证所有线程均完成任务，线程数为0意味着只剩主线程
        #pragma omp barrier
        if(omp_get_num_threads==0)
        {
            printf(".\n");
        }

    }
    /*
    等效的简写方式：
    #pragma omp parallel for
    #pragma omp parallel
    {
        #pragma omp for
        for()
        {}
    }
    */



    return 0;
}