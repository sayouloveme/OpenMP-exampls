set(SOURCES
    # 只添加一个cpp
    demo01.cpp
)

add_executable(task_constructs ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(task_constructs OpenMP::OpenMP_CXX)
endif()
