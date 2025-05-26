#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "GlobalClassMappings.generated.h"

class AGridNetwork;
class UEventDataAsset;
class UGridTileLandscapeLayer;
class UManualStringToSimulationActorMappings;

UCLASS(Blueprintable)
class LOC_API UGlobalClassMappings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridNetwork> PathInstanceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGridTileLandscapeLayer* RampLandscapeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UManualStringToSimulationActorMappings* ManualStringToSimulationActorMappings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEventDataAsset* OpenedUIEvent;
    
    UGlobalClassMappings();

};

