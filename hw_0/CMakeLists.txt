cmake_minimum_required(VERSION 3.14)

project(quadratic)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wpedantic")

## For Release - cmake -DCMAKE_BUILD_TYPE=Release ../
## For Debug - cmake -DCMAKE_BUILD_TYPE=Debug ../
add_compile_options(
  $<$<CONFIG:DEBUG>:-g3>
  $<$<CONFIG:DEBUG>:-O0>
  $<$<CONFIG:RELEASE>:-O3>
)


set(SOURCE_LIST
    src/sources/main.cpp 
    src/sources/quadratic.cpp
    src/sources/input_process.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCE_LIST}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE src/headers)


