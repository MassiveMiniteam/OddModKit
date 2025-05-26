#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "SetBiomeMusicAsPlayedCommand.generated.h"

class UBiomeMusicPlayerSimulationComponent;
class UMetaSoundSource;

UCLASS(Blueprintable)
class LOC_API USetBiomeMusicAsPlayedCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMetaSoundSource>> MetaSoundTracks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeMusicPlayerSimulationComponent* MusicPlayerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSetMusicAsPlayed;
    
    USetBiomeMusicAsPlayedCommand();

};

