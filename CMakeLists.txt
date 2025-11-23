if (NOT TARGET pico-util)

    add_library(pico-util INTERFACE)

    target_include_directories(pico-util INTERFACE
        include
    )

endif()