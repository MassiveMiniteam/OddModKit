#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "LockTargetPresentationComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULockTargetPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    ULockTargetPresentationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUnlock();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnLockAtTarget(AActor* LockedActor);
    
};

