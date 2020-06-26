cmake_minimum_required(VERSION 2.8.0)
project("aes" LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -Wextra")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DAES_DEBUG")

add_library(aes SHARED
        src/proc.c
        src/key_sched.c
        src/gf256.c
        src/encrypt.c
        src/decrypt.c
        )

target_include_directories(aes PUBLIC include)

enable_testing()
add_subdirectory(tests)
