### 128 bit keys ###

add_executable(aes_key_sched_128_test
        aes_key_sched_128.c
        )

add_executable(aes_encrypt_128_test
        aes_encrypt_128.c
        )

add_executable(aes_decrypt_128_test
        aes_decrypt_128.c
        )

target_link_libraries(aes_key_sched_128_test PUBLIC msaes)
target_link_libraries(aes_encrypt_128_test PUBLIC msaes)
target_link_libraries(aes_decrypt_128_test PUBLIC msaes)

add_test(NAME aes_key_sched_128 COMMAND aes_key_sched_128_test)
add_test(NAME aes_encrypt_128 COMMAND aes_encrypt_128_test)
add_test(NAME aes_decrypt_128 COMMAND aes_decrypt_128_test)

### 192 bit keys ###

add_executable(aes_key_sched_192_test
        aes_key_sched_192.c
        )

add_executable(aes_encrypt_192_test
        aes_encrypt_192.c
        )

add_executable(aes_decrypt_192_test
        aes_decrypt_192.c
        )

target_link_libraries(aes_key_sched_192_test PUBLIC msaes)
target_link_libraries(aes_encrypt_192_test PUBLIC msaes)
target_link_libraries(aes_decrypt_192_test PUBLIC msaes)

add_test(NAME aes_key_sched_192 COMMAND aes_key_sched_192_test)
add_test(NAME aes_encrypt_192 COMMAND aes_encrypt_192_test)
add_test(NAME aes_decrypt_192 COMMAND aes_decrypt_192_test)

### 256 bit keys ###

add_executable(aes_key_sched_256_test
        aes_key_sched_256.c
        )

add_executable(aes_encrypt_256_test
        aes_encrypt_256.c
        )

add_executable(aes_decrypt_256_test
        aes_decrypt_256.c
        )

target_link_libraries(aes_key_sched_256_test PUBLIC msaes)
target_link_libraries(aes_encrypt_256_test PUBLIC msaes)
target_link_libraries(aes_decrypt_256_test PUBLIC msaes)

add_test(NAME aes_key_sched_256 COMMAND aes_key_sched_256_test)
add_test(NAME aes_encrypt_256 COMMAND aes_encrypt_256_test)
add_test(NAME aes_decrypt_256 COMMAND aes_decrypt_256_test)

### Padding ###

add_executable(aes_pad_buf_len_test
        aes_pad_buf_len.c
        )

add_executable(aes_pad_buffer_test
        aes_pad_buffer.c
        )

add_executable(aes_unpad_buf_len_test
        aes_unpad_buf_len.c
        )

add_executable(aes_unpad_buffer_test
        aes_unpad_buffer.c
        )

target_link_libraries(aes_pad_buf_len_test PUBLIC msaes)
target_link_libraries(aes_pad_buffer_test PUBLIC msaes)
target_link_libraries(aes_unpad_buf_len_test PUBLIC msaes)
target_link_libraries(aes_unpad_buffer_test PUBLIC msaes)

add_test(NAME aes_pad_buf_len COMMAND aes_pad_buf_len_test)
add_test(NAME aes_pad_buffer COMMAND aes_pad_buffer_test)
add_test(NAME aes_unpad_buf_len COMMAND aes_unpad_buf_len_test)
add_test(NAME aes_unpad_buffer COMMAND aes_unpad_buffer_test)
