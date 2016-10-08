//
//  primitives_2D.hpp
//  Xcode_glfw
//
//  Created by zpf on 16/3/11.
//
//

#ifndef primitives_2D_hpp
#define primitives_2D_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
typedef struct{
    GLfloat x, y, z;
    GLfloat r, g, b, a;
}Vertex;

typedef struct{
    GLfloat x, y, z;
} Data;

void drawPoint(Vertex v1, GLfloat size);
void drawPointsDemo(int width, int height);
void drawLineSegment(Vertex v1, Vertex v2, GLfloat width);
void drawGrid(GLfloat width, GLfloat height, GLfloat grid_width);
void drawLineDemo();
void drawTriangle(Vertex v1, Vertex v2, Vertex v3);
void drawTrianlgeDemo();
void gaussianDemo(float sigma);
void draw2DHeatMap(const Data*, int num_points);
#endif /* primitives_2D_hpp */
