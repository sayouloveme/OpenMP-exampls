cmake_minimum_required(VERSION 3.10)

project(OpenMPExample)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenMP REQUIRED)

add_subdirectory(parallel_constructs)
add_subdirectory(loop_constructs)
add_subdirectory(thread_safety)
add_subdirectory(private_firstprivate_shared_clauses)
add_subdirectory(reduction)
add_subdirectory(execution_synchronization)
add_subdirectory(task_constructs)
add_subdirectory(thread_cancellation)

if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
