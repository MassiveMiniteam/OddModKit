#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "Engine/TextureDefines.h"
#include "DynamicTexture.generated.h"

class UTexture2D;

UCLASS(Blueprintable)
class UDynamicTexture : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
public:
    UDynamicTexture();

    UFUNCTION(BlueprintCallable)
    void UpdateTexture();
    
    UFUNCTION(BlueprintCallable)
    void SetPixel(int32 X, int32 Y, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void Initialize(int32 InWidth, int32 InHeight, FLinearColor InClearColor, TEnumAsByte<TextureFilter> FilterMethod, bool bSRGB);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetWidth();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetTextureResource();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetPixelColor(int32 X, int32 Y) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHeight();
    
    UFUNCTION(BlueprintCallable)
    void FillRect(int32 X, int32 Y, int32 Width, int32 Height, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void Fill(FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void DrawLine(int32 X1, int32 Y1, int32 X2, int32 Y2, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void Clear();
    
};

