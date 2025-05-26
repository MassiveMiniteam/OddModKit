#pragma once
#include "CoreMinimal.h"
#include "GridNetworkManagerSubsystem.h"
#include "PathNetworkManagerSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UPathNetworkManagerSubsystem : public UGridNetworkManagerSubsystem {
    GENERATED_BODY()
public:
    UPathNetworkManagerSubsystem();

};

