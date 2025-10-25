set(SOURCES
    # 只添加一个cpp
    demo01.cpp
)

add_executable(private_firstprivate_shared_clauses ${SOURCES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(private_firstprivate_shared_clauses OpenMP::OpenMP_CXX)
endif()
