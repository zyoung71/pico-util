if (NOT TARGET pico-util)

    add_library(pico-util STATIC
        src/StringLite.h
    )

    target_include_directories(pico-util PUBLIC
        include
        src # for tpp files
    )

endif()