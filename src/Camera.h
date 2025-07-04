//
// Created by thego on 7/1/2025.
//



#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/glm.hpp"
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>


#ifndef VULKAN_IMGUI_STARTER_CAMERA_H
#define VULKAN_IMGUI_STARTER_CAMERA_H


// Basic Y-up 3D camera


class Camera {

  private:
    float frustum[3];
    enum {
        fov, near, far
    };

    // update the m_viewMat matrix based on current position and m_rotation
    void updateViewMatrix();


    glm::vec3 m_rotation = glm::vec3(); // pitch, yaw, roll (euler angles)
    glm::vec3 m_position = glm::vec3(); // x, y, z position in world space
    glm::vec4 viewPos = glm::vec4();    // look inside updateViewMatrix() for more details

  public:

    //===| Configs |=====|
    enum CameraControlType { lookat, firstperson };
    CameraControlType type = CameraControlType::lookat; // for testing purposes


    float m_rotationSpeed = 1.0f;
    float movementSpeed = 1.0f;

    glm::mat4 m_perspectiveMat;
    glm::mat4 m_viewMat;



    //===| Controls |=====|
    bool m_updated = true;
    bool m_flipY = false;  // y axis has to be fliped for openGL since it's NDC is


    //===| functions |=====|
    [[nodiscard]] float getNearClip() const {return frustum[near];}

    [[nodiscard]] float getFarClip() const {return frustum[far];}

    void setPerspective(float fov, float newAspect, float nearClip, float farClip);

    void updateAspectRatio(float aspect);

    void setPosition(glm::vec3 position);

    void setRotation(glm::vec3 rotation);

    void rotate(glm::vec3 delta);

    void setTranslation(glm::vec3 translation);

    void translate(glm::vec3 delta);

    void setRotationSpeed(float newRotationSpeed);

    void
};

#endif // VULKAN_IMGUI_STARTER_CAMERA_H
