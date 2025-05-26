#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimulationActorComponent.h"
#include "EPathFindingRequestResult.h"
#include "PathCalculationEventDelegate.h"
#include "PathCalculatationComponent.generated.h"

class UPathFinderComponent;
class UPathFindingRequest;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathCalculatationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathCalculationEvent OnNewPathCalculated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FIntVector> CachedPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPathFinderComponent* PathFinderComponent;
    
public:
    UPathCalculatationComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION()
    void OnPathCalculated(UPathFinderComponent* InPathFinderComponent, EPathFindingRequestResult Result, UPathFindingRequest* Path, FIntVector TargetPosition);
    
public:
    UFUNCTION(BlueprintCallable)
    void CalculatePath(FIntVector TargetLocation);
    
};

