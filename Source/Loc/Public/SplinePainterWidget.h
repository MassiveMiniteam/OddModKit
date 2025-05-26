#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SplinePainterStruct.h"
#include "SplinePainterWidget.generated.h"

class UWorldGenerator;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API USplinePainterWidget : public UUserWidget {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThicknessZoomedIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThicknessZoomedOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldGenerator* WorldGenerator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSplinePainterStruct> Splines;
    
public:
    USplinePainterWidget();

    UFUNCTION(BlueprintCallable)
    void SetZoomMultiplier(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OverwriteSplines(const TArray<FSplinePainterStruct>& NewSplines);
    
    UFUNCTION(BlueprintCallable)
    void ClearSplines();
    
    UFUNCTION(BlueprintCallable)
    void AddSpline(const FSplinePainterStruct& NewPaintedSpline);
    
};

