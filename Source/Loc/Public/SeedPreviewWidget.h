#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "SeedPreviewGeneratedEventDelegate.h"
#include "SeedPreviewWidget.generated.h"

class UBiomeCellInstance;
class UDynamicTexture;
class UObject;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class USeedPreviewWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSeedPreviewGeneratedEvent OnPreviewGenerationDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Size;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicTexture* DynamicTexture;
    
    USeedPreviewWidget();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateLoading(float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetTexture() const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void GeneratePreview(const UObject* WorldContext, const FString& SeedText);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearIcons();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddIcon(UBiomeCellInstance* CellInstance, FVector2f position);
    
};

