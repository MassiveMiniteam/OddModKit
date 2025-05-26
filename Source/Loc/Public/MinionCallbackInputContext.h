#pragma once
#include "CoreMinimal.h"
#include "InputContext.h"
#include "MinionCallbackInputContext.generated.h"

class AActor;
class ALocPlayerController;
class UControllableMinionSimulationComponent;
class UInputActionData;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable)
class LOC_API UMinionCallbackInputContext : public UInputContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinionControllerSimulationBaseComponent* MyMinionController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* CallbackAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> CursorActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> CursorCallbackAreaClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> OverlappableActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CursorReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CallbackAreaReference;
    
    UMinionCallbackInputContext();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* TryGetCursor();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool TryCallbackMinion(UControllableMinionSimulationComponent* MinionComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCallbackInputStop();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCallbackInputStart();
    
    UFUNCTION(BlueprintCallable)
    void OnCallbackInput(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsControlGroupForMinionCallable(UControllableMinionSimulationComponent* MinionComponent);
    
};

