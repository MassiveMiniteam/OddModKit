#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DynamicMaterialPool.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable)
class LOC_API UDynamicMaterialPool : public UObject {
    GENERATED_BODY()
public:
    UDynamicMaterialPool();

    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* GetDynamicMaterial(int32 InKey, UMaterialInterface* InParentMaterial);
    
};

