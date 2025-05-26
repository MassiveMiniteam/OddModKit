#include "LocAutosaver.h"

ALocAutosaver::ALocAutosaver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TimeUntilAutosave = 0.00f;
    this->BeforeAutoSaveDelay = 1.00f;
}

void ALocAutosaver::TriggerAutosaveForSaveGame(ULocSaveGame* SaveGame) {
}

void ALocAutosaver::SimulateAutosave() {
}

void ALocAutosaver::ResetAutosaveTimer() {
}



float ALocAutosaver::GetTimeUntilAutosave() const {
    return 0.0f;
}


