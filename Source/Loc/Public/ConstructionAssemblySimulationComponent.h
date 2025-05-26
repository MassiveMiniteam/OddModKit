#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "AssemblyComponentEventDelegate.h"
#include "AssemblyEventDelegate.h"
#include "Assembly_GridObjectArray_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "ConstructionAssemblySimulationComponent.generated.h"

class ASimulationPlayer;
class UAssemblyCondition;
class UConstructableConfig;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UConstructionAssemblySimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed AssemblyTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed DisassembleTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SpawnOrderIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisassembleOverlappingPathsOnDisassemble;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConstructableConfig* ConstructableConfig;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyEvent OnAssemblyStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyEvent OnAssemblyAfterMovingStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyEvent OnAssemblyDone;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyEvent OnRelocateStateStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyEvent OnRelocateStateEnded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyEvent OnDisassemble;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyComponentEvent OnDisassembleAfterReplace;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyComponentEvent OnReplaceStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssemblyComponentEvent OnReplaceCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssembly_GridObjectArray_Event OnResourcesDroppedAfterDisassembly;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsRelocating;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAssemblyCondition>> DisassemblyConditionStrategies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAssemblyCondition>> RelocateConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bResetTickingAfterFinish;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASimulationPlayer* SimulationPlayer;
    
public:
    UConstructionAssemblySimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartAssemblyAfterReplace();
    
    UFUNCTION(BlueprintCallable)
    void StartAssemblyAfterMoving(ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void StartAssembly(ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void SetRelocateState(bool bInIsRelocating, ASimulationPlayer* ExecutingSimulationPlayer);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRelocateStartEvent(ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRelocateEndEvent(ASimulationPlayer* ExecutingSimulationPlayer);
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsDisassemblyAllowed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UConstructableConfig* GetConstructableConfig() const;
    
    UFUNCTION(BlueprintCallable)
    void DisassembleFromReplace();
    
    UFUNCTION(BlueprintCallable)
    void Disassemble(ASimulationPlayer* ExecutingSimulationPlayer);
    
};

