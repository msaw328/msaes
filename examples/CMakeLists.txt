add_subdirectory(ofb_pipe)

add_custom_target(examples DEPENDS
        ofb_pipe
        )
