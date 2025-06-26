#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "SimulationActorComponent.h"
#include "ActorSpawnCarouselCallbackDelegate.h"
#include "Templates/SubclassOf.h"
#include "ActorSpawnCarouselComponent.generated.h"

class ASimulationActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UActorSpawnCarouselComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumMaxActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASimulationActor> ActorClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<ASimulationActor*> Actors;
    
public:
    UActorSpawnCarouselComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    ASimulationActor* SpawnActor(FIntVector CornerLocation, int32 Rotation, FActorSpawnCarouselCallback BeforeRegistrationCallback);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationActorShutDown(ASimulationActor* Actor, EDestructionReason Reason);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetActors() const;
    
    UFUNCTION(BlueprintCallable)
    void DestroyActor(ASimulationActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void Clear();
    
};

