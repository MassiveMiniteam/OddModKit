#pragma once
#include "CoreMinimal.h"
#include "ComponentRegistrationSubsystem.h"
#include "BossTokenGeneratorSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UBossTokenGeneratorSubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
    UBossTokenGeneratorSubsystem();

};

