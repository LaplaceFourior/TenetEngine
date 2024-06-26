#include "Components/TransformComponent.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/matrix_decompose.hpp>
#include "Components/TransformComponent.h"

using namespace TenetEngine;

void TransformComponent::setTransform(const glm::mat4& transform)
{
    mTransform = transform;
    glm::quat orientation;
    glm::vec3 skew;
    glm::vec4 perspective;
    glm::decompose(transform, mScale, orientation, mTranslate, skew, perspective);

    // Convert quaternion to Euler angles (in radians)
    mRotation = glm::eulerAngles(orientation);
    // Convert radians to degrees, if necessary
    mRotation = glm::degrees(mRotation);
}
void TransformComponent::setTranslation(const glm::vec3& translation)
{
    mTranslate = translation;
}
void TransformComponent::setRotation(const glm::vec3& rotation)
{
    mRotation = rotation;
}
void TransformComponent::setScale(const glm::vec3& scale)
{
    mScale = scale;
}

void TransformComponent::updateTransform()
{
    mTransform = glm::mat4(1.0f);

    mTransform = glm::translate(mTransform, mTranslate);

    mTransform = glm::rotate(mTransform, glm::radians(mRotation.x), glm::vec3(1, 0, 0));
    mTransform = glm::rotate(mTransform, glm::radians(mRotation.y), glm::vec3(0, 1, 0));
    mTransform = glm::rotate(mTransform, glm::radians(mRotation.z), glm::vec3(0, 0, 1));

    mTransform = glm::scale(mTransform, mScale);
}

void TransformComponent::update(float deltaTime)
{
}
const glm::mat4& TransformComponent::getTransform() 
{   
    updateTransform();
    return mTransform; 
}