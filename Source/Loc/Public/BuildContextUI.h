#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BuildMenuCostConfig.h"
#include "BuildContextUI.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UBuildContextUI : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBuildMenuCostConfig> PreviousCost;
    
public:
    UBuildContextUI();

    UFUNCTION(BlueprintCallable)
    void RefreshCostWidget(const TArray<FBuildMenuCostConfig>& BuildMenuCostConfigs);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRefreshCostWidgetEvent(const TArray<FBuildMenuCostConfig>& BuildMenuCostConfigs);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HighlightFailEvent();
    
public:
    UFUNCTION(BlueprintCallable)
    void HighlightFail();
    
};

