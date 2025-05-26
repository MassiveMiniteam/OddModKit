#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TweenBase.h"
#include "TweenSetActorLocation.generated.h"

UCLASS(Blueprintable)
class MMTTWEEN_API UTweenSetActorLocation : public UTweenBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetLocation;
    
public:
    UTweenSetActorLocation();

};

