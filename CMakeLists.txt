cmake_minimum_required( VERSION 4.3.3 )

project( cheese LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 26 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS ON )

# External dependencies
find_package( SDL3 REQUIRED )


# Options
option( IS_TESTING "Enables the testing." OFF )


add_subdirectory( cheese-engine )

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
            cheese-engine
            GTest::gtest
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests( ${PROJECT_NAME}-testing )

else()
 
    # Creates main build
    add_executable( ${PROJECT_NAME}-main main.cpp )

    target_link_libraries( ${PROJECT_NAME}-main

        PRIVATE
            cheese-engine
    )

endif()