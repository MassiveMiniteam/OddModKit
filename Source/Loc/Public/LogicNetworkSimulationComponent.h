#pragma once
#include "CoreMinimal.h"
#include "GridNetworkSimulationComponent.h"
#include "OnLogicNetworkEventDelegate.h"
#include "LogicNetworkSimulationComponent.generated.h"

class ALogicNetwork;
class ULogicNetworkSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicNetworkSimulationComponent : public UGridNetworkSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BitMask;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLogicNetworkEvent OnSignalChanged;
    
    ULogicNetworkSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void NotifyAboutSignalChange(ALogicNetwork* Network);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsConnectedToLogicNetworkComponent(ULogicNetworkSimulationComponent* OtherLogicNetworkComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLogicNetworkState();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ALogicNetwork* GetLogicNetwork();
    
};

