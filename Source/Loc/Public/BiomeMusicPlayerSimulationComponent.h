#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "LocRandom.h"
#include "SimulationActorComponent.h"
#include "BiomeMusicPlayerEventDelegate.h"
#include "BiomeMusicPlayerFloatEventDelegate.h"
#include "BiomeMusicPlayerSimulationComponent.generated.h"

class ASimulationPlayer;
class UBiomeCellInstance;
class UBiomeConfig;
class UBiomeMusicConfig;
class UBiomeTrackerSimulationComponent;
class UMetaSoundSource;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UBiomeMusicPlayerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeMusicPlayerEvent OnTracklistChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeMusicPlayerFloatEvent OnNewWaitInterval;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeMusicPlayerFloatEvent OnElapsedTimeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UBiomeMusicConfig* LastBiomeMusicConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MinWaitInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed MaxWaitInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed WaitInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMetaSoundSource>> PlayedMusicClips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FLocRandom Random;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBiomeTrackerSimulationComponent* BiomeTracker;
    
public:
    UBiomeMusicPlayerSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void PlayTrack(TSoftObjectPtr<UMetaSoundSource> Metasound);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PlayNextTrackImmediately();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnNewMusicSelected(const TSoftObjectPtr<UMetaSoundSource>& Metasound, ASimulationPlayer* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnteredNewCellInstance(UBiomeTrackerSimulationComponent* Component, UBiomeCellInstance* BiomeCellInstance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBiomeMusicConfigChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBiomeEnteredFirstTime(UBiomeTrackerSimulationComponent* Component, UBiomeConfig* Biome);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBiomeEntered(UBiomeTrackerSimulationComponent* Component, UBiomeConfig* Biome);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<TSoftObjectPtr<UMetaSoundSource>> GetPlayedMusicClips() const;
    
};

