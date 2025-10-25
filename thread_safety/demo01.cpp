#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int counter = 0;
    int value = 1;

    #pragma omp parallel
    {
        for(int n = 0;n<100;n++)
        {
            //将操作原子化，该操作不会因为竞争而被打断
            #pragma omp atomic
            counter +=value;
        }

    }

    printf("final counter is %d\n",counter);

    return 0;
}