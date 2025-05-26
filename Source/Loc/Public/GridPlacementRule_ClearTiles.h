#pragma once
#include "CoreMinimal.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_ClearTiles.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_ClearTiles : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> WhiteListClasses;
    
    UGridPlacementRule_ClearTiles();

    UFUNCTION(BlueprintCallable)
    bool GetIsClassWhitelisted(UClass* Class);
    
};

