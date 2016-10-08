//
//  main.cpp
//  Chapter3
//
//  Created by zpf on 16/3/26.
//
//

#include <GLFW/glfw3.h>

#include "camera.hpp"
#include "gaussian.hpp"

const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 720;


void draw2DHeatMap(const Data* data, int num_points);

void gaussianDemo(float sigma);

int main(void){
    GLFWwindow* window;
    int width, height;
    if(!glfwInit()){
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Chapter3: 3D gaussianDemo", NULL, NULL);
    if(!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_DST_ALPHA);
    glEnable(GL_ALPHA_TEST);
    
    float sigma = 0.1f;
    float sign = 1.0f;
    float step_size = 0.007f;
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -zoom);
        glRotatef(beta, 1.0, 0.0, 0.0);
        glRotatef(alpha, 0.0, 0.0, 1.0);
        drawOrigin();
        
        if(!freeze){
            sigma = sigma + sign * step_size;
            if(sigma > 1.0f){
                sign = -1.0f;
            }
            if (sigma < 0.1f){
                sign = 1.0f;
            }
        }
        gaussianDemo(sigma);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}