#pragma once
#include "CoreMinimal.h"
#include "GridNetwork.h"
#include "WaterNetwork.generated.h"

UCLASS(Blueprintable)
class AWaterNetwork : public AGridNetwork {
    GENERATED_BODY()
public:
    AWaterNetwork(const FObjectInitializer& ObjectInitializer);

};

