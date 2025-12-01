if (NOT TARGET pico-util)

    add_library(pico-util STATIC
        src/util/StringLite.h
    )

    target_include_directories(pico-util PUBLIC
        include
        src # for tpp files
    )

endif()