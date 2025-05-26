#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "LocActor.h"
#include "PresentationActorEventDelegate.h"
#include "PresentationActorSimulationActorAssignedEventDelegate.h"
#include "PresentationBeginActorEventDelegate.h"
#include "PresentationObjectInterface.h"
#include "PresentationActor.generated.h"

class ASimulationActor;

UCLASS(Blueprintable)
class LOCCORE_API APresentationActor : public ALocActor, public IPresentationObjectInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> SimulationActor;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPresentationBeginActorEvent OnPresentationBeginEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPresentationActorEvent OnPresentationEndEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPresentationActorSimulationActorAssignedEvent OnSimulationActorAssigned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bSaveActor;
    
    APresentationActor(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

