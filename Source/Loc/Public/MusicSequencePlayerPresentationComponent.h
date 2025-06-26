#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "PresentationActorComponent.h"
#include "MusicPitch.h"
#include "MusicSequencePlayerPresentationComponent.generated.h"

class UAudioComponent;
class UMusicSequencePlayerSimulationComponent;
class UQuartzClockHandle;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UMusicSequencePlayerPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMusicSequencePlayerSimulationComponent> SimulationComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SimulationComponentRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UQuartzClockHandle* ClockHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* AudioComponent;
    
public:
    UMusicSequencePlayerPresentationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNotePlayed(const FMusicPitch& MusicPitch);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAudioComponent* GetAudioComponent() const;
    
};

