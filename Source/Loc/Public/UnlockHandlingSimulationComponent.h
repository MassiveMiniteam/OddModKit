#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "OnItemUnlockedDelegate.h"
#include "UnlockHandlingSimulationComponent.generated.h"

class UObject;
class UUnlockHandlingSimulationComponent;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UUnlockHandlingSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemUnlocked OnItemUnlocked;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> UnlockedDataAssets;
    
public:
    UUnlockHandlingSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UUnlockHandlingSimulationComponent* Get(UObject* WorldContext);
    
};

