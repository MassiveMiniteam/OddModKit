#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "EntitlementSimulation.generated.h"

class UProductEntitlementDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UEntitlementSimulation : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UProductEntitlementDataAsset* EntitlementDataAsset;
    
    UEntitlementSimulation(const FObjectInitializer& ObjectInitializer);

};

