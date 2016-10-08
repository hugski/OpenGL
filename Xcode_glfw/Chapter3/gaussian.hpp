//
//  gaussian.hpp
//  Xcode_glfw
//
//  Created by zpf on 16/3/26.
//
//

#ifndef gaussian_hpp
#define gaussian_hpp

#include <stdio.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <stdlib.h>
typedef struct{
    GLfloat x, y, z;
} Data;
void gaussianDemo(float sigma);
void draw2DHeatMap(const Data*, int num_points);
#endif /* gaussian_hpp */
