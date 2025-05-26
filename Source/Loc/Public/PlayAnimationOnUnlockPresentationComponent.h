#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "UnlockableToAnimationMapping.h"
#include "PlayAnimationOnUnlockPresentationComponent.generated.h"

class UAnimationPresentationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPlayAnimationOnUnlockPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUnlockableToAnimationMapping UnlockableToAnimationMapping;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationPresentationComponent* CachedAnimationComponent;
    
public:
    UPlayAnimationOnUnlockPresentationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnUnlock(UUnlockableDataAsset* UnlockableDataAsset);
    
};

