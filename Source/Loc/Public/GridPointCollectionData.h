#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "GridPointCollectionData.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPointCollectionData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntPoint> GridPositions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInverse;
    
    UGridPointCollectionData();

    UFUNCTION(BlueprintCallable)
    bool IsValidPosition(FIntPoint Point);
    
};

