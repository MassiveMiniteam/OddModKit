#pragma once
#include "CoreMinimal.h"
#include "GameplayStatsContainerBase.h"
#include "GameplayStatsContainer.generated.h"

class UGameplayStatsContainer;

UCLASS(Blueprintable)
class LOC_API UGameplayStatsContainer : public UGameplayStatsContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameplayStatsContainer* ParentAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameplayStatsContainerBase*> ParentContainers;
    
    UGameplayStatsContainer();

};

