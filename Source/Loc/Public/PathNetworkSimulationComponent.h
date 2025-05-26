#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "GridNetworkSimulationComponent.h"
#include "PathNetworkSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathNetworkSimulationComponent : public UGridNetworkSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed SpeedMultiplier;
    
    UPathNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

