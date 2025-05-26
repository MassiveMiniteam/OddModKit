#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MinionConfigTagPair.h"
#include "MinionControllerPresentationLibrary.generated.h"

class ASimulationActor;
class UMinionControllerSimulationBaseComponent;

UCLASS(Blueprintable)
class UMinionControllerPresentationLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UMinionControllerPresentationLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<ASimulationActor*> GetThrowableDeployedMinions(const UMinionControllerSimulationBaseComponent* Controller, int32 ControlGroupIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetThrowableDeployedMinionCount(const UMinionControllerSimulationBaseComponent* Controller, int32 MinionSlotIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ASimulationActor* GetNextDeployedAndThrowableMinion(UMinionControllerSimulationBaseComponent* Controller, FMinionConfigTagPair ConfigTagPair);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<ASimulationActor*> GetAllThrowableDeployedMinions(const UMinionControllerSimulationBaseComponent* Controller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreAllMinionsThrowable(const UMinionControllerSimulationBaseComponent* Controller);
    
};

