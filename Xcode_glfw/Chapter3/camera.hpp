//
//  camera.hpp
//  Xcode_glfw
//
//  Created by zpf on 16/3/26.
//
//

#ifndef camera_hpp
#define camera_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <math.h>

extern bool freeze;

//rotation angles and zoom factor for 3D rendering
extern GLfloat alpha, beta, zoom;
extern GLboolean locked;

extern int cursorX;
extern int cursorY;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* , int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double x, double y);
void scroll_callback(GLFWwindow* window, double x, double y);
void mouse_button_callback(GLFWwindow* window, int , int , int);
void drawOrigin();
#endif /* camera_hpp */
