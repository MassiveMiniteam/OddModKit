#pragma once
#include "CoreMinimal.h"
#include "EDestructionReason.h"
#include "Fixed.h"
#include "ItemTransferSimulationComponent.h"
#include "ItemTransferActorPairSimulationComponent.generated.h"

class AGridObject;
class ASimulationActor;
class ASimulationPlayer;
class UConstructionAssemblySimulationComponent;
class UGridObjectPairSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UItemTransferActorPairSimulationComponent : public UItemTransferSimulationComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UGridObjectPairSimulationComponent> GridObjectPairComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UConstructionAssemblySimulationComponent> AssemblySimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UConstructionAssemblySimulationComponent> PairedAssemblySimulationComponent;
    
public:
    UItemTransferActorPairSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnRelatedGridObjectConnected(UGridObjectPairSimulationComponent* Component, AGridObject* GridObject);
    
    UFUNCTION(BlueprintCallable)
    void OnPairedSimulationActorShutdown(ASimulationActor* InSimulationActor, EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable)
    void OnPairedActorDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnDisassemble(UConstructionAssemblySimulationComponent* Component, ASimulationPlayer* ExecutingSimulationPlayer);
    
};

