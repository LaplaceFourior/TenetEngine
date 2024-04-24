#include "RegisterTypes.h"
#include "Register.h"
#include "Components/BaseComponent.h"
#include "Components/CameraComponent.h"
#include "Components/LightComponent.h"
#include "Components/MeshComponent.h"
#include "Components/TransformComponent.h"
// global functions
void registerTypes()
{
    REGISTER_CLASS(BaseComponent);
    REGISTER_CLASS(CameraComponent);
    REGISTER_CLASS(LightComponent);
    REGISTER_CLASS(MeshComponent);
    REGISTER_CLASS(TransformComponent);
}