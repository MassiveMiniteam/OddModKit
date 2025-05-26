#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TweenBase.h"
#include "TweenSetActorLocation_ThreeLocations.generated.h"

UCLASS(Blueprintable)
class MMTTWEEN_API UTweenSetActorLocation_ThreeLocations : public UTweenBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MidLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MidValueAlpha;
    
public:
    UTweenSetActorLocation_ThreeLocations();

};

