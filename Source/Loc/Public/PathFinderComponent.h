#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "PathFindingSettings.h"
#include "ProjectileParameters.h"
#include "PathFinderComponent.generated.h"

class UPathFindingRequest;
class UPositionSimulationComponent;
class UProjectileSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPathFinderComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProjectileSimulationComponent> ProjectileSimulationComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UPathFindingRequest* PathFindingRequest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> TargetPositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector TargetPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentCalculationDuration;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPathFindingSettings JumpSettings;
    
    UPathFinderComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetTargetByObject(UPositionSimulationComponent* NewTargetPositionComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetByCoordinates(const FIntVector& TargetCoordinates);
    
    UFUNCTION(BlueprintCallable)
    void ResetAllProperties();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnJumpCancelPathfinding(UProjectileSimulationComponent* ProjectileComponent, const FProjectileParameters& Parameters);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentlyCalculatingPath() const;
    
};

