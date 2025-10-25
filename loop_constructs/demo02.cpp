#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    //总任务量
    int total_iterations = 10;

    #pragma omp parallel
    {
        //获取线程ID和线程数
        int this_thread = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        //均分任务量，this_thread（+1）负责确定起始和结束位置
        int m_start = (this_thread)*total_iterations/num_threads;
        int m_end = (this_thread+1)*total_iterations/num_threads;

        for(int n = m_start;n<m_end;n++)
        {
            printf("线程%d:%d\n",this_thread,n);
        }



    }



    return 0;
}