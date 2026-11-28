
## File-System

### World data ( .world )

World data is stored in `.world` files. In a JSON-like data structure.

They store a list of objects.
These objects have a name, transform, and filepaths to there components. Such as a `.mesh`, `.mat`, `.glsl`, `.tga` files-paths.

This was done to easily change the object in the scene file, without having to hardcode values.


This could later be expanded to hold prefab data, where only a name, transform and a `.prefab` file is given.
This would help have instanced objects, and similar objects in general, not having to write the same data over, and over again.
<br>


### Mesh data ( .mesh )

Mesh data is stored in `.mesh` files. In a binary data structure.

They would be broken down into different sections. These would be:

- Header  
- Reading
- Groups 
[
  - Vertex 
  - Index
]
- Footer

The header section would store metadata about the mesh.

The reading section would store data about the layout of a span of data one stride wide.
It would store variables on the composition of the span and how it should be read.

The group section specifies a group of sections, so more than one object can be stored in a mesh.

The vertex section would store a structure of arrays of floats for the individual attributes of the vertex data. 
The index section would store a contiguous list of integers for the index positions . 

The footer section would store data about integrity, such as a signature and check-sums.


This could be expanded to convert filetypes such as `.stl` `.obj` `.fbx`
<br>


### Material data ( .mat )

Material data is stored in `.mat` files, in a JSON-like data structure.

They may be split into different sections:

- Header
- Body
- Footer


The header would store metadata about a material.

The body section would store the main data about a material.
It stores values on how the material should be coloured and shaded, such as albedo colour, specular intensity, fresnel power.
They also store file-paths to textures. This are used to store contiguous-square ( aspect ratio of 1:1 ) data.
They must also store a filepath to a shader to render the material onto the mesh.

The footer section would store data about integrity, such as a signature and check-sums.
<br>


### Texture data 

Texture data is stored as various file types, for now only `.tga` `.png` files in binary or hex ( depending on the filetype ).

Most ( if not all image files ) store data in 3 primary sections. These are:

- Header
- Image / Data Maps
- ( Extension Area )
- Footer


The header section would hold metadata about the image, like its image type, image resolution, colour resolution.

The Image / Data Maps section would hold the values of data at each channel. 

The Extension Area section holds additional metadata, "and pointers to auxiliary data", without changing the original tga file.
It was made so supported software can get more info in same tga file, without having to import said data.

The footer section would store data specifying and extensions added to the file, and integrity; such as a signature and check-sums.


[TGA File Layout](http://tfc.duke.free.fr/coding/tga_specs.pdf)
[PNG File Layout](https://www.libpng.org/pub/png/spec/1.2/PNG-Structure.html)
<br>


### Prefabs ( .prefab )

Prefab data is stored in `.prefab` files in JSON-like data structures.

They store set data on an entity, including paths to materials, meshes, other components.
But it may lack a transform however, as it might be instanced.
<br>


## Rendering 

The rendering happens on entities. These are loaded in from storage, as specified by world data and sent to the gpu. 
They are then drawn onto the screen using their data, materials, textures, and shaders stored in the gpu.
<br>


### Loading Entities & The World

World data holds pre-made lightweight objects containing a transform, and file paths to other components.

Depending, and as stated by the world data, entities are loaded dynamically.
These entities are loaded from storage using the file paths.

An Entity Manager builds the entities and stores temporarily in RAM.
They are then sent onto the gpu into VRAM, and cleared from RAM.
<br>


#### Objects

Objects are pre-made lightweight containers held in raw data files. 

They hold a raw transform, as a list of floats. Used for positional, rotational, and scalar transformations.
They also hold file-paths to other raw components. These components specify functionality and allow entities to do more.

The main components for rendering are:
    
- Mesh          ( `.mesh` `.obj` )
- Material      ( `.mat` )
- Shader        ( `.fs` `.vs` `.glsl` )
- Texture(s)    ( `.tga` `.png` )
<br>


#### Entity Manager

It handles loading and unloading of entities.
The Entity Manager compiles the object into entity by finding the relevant file paths, and loading in the data for associated components.
<br>


#### Entity

Entities are in-game objects ( containers ) to store components. 
Components store data pertaining to one specific purpose, and can be added easily, to expand an entities functionality and complexity.

The main components for rendering are:

- Transform
- Mesh
- Material


The Transform holds data about the entity's position, rotation and scale.

The Mesh holds the vertices to be drawn onto the screen.

The Material holds data to colour, light, texture, the Mesh by. Along with a shader, to specify how it is drawn. 
<br>


#### Mesh

Meshes are components that hold vertex data, and the values specifying how a 2d/3d object is created.

Meshes hold ids to buffers that stores data stored on the gpu.
They are initialised with the vertex data, along with vao, vbo, ebo, and other buffer objects; 
but do not store any data directly. 
<br>


#### Materials

Materials are components that hold data on how to draw a mesh.
Materials hold data about colouring, lighting, texturing.

They also have a shader. This takes data from the material and actually renders it onto the screen.



