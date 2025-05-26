#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "GlobalMapInteractionTracker_MapIconActorClass_Int_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "GlobalMapInteractionTracker.generated.h"

class ASimulationActor;
class UGlobalMapInteractionTracker;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGlobalMapInteractionTracker : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalMapInteractionTracker_MapIconActorClass_Int_Event OnInteractedFromMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<ASimulationActor>, int32> MapIconTypeToCount;
    
public:
    UGlobalMapInteractionTracker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    static UGlobalMapInteractionTracker* GetGlobalMapInteractionTracker(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAmountForType(TSubclassOf<ASimulationActor> ActorClass);
    
    UFUNCTION(BlueprintCallable)
    void Add(ASimulationActor* InSimulationActor);
    
};

