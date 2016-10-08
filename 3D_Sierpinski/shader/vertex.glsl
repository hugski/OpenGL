#version 150

uniform mat4 camera;
uniform mat4 model;
in vec3 vNormal;
in vec3 vert;
in vec3 vColor;



out vec3 fragVert;
out vec3 fragNormal;
out vec4 color;

void main() {
    //matrix transformation to vert
    gl_Position =  camera * model * vec4(vert,1);
    
    //to fragment shader
    fragNormal = vNormal;
    fragVert = vert;
    
    color = vec4(vColor, 1.0);
    
}