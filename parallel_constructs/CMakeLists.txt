
set(SOURCES
    # 只添加一个cpp
    demo02.cpp
)

add_executable(parallel_constructs_demo ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(parallel_constructs_demo OpenMP::OpenMP_CXX)
endif()
