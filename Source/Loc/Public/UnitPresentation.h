#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PresentationObjectInterface.h"
#include "UnitPresentation.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API AUnitPresentation : public APawn, public IPresentationObjectInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> SimulationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnSimulationActorNameIndexReplicated, meta=(AllowPrivateAccess=true))
    int32 SimulationActorNameIndex;
    
public:
    AUnitPresentation(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnSimulationActorNameIndexReplicated();
    

    // Fix for true pure virtual functions not being implemented
};

