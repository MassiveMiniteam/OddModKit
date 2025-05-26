#pragma once
#include "CoreMinimal.h"
#include "GridPlacementRuleConfig.h"
#include "GridPlacementRule_BlackList.generated.h"

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_BlackList : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> BlackListClasses;
    
    UGridPlacementRule_BlackList();

    UFUNCTION(BlueprintCallable)
    bool GetIsClassBlackListed(UClass* Class);
    
};

