add_library(aeslib
        src/aes_proc.c
        src/aes_key_sched.c
        )

target_include_directories(aeslib PUBLIC headers)
