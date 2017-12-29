The Echo Effect

The following documentation will outline the functionality of the classes currently integrated in the project and how to use them.


#Application#
The main method class and where all of the main testing and building will be done. 


#Callbacks#
These are GLFW methods that we will fill in later. 
They essentially exist as the middle-man functions between the Window and the Input classes. 
All input (key press, mouse press, mouse move, etc) will be fed to these functions, and we can decide where to process it later.


#Color#
A 4-component color class <r,g,b,a>. Does not yet have support for other color types like hsv. 
Can be constructed from an unsigned integer or 4 floats.
Contains several static colors ready to use. 


#ShaderProgram#
A shader to manipulate how images are drawn to the screen. 
Must pass in a vertex, geometry, and fragment filepath, although the geometry shader can be 0.
A shader must be active before uploading uniforms and binding textures (use the use() method).
Uniform values currently accept integers, floats, colors, and vector2fs.  


#Vector2f#
A storage class for two floats, can be a direction, a position, or anything else. Most common operations are already overloaded


#Window#
Creates the OpenGL instance (Allows us to make OGL calls) and creates the window.
Contains methods for dealing with the actual Window, such as cursor position, window size, etc. 
Does not contain any logic for items contained in the window, like the world. 


