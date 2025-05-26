#pragma once
#include "CoreMinimal.h"
#include "GridNetworkSimulationComponent.h"
#include "TrackNetworkSimulationComponent.generated.h"

class UTrackNetworkSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UTrackNetworkSimulationComponent : public UGridNetworkSimulationComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCartStation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrackNetworkSimulationComponent* TargetStation;
    
public:
    UTrackNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

