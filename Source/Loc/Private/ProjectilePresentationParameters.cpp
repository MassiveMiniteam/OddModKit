#include "ProjectilePresentationParameters.h"

FProjectilePresentationParameters::FProjectilePresentationParameters() {
    this->LaunchType = EProjectileLaunchType::None;
    this->TargetActor = NULL;
    this->Height = 0.00f;
    this->Duration = 0.00f;
}

