#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EFactionType.h"
#include "FactionSimulationComponent.generated.h"

class UFactionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UFactionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFactionType Type;
    
    UFactionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ConsidersOtherFactionAsPrey(const UFactionSimulationComponent* OtherFaction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAttack(const UFactionSimulationComponent* OtherFaction) const;
    
};

