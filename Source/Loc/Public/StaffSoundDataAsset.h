#pragma once
#include "CoreMinimal.h"
#include "UnlockableDataAsset.h"
#include "StaffSoundDataAsset.generated.h"

class USoundBase;
class USoundCue;

UCLASS(Blueprintable)
class LOC_API UStaffSoundDataAsset : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> StaffSoundPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> SFXMinionCallStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundBase> SFXMinionCallPattern;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> SFXMinionRush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> SFXPlayerPing;
    
    UStaffSoundDataAsset();

};

