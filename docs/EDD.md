Engine Design Document

# Main Page


## About

<span style = "font-size:30px;" >C.H.E.E.S.E</span>

A 3D Renderer & Environment Simulator.
<br>Started in June 2026.
<br>Written, Programmed & Tested by Chillichez.

C.H.E.E.S.E is a modular 3D Physics simulation engine, with a dedicated 3D/2D renderer, custom file handler, and UI. 
It simulates environments by using approximations that are realistic, and as accurate as possible, only sacrificing realism for the sake of optimisation, performance, and scope. It will be an ongoing project and be added upon throughout many years, being expanded and improved as I ( Chillichez ) learn better techniques, and proficiency in coding.

This is not a comprehensive list, but merely a snapshot of what to create. And what I believe can be achieved:

- Simple Plant-life, ( Moss, Lichen, Grass, Trees ) and how they grow and evolve according to varying factors.
- Wind Simulations on Nature ( Trees, Grass, Clouds ).
- Water Cycle, and its effects on environments ( Humidity, Rain Cycles, Hazardous Weather, Water Retention ).
- Heating Simulations and its effects in environments ( Evaporation, Soil Degradation ).
- Atmospheric Simulations and its effect on local flora.

<br>

## Dependencies

The project will be written in C++ 26 with ( C++ 202400 ), using the CMake Library ( CMAKE 4.3.3 ) to build the project, and the GGC Compiler for C++ ( GCC 15.2.0 ) as the minimum required.  

Additionally the project will use the Simple Direct Layer 3 ( SDL3 3.4.10 ) only for the window, screen, and audio. Along with Google Test ( GTest 1.17.0 ) as a testing framework.

<br>

# 1.0 System Overview


## 1.1 Roadmap

### 1.2.0 Phase 0 - Setup, Loop, Basic UI

Setup the project by implementing all dependencies. Have the project successfully build, and documentation started.
Have the rest of the roadmap, and achievable goals set.

Setup the screen, and window for the project.
Create the main loop for the project. 

Learn SDL3 to implement input handling from a user.
Start creating new files and classes for the UI, so its modular.

Have the screen be able to close, and resize.


### 1.2.1 Phase 1 - 2D Rendering

Create 2D Vectors.
Create 2D Lines.

Create simple 2D shapes, Tri and Quads.

Learn and use straight line rasterisation equations.
Learn and create anti-aliased lines.

Create a tessellator, to convert a quad into tris.

Start on a primitives rasteriser.
Rasterise tris.
Rasterise quads.
Rasterise circles.

Create more complex 2D shapes, N-gons and Polygons.
Expand the tessellator, to convert polygons and complex 2D shapes into primitives.


### 1.2.2 Phase 2 - 3D Rendering

Create 3D and 4D Vectors.
Create 3D lines.

Create simple 3D objects, Planes and Boxes.

Learn how to use the matrix needed to convert from 3D to 2D.

Use normals to hide faces when not facing the camera.
Implement Z-Buffering and the Z-Buffer to make a distance ( shadow ) map.

Implement 3D complex, with all sides as tris.


### 1.2.3 Phase 3 - Rigid Bodies & Collisions

Start implementing vector collisions:

    2D Vector-Vector,

    Start implementing Vector and 2D shape collisions:

        Vector-Point
        Vector-Line,
        Vector-Tri,
        Vector-Rect,
        Vector-Circle,
    
    3D Vector-Vector,

    Start implementing Vector and 3D shape collisions:

        Vector-Point
        Vector-Line
        Vector-Tri
        Vector-Plane
        Vector-Box
        Vector-Sphere


Start implementing point collisions:

    2D Point-Point,

    Start implementing Point and 2D shape collisions:

        Point-Line,
        Point-Tri,
        Point-Rect,
        Point-Circle,
    
    3D Point-Point,

    Start implementing Point and 3D shape collisions:

        Point-Line
        Point-Tri
        Point-Plane
        Point-Box
        Point-Sphere


Start implementing Line collisions:

    2D Line-Line,

    Start implementing Line and 2D shape collisions:

        Line-Tri,
        Line-Rect,
        Line-Circle,
    
    3D Line-Line,

    Start implementing Line and 3D shape collisions:

        Line-Tri
        Line-Plane
        Line-Box
        Line-Sphere



### 1.2.4 Phase 4 - File Handling ( Loading )

Implement loading of 3D Models and objects.

Implement loading of 2D Textures and images.

Implement loading of settings
Implement loading of world data

### 1.2.5 Phase 5 - File Handling ( Saving )

Learn how to make own filetypes to save custom world data.
Split world data into multiple files.

Learn how to save 3D Models.
Learn how to save 2D Images.


### 1.2.6 Phase 6 - UI/UX Overhaul

TBC

## UML Diagrams

