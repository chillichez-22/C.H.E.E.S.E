

set( components_sources 

    "source/components/component.cpp"

    "source/components/transform.cpp"
)

set( entity_sources 

    "source/entity/entity.cpp"

    "source/entity/camera.cpp"
    
)

set( files_sources

    "source/files/loading.cpp"
)

set( fonts_sources

    "source/fonts/font.cpp"

    "source/fonts/ttf.cpp"
)

set( inputs_sources 

    "source/inputs/input_manager.cpp"
    "source/inputs/mouse.cpp"
)

set( iterables_sources 

    "source/iterables/buffer.cpp"
)

set( maths_sources

    "source/maths/math.cpp"

    "source/maths/interpolation.cpp"
    "source/maths/matrix.cpp"
    "source/maths/ray_2d.cpp"
    "source/maths/ray_3d.cpp"
    "source/maths/vector_2.cpp"
    "source/maths/vector_3.cpp"
    "source/maths/vector_4.cpp"
)

set( collisions_sources


    "source/collisions/collisions.cpp"    
    "source/collisions/collision_result.cpp"    

    # Collision2D

    # Collision3D
    "source/collisions/collisions_3d/ray_3d_collisions.cpp"   

)


set( rendering_sources
    
    "source/rendering/colour.cpp"
    "source/rendering/primitives.cpp"
    "source/rendering/projection.cpp"
    "source/rendering/vertex.cpp"
    "source/rendering/view_volume.cpp"

    # Pipeline
    "source/rendering/pipeline/fragment_shader.cpp"
    "source/rendering/pipeline/input_assembler.cpp"
    "source/rendering/pipeline/primitive_assembler.cpp"
    "source/rendering/pipeline/rasteriser.cpp"
    "source/rendering/pipeline/rendering.cpp"
    "source/rendering/pipeline/vertex_shader.cpp"
    
    
)


set( scenes_sources
    
    "sources/scenes/scene.cpp"
    
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


set( ui_sources     

    "source/ui/ui.cpp"

    "source/ui/button.cpp"
    "source/ui/checkbox.cpp"
    "source/ui/interactable.cpp"
    "source/ui/slider.cpp"
    "source/ui/text.cpp"
    "source/ui/ui_element.cpp"
    
)




# Creates engine library
add_library( cheese-engine STATIC

    # Source files
    ${components_sources}
    ${entity_sources}
    ${files_sources}
    ${fonts_sources}
    ${inputs_sources}
    ${iterables_sources}
    ${maths_sources}
    ${collisions_sources}
    ${rendering_sources}
    ${scene_sources}
    ${shape_sources}
    ${ui_sources}

)

# Attaches the header files
target_include_directories( cheese-engine

    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/header
    
)

# Links SDL3 to the engine library
target_link_libraries( cheese-engine

    PUBLIC
        SDL3::SDL3
)


target_compile_features( cheese-engine PUBLIC )