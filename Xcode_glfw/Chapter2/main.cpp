//
//  main.cpp
//  Chapter2
//
//  Created by zpf on 16/3/11.
//
//

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "primitives_2D.hpp"
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 480;

int main(){
    GLFWwindow* window;
    if(!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Primitive drawings", NULL, NULL);
    if(!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    float sigma = 0.01f;
    while(!glfwWindowShouldClose(window)){
        float ratio;
        int width, height;
        
        glfwGetFramebufferSize(window, &width, &height);
        ratio = (float) width/ height;
        
        glViewport(0,0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f); // 正交投影
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
        //画点函数示例
//        drawPointsDemo(width, height);
//        drawLineDemo(); //画线示例
//        drawTrianlgeDemo(); // 画三角形示例
        drawGrid(5.0f, 1.0f, 0.1f);
        
        sigma += 0.01f;
        if(sigma > 1.0f)
            sigma = 0.01f;
        gaussianDemo(sigma);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}

