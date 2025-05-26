#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SerializedSimulationObject.h"
#include "QuestStepBehaviourBool_EventDelegate.h"
#include "QuestStepBehaviourHasChanged_EventDelegate.h"
#include "QuestStepBehaviour_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "QuestStepBehaviour.generated.h"

class AQuestInstance;
class ASimulationActor;
class ASimulationPlayer;
class UPlayerIdentificationSimulationComponent;
class UQuestManagerSimulationComponent;
class UQuestStepUI;

UCLASS(Blueprintable)
class LOC_API UQuestStepBehaviour : public USerializedSimulationObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestStepBehaviour_Event OnQuestStepSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestStepBehaviourHasChanged_Event OnQuestStepPresentationUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestStepBehaviourBool_Event OnQuestStepSuccessStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UQuestStepUI> QuestStepUIType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIndividualCompletionCheckPerPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<ASimulationPlayer*, bool> PlayerToCompletionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOptional;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRememberSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bCompletedSuccessful;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AQuestInstance* QuestInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> TargetMarkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* TargetMarker;
    
public:
    UQuestStepBehaviour();

    UFUNCTION(BlueprintCallable)
    void UpdateSuccessState(bool bSuccess);
    
    UFUNCTION(BlueprintCallable)
    void SetCompletionStatePerPlayer(ASimulationPlayer* InPlayer, bool bState);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTick(FFixed DeltaTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTargetMarkerSpawned(ASimulationActor* Marker);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopForPlayer(ASimulationActor* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartForPlayer(ASimulationActor* Player, bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStart(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable)
    void OnQuestUnpinned(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* UnpinnedQuestInstance);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnQuestStepSuccessStateChanged_Event(bool bSucces);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnQuestPinned(UQuestManagerSimulationComponent* QuestManagerSimulationComponent, AQuestInstance* PinnedQuestInstance);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerLeft(ASimulationActor* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerJoined(ASimulationActor* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerIdentificationChanged(UPlayerIdentificationSimulationComponent* PlayerIdentificationComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinish(ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCancel();
    
public:
    UFUNCTION(BlueprintCallable)
    void NotifyUpdatesForPresentation(bool bHasChangedSinceLastTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetTitleText(bool bCompleted);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FText GetDescriptionText();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool Editor_SupportsIndividualCheckPerPlayer();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanCompleteIgnoreOptional(ASimulationPlayer* SimulationPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanComplete(ASimulationPlayer* SimulationPlayer);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanBeCompletedEvent(ASimulationPlayer* SimulationPlayer);
    
};

