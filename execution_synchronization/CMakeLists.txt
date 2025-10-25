set(SOURCES
    # 只添加一个cpp
    demo01.cpp
)

add_executable(execution_synchronization ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(execution_synchronization OpenMP::OpenMP_CXX)
endif()
