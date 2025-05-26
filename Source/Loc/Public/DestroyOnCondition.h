#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "DestroyOnCondition.generated.h"

class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UDestroyOnCondition : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUnlockHandlingSimulationComponent* UnlockHandlingSimulationComponent;
    
public:
    UDestroyOnCondition(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnUnlock(UUnlockableDataAsset* UnlockableDataAsset);
    
};

