cmake_minimum_required(VERSION 3.16)
project(crawler)

set(PROG crawler)

#add_subdirectory(curl-7.79.1)
add_subdirectory(3rdparty)

set(CMAKE_CXX_STANDARD 14)

file(GLOB source
        main.cpp
)

add_executable(${PROG} ${source})

#PRIVATE关键字必须大写
target_include_directories(${PROG}
    PRIVATE 3rdparty/restclient-cpp-0.5.2/include
    # PRIVATE curl-7.79.1/include
)

target_link_libraries(${PROG}
    restclient-cpp
)
