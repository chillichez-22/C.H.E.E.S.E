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


set( components_sources 

    "cheese-engine/source/components/component.cpp"

    "cheese-engine/source/components/transform.cpp"
)

set( entity_sources 

    "cheese-engine/source/entity/entity.cpp"
    
)

set( file_sources

    "cheese-engine/source/files/loading.cpp"
)

set( font_sources

    "cheese-engine/source/fonts/font.cpp"

    "cheese-engine/source/fonts/ttf.cpp"
)


set( iterables_sources 

    "cheese-engine/source/iterables/buffer.cpp"
)

set( maths_sources

    "cheese-engine/source/maths/math.cpp"

    "cheese-engine/source/maths/interpolation.cpp"
    "cheese-engine/source/maths/matrix.cpp"
    "cheese-engine/source/maths/ray.cpp"
    "cheese-engine/source/maths/vector_2.cpp"
    "cheese-engine/source/maths/vector_3.cpp"
    "cheese-engine/source/maths/vector_4.cpp"
)

set( physics_sources

    "cheese-engine/source/physics/collision_result.cpp"    
    "cheese-engine/source/physics/collisions.cpp"    

    # Collision2D

    # Collision3D
    "cheese-engine/source/physics/collision_3d/ray_3d_collisions.cpp"   

)


set( rendering_sources
    
    "cheese-engine/source/rendering/rendering.cpp"
    
    "cheese-engine/source/rendering/colour.cpp"
    "cheese-engine/source/rendering/fragment_shader.cpp"
    "cheese-engine/source/rendering/input_assembler.cpp"
    "cheese-engine/source/rendering/rasteriser.cpp"
    "cheese-engine/source/rendering/primitives.cpp"
    "cheese-engine/source/rendering/primitive_assembler.cpp"
    "cheese-engine/source/rendering/vertex_shader.cpp"
    "cheese-engine/source/rendering/vertex.cpp"
)

set( shape_sources

    "cheese-engine/source/shapes/shape.cpp"

    # Shape 2D
    "cheese-engine/source/shapes/shapes_2d/shape_2d.cpp"
    
    "cheese-engine/source/shapes/shapes_2d/circle_2d.cpp"
    "cheese-engine/source/shapes/shapes_2d/line_2d.cpp"
    "cheese-engine/source/shapes/shapes_2d/quad_2d.cpp"
    "cheese-engine/source/shapes/shapes_2d/rect_2d.cpp"
    "cheese-engine/source/shapes/shapes_2d/tri_2d.cpp"

    # Shape 3D
    "cheese-engine/source/shapes/shapes_3d/shape_3d.cpp"

    "cheese-engine/source/shapes/shapes_3d/box.cpp"
    "cheese-engine/source/shapes/shapes_3d/line_3d.cpp"
    "cheese-engine/source/shapes/shapes_3d/sphere.cpp"
    "cheese-engine/source/shapes/shapes_3d/tri_3d.cpp"
    "cheese-engine/source/shapes/shapes_3d/quad_3d.cpp"
)

set( interactions_sources 

    # Inputs
    "cheese-engine/source/interactions/inputs/mouse.cpp"

    # UI
    "cheese-engine/source/interactions/ui/ui.cpp"

    "cheese-engine/source/interactions/ui/button.cpp"
    "cheese-engine/source/interactions/ui/checkbox.cpp"
    "cheese-engine/source/interactions/ui/interactable.cpp"
    "cheese-engine/source/interactions/ui/slider.cpp"
    "cheese-engine/source/interactions/ui/text.cpp"
    "cheese-engine/source/interactions/ui/ui_element.cpp"
    
)


# Creates engine library
add_library( engine

    # Source files ( Headers aren't necessary )
    ${components_sources}
    ${entity_sources}
    ${file_sources}
    ${interactions_sources}
    ${iterables_sources}
    ${maths_sources}
    ${physics_sources}
    ${rendering_sources}
    ${shape_sources}

)

# Attaches the header files
target_include_directories( engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header
    
        # Likes to misbehave without calling all individual header folders
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/components
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/entity
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/files
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/fonts

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/interactions
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/interactions/inputs
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/interactions/ui

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/iterables
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/maths

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/physics
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/physics/collision_2d
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/physics/collision_3d

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/rendering   

        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes/shapes_2d
        ${CMAKE_CURRENT_SOURCE_DIR}/cheese-engine/header/shapes/shapes_3d
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