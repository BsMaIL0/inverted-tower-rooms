cmake_minimum_required(VERSION 3.10)

project(inverted-tower-rooms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
endif()

include_directories(include)

add_executable(inverted-tower-rooms 
    src/main.cpp
    src/inverted-tower-rooms.cpp
)

option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)
    
    add_executable(tests 
        tests/test_inverted-tower-rooms.cpp
        src/inverted-tower-rooms.cpp
    )
    
    target_include_directories(tests PRIVATE include)
    target_link_libraries(tests gtest_main)
    
    add_test(NAME inverted-tower-rooms-tests COMMAND tests)
endif()