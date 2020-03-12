cmake_minimum_required(VERSION 2.8.0)
project("aes" LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -Wextra")

add_subdirectory(lib)
add_subdirectory(bin)
