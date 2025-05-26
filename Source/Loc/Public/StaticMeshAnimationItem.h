#pragma once
#include "CoreMinimal.h"
#include "StaticMeshAnimationItem.generated.h"

class UCurveVector;
class UStaticMeshEffectTrack;

USTRUCT(BlueprintType)
struct FStaticMeshAnimationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* PositionCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* RotationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* ScaleCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMeshEffectTrack* EffectTrack;
    
    LOC_API FStaticMeshAnimationItem();
};

