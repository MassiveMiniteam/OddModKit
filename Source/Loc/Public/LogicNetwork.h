#pragma once
#include "CoreMinimal.h"
#include "GridNetwork.h"
#include "LogicNetwork.generated.h"

class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ALogicNetwork : public AGridNetwork {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentSignalValue;
    
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULogicInputSimulationComponent>> LogicInputs;
    
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULogicOutputSimulationComponent>> LogicOutputs;
    
public:
    ALogicNetwork(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RemoveConnection(ULogicConnectionSimulationComponent* Connection);
    
protected:
    UFUNCTION(BlueprintCallable)
    void NotifySignalChange();
    
public:
    UFUNCTION(BlueprintCallable)
    bool HasConnection(ULogicConnectionSimulationComponent* Connection) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetLogicChannel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAsIntFromChannel(FName Channel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAsInt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAsBoolFromChannel(FName Channel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAsBool() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetActiveBitsOnRibbonChannel() const;
    
    UFUNCTION(BlueprintCallable)
    void AddConnection(ULogicConnectionSimulationComponent* Connection);
    
};

