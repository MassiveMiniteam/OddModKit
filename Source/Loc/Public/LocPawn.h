#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PresentationObjectInterface.h"
#include "LocPawn.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API ALocPawn : public APawn, public IPresentationObjectInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> SimulationActor;
    
public:
    ALocPawn(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

