set(SOURCES
    # 只添加一个cpp
    demo01.cpp
)

add_executable(reduction ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(reduction OpenMP::OpenMP_CXX)
endif()
