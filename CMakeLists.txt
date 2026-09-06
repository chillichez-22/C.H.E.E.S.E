cmake_minimum_required( VERSION 4.3.3 )
project( cheese LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 26 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS ON )

# External dependencies
find_package( SDL3 REQUIRED )


# Options
option( IS_TESTING "Enables the testing." OFF )


# Finds engine source files

set( collision_sources

    "cheese-engine/source/collisions/collision_result.cpp"    
)

set( colour_sources 

    "cheese-engine/source/colour/colour.cpp"
)

set( font_sources

    "cheese-engine/source/fonts/font.cpp"
    "cheese-engine/source/fonts/ttf.cpp"
)

set( inputs_sources 

    "cheese-engine/source/inputs/mouse.cpp"
)


set( maths_sources

    "cheese-engine/source/maths/math.cpp"

    "cheese-engine/source/maths/matrix.cpp"
    "cheese-engine/source/maths/vector_2.cpp"
    "cheese-engine/source/maths/vector_3.cpp"
    "cheese-engine/source/maths/vector_4.cpp"
)

set( shape_base_sources

    "cheese-engine/source/shapes/shape.cpp"
)

set( shapes_2d_sources

    "cheese-engine/source/shapes_2d/shape_2d.cpp"

    "cheese-engine/source/shapes_2d/circle.cpp"
    "cheese-engine/source/shapes_2d/line_2d.cpp"
    "cheese-engine/source/shapes_2d/rect.cpp"
    "cheese-engine/source/shapes_2d/tri.cpp"
)

set( shapes_3d_sources

    "cheese-engine/source/shapes_3d/shape_3d.cpp"

    "cheese-engine/source/shapes_3d/box.cpp"
    "cheese-engine/source/shapes_3d/line_3d.cpp"
    "cheese-engine/source/shapes_3d/sphere.cpp"
)

set( ui_sources 

    "cheese-engine/source/ui/ui.cpp"

    "cheese-engine/source/ui/button.cpp"
    "cheese-engine/source/ui/checkbox.cpp"
    "cheese-engine/source/ui/interactable.cpp"
    "cheese-engine/source/ui/slider.cpp"
    "cheese-engine/source/ui/text.cpp"
    "cheese-engine/source/ui/ui_element.cpp"
    
)


# Creates engine library
add_library( engine

    # Source files ( Headers aren't necessary )
    ${collision_sources}
    ${colour_sources}
    ${inputs_sources}
    ${maths_sources}
    ${shape_base_sources}
    ${shapes_2d_sources}
    ${shapes_3d_sources}
    ${ui_sources}

)

# Attaches the header files
target_include_directories( engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header
    
        # Likes to misbehave without calling all individual header folders
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/collisions
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/colour
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/fonts
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/inputs
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/maths
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes_2d
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes_3d
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/ui
)

# Links SDL3 to the engine library
target_link_libraries( engine

    PUBLIC
        SDL3::SDL3
)


if( IS_TESTING )
    
    find_package( GTest REQUIRED )

    include( CTest )
    enable_testing()

    # Gets the unit test sources
    set( test_sources

        "cheese-engine/tests/vector_test.cpp"
    )

    # Creates testing build
    add_executable( ${PROJECT_NAME}-testing ${test_sources} )

    # Adds test header files to the project
    target_include_directories( ${PROJECT_NAME}-testing

        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header
            ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/tests
    )

    # Adds Gtest to the project
    target_link_libraries( ${PROJECT_NAME}-testing
    
        PRIVATE
            engine
            GTest::gtest
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests( ${PROJECT_NAME}-testing )

else()
 
    # Creates main build
    add_executable( ${PROJECT_NAME}-main cheese-engine/source/main.cpp )

    target_link_libraries( ${PROJECT_NAME}-main

        PRIVATE
            engine
    )

endif()