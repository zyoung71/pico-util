if (NOT TARGET pico-util)

    add_library(pico-util INTERFACE)

    target_include_directories(pico-util INTERFACE
        include
    )

    target_include_directories(pico-util INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src> 
    )

endif()