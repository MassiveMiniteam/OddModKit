#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "Fuel.generated.h"

USTRUCT(BlueprintType)
struct FFuel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed BurnDuration;
    
    LOC_API FFuel();
};

