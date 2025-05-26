#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EDestructionReason.h"
#include "PresentationObjectInterface.generated.h"

class AActor;
class ASimulationActor;

UINTERFACE(Blueprintable)
class LOCCORE_API UPresentationObjectInterface : public UInterface {
    GENERATED_BODY()
};

class LOCCORE_API IPresentationObjectInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSimulationActor(ASimulationActor* InSimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationPreBegin(bool bIsLoading, ASimulationActor* InSimulationActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationEnd(EDestructionReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPresentationBegin(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ASimulationActor* GetSimulationActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* GetActor();
    
};

