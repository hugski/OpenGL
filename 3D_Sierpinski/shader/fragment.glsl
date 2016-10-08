#version 150

uniform mat4 model;
uniform vec3 cameraPosition;

//material and Light
uniform float materialShininess;
uniform vec3 materialSpecularColor;

uniform struct Light {
    vec3 position;
    vec3 intensities;
    float attenuation;
    float ambientCoefficient;
} light;

in vec3 fragNormal;
in vec3 fragVert;
in vec4 color;

out vec4 finalColor;



void main () {
    //normal in world coordinates
    vec3 normal = normalize(transpose(inverse(mat3(model))) * fragNormal);
    vec3 surfacePos = vec3(model * vec4(fragVert, 1));
    vec3 surfaceToLight = normalize(light.position - surfacePos);
    vec3 surfaceToCamera = normalize(cameraPosition - surfacePos);
    
    //phong model
    vec3 ambient = light.ambientCoefficient * color.rgb * light.intensities;
    
    float diffuseCoefficient = max(0.0, dot(normal, surfaceToLight)); // diffuse
    vec3 diffuse = diffuseCoefficient * color.rgb * light.intensities;
    
    float specularCoefficient = 0.0;
    if (diffuseCoefficient > 0.0)
        specularCoefficient = pow(max(0.0, dot(surfaceToCamera, reflect(-surfaceToLight, normal))), materialShininess);
    vec3 specular = specularCoefficient * materialSpecularColor * light.intensities;
    
    float distanceToLight = length (light.position - surfacePos);
    float attenuation = 1.0/(1.0 + light.attenuation * pow(distanceToLight ,2));
    
    vec3 phongColor = ambient + attenuation * (diffuse + specular);
    vec3 gamma = vec3 (1.0/2.2);
    finalColor = vec4(pow(phongColor,gamma),1);
}