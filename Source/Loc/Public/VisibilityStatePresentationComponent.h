#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "EVisibilityState.h"
#include "OnPresentationStateChangedDelegate.h"
#include "VisibilityStatePresentationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UVisibilityStatePresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EVisibilityState> CurrentState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPresentationStateChanged OnPresentationStateChanged;
    
public:
    UVisibilityStatePresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetState(TEnumAsByte<EVisibilityState> NewState);
    
};

