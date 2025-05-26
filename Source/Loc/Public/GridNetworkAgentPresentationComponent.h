#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "SpaceTimePosition.h"
#include "GridNetworkAgentPresentationComponent.generated.h"

class UStatsComponent;
class USubGridMovementSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridNetworkAgentPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrthogonalOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowPitchRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PositionOffset;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USubGridMovementSimulationComponent> SubGridMovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSpaceTimePosition> PositionHistory;
    
public:
    UGridNetworkAgentPresentationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnSimulationSubGridPositionChanged(USubGridMovementSimulationComponent* Component);
    
};

