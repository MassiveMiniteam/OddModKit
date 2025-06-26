#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "CopyToolUseable.h"
#include "MusicPitch.h"
#include "MusicSquenceEventDelegate.h"
#include "SimulationTimerComponent.h"
#include "MusicSequencePlayerSimulationComponent.generated.h"

class UInventoryComponent;
class UItemConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMusicSequencePlayerSimulationComponent : public USimulationTimerComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InstrumentInventoryRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference NoteInventoryRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference OctaveInventoryRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTreatEmptyNoteAsC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InstrumentInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* NoteInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* OctaveInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSustainSound;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMusicSquenceEvent OnSustainSoundChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMusicPitch CurrentPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentSequenceIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsPlayingMusic;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMusicSquenceEvent OnInstrumentChanged;
    
public:
    UMusicSequencePlayerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopSequence();
    
    UFUNCTION(BlueprintCallable)
    void StopCurrentNote();
    
    UFUNCTION(BlueprintCallable)
    void StartCurrentNote();
    
    UFUNCTION(BlueprintCallable)
    void SetSustainSound(bool bSustainSoundIn);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RefreshCurrentNote();
    
public:
    UFUNCTION(BlueprintCallable)
    void PlaySequence(bool bLoopIn);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnInstrumentInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
public:
    UFUNCTION(BlueprintCallable)
    void NextIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSustainSound();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayingMusic();
    
protected:
    UFUNCTION(BlueprintCallable)
    void InventorySlotChanged(int32 SlotIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FMusicPitch GetCurrentPitch() const;
    

    // Fix for true pure virtual functions not being implemented
};

