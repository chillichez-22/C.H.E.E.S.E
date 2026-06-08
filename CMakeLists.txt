cmake_minimum_required( VERSION 3.20 )

project( spicy-engine )

find_package( SDL3 REQUIRED )

add_executable( ${PROJECT_NAME} spicy-engine/source/main.cpp )

target_sources( ${PROJECT_NAME}
    PRIVATE 

        # Header files

            # Maths 
            spicy-engine/header/maths/math.hpp

            spicy-engine/header/maths/vector.hpp
            spicy-engine/header/maths/matrix.hpp

            # Shapes
            spicy-engine/header/shapes/shape.hpp

            spicy-engine/header/shapes/circle.hpp
            spicy-engine/header/shapes/line.hpp
            spicy-engine/header/shapes/rect.hpp
            spicy-engine/header/shapes/tri.hpp


        # Source files
        spicy-engine/source/main.cpp

            # Maths
            spicy-engine/source/maths/math.cpp

            spicy-engine/source/maths/vector.cpp
            spicy-engine/source/maths/matrix.cpp

            # Shapes
            spicy-engine/source/shapes/shape.cpp

            spicy-engine/source/shapes/circle.cpp
            spicy-engine/source/shapes/line.cpp
            spicy-engine/source/shapes/rect.cpp
            spicy-engine/source/shapes/tri.cpp

)

target_include_directories( ${PROJECT_NAME}

    PRIVATE

        ${CMAKE_CURRENT_SOURCE_DIR}/spicy-engine/header
        ${CMAKE_CURRENT_SOURCE_DIR}/spicy-engine/header/maths
        ${CMAKE_CURRENT_SOURCE_DIR}/spicy-engine/header/shapes
)

target_link_libraries( ${PROJECT_NAME} 
    PRIVATE
    SDL3::SDL3
)
