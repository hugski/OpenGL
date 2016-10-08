###### OpenGL desktop(Mac and windows)

A Program realized the basic computer graphic concepts.

* Transform the coordinates(position, orientation,size), making the 3D objects scaling,rotation and projection.  
* The tetrahedron was divided iteratively about    4 times, shaping a 3D object called sierpinski.
* Lighting model of Phong illumination which divides reflection into 3 components(Ambient Diffuse Specular)

  
Use OpenGL 4.x programable rendering pipline to manipulate the 3D model‘s translation and lighting(red green white).
`fragment.glsl` and `vertex.glsl` are the shader files of this program.

Besides the OpenGL library, some other libraries were needed

* [`GLM`](http://glm.g-truc.net/0.9.8/index.html) is a math libraries for vectors and matrix calculation.
* [`GLEW`](http://glew.sourceforge.net) is a C\C++ loading library for OpenGL extensions
* [`GLFW`](http://www.glfw.org) provides a simple API for creating windows and receiving input and events.

The source in my github targeted to OS X system and  use **Xcode** as the C++ IDE. 
The built result:

![sierpinski1](http://oarcqlfu0.bkt.clouddn.com/2016-10-08-sierpinski1.gif)

The Xcode_glfw folder source is a practice about glfw and i made a 3D gaussian demo

![gaussian](http://oarcqlfu0.bkt.clouddn.com/2016-10-08-gaussian.gif)
 

