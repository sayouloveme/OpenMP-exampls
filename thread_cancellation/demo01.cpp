#include <iostream>  
#include <cstring>   
#include <cstdlib>   
#include <unistd.h>  
#include <omp.h>     

static const char* FindAnyNeedle(const char* haystack, size_t size, char needle)
{
    const char* result = haystack + size;  // 初始化为NULL，表示未找到
    #pragma omp parallel
    {
        unsigned num_iterations = 0;
        #pragma omp for
        for (size_t p = 0; p < size; ++p)
        {
            ++num_iterations;
            if (haystack[p] == needle)  // 如果找到了needle
            {
                #pragma omp atomic write  // 使用原子操作确保写入安全
                result = haystack + p;   // 记录找到的位置
                // 线程间同步，取消其他线程的执行
                #pragma omp cancel for
            }
            // 取消点：所有线程在这里检查是否已被取消
            #pragma omp cancellation point for
        }
        // 所有线程都会到达这里，取消会让它们更早结束
        std::cout << "Thread " << omp_get_thread_num() << ": " 
                  << num_iterations << " iterations completed" << std::endl;
    }
    return result;  // 返回找到的匹配位置
}

int main(int argc, char** argv)
{
    if (!omp_get_cancellation())  // 检查是否启用了取消功能
    {
        std::cout << "Cancellations were not enabled, enabling cancellation and rerunning program" << std::endl;
        putenv("OMP_CANCELLATION=true");  // 启用取消功能
        execv(argv[0], argv);  // 重新启动程序
    }

    // 查找字符needle的位置并输出
    const char* result = FindAnyNeedle(argv[1], strlen(argv[1]), argv[2][0]);
    if (result != nullptr)
    {
        std::cout << argv[1] << std::endl;
        std::cout << std::string(result - argv[1], ' ') << "^" << std::endl;
    }
    else
    {
        std::cout << "Needle not found." << std::endl;
    }

    return 0;
}
