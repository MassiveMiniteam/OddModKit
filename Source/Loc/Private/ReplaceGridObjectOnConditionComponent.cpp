#include "ReplaceGridObjectOnConditionComponent.h"

UReplaceGridObjectOnConditionComponent::UReplaceGridObjectOnConditionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UnlockableCondition = NULL;
    this->bUseAlternativeUnlockableInDemo = false;
    this->AlternativeDemoUnlockableCondition = NULL;
    this->Dialogue_Success = NULL;
    this->Dialogue_Fail = NULL;
    this->bShowAlternativeFailDialogue = false;
    this->Dialogue_AlternativeFail = NULL;
    this->ReplacementClass = NULL;
}

void UReplaceGridObjectOnConditionComponent::TriggerReplacement(ASimulationPlayer* Player) {
}

bool UReplaceGridObjectOnConditionComponent::CanTriggerReplacement() {
    return false;
}


