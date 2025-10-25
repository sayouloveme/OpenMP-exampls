set(SOURCES
    # 只添加一个cpp
    demo03.cpp
)

add_executable(thread_safety ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(thread_safety OpenMP::OpenMP_CXX)
endif()
