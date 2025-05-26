#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemStackingStrategy.h"
#include "ItemStackingStrategy_Triangle.generated.h"

UCLASS(Blueprintable)
class UItemStackingStrategy_Triangle : public UItemStackingStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumInstancesBottomRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Spacing;
    
public:
    UItemStackingStrategy_Triangle();

};

