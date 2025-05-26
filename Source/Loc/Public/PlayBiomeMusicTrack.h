#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "PlayBiomeMusicTrack.generated.h"

class UBiomeMusicPlayerSimulationComponent;
class UMetaSoundSource;

UCLASS(Blueprintable)
class LOC_API UPlayBiomeMusicTrack : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMetaSoundSource> MusicClip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeMusicPlayerSimulationComponent* MusicPlayerComponent;
    
    UPlayBiomeMusicTrack();

};

