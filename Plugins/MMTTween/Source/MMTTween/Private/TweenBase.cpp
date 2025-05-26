#include "TweenBase.h"

UTweenBase::UTweenBase() {
    this->AttachToObject = NULL;
    this->TotalTime = 0.00f;
    this->Duration = 1.00f;
    this->EaseFunction = ETweenEaseFunction::Linear;
    this->bPlayReverse = false;
}

void UTweenBase::OnUpdate_Implementation(float Progress) {
}

void UTweenBase::OnStop_Implementation() {
}

void UTweenBase::OnStart_Implementation() {
}

void UTweenBase::OnCancel_Implementation() {
}


