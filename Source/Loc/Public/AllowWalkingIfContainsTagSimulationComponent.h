#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "AllowWalkingIfContainsTagSimulationComponent.generated.h"

class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UAllowWalkingIfContainsTagSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ListeningTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CustomWalkabilityBitmaskOnTag;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComponent;
    
public:
    UAllowWalkingIfContainsTagSimulationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnGameplayStatChanged(UStatsComponent* InStatsComponent, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
};

