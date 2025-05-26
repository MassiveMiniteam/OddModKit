#pragma once
#include "CoreMinimal.h"
#include "EInputDeviceType.h"
#include "EMenuShowForDevice.h"
#include "UnlockableDataAsset.h"
#include "UnlockableAction.generated.h"

class UInputActionData;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UUnlockableAction : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EMenuShowForDevice, UInputActionData*> AssociatedInputAction;
    
public:
    UUnlockableAction();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInputActionData* FindAssociatedInputAction(EInputDeviceType Device) const;
    
};

