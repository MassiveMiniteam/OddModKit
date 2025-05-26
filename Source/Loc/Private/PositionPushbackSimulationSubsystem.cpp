#include "PositionPushbackSimulationSubsystem.h"

UPositionPushbackSimulationSubsystem::UPositionPushbackSimulationSubsystem() {
    this->BitmaskSetting.AddDefaulted(4);
    this->PushDirectorCounter = 0;
    this->PushDirections.AddDefaulted(8);
}


