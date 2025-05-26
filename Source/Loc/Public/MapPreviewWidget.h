#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapPreviewCell.h"
#include "MapPreviewWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UMapPreviewWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapPreviewCell> Cells;
    
public:
    UMapPreviewWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void GenerateWithSeed(int32 Seed);
    
};

