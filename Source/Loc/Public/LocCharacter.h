#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "LocCoreCharacter.h"
#include "OnCharacterTeleportStartedDelegate.h"
#include "Templates/SubclassOf.h"
#include "LocCharacter.generated.h"

class ASimulationActor;
class UDialogueConfig;
class UDialoguePlayerComponent;
class UPresentationActorComponent;

UCLASS(Blueprintable)
class LOC_API ALocCharacter : public ALocCoreCharacter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPresentationActorComponent*> PresentationActorComponents;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCharacterTeleportStarted OnCharacterTeleportStarted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravitiyScaleAtGameStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumZPositionToTeleport;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTeleporting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideLoadingScreenOnTeleportDone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeleportGroundCheckDelay;
    
public:
    ALocCharacter(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TeleportStartEffectEvent(FIntVector Location);
    
public:
    UFUNCTION(BlueprintCallable)
    void TeleportCharacterToTop();
    
    UFUNCTION(BlueprintCallable)
    void TeleportCharacterToPositionOnDialogueOver(UDialoguePlayerComponent* DialoguePlayerComponent, FVector position, FRotator Rotation);
    
    UFUNCTION(BlueprintCallable)
    void TeleportCharacterToClosestActorOfType(TSubclassOf<ASimulationActor> ActorClass, bool bShowLoadingScreen);
    
    UFUNCTION(BlueprintCallable)
    void TeleportCharacterTo(FVector position, FRotator Rotation, bool bSnapToTerrain, bool bShowLoadingScreen);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTeleportDone_Event(bool bWithLoadingScreen);
    
    UFUNCTION(BlueprintCallable)
    void OnTeleportDone();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDialoguePlayed(UDialoguePlayerComponent* DialoguePlayer, UDialogueConfig* Dialogue);
    
public:
    UFUNCTION(BlueprintCallable, Exec)
    void LocRestartRVT();
    
    UFUNCTION(BlueprintCallable)
    void EnableGravity();
    
    UFUNCTION(BlueprintCallable)
    void DisableMovementComponentReplication();
    
    UFUNCTION(BlueprintCallable)
    void DisableGravity();
    
};

