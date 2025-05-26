#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "InputContextTrainPoleRelocation.generated.h"

class AActor;
class ALocPlayerController;
class ASimulationActor;
class UConstructableConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextConstructionToolsGamepadMovement;
class UInputContextTrainPolePlacement;
class USceneComponent;
class UTrainTracksPoleConnectionSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UInputContextTrainPoleRelocation : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationActor* PoleForRelocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PreviewRails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTrainTracksPoleConnectionSimulationComponent*> RailTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> RailStarsOnPreviewActorScenes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextTrainPolePlacement* InputContext_PolePlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsGamepadMovement* GamepadMovementInputContext;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfigRails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextConstructionToolsGamepadMovement> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextTrainPolePlacement> PolePlacementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> ConnectorOverlapObjectTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Place;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Cancel;
    
public:
    UInputContextTrainPoleRelocation();

private:
    UFUNCTION(BlueprintCallable)
    void OnPolePlacementContextUpdated(UInputContextTrainPolePlacement* InputContext);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputActionPlaceBlueprint();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Place(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Cancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetPoleForRelocation() const;
    
};

