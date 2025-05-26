#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RandomSpawnObjectBiomeGenerator.h"
#include "SpawnFoundationGridBiomeGenerator.generated.h"

UCLASS(Blueprintable)
class LOC_API USpawnFoundationGridBiomeGenerator : public URandomSpawnObjectBiomeGenerator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GridSpacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxDistanceToCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomIndividualRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomGridRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint HeightRange;
    
public:
    USpawnFoundationGridBiomeGenerator();

};

