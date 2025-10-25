#include <iostream>
#include <omp.h>

using namespace std;

void Work()
{
    cout << "working" << endl;
}

void someCode()
{
    cout << "someCode" << endl;
}

void someMoreCode()
{
    cout << "someMoreCode" << endl;
}


int main()
{
    //示例1,barrier指令-显式
    #pragma omp parallel
    {
        someCode();
        //同步，所有线程完成任务后再执行下一操作
        #pragma omp barrier

        someMoreCode();
    }

    //示例2,隐式barrier
    #pragma omp parallel
    {
        #pragma omp for
        for(int n = 0;n<100;n++)
        {
            Work();
        }
        //必须完成循环再进行下一段
        someCode();
    }

    //示例3，使用nowait
    #pragma omp parallel
    {
        #pragma omp for nowait
        for(int n = 0;n<100;n++)
        {
            Work();
        }
        //部分线程没有完成循环，其他可以直接接下一任务
        someCode();
    }
    //这属于主线程，需要其他并行区域全部结束才运行
    printf("CodeContinus\n");

    return 0;
}