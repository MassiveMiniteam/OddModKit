#pragma once
#include "CoreMinimal.h"
#include "SaveContainerBase.h"
#include "LoadBytesContainer.generated.h"

UCLASS(Blueprintable)
class ULoadBytesContainer : public USaveContainerBase {
    GENERATED_BODY()
public:
    ULoadBytesContainer();

};

