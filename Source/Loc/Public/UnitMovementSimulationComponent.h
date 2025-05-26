#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "EMovementEndResult.h"
#include "EMovementSetupResult.h"
#include "EPathFindingRequestResult.h"
#include "OnCurrentPathChangedDelegate.h"
#include "OnMovementFinishedDelegate.h"
#include "OnTeleportDelegate.h"
#include "UnitMovementConditionDelegateDelegate.h"
#include "UnitMovementSimulationComponent.generated.h"

class UDifficultySettingsSubsystem;
class UPathFinderComponent;
class UPathFindingRequest;
class UPositionSimulationComponent;
class UProjectileSimulationComponent;
class UStatsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UUnitMovementSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMovementFinished OnMovementFinished;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCurrentPathChanged OnCurrentPathChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUnitMovementConditionDelegate OnTryTeleport;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTeleport OnBeforeTeleport;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTeleport OnAfterTeleport;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPathFinderComponent> PathFinderComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStatsComponent> StatsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProjectileSimulationComponent> ProjectileComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UPathFindingRequest* CurrentPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentPathTargetIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 LastPathTargetIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentMovementSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed CurrentRotationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector CurrentPathTargetPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NewRequestedAcceptanceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentAcceptanceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bPositionOrRotationUpdatedLastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FFixed SecondsNotMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector PositionLastFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 RotationLastFrame;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFixed JumpProjectileDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTeleportIfNoPathFound;
    
public:
    UUnitMovementSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StopMovement(EMovementEndResult Reason);
    
    UFUNCTION(BlueprintCallable)
    EMovementSetupResult SetTargetByObject(UPositionSimulationComponent* NewTargetPositionComponent, int32 AcceptanceRadius);
    
    UFUNCTION(BlueprintCallable)
    EMovementSetupResult SetTargetByCoordinates(const FIntVector& TargetCoordinates, int32 AcceptanceRadius);
    
private:
    UFUNCTION()
    void OnNewPathFindingRequestCompleted(UPathFinderComponent* PathFinderComp, EPathFindingRequestResult Result, UPathFindingRequest* Path, FIntVector TargetPosition);
    
    UFUNCTION(BlueprintCallable)
    void OnGameplayTagChanged(UStatsComponent* StatsComp, FGameplayTag Tag, FFixed OldValue, FFixed NewValue);
    
    UFUNCTION(BlueprintCallable)
    void OnDifficultySettingsChanged(UDifficultySettingsSubsystem* Subsystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRotationDifferenceToLastFrame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPositionDifferenceToLastFrame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentRotationSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetCurrentMovementSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CurrentPathIsValid() const;
    
};

