#pragma once
#include "CoreMinimal.h"
#include "ComponentRegistrationSubsystem.h"
#include "MapIconSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UMapIconSubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
    UMapIconSubsystem();

};

