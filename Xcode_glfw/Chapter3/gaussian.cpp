//
//  gaussian.cpp
//  Xcode_glfw
//
//  Created by zpf on 16/3/26.
//
//

#include "gaussian.hpp"


void gaussianDemo(float sigma){
    const int grid_x = 400;
    const int grid_y = 400;
    const int num_points = grid_x * grid_y;
    Data *data = (Data*) malloc(sizeof(Data) * num_points);
    int data_counter = 0;
    for(int x = -grid_x /2; x < grid_x/ 2 ; x+=1) {
        for(int y = -grid_y /2; y < grid_y / 2; y+=1){
            float x_data = 2.0f * x / grid_x;
            float y_data = 2.0f * y / grid_y;
            
            float z_data = exp(-0.5f * (x_data * x_data) / (sigma * sigma)
                               -0.5f * (y_data * y_data) / (sigma * sigma)) /
            (sigma * sigma * 30.0f * M_PI);
            
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
        glVertex3f(d.x, d.y, d.z);
    }
    
    glEnd();
}