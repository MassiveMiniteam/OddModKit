#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LocPlayerId.h"
#include "PresentationObjectInterface.h"
#include "LocCoreCharacter.generated.h"

class ASimulationActor;
class UCameraComponent;
class USpringArmComponent;

UCLASS(Blueprintable)
class LOCCORE_API ALocCoreCharacter : public ACharacter, public IPresentationObjectInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASimulationActor> SimulationActor;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnLocPlayerIdReplicated, meta=(AllowPrivateAccess=true))
    FLocPlayerId LocPlayerId;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* TopDownCameraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringArmComponent* CameraBoom;
    
public:
    ALocCoreCharacter(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetLocPlayerId(FLocPlayerId LocalPlayerId);
    
    UFUNCTION(BlueprintCallable)
    void OnLocPlayerIdReplicated();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetLocPlayerId(FLocPlayerId LocalPlayerId);
    

    // Fix for true pure virtual functions not being implemented
};

