#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UIPlayerEntity.generated.h"

UCLASS(Blueprintable)
class LOC_API UUIPlayerEntity : public UObject {
    GENERATED_BODY()
public:
    UUIPlayerEntity();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPlayerControllerID() const;
    
};

