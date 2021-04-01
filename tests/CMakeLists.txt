# This file finds all files in subdirectories in current folder and generates
# a test with matching name for each one of them (1 source file = 1 test)

# example: file "module1/test.c" generates executable target "module1_test" and test "module1/test"

# find all .c files in subdirs
file(GLOB files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*/*.c")

foreach(filename ${files})
    string(REPLACE ".c" "" testname ${filename})

    string(REPLACE "/" "_" execname ${testname})

    message("Generating test " ${testname})

    # create target
    add_executable(${execname}
        ${filename}
        )
    
    # link test to library
    target_link_libraries(${execname} PUBLIC msaes)

    # create test
    add_test(NAME ${testname} COMMAND ${execname}) 
endforeach()
