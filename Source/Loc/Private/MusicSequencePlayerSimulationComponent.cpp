#include "MusicSequencePlayerSimulationComponent.h"

UMusicSequencePlayerSimulationComponent::UMusicSequencePlayerSimulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bTreatEmptyNoteAsC = true;
    this->InstrumentInventory = NULL;
    this->NoteInventory = NULL;
    this->OctaveInventory = NULL;
    this->bLoop = false;
    this->bSustainSound = true;
    this->CurrentSequenceIndex = 0;
    this->bIsPlayingMusic = false;
}

void UMusicSequencePlayerSimulationComponent::StopSequence() {
}

void UMusicSequencePlayerSimulationComponent::StopCurrentNote() {
}

void UMusicSequencePlayerSimulationComponent::StartCurrentNote() {
}

void UMusicSequencePlayerSimulationComponent::SetSustainSound(bool bSustainSoundIn) {
}

void UMusicSequencePlayerSimulationComponent::RefreshCurrentNote() {
}

void UMusicSequencePlayerSimulationComponent::PlaySequence(bool bLoopIn) {
}

void UMusicSequencePlayerSimulationComponent::OnInstrumentInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item) {
}

void UMusicSequencePlayerSimulationComponent::NextIndex() {
}

bool UMusicSequencePlayerSimulationComponent::IsSustainSound() {
    return false;
}

bool UMusicSequencePlayerSimulationComponent::IsPlayingMusic() {
    return false;
}

void UMusicSequencePlayerSimulationComponent::InventorySlotChanged(int32 SlotIndex) {
}

FMusicPitch UMusicSequencePlayerSimulationComponent::GetCurrentPitch() const {
    return FMusicPitch{};
}


