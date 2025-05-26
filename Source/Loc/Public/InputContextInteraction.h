#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "InputContextInteraction.generated.h"

class AActor;
class ALocPlayerController;
class UInputActionData;
class UInteractionPresentationComponent;

UCLASS(Blueprintable)
class LOC_API UInputContextInteraction : public UInputContext {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* PrimaryAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputActionData* SecondaryAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInteractionPresentationComponent> CurrentInteractionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UInteractionPresentationComponent> LastInteractedPresentationComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeQueries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> ActorPrioritiesForMultipleHits;
    
public:
    UInputContextInteraction();

    UFUNCTION(BlueprintCallable)
    void UseCustomSphereTraceLocations(const FVector& Start, const FVector& End, float Radius);
    
protected:
    UFUNCTION(BlueprintCallable)
    void UnsubscribeFromLastInteractedPresentationComponent();
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentInteractionComponent(UInteractionPresentationComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSecondaryAction();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPrimaryAction();
    
public:
    UFUNCTION(BlueprintCallable)
    void DisableCustomSphereTraceLocations();
    
private:
    UFUNCTION(BlueprintCallable)
    void CallSecondaryAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    void CallPrimaryAction(UInputActionData* InputAction, ALocPlayerController* Player);
    
};

