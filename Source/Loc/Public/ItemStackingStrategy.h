#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StaticMeshAndTransforms.h"
#include "ItemStackingStrategy.generated.h"

class UItemConfig;

UCLASS(Abstract, Blueprintable)
class LOC_API UItemStackingStrategy : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldPlayGrowAnimation;
    
    UItemStackingStrategy();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FStaticMeshAndTransforms CalcStackLayout(const UItemConfig* ItemConfig, int32 Amount) const;
    
};

