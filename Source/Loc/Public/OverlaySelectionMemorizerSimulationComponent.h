#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "OverlaySelectionMemorizerEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "OverlaySelectionMemorizerSimulationComponent.generated.h"

class UOverlayVisualizationComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API UOverlaySelectionMemorizerSimulationComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOverlaySelectionMemorizerEvent OnOverlaySelectionSet;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UOverlayVisualizationComponent> SelectedOverlayVisualizerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bAllowOverlaySelection;
    
public:
    UOverlaySelectionMemorizerSimulationComponent(const FObjectInitializer& ObjectInitializer);

};

