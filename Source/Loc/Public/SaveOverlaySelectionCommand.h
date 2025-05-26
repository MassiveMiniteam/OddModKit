#pragma once
#include "CoreMinimal.h"
#include "SimulationCommand.h"
#include "Templates/SubclassOf.h"
#include "SaveOverlaySelectionCommand.generated.h"

class UOverlaySelectionMemorizerSimulationComponent;
class UOverlayVisualizationComponent;

UCLASS(Blueprintable)
class USaveOverlaySelectionCommand : public USimulationCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UOverlaySelectionMemorizerSimulationComponent* OverlaySelectionMemorizer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UOverlayVisualizationComponent> SelectedOverlayVisualizerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bAllowOverlaySelection;
    
    USaveOverlaySelectionCommand();

};

