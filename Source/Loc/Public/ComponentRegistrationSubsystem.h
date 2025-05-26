#pragma once
#include "CoreMinimal.h"
#include "LocSimulationSubsystem.h"
#include "RegistrationSubsystemEventDelegate.h"
#include "RegistrationSubsystem_WithComponent_EventDelegate.h"
#include "ComponentRegistrationSubsystem.generated.h"

class URegisteredSimulationComponent;

UCLASS(Abstract, Blueprintable)
class LOC_API UComponentRegistrationSubsystem : public ULocSimulationSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegistrationSubsystemEvent OnRegisteredComponentsArrayChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegistrationSubsystem_WithComponent_Event OnComponentRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRegistrationSubsystem_WithComponent_Event OnComponentUnRegistered;
    
protected:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<URegisteredSimulationComponent>> RegisteredComponents;
    
public:
    UComponentRegistrationSubsystem();

    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    TArray<URegisteredSimulationComponent*> GetRegisteredComponents() const;
    
};

