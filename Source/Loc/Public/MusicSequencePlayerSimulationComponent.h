#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "MusicPitch.h"
#include "MusicSequenceEventWithPitchesDelegate.h"
#include "MusicSquenceEventDelegate.h"
#include "MusicSequencePlayerSimulationComponent.generated.h"

class UAudioComponent;
class UInventoryComponent;
class UItemConfig;
class ULogicConnectionSimulationComponent;
class UMusicInstrumentMappingDataAsset;
class UQuartzClockHandle;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMusicSequencePlayerSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMusicInstrumentMappingDataAsset* MusicInstrumentMappingDataAsset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMusicSquenceEvent OnSettingsChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMusicSequenceEventWithPitches OnPlayNoteScheduledToQuartz;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTreatEmptyNoteAsC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBindPlayNoteToLogicComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Num32BetweenNotes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* InstrumentInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* NoteInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInventoryComponent* OctaveInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULogicConnectionSimulationComponent* LogicComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSustainSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bForceGlobalSound;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideForceGlobalSoundOptionInUI;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuartzClockHandle* ClockHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAudioComponent*> AudioComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMusicPitch> CachedMusicPitches;
    
public:
    UMusicSequencePlayerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSustainSound(bool bSustainSoundIn);
    
    UFUNCTION(BlueprintCallable)
    void SetForceGlobalSound(bool bForceGlobalSoundIn);
    
    UFUNCTION(BlueprintCallable)
    void PlaySequence();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnNoteOrOctaveInventorySlotChanged(int32 SlotIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnLogicSignalChanged(ULogicConnectionSimulationComponent* Input);
    
    UFUNCTION(BlueprintCallable)
    void OnInstrumentInventoryChanged(UInventoryComponent* Inventory, bool bAdded, UItemConfig* Item);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSustainSound() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasForcedGlobalSound() const;
    

    // Fix for true pure virtual functions not being implemented
};

