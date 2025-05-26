#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ItemStackingStrategy.h"
#include "ItemStackingStrategy_Grid.generated.h"

UCLASS(Blueprintable)
class UItemStackingStrategy_Grid : public UItemStackingStrategy {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntPoint NumInstancesPerPlane;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Spacing;
    
public:
    UItemStackingStrategy_Grid();

};

