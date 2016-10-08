//
//  Camera.h
//  Assignment
//
//  Created by zpf on 15-1-2.
//
//

#ifndef __Assignment__Camera__
#define __Assignment__Camera__

#include <glm/glm.hpp>

namespace tdogl {
    
    class Camera {
    public:
        Camera();
        //position of the camera
        const glm::vec3& position() const;
        void setPosition(const glm::vec3& position);
        void offsetPositon(const glm::vec3& offset);
        
        //vertical viewing angle of the Camera
        float fieldOfView() const;
        void setFieldOfView(float fieldOfView);
        
        //nearset distance from the camera
        float nearPlane() const;
        
        //farest visible distance from the camera
        float farPlane() const;
        
        void  setNearAndFarPlanes(float nearPlane, float farPlane);
        
        glm::mat4 orientation() const;
        
        void offsetOrientation(float upAngle, float rightAngle);
        
        void lookAt(glm::vec3 positon);
        
        float viewportAspectRatio() const;
        void setViewportAspectRatio(float viewportAspectRatio);
        
        glm::vec3 forward() const;
        
        glm::vec3 right() const;
        
        glm::vec3 up() const;
        
        //camera transformation matrix
        glm::mat4 matrix() const;
        //the perspective projection transformation martix
        glm::mat4 projection() const;
        
        //the translation and rotation matrix of camera
        glm::mat4 view() const;
        
    private:
        glm::vec3 _position;
        float _horizontalAngle;
        float _verticalAngle;
        
        float _fieldOfView;
        float _nearPlane;
        float _farPlane;
        float _viewportAspectRatio;
        
        void normalizeAngles();
        
    };
}

#endif /* defined(__Assignment__Camera__) */
