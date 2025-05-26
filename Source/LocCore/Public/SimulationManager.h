#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EDestructionReason.h"
#include "LocActor.h"
#include "OnSimulationTickEventDelegate.h"
#include "SimulationActorEventDelegate.h"
#include "SimulationActorHookArray.h"
#include "SimulationActorsWrapper.h"
#include "SimulationManagerActorEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "SimulationManager.generated.h"

class AActor;
class ASimulationActor;
class ULocSimulationSubsystem;
class UObject;
class USimulationActorComponent;
class USimulationActorHook;

UCLASS(Blueprintable)
class LOCCORE_API ASimulationManager : public ALocActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationActorsWrapper SimulationActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<USimulationActorComponent*, USimulationActorComponent*> PredictedActorComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PredictionTimeoutFrames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasBegunSimulation;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCurrentlyResettingPredictedComponents;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double CurrentFrameStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, AActor*> TableHashActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, int32> TableActorHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULocSimulationSubsystem*> SimulationSubsystems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, AActor*> PresentationActorsWaitingForAssign;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSimulationTickEvent OnPreSimulationTick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSimulationTickEvent OnPostSimulationTick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSimulationTickEvent OnSimulationTick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationManagerActorEvent OnSimulationActorSpawned;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint64 NameIndexCounter;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint64 HashCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SimulationActorTickIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActorTicksPerSubTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActorHashesPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceDesync;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimulationActorEvent OnSimulationActorShutDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UClass*, FSimulationActorHookArray> SimulationActorHooks;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, TWeakObjectPtr<UObject>> ResolvedObjectMappings;
    
    ASimulationManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnregisterSimulationActorHook(UClass* Class, TSubclassOf<USimulationActorHook> Hook);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterSimulationActor(ASimulationActor* SimulationActor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    ASimulationActor* SpawnSimulationActorWithoutRegisteringWithName(TSubclassOf<ASimulationActor> Class, FName Name, FIntVector CenterLocation, int32 Rotation);
    
    UFUNCTION(BlueprintCallable)
    ASimulationActor* SpawnSimulationActorWithoutRegistering(TSubclassOf<ASimulationActor> Class, FIntVector CenterLocation, int32 Rotation);
    
    UFUNCTION(BlueprintCallable)
    ASimulationActor* SpawnSimulationActor(TSubclassOf<ASimulationActor> Class, FIntVector CenterLocation, int32 Rotation, bool bForceSyncPresentationActorSpawn);
    
    UFUNCTION(BlueprintCallable)
    bool RollChanceInPercent(int32 Chance);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseComponentPrediction(USimulationActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void RegisterSimulationActorHook(UClass* Class, TSubclassOf<USimulationActorHook> Hook);
    
    UFUNCTION(BlueprintCallable)
    void RegisterSimulationActor(ASimulationActor* SimulationActor, bool bIsLoading, bool bForceSyncPresentationActorSpawn);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASimulationActor*> GetSimulationActors() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<TSubclassOf<USimulationActorHook>> GetSimulationActorHooks(UClass* Class);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetRandomIntPointUniformDistributedOnRing(FInt32Interval Range);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetRandomIntPointUniformDistributedOnCircle(int32 Radius);
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetRandomIntPointInRingThatIsAlsoOnCircle(FIntPoint RingOrigin, FInt32Interval RingRadii, FIntPoint CircleOrigin, int32 CircleRadius);
    
    UFUNCTION(BlueprintCallable)
    int32 GetRandomIntegerInRange(int32 min, int32 max);
    
    UFUNCTION(BlueprintCallable)
    int32 GetRandomInteger();
    
    UFUNCTION(BlueprintCallable)
    USimulationActorComponent* GetPredictedActorComponentIfPossible(USimulationActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    USimulationActorComponent* GetPredictedActorComponent(USimulationActorComponent* Component);
    
    UFUNCTION(BlueprintCallable, Exec)
    TArray<FIntPoint> GetMostBusyPositions(int32 Num, float Radius);
    
    UFUNCTION(BlueprintCallable)
    void DestroySimulationActor(ASimulationActor* SimulationActor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void CreateComponentPrediction(USimulationActorComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void ClearSimulation();
    
};

