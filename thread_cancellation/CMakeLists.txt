set(SOURCES
    # 只添加一个cpp
    demo01.cpp
)

add_executable(thread_cancellation ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(thread_cancellation OpenMP::OpenMP_CXX)
endif()
