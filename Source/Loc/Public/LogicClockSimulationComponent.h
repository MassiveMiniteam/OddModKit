#pragma once
#include "CoreMinimal.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "CopyToolUseable.h"
#include "LogicClockEventDelegate.h"
#include "LogicClockSimulationComponent.generated.h"

class ULogicOutputSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicClockSimulationComponent : public USimulationActorComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLogicClockEvent OnTargetValuesChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed OffTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed OnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed LocalTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicOutputSimulationComponent> LogicOutput;
    
public:
    ULogicClockSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetOnTime(FFixed Time);
    
    UFUNCTION(BlueprintCallable)
    void SetOffTime(FFixed Time);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetTotalDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetTime01() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetOnTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetOffTime();
    

    // Fix for true pure virtual functions not being implemented
};

