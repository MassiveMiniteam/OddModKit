#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "TrainsConnectionChangeDelegateParams.h"
#include "InputContextBuildConnector.generated.h"

class AActor;
class ALocPlayerController;
class APresentationActor;
class ASimulationActor;
class UConstructableConfig;
class UInputActionData;
class UInputContextConstructionToolsCursor;
class UInputContextConstructionToolsGamepadMovement;
class UInputContextTrainPolePlacement;
class UTrainTracksPoleBaseSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UInputContextBuildConnector : public UInputContext {
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
    UInputContextTrainPolePlacement* InputContext_PolePlacement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfigRails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfigPole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APresentationActor* PreviewPresentationActor_Rail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CachedHoveredRail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CachedHoveredPole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForPlacementCommand;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Place;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Cancel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* InputAction_Destroy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextConstructionToolsGamepadMovement> GamepadMovementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UInputContextTrainPolePlacement> PolePlacementInputContextClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> CursorActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> GridIndicatorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MouseHitSphereRadius;
    
public:
    UInputContextBuildConnector();

private:
    UFUNCTION(BlueprintCallable)
    void OnPolePlacementContextUpdated(UInputContextTrainPolePlacement* InputContext);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnOtherPoleHovered_VisualUpdate(AActor* HoveredPole);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputActionPlaceBlueprint();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputActionDestroy_NotHovering();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInputActionCancelBlueprint();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Place(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Destroy(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void OnInputAction_Cancel(UInputActionData* InputAction, ALocPlayerController* Player);
    
protected:
    UFUNCTION(BlueprintCallable)
    void NotifyConnectionChange(FTrainsConnectionChangeDelegateParams ConnectionChangeParams);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetHoveredRailSimulation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTrainTracksPoleBaseSimulationComponent* GetHoveredPoleSimulationComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASimulationActor* GetHoveredPoleSimulationActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool FirstConnectionIsSet() const;
    
};

