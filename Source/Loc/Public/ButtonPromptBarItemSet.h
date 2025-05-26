#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ButtonPromptBarItem.h"
#include "ButtonPromptBarItemSet.generated.h"

UCLASS(Blueprintable)
class LOC_API UButtonPromptBarItemSet : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FButtonPromptBarItem> BarItems;
    
    UButtonPromptBarItemSet();

};

