#pragma once
#include "CoreMinimal.h"
#include "Engine/Channel.h"
#include "LocCoreNetChannel.generated.h"

UCLASS(Blueprintable, NonTransient)
class LOCCORE_API ULocCoreNetChannel : public UChannel {
    GENERATED_BODY()
public:
    ULocCoreNetChannel();

};

