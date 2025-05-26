#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VillageLandscapeData.generated.h"

class UGridTileGroundLayer;

UCLASS(Blueprintable)
class UVillageLandscapeData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> HeightData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> RampLocationsAndRotations;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int8> WaterHeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGridTileGroundLayer*> GroundLayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Width;
    
    UVillageLandscapeData();

};

