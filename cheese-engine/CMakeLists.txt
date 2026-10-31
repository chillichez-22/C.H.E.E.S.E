

set( components_sources 

    "source/components/component.cpp"

    "source/components/transform.cpp"
)

set( entity_sources 

    "source/entity/entity.cpp"

    "source/entity/camera.cpp"
    
)

set( file_sources

    "source/files/loading.cpp"
)

set( font_sources

    "source/fonts/font.cpp"

    "source/fonts/ttf.cpp"
)


set( iterables_sources 

    "source/iterables/buffer.cpp"
)

set( maths_sources

    "source/maths/math.cpp"

    "source/maths/interpolation.cpp"
    "source/maths/matrix.cpp"
    "source/maths/ray.cpp"
    "source/maths/vector_2.cpp"
    "source/maths/vector_3.cpp"
    "source/maths/vector_4.cpp"
)

set( physics_sources

    "source/physics/collision_result.cpp"    
    "source/physics/collisions.cpp"    

    # Collision2D

    # Collision3D
    "source/physics/collision_3d/ray_3d_collisions.cpp"   

)


set( rendering_sources
    
    "source/rendering/rendering.cpp"
    
    "source/rendering/colour.cpp"
    "source/rendering/fragment_shader.cpp"
    "source/rendering/input_assembler.cpp"
    "source/rendering/rasteriser.cpp"
    "source/rendering/primitive_assembler.cpp"
    "source/rendering/primitives.cpp"
    "source/rendering/projection.cpp"
    "source/rendering/vertex_shader.cpp"
    "source/rendering/vertex.cpp"
    "source/rendering/view_volume.cpp"
)

set( shape_sources

    "source/shapes/shape.cpp"

    # Shape 2D
    "source/shapes/shapes_2d/shape_2d.cpp"
    
    "source/shapes/shapes_2d/circle_2d.cpp"
    "source/shapes/shapes_2d/line_2d.cpp"
    "source/shapes/shapes_2d/quad_2d.cpp"
    "source/shapes/shapes_2d/rect_2d.cpp"
    "source/shapes/shapes_2d/tri_2d.cpp"

    # Shape 3D
    "source/shapes/shapes_3d/shape_3d.cpp"

    "source/shapes/shapes_3d/box.cpp"
    "source/shapes/shapes_3d/line_3d.cpp"
    "source/shapes/shapes_3d/sphere.cpp"
    "source/shapes/shapes_3d/tri_3d.cpp"
    "source/shapes/shapes_3d/quad_3d.cpp"
)

set( interactions_sources 

    # Inputs
    "source/interactions/inputs/mouse.cpp"

    # UI
    "source/interactions/ui/ui.cpp"

    "source/interactions/ui/button.cpp"
    "source/interactions/ui/checkbox.cpp"
    "source/interactions/ui/interactable.cpp"
    "source/interactions/ui/slider.cpp"
    "source/interactions/ui/text.cpp"
    "source/interactions/ui/ui_element.cpp"
    
)


# Creates engine library
add_library( cheese-engine STATIC

    # Source files
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
target_include_directories( cheese-engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/header
    
        # Likes to misbehave without calling all individual header folders
        ${CMAKE_CURRENT_SOURCE_DIR}/header/components
        ${CMAKE_CURRENT_SOURCE_DIR}/header/entity
        ${CMAKE_CURRENT_SOURCE_DIR}/header/files
        ${CMAKE_CURRENT_SOURCE_DIR}/header/fonts

        ${CMAKE_CURRENT_SOURCE_DIR}/header/interactions
        ${CMAKE_CURRENT_SOURCE_DIR}/header/interactions/inputs
        ${CMAKE_CURRENT_SOURCE_DIR}/header/interactions/ui

        ${CMAKE_CURRENT_SOURCE_DIR}/header/iterables
        ${CMAKE_CURRENT_SOURCE_DIR}/header/maths

        ${CMAKE_CURRENT_SOURCE_DIR}/header/physics
        ${CMAKE_CURRENT_SOURCE_DIR}/header/physics/collision_2d
        ${CMAKE_CURRENT_SOURCE_DIR}/header/physics/collision_3d

        ${CMAKE_CURRENT_SOURCE_DIR}/header/rendering   

        ${CMAKE_CURRENT_SOURCE_DIR}/header/shapes
        ${CMAKE_CURRENT_SOURCE_DIR}/header/shapes/shapes_2d
        ${CMAKE_CURRENT_SOURCE_DIR}/header/shapes/shapes_3d
)

# Links SDL3 to the engine library
target_link_libraries( cheese-engine

    PUBLIC
        SDL3::SDL3
)


target_compile_features( cheese-engine PUBLIC )