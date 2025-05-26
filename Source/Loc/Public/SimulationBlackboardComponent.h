#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "LocCoreSavable.h"
#include "BlackboardEntryItem.h"
#include "OnBlackboardKeyChangedEventDelegate.h"
#include "SimulationBlackboardComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USimulationBlackboardComponent : public UBlackboardComponent, public ILocCoreSavable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FBlackboardEntryItem> Memory;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBlackboardKeyChangedEvent OnBlackboardKeyChanged;
    
public:
    USimulationBlackboardComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void UnregisterObserverForKey(FName Key);
    
    UFUNCTION(BlueprintCallable)
    void RegisterObserverForKey(FName Key);
    

    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

