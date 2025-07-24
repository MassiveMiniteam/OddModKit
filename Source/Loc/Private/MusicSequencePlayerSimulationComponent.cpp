#include "MusicSequencePlayerSimulationComponent.h"

UMusicSequencePlayerSimulationComponent::UMusicSequencePlayerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MusicInstrumentMappingDataAsset = NULL;
    this->bTreatEmptyNoteAsC = true;
    this->bBindPlayNoteToLogicComponent = true;
    this->Num32BetweenNotes = 4;
    this->InstrumentInventory = NULL;
    this->NoteInventory = NULL;
    this->OctaveInventory = NULL;
    this->LogicComponent = NULL;
    this->bSustainSound = true;
    this->bForceGlobalSound = false;
    this->bHideForceGlobalSoundOptionInUI = false;
    this->ClockHandle = NULL;
}

void UMusicSequencePlayerSimulationComponent::SetSustainSound(bool bSustainSoundIn) {
}

void UMusicSequencePlayerSimulationComponent::SetForceGlobalSound(bool bForceGlobalSoundIn) {
}

void UMusicSequencePlayerSimulationComponent::PlaySequence() {
}

void UMusicSequencePlayerSimulationComponent::OnNoteOrOctaveInventorySlotChanged(int32 SlotIndex) {
}

void UMusicSequencePlayerSimulationComponent::OnLogicSignalChanged(ULogicConnectionSimulationComponent* Input) {
}

void UMusicSequencePlayerSimulationComponent::OnInstrumentInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}

bool UMusicSequencePlayerSimulationComponent::IsSustainSound() const {
    return false;
}

bool UMusicSequencePlayerSimulationComponent::HasForcedGlobalSound() const {
    return false;
}


