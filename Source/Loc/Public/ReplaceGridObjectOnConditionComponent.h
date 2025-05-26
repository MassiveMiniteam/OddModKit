#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "ReplaceGridObjectComponent_EventDelegate.h"
#include "Templates/SubclassOf.h"
#include "ReplaceGridObjectOnConditionComponent.generated.h"

class AGridObject;
class ASimulationPlayer;
class UDialogueConfig;
class UUnlockableDataAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UReplaceGridObjectOnConditionComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReplaceGridObjectComponent_Event OnBeforeReplace;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* UnlockableCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAlternativeUnlockableInDemo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUnlockableDataAsset* AlternativeDemoUnlockableCondition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> OnReplaceUnlockables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* Dialogue_Success;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* Dialogue_Fail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAlternativeFailDialogue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogueConfig* Dialogue_AlternativeFail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGridObject> ReplacementClass;
    
public:
    UReplaceGridObjectOnConditionComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void TriggerReplacement(ASimulationPlayer* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanTriggerReplacement();
    
};

