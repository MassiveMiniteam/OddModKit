#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "HostilitySimulationComponentIntEventDelegate.h"
#include "RegisteredSimulationComponent.h"
#include "HostilityRadiusSimulationComponent.generated.h"

class UTimedTargetDetectorSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UHostilityRadiusSimulationComponent : public URegisteredSimulationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHostilitySimulationComponentIntEvent OnHostilityLevelSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HostilityLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TimedTargetDetectorReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimedTargetDetectorSimulationComponent* TimedTargetDetector;
    
public:
    UHostilityRadiusSimulationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void SetHostilityLevel(int32 NewHostilityLevel);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetHostilityLevel() const;
    
};

