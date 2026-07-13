cmake_minimum_required( VERSION 4.3.3 )

project( cheese LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 26 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS ON )

find_package( SDL3 REQUIRED )

# Finds engine source files

set( maths_sources

    "cheese-engine/source/maths/math.cpp"

    "cheese-engine/source/maths/matrix.cpp"
    "cheese-engine/source/maths/vector_2.cpp"
    "cheese-engine/source/maths/vector_3.cpp"
    "cheese-engine/source/maths/vector_4.cpp"
)

set( shapes_sources

    "cheese-engine/source/shapes/shape.cpp"

    "cheese-engine/source/shapes/circle.cpp"
    "cheese-engine/source/shapes/line.cpp"
    "cheese-engine/source/shapes/rect.cpp"
    "cheese-engine/source/shapes/tri.cpp"
)

set( test_sources

    "cheese-engine/source/tests/vector_test.cpp"
)

# Creates engine library
add_library( engine

    # Source files ( Headers aren't necessary )

    ${maths_sources}
    ${shapes_sources}
)

# Attaches the header files
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
add_executable( ${PROJECT_NAME}-main cheese-engine/source/main.cpp )

target_link_libraries( ${PROJECT_NAME}-main

    PRIVATE
        engine
)


# Creates testing build
add_executable( ${PROJECT_NAME}-testing cheese-engine/source/testing.cpp )

# Adds test source files
target_sources( engine

    PRIVATE
        ${test_sources}
)

# Adds test header files
target_include_directories( engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/tests
)

target_link_libraries( ${PROJECT_NAME}-testing

    PRIVATE
        engine
)

