#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Fixed.h"
#include "SimulationActorComponent.h"
#include "Fixed64.h"
#include "Fixed64Vector.h"
#include "EPositionPushbackType.h"
#include "GridPositionChangedEventDelegate.h"
#include "GridPositionOverlapEventDelegate.h"
#include "PositionChangedEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "PositionSimulationComponent.generated.h"

class UGridAreaRegistrationStrategy;
class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UPositionSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPositionChangedEvent OnPositionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridPositionChangedEvent OnGridPositionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGridPositionOverlapEvent OnGridPositionOverlapEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGridAreaRegistrationStrategy> GridAreaRegistrationStrategy;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FIntVector Position_Internal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Rotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPositionPushbackType PushbackType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bRegisteredOnPushbackSubSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CanBePushedByBitMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bCanBePushedBack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool UseRadiusOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 RadiusOverride;
    
public:
    UPositionSimulationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnregisterOnGrid();
    
    UFUNCTION(BlueprintCallable)
    void SetRotation(int32 NewRotation);
    
    UFUNCTION(BlueprintCallable)
    void SetRadiusOverride(int32 NewRadiusOverride);
    
    UFUNCTION(BlueprintCallable)
    void SetRadius(int32 InRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetPositionAndRotation(FIntVector NewPosition, int32 NewRotation);
    
    UFUNCTION(BlueprintCallable)
    void SetPosition(FIntVector NewPosition);
    
    UFUNCTION(BlueprintCallable)
    void SetEnablePushback(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetCanNotBePushedByMask(const TArray<EPositionPushbackType>& BitmaskEnums);
    
    UFUNCTION(BlueprintCallable)
    bool RotateTowardsPosition(const FIntVector& position, const FFixed& Angle);
    
    UFUNCTION(BlueprintCallable)
    bool RotateTowardsAngle(const FFixed& TargetRotation, const FFixed& Angle);
    
    UFUNCTION(BlueprintCallable)
    bool RotateTowards(const FIntVector& Direction, const FFixed& Angle);
    
    UFUNCTION(BlueprintCallable)
    void ResetRadiusOverride();
    
    UFUNCTION(BlueprintCallable)
    void RegisterOnGrid(bool bIsLoading);
    
    UFUNCTION(BlueprintCallable)
    bool IsOverlapping(UPositionSimulationComponent* Other);
    
    UFUNCTION(BlueprintCallable)
    bool IsAdvanceBlocked(const FIntVector& MovementDirection, FFixed64 Distance, bool bStopOnOccupiedTiles, int32 StopUpCliffHeight, const FGameplayTagContainer& BlockingTags);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetSignedRotationDeltaToPosition(const FIntVector& position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetSignedRotationDeltaTo(const FIntVector& Direction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetRotationDeltaToPosition(const FIntVector& position) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed GetRotationDeltaTo(const FIntVector& Direction) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPositionInFront(int32 ForwardDistance) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64Vector GetNormalizedDirectionTo(const UPositionSimulationComponent* Other, bool IgnoreCoordinateZ) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UGridAreaRegistrationStrategy* GetGridAreaRegistrationStrategyCDO() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64Vector GetForwardNormalized() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetForward(int32 Scale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetDistanceToPositionFFixed(const FIntVector& position, bool IgnoreCoordinateZ) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDistanceToPosition(const FIntVector& position, bool IgnoreCoordinateZ) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FFixed64 GetDistanceToGridPositionFFixed(const FIntPoint& Point) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDistanceTo(const UPositionSimulationComponent* Other, bool IgnoreCoordinateZ) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDistanceSquaredTo(const FIntVector& OtherPosition, bool IgnoreCoordinateZ) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDefaultRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DistanceToPositionIsLessThen(const FIntVector& position, int32 DistanceThreshold) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DistanceToPositionComponentIsLessThen(const UPositionSimulationComponent* Other, int32 DistanceThreshold) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector ConvertLocalPositionToGlobalPosition_WithRotation(FIntVector LocalPosition, int32 RotationIn) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector ConvertLocalPositionToGlobalPosition(FIntVector LocalPosition) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector ConvertLocalDirectionToGlobalDirection(FIntVector LocalDirection) const;
    
    UFUNCTION(BlueprintCallable)
    void ChangeRegistrationOnPushbackSubSystem(bool bEnablePushback);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBePushedBackAndIsRegistered() const;
    
    UFUNCTION(BlueprintCallable)
    bool Advance(const FIntVector& MovementDirection, FFixed Distance, bool bFindClosestWalkablePositionInLineTowardsTarget, bool bStopOnOccupiedTiles, int32 StopUpCliffHeight);
    
};

