#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "EAxisYAlignmentMode.h"
#include "ELimitsMode.h"
#include "LineChartData.h"
#include "LineChartWidget.generated.h"

class UDataAsset;

UCLASS(Blueprintable, EditInlineNew)
class MMTUNREALTOOLS_API ULineChartWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAxisYAlignmentMode AxisYAlignment;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FLineChartData> TaggedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UDataAsset*, FLineChartData> AssetMappedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLineChartData> DisplayedData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFlipYAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D WidgetSize;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval LimitsX;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval LimitsY;
    
public:
    ULineChartWidget();

    UFUNCTION(BlueprintCallable)
    void UpdateVisibilityByTag(FGameplayTag Tag, bool bNewVisibility);
    
    UFUNCTION(BlueprintCallable)
    void UpdateVisibilityByAsset(UDataAsset* DataAsset, bool bNewVisibility);
    
    UFUNCTION(BlueprintCallable)
    void UpdateLimits(FFloatInterval NewLimitsX, FFloatInterval NewLimitsY, ELimitsMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void UpdateChartDataWithTag(FGameplayTag Tag, FLineChartData LineChartData);
    
    UFUNCTION(BlueprintCallable)
    void UpdateChartDataByDataAsset(UDataAsset* DataAsset, FLineChartData LineChartData);
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateAllDisplayedData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLimitsChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FLineChartData> GetDisplayedLineChartData() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetAxisYOrigin() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void DeleteDataWithTag(FGameplayTag Tag);
    
    UFUNCTION(BlueprintCallable)
    void DeleteDataByDataAsset(UDataAsset* DataAsset);
    
    UFUNCTION(BlueprintCallable)
    void ClearAllData();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D CalcPixelPosition_StartAxisY() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D CalcPixelPosition_StartAxisX() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D CalcPixelPosition_EndAxisY() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D CalcPixelPosition_EndAxisX() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D CalcPixelPosition(FVector2D DataPoint) const;
    
};

