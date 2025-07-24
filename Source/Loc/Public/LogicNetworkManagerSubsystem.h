#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GridNetworkManagerSubsystem.h"
#include "LogicNetworkManagerSubsystem.generated.h"

class ALogicNetwork;
class UActorComponent;
class ULogicOutputSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ULogicNetworkManagerSubsystem : public UGridNetworkManagerSubsystem {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UActorComponent>> LogicTickingComponents;
    
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ALogicNetwork>> DirtyNetworks;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULogicOutputSimulationComponent>> DirtyOutputsWithoutNetwork;
    
public:
    ULogicNetworkManagerSubsystem();

    UFUNCTION(BlueprintCallable)
    void QueueNetworkForUpdate(ALogicNetwork* Network);
    
    UFUNCTION(BlueprintCallable)
    ALogicNetwork* FindLogicNetworkAt(FIntPoint position);
    
};

