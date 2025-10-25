#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    //设置线程数
    omp_set_num_threads(4);

    //并行执行
    #pragma omp parallel
    {
        cout << "hello from thread" << omp_get_num_threads() << endl;
        //omp_get_num_threads()输出的是线程数量
        //竞争输出，顺序由操作系统决定
    }


    return 0;
}