#pragma once
#include "CoreMinimal.h"
#include "ComponentOutlineData.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FComponentOutlineData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Component;
    
    LOC_API FComponentOutlineData();
};

