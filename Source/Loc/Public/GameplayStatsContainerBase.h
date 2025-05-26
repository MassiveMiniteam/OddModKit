#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayFixedStatMap.h"
#include "GameplayStatsContainerBase.generated.h"

UCLASS(Blueprintable)
class LOC_API UGameplayStatsContainerBase : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayFixedStatMap BaseStats;
    
    UGameplayStatsContainerBase();

};

