#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "BuildableAreaOverrideSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBuildableAreaOverrideSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBuildable;
    
    UBuildableAreaOverrideSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

