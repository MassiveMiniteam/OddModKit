#pragma once
#include "CoreMinimal.h"
#include "SaveContainerBase.h"
#include "LoadContainer.generated.h"

UCLASS(Blueprintable)
class ULoadContainer : public USaveContainerBase {
    GENERATED_BODY()
public:
    ULoadContainer();

};

