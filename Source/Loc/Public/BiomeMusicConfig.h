#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BiomeMusicConfig.generated.h"

class UMetaSoundSource;

UCLASS(Blueprintable)
class LOC_API UBiomeMusicConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMetaSoundSource>> SoftMusicClips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMetaSoundSource* IntroSound;
    
    UBiomeMusicConfig();

};

