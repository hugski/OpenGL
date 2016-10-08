//
//  primitives_2D.cpp
//  Xcode_glfw
//
//  Created by zpf on 16/3/11.
//
//

#include "primitives_2D.hpp"
#include <math.h>
#define _USE_MATH_DEFINES
void drawPoint(Vertex v1, GLfloat size){
    glPointSize(size);
    glBegin(GL_POINTS);
    glColor4f(v1.r, v1.g, v1.b, v1.a);
    glVertex3f(v1.x, v1.y, v1.z);
    glEnd();
}

void drawPointsDemo(int width, int height){
    GLfloat size = 5.0f;
    for(GLfloat x = 0.0f; x<=1.0f; x+= 0.2f, size+=5){
        Vertex v1 = {x, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
        drawPoint(v1, size);
    }
}

void drawLineSegment(Vertex v1, Vertex v2, GLfloat width){
    glLineWidth(width);
    glBegin(GL_LINES);
    glColor4f(v1.r, v1.g, v1.b, v1.a);
    glVertex3f(v1.x, v1.y, v1.z);
    glColor4f(v2.r, v2.g, v2.b, v2.a);
    glVertex3f(v2.x, v2.y, v2.z);
    glEnd();
}

void drawGrid(GLfloat width, GLfloat height, GLfloat grid_width){
    //水平直线
    for(float i = -height; i < height; i+=grid_width){
        Vertex v1 = {-width, i, 0.0f, 1.0f, 1.0f, 1.0f, 0.3f};
        Vertex v2 = {width,  i, 0.0f, 1.0f, 1.0f, 1.0f, 0.3f};
        drawLineSegment(v1, v2, 0.1f);
    }
    //垂直直线
    for(float i = -width; i < width; i+=grid_width){
        Vertex v1 = {i, -height, 0.f, 1.f, 1.f, 1.f, 0.3f};
        Vertex v2 = {i, height,  0.f, 1.f, 1.f, 1.f, 0.3f};
        drawLineSegment(v1, v2, 0.1f);
    }
}

void drawLineDemo(){
    //网格
    drawGrid(5.0f, 1.0f, 0.1f);
    
    Vertex v1 = {-5.0f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.7f};
    Vertex v2 = { 5.0f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.7f};
    Vertex v3 = { 0.0f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.7f};
    Vertex v4 = {0.0f, -1.f, 0.f, 0.f, 1.f, 0.f, 0.7f};
    
    drawLineSegment(v1, v2, 2.f);
    drawLineSegment(v3, v4, 2.f);

}

void drawTriangle(Vertex v1, Vertex v2, Vertex v3){
    glBegin(GL_TRIANGLES);
    glColor4f(v1.r, v1.g, v1.b, v1.a);
    glVertex3f(v1.x, v1.y, v1.z);
    
    glColor4f(v2.r, v2.g, v2.b, v2.a);
        glVertex3f(v2.x, v2.y, v2.z);
    glColor4f(v3.r, v3.g, v3.b, v3.a);
        glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
    
}

void drawTrianlgeDemo(){
    Vertex v1 = {0.0f, 0.8f, 0.0f, 1.0f, 0.0f, 0.f, 0.6f};
    Vertex v2 = {-1.f, -0.8f, 0.0f, 0.0f, 1.0f, 0.0f, 0.6f};
    Vertex v3 = {1.0f, -0.8f, 0.0f, 0.0f, 0.0f, 1.0f, 0.6f};
    drawTriangle(v1, v2, v3);
}

void gaussianDemo(float sigma){
    const int grid_x = 1000;
    const int grid_y = 1000;
    const int num_points = grid_x * grid_y;
    Data *data = (Data*) malloc(sizeof(Data) * num_points);
    int data_counter = 0;
    for(int x = -grid_x /2; x < grid_x/ 2 ; x+=1) {
        for(int y = -grid_y /2; y < grid_y / 2; y+=1){
            float x_data = 2.0f * x / grid_x;
            float y_data = 2.0f * y / grid_y;
            
            float z_data = exp(-0.5f * (x_data * x_data) / (sigma * sigma)
                        -0.5f * (y_data * y_data) / (sigma * sigma)) /
            (sigma * sigma * 2.0f * M_PI);
            
            data[data_counter].x = x_data;
            data[data_counter].y = y_data;
            data[data_counter].z = z_data;
            data_counter++;
        }
    }
    
    draw2DHeatMap(data, num_points);
    free(data);
}

void draw2DHeatMap(const Data* data, int num_points){
    float max_value = -999.9f;
    float min_value = 999.9f;
    for(int i = 0; i < num_points; i++){
        const Data d = data[i];
        if(d.z > max_value){
            max_value = d.z;
        }
        if(d.z < min_value){
            min_value = d.z;
        }
    }
    
    const float halfmax = (max_value + min_value) / 2;
    
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for(int i = 0 ; i < num_points; i++){
        const Data d = data[i];
        float value = d.z;
        float b = 1.0f - value/halfmax;
        float r = value/halfmax - 1.0f;
        if( b < 0){
            b = 0;
        }
        if (r < 0){
            r = 0;
        }
        
        float g = 1.0f - r - b;
        glColor4f(r, g, b, 0.1f);
        glVertex3f(d.x, d.y, 0.0f);
    }
    
    glEnd();
}