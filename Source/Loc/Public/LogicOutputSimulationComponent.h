#pragma once
#include "CoreMinimal.h"
#include "CopyToolUseable.h"
#include "LogicConnectionSimulationComponent.h"
#include "LogicOutputSimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicOutputSimulationComponent : public ULogicConnectionSimulationComponent, public ICopyToolUseable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCopySignalWithCopyTool;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> Signals;
    
public:
    ULogicOutputSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SendSignal(FName ChannelID, int32 NewValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetValue(FName ChannelID) const;
    

    // Fix for true pure virtual functions not being implemented
};

