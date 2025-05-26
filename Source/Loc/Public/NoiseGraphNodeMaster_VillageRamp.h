#pragma once
#include "CoreMinimal.h"
#include "NoiseGraphNodeMaster_Ramp.h"
#include "NoiseGraphNodeMaster_VillageRamp.generated.h"

class UVillageLandscapeData;

UCLASS(Blueprintable)
class LOC_API UNoiseGraphNodeMaster_VillageRamp : public UNoiseGraphNodeMaster_Ramp {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVillageLandscapeData* VillageLandscapeData;
    
public:
    UNoiseGraphNodeMaster_VillageRamp();

};

