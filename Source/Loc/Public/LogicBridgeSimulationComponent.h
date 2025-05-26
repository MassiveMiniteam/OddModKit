#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SimulationActorComponent.h"
#include "LogicBridgeSimulationComponent.generated.h"

class ALogicNetwork;
class ULogicConnectionSimulationComponent;
class ULogicInputSimulationComponent;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULogicBridgeSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference LogicInput1Ref;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference LogicInput2Ref;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPositionSimulationComponent* PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULogicInputSimulationComponent> LogicInput2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ALogicNetwork> MyNetwork;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint BridgedPos1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntPoint BridgedPos2;
    
public:
    ULogicBridgeSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void Unbridge();
    
    UFUNCTION(BlueprintCallable)
    void OnPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnNetworkTilesChanged(TArray<FIntPoint> Points);
    
    UFUNCTION(BlueprintCallable)
    void OnConnectionChanged(ULogicConnectionSimulationComponent* Connection);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool Bridge();
    
};

