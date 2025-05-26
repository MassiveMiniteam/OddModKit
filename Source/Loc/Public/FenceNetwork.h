#pragma once
#include "CoreMinimal.h"
#include "GridNetwork.h"
#include "FenceNetwork.generated.h"

UCLASS(Blueprintable)
class AFenceNetwork : public AGridNetwork {
    GENERATED_BODY()
public:
    AFenceNetwork(const FObjectInitializer& ObjectInitializer);

};

