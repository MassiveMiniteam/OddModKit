#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PresentationActorComponent.h"
#include "OnSimulationPositionUpdatedDelegate.h"
#include "StaticPositionPresentationComponent.generated.h"

class UPositionSimulationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UStaticPositionPresentationComponent : public UPresentationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPositionSimulationComponent> PositionComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSimulationPositionUpdated OnSimulationPositionUpdated;
    
    UStaticPositionPresentationComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnPositionChanged(UPositionSimulationComponent* InPositionComponent, FIntVector LastPosition);
    
};

