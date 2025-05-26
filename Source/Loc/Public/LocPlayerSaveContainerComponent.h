#pragma once
#include "CoreMinimal.h"
#include "SimulationActorComponent.h"
#include "LocPlayerSaveContainerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class LOC_API ULocPlayerSaveContainerComponent : public USimulationActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint8> SaveData;
    
    ULocPlayerSaveContainerComponent(const FObjectInitializer& ObjectInitializer);

};

