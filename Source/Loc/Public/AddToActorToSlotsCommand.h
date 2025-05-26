#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "AddActorToSlotsCommand_DelegateDelegate.h"
#include "AddToActorToSlotsCommand.generated.h"

class ASimulationActor;
class UActorSlotsSimulationComponent;

UCLASS(Blueprintable)
class LOC_API UAddToActorToSlotsCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAddActorToSlotsCommand_Delegate OnAddActorToSlotsCommandExecuted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorSlotsSimulationComponent* SlotsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ASimulationActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bAddActor;
    
    UAddToActorToSlotsCommand();

};

