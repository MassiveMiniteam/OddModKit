#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "ManualStringToSimulationActorMappings.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UManualStringToSimulationActorMappings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, TSubclassOf<ASimulationActor>> Map;
    
    UManualStringToSimulationActorMappings();

};

