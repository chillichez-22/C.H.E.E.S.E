cmake_minimum_required( VERSION 3.20 )

project( cheese-engine )

find_package( SDL3 REQUIRED )


# Creates engine library
add_library( engine

    # Source files ( Headers aren't necessary )

    # Maths
    cheese-engine/source/maths/math.cpp

    cheese-engine/source/maths/matrix.cpp
    cheese-engine/source/maths/vector_2.cpp
    cheese-engine/source/maths/vector_3.cpp
    cheese-engine/source/maths/vector_4.cpp

    # Shapes
    cheese-engine/source/shapes/shape.cpp

    cheese-engine/source/shapes/circle.cpp
    cheese-engine/source/shapes/line.cpp
    cheese-engine/source/shapes/rect.cpp
    cheese-engine/source/shapes/tri.cpp

)

target_include_directories( engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/maths
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes
)

# Links SDL3 to the engine library
target_link_libraries( engine

    PUBLIC
        SDL3::SDL3
)


# Creates main build
add_executable( cheese-engine-main cheese-engine/source/main.cpp )

target_link_libraries( cheese-engine-main

    PRIVATE
        engine
)

# Creates testing build
add_executable( cheese-engine-testing cheese-engine/source/testing.cpp )

# Adds test files to the testing scene
target_sources( engine

    PUBLIC
    
        # Tests
        cheese-engine/source/tests/vector_test.cpp


)

target_include_directories( engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/tests
)

target_link_libraries( cheese-engine-testing

    PRIVATE
        engine
)

