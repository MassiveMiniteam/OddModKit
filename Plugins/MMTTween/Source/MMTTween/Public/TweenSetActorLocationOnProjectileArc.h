#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TweenBase.h"
#include "TweenSetActorLocationOnProjectileArc.generated.h"

UCLASS(Blueprintable)
class MMTTWEEN_API UTweenSetActorLocationOnProjectileArc : public UTweenBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Height;
    
    UTweenSetActorLocationOnProjectileArc();

};

