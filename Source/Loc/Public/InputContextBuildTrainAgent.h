#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ETrainBuildingResult.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "InputContextBuildTrainAgent.generated.h"

class AActor;
class ALocPlayerController;
class APresentationActor;
class UConstructableConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextConstructionToolsGamepadMovement;
class UMaterialAdjustPresentationComponent;
class UTrainTracksPoleConnectionSimulationComponent;
class UVisibilityStatePresentationComponent;

UCLASS(Blueprintable)
class LOC_API UInputContextBuildTrainAgent : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> ConnectorOverlapObjectTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsCursor* CursorInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextConstructionToolsGamepadMovement* GamepadMovementInputContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APresentationActor* PreviewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CachedHoveredRail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CachedHoveredTrainAgent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* TrainAgentConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseHitSphereRadius;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Place;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Destroy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Rotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Cancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextConstructionToolsGamepadMovement> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfigRails;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrainTracksPoleConnectionSimulationComponent* TickHoveredPoleConnection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UVisibilityStatePresentationComponent> VisibilityStatePresentationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMaterialAdjustPresentationComponent> MaterialAdjustComponent;
    
public:
    UInputContextBuildTrainAgent();

protected:
    UFUNCTION(BlueprintCallable)
    void SetConstructableConfig(UConstructableConfig* Config);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRotatingPreviewActor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlaceTrainAttempt(ETrainBuildingResult Result);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Rotate(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Place(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Destroy(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Cancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UConstructableConfig* GetCurrentConfig() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* FindHoveredTrainAgent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* FindHoveredRail() const;
    
};

