//
// Created by thego on 7/1/2025.
//

#include "Camera.h"
void Camera::updateViewMatrix() {

    glm::mat4 currentMatrix = m_viewMat;

    glm::mat4 rotM = glm::mat4(1.0F);
    glm::mat4 transM;

    // apply m_rotation
    rotM = glm::rotate(rotM, glm::radians(m_rotation.x * (m_flipY ? -1.0F : 1.0F)), glm::vec3(1.0F, 0.0F, 0.0F));
    rotM = glm::rotate(rotM, glm::radians(m_rotation.y), glm::vec3(0.0F, 1.0F, 0.0F));
    rotM = glm::rotate(rotM, glm::radians(m_rotation.z), glm::vec3(0.0F, 0.0F, 1.0F));

    glm::vec3 translation = m_position;
    if (m_flipY) {
        translation.y *= -1.0f;
    }
    transM = glm::translate(glm::mat4(1.0F), translation);

    if (type == CameraControlType::firstperson)
        m_viewMat = rotM * transM;
    else
        m_viewMat = transM * rotM;

    // because view space uses an inverted x and z axis, we need to flip them, this is vector
    // we will be passing to the shaders in the future precomputed as a vec4
    // it should be inverted here since this means that per batch / frame we will not have to
    // recompute this vector inside the shader per-instance.
    viewPos = glm::vec4(m_position, 0.0F) * glm::vec4(-1.0F, 1.0F, -1.0F, 1.0F);

    if (m_viewMat != currentMatrix) { m_updated = true; } // if the view matrix has changed, we need to update it


}

// update the frustum perspective projection matrix
void Camera::setPerspective(float fov, float newAspect, float nearClip, float farClip) {
    glm::mat4 currentMatrix = m_perspectiveMat;
    this->frustum[Camera::fov] = fov;
    this->frustum[Camera::near] = nearClip;
    this->frustum[Camera::far] = farClip;
    m_perspectiveMat = glm::perspective(glm::radians(fov), newAspect, nearClip, farClip);
    if (m_flipY) { m_perspectiveMat[1][1] *= -1.0F; }
    if (m_viewMat != currentMatrix) { m_updated = true;}
}

// update the aspect ratio of the perspective projection matrix
void Camera::updateAspectRatio(float aspect){
    glm::mat4 currentMatrix = m_perspectiveMat;
    m_perspectiveMat = glm::perspective(glm::radians(frustum[fov]), aspect, frustum[near] , frustum[far]);
    if (m_flipY) {
       m_perspectiveMat[1][1] *= -1.0f;
    }
    if (m_viewMat != currentMatrix) {
        m_updated = true;
    }
}

// set the camera's position in world space
void Camera::setPosition(glm::vec3 position) {
    this->m_position = position;
    updateViewMatrix();
}

// set the camera's rotation in world space
void Camera::setRotation(glm::vec3 rotation) {
    this->m_rotation = rotation;
    updateViewMatrix();
}

void Camera::rotate(glm::vec3 delta) {
    this->m_rotation += delta;
    updateViewMatrix();
}
void Camera::setTranslation(glm::vec3 translation) {
    this->m_position = translation;
    updateViewMatrix();
}

void Camera::translate(glm::vec3 delta) {
    this->m_position += delta;
    updateViewMatrix();
}



