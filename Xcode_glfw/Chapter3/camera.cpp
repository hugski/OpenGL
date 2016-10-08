//
//  camera.cpp
//  Xcode_glfw
//
//  Created by zpf on 16/3/26.
//
//

#include "camera.hpp"

bool freeze = false;

//rotation angles and zoom factor for 3D rendering
GLfloat alpha=210.0f, beta=-70.0f, zoom=2.0f;
GLboolean locked = GL_FALSE;

int cursorX = 0;
int cursorY = 0;
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    const double deg2rad = 3.1415926 / 180;
    const float fovY = 45.0f;
    const float front = 0.1f;
    const float back = 128.0f;
    float ratio = 1.0f;
    if(height > 0)
        ratio = (float) width /(float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double tangent = tan(fovY /2 * deg2rad);
    double height_f = front * tangent;
    double width_f = height_f * ratio;
    
    glFrustum(-width_f, width_f, -height_f, height_f, front, back);
}


void drawOrigin(){
    float transparency = 0.5f;
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    
    glColor4f(1.0f, 0.0f, 0.0f, transparency);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor4f(1.0f, 0.0f, 0.0f, transparency);
    glVertex3f(0.3f, 0.0f, 0.0f);
    
    glColor4f(0.0f, 1.0f, 0.0f, transparency);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor4f(0.0f, 1.0f, 0.0f, transparency);
    glVertex3f(0.0f, 0.0f, 0.3f);
    
    glColor4f(0.0f, 0.0f, 1.0f, transparency);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glColor4f(0.0f, 0.0f, 1.0f, transparency);
    glVertex3f(0.0f, 0.3f, 0.0f);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;
    
    switch (key)
    {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_SPACE:
            freeze=!freeze;
            break;
        case GLFW_KEY_LEFT:
            alpha += 5.0f;
            break;
        case GLFW_KEY_RIGHT:
            alpha -= 5.0f;
            break;
        case GLFW_KEY_UP:
            beta -= 5.0f;
            break;
        case GLFW_KEY_DOWN:
            beta += 5.0f;
            break;
        case GLFW_KEY_PAGE_UP:
            zoom -= 0.25f;
            if (zoom < 0.0f)
                zoom = 0.0f;
            break;
        case GLFW_KEY_PAGE_DOWN:
            zoom += 0.25f;
            break;
        default:
            break;
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button != GLFW_MOUSE_BUTTON_LEFT)
        return;
    
    if (action == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        locked = GL_TRUE;
    }
    else
    {
        locked = GL_FALSE;
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
}

void scroll_callback(GLFWwindow* window, double x, double y)
{
    zoom += (float) y / 4.0f;
    if (zoom < 0.0f)
        zoom = 0.0f;
}

void cursor_position_callback(GLFWwindow* window, double x, double y)
{
    //if the mouse button is pressed
    if (locked)
    {
        alpha += (GLfloat) (x - cursorX) / 10.0f;
        beta += (GLfloat) (y - cursorY) / 10.0f;
    }
    //update the cursor position
    cursorX = (int) x;
    cursorY = (int) y;
}

