#pragma once
#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "OnNoteIndexChangedDelegate.h"
#include "OnPlayMusicNoteDelegate.h"
#include "PathAddOnSimulationComponent.h"
#include "PathAddOn_PlayMusicNote_SimulationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathAddOn_PlayMusicNote_SimulationComponent : public UPathAddOnSimulationComponent, public IInteractionInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayMusicNote OnPlayMusicNote;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNoteIndexChanged OnNoteIndexChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NoteIndex;
    
    UPathAddOn_PlayMusicNote_SimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void Interact_Implementation();
    

    // Fix for true pure virtual functions not being implemented
};

