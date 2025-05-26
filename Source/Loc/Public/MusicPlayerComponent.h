#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BiomeMusicPlayerEventDelegate.h"
#include "BiomeMusicPlayerFloatEventDelegate.h"
#include "MusicPlayerComponent.generated.h"

class ASimulationPlayer;
class UBiomeCellInstance;
class UBiomeConfig;
class UBiomeMusicConfig;
class UBiomeTrackerSimulationComponent;
class UMetaSoundSource;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMusicPlayerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeMusicPlayerEvent OnTracklistChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeMusicPlayerFloatEvent OnNewWaitInterval;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiomeMusicPlayerFloatEvent OnElapsedTimeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBiomeMusicConfig* LastBiomeMusicConfig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinWaitInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWaitInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElapsedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WaitInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UMetaSoundSource>> PlayedMusicClips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBiomeTrackerSimulationComponent* BiomeTracker;
    
public:
    UMusicPlayerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTracksAsUnplayed(TArray<TSoftObjectPtr<UMetaSoundSource>> Tracks);
    
    UFUNCTION(BlueprintCallable)
    void SetTracksAsPlayed(TArray<TSoftObjectPtr<UMetaSoundSource>> Tracks);
    
    UFUNCTION(BlueprintCallable)
    void ResetAll();
    
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

