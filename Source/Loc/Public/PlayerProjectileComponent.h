#pragma once
#include "CoreMinimal.h"
#include "PresentationActorComponent.h"
#include "ProjectilePresentationParameters.h"
#include "PlayerProjectileComponent.generated.h"

class UTweenBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPlayerProjectileComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPlayerProjectileComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnTweenFinished(UTweenBase* Tween);
    
    UFUNCTION(BlueprintCallable)
    void OnTweenCancelled(UTweenBase* Tween);
    
public:
    UFUNCTION(BlueprintCallable)
    void LaunchPlayer(const FProjectilePresentationParameters& Parameters);
    
};

