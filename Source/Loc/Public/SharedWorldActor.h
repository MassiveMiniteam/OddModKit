#pragma once
#include "CoreMinimal.h"
#include "LocCoreSavable.h"
#include "SimulationActor.h"
#include "SharedWorldActor.generated.h"

class AActor;
class USimulationCommand;
class UUnlockHandlingSimulationComponent;

UCLASS(Blueprintable)
class LOC_API ASharedWorldActor : public ASimulationActor, public ILocCoreSavable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideOutlineAndHover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* VisualLoggerActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUnlockHandlingSimulationComponent* UnlockHandlingComponent;
    
public:
    ASharedWorldActor(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnRunCommand(USimulationCommand* Command);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UUnlockHandlingSimulationComponent* GetUnlockHandlingComponent();
    
protected:
    UFUNCTION(BlueprintCallable)
    FString GetBuildingCountsAsString();
    

    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION()
    void OnAllSaveGameActorsLoadedAndRegistered() override PURE_VIRTUAL(OnAllSaveGameActorsLoadedAndRegistered,);
    
};

