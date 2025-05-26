#pragma once
#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GE_MovementIsBlocked_IfPathAddonInFrontDemandsIt.generated.h"

class UGridNetworkAgentSimulationComponent;
class USubGridMovementSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UGE_MovementIsBlocked_IfPathAddonInFrontDemandsIt : public UGameplayEffect {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USubGridMovementSimulationComponent* SubGridMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGridNetworkAgentSimulationComponent* GridNetworkAgentComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsCurrentlyWaitingInFrontOfPathAddon;
    
public:
    UGE_MovementIsBlocked_IfPathAddonInFrontDemandsIt();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInFrontOfPathAddonThatDemandsWaiting() const;
    
};

