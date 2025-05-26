#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "GridObjectMovementPresentationComponent.generated.h"

class UPositionSimulationComponent;
class UProjectilePresentationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UGridObjectMovementPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionSimulationComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UProjectilePresentationComponent> ProjectilePresentationComponent;
    
public:
    UGridObjectMovementPresentationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnGridPositionChanged(UPositionSimulationComponent* PositionComponent, FIntPoint LastGridPosition);
    
};

