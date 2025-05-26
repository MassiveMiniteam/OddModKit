#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "SimulationActorComponent.h"
#include "PlayerInputForwardSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPlayerInputForwardSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CurrentInputTags;
    
public:
    UPlayerInputForwardSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void OverWriteInputTags(const FGameplayTagContainer& NewTags);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCurrentlyTag(const FGameplayTag& Tag) const;
    
};

