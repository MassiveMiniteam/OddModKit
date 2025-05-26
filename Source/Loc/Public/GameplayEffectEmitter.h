#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocCoreSavable.h"
#include "SimulationActor.h"
#include "GameplayEffectTriggerDelegate.h"
#include "GameplayEffectEmitter.generated.h"

class UGameplayEffect;

UCLASS(Blueprintable)
class LOC_API AGameplayEffectEmitter : public ASimulationActor, public ILocCoreSavable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UGameplayEffect* TargetGameplayEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed WindupDuration;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayEffectTrigger OnGameplayEffectTriggered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentWindupTime;
    
    AGameplayEffectEmitter(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SendHitCommand(ASimulationActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ApplyHit(ASimulationActor* Target);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

