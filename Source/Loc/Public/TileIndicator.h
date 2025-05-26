#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileIndicator.generated.h"

UCLASS(Blueprintable)
class LOC_API ATileIndicator : public AActor {
    GENERATED_BODY()
public:
    ATileIndicator(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetValidState(bool bState);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAsInventoryConnector(bool bIsInput, float Roation);
    
};

