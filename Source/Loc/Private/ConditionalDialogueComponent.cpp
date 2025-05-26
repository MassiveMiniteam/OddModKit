#include "ConditionalDialogueComponent.h"

UConditionalDialogueComponent::UConditionalDialogueComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DialogueA = NULL;
    this->DialogueB = NULL;
    this->DialogueC = NULL;
    this->Condition_PickDialogueB = NULL;
    this->Condition_PickDialogueC = NULL;
}

UDialogueConfig* UConditionalDialogueComponent::GetDialogue() {
    return NULL;
}


