#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject.h"
#include "NoiseSpawnObjectGroundTypeItem.h"
#include "NoiseGraphNodeMaster_NoiseSpawnObject_GroundType.generated.h"

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_NoiseSpawnObject_GroundType : public UNoiseGraphNodeMaster_NoiseSpawnObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNoiseSpawnObjectGroundTypeItem> SpawnByGroundTypes;
    
    UNoiseGraphNodeMaster_NoiseSpawnObject_GroundType();

};

