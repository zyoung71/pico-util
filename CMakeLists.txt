if (NOT TARGET pico-util)

    add_library(pico-util STATIC
        src/util/StringLite.cpp
        src/util/FilesystemTree.cpp
        src/util/TimeHandler.cpp
        src/util/Chars.c
    )

    target_include_directories(pico-util PUBLIC
        include
        src # for tpp files
    )

    target_link_libraries(pico-util
        hardware_rtc
    )

endif()