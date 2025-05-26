#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "LocCoreSavable.h"
#include "NodeStackInfo.h"
#include "OnBehaviorTreeFinishedDelegate.h"
#include "SimulationBehaviorTreeSaveInfo.h"
#include "SimulationBehaviorTreeComponent.generated.h"

class UBTNode;
class UBehaviorTree;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API USimulationBehaviorTreeComponent : public UBehaviorTreeComponent, public ILocCoreSavable {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FNodeStackInfo CurrentNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FNodeStackInfo> NodeStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bTickImmediately;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSimulationBehaviorTreeSaveInfo SaveInfo;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, int16> TreeIdentifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bLocStopIsRequested;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bLocIsRunning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bLocIsLooping;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBehaviorTreeFinished OnBehaviorTreeFinished;
    
    USimulationBehaviorTreeComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetLoopMode(bool LoopMode);
    
    UFUNCTION(BlueprintCallable)
    void RunSubTreeForIdentifier(UBehaviorTree* Tree, FName TreeIdentifier);
    
    UFUNCTION(BlueprintCallable)
    void RunNode(UBTNode* Node);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLoopMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetCurrentNodeName() const;
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

