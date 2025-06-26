#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemStackingStrategy.generated.h"

class UItemConfig;
class UStaticMesh;

UCLASS(Abstract, Blueprintable)
class LOC_API UItemStackingStrategy : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldPlayGrowAnimation;
    
    UItemStackingStrategy();

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSoftObjectPtr<UStaticMesh> CalcStackLayout(const UItemConfig* ItemConfig, int32 Amount) const;
    
};

