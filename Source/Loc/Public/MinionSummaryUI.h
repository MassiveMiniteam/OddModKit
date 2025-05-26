#pragma once
#include "CoreMinimal.h"
#include "NavUserWidget.h"
#include "MinionSummaryUI.generated.h"

class UItemMinionConfig;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UMinionSummaryUI : public UNavUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemMinionConfig* MinionItemConfig;
    
public:
    UMinionSummaryUI();

};

