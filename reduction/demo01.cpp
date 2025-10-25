#include <iostream>
#include <omp.h>

using namespace std;
/*
区别：
reduction语法:reduction(operator,var)，对var进行operator操作
每个线程会创建一个var的副本，副本内进行操作，不同的线程可以并行操作，最后通过operator合并
比如thread1(负责2*3),thread2（负责4*5*6）
合并后传入shared var

atomic会让操作原子化，即thread1在占用这个操作的时候thread2无法占用，虽然可以保证线程安全，没有竞争，但是会导致性能瓶颈
*/
int factorial1(int number)
{
    int fac = 1;
    #pragma omp parallel for reduction(*:fac)
    for(int n = 2;n<number;n++)
    {
        fac *= n;
    }
    return fac;
}

int factorial2(int number)
{
    int fac = 1;
    #pragma omp parallel for 
    for(int n = 2;n<number;n++)
    {
        #pragma omp atomic
        fac *= n;
    }
    return fac;
}

int main()
{
    int number = 10;
    int result1 = factorial1(number);
    int result2 = factorial2(number);

    cout << "result1 is " << result1 << endl;
    cout << "result2 is " << result2 << endl;
    return 0;
}