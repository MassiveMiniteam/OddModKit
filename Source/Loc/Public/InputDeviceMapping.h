#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerInput.h"
#include "Engine/DataAsset.h"
#include "InputCoreTypes.h"
#include "EInputDeviceType.h"
#include "InputKeySpriteMapping.h"
#include "InputDeviceMapping.generated.h"

class UInputActionData;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UInputDeviceMapping : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputDeviceType DeviceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* DefaultTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputKeySpriteMapping> MappedSprites;
    
    UInputDeviceMapping();

    UFUNCTION(BlueprintCallable)
    UTexture2D* GetTextureForKey(FKey Key);
    
    UFUNCTION(BlueprintCallable)
    FInputKeySpriteMapping GetSpriteMappingForSpecificKey(FInputActionKeyMapping KeyMapping, bool& bHasModifier, FInputKeySpriteMapping& ModifierSprite);
    
    UFUNCTION(BlueprintCallable)
    FInputKeySpriteMapping GetSpriteMappingForInputAction(UInputActionData* InputAction, bool& bHasModifier, FInputKeySpriteMapping& ModifierSprite);
    
    UFUNCTION(BlueprintCallable)
    FInputKeySpriteMapping GetModifierSpriteMapping(FInputActionKeyMapping KeyMapping);
    
};

