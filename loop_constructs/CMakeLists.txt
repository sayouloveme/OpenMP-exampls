set(SOURCES
    # 只添加一个cpp
    demo03.cpp
)

add_executable(loop_constructs_demo ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(loop_constructs_demo OpenMP::OpenMP_CXX)
endif()
