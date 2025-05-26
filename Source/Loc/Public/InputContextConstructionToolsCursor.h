#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ConstructionToolsCursorGridPositionEventDelegate.h"
#include "InputContext.h"
#include "Templates/SubclassOf.h"
#include "InputContextConstructionToolsCursor.generated.h"

class AActor;
class ASimulationActor;
class UInputContextSubsystem;
class UPrimitiveComponent;
class USimulationActorComponent;

UCLASS(Blueprintable)
class LOC_API UInputContextConstructionToolsCursor : public UInputContext {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInputContextSubsystem* InputContextSubsystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CursorActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> GridPositionAttachedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TEnumAsByte<EObjectTypeQuery>> ObjectQueryTypes;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConstructionToolsCursorGridPositionEvent OnGridPositionChanged;
    
    UInputContextConstructionToolsCursor();

    UFUNCTION(BlueprintCallable)
    AActor* SpawnCursorActor(TSubclassOf<AActor> CursorClass);
    
    UFUNCTION(BlueprintCallable)
    AActor* SpawnActorAttachedToGridPosition(TSubclassOf<AActor> GridIndicatorClass);
    
    UFUNCTION(BlueprintCallable)
    void SetObjectQueryTypes(const TArray<TEnumAsByte<EObjectTypeQuery>>& NewObjectQueryTypes);
    
    UFUNCTION(BlueprintCallable)
    void SetCursorPosition(const FVector& NewCursorPosition);
    
    UFUNCTION(BlueprintCallable)
    void SetCursorHeight(float NewHeight);
    
    UFUNCTION(BlueprintCallable)
    void RaycastCursorLocationToLandscape();
    
    UFUNCTION(BlueprintCallable)
    TArray<FIntPoint> GetTilesInDragArea(FIntPoint StartGridPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetMouseHitOrCursorPosition(float CursorSphereRadius) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetHoveredGridTileCenterPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetGridPositionAttachedActors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCursorPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntVector GetCursorGridPositionCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetCursorGridPosition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCursorActor() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<UPrimitiveComponent*> FindComponentsUnderMouseOrCursorPosition(float SphereOverlapRadius);
    
    UFUNCTION(BlueprintCallable)
    AActor* FindActorUnderMouseOrCursorPosition_BySimulationComponent(TSubclassOf<USimulationActorComponent> SimulationComponentClass, float SphereOverlapRadius);
    
    UFUNCTION(BlueprintCallable)
    AActor* FindActorUnderMouseOrCursorPosition_BySimulationClass(TSubclassOf<ASimulationActor> SimulationActorClass, float SphereOverlapRadius);
    
    UFUNCTION(BlueprintCallable)
    TArray<AActor*> FindActorsUnderMouseOrCursorPosition(float SphereOverlapRadius);
    
    UFUNCTION(BlueprintCallable)
    TArray<AActor*> FindActorsFromCameraSphereTraceToCursorPosition(float SphereOverlapRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* FindActorAttachedToGridPositionByClass(TSubclassOf<AActor> GridIndicatorClass) const;
    
    UFUNCTION(BlueprintCallable)
    void CalculateMinMaxForDragArea(FIntPoint StartGridPosition, FIntPoint& Out_Min, FIntPoint& Out_Max);
    
};

