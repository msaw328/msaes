add_executable(aes_key_sched_128_test
        aes_key_sched_128.c
        )

add_executable(aes_encrypt_128_test
        aes_encrypt_128.c
        )

add_executable(aes_decrypt_128_test
        aes_decrypt_128.c
        )

target_link_libraries(aes_key_sched_128_test PUBLIC aes)
target_link_libraries(aes_encrypt_128_test PUBLIC aes)
target_link_libraries(aes_decrypt_128_test PUBLIC aes)

add_test(NAME aes_key_sched_128 COMMAND aes_key_sched_128_test)
add_test(NAME aes_encrypt_128 COMMAND aes_encrypt_128_test)
add_test(NAME aes_decrypt_128 COMMAND aes_decrypt_128_test)

#TODO:Add tests for 192 and 256 key lengths
