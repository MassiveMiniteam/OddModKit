#pragma once
#include "CoreMinimal.h"
#include "ComponentRegistrationSubsystem.h"
#include "BlackBoardValidatorSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API UBlackBoardValidatorSubsystem : public UComponentRegistrationSubsystem {
    GENERATED_BODY()
public:
    UBlackBoardValidatorSubsystem();

};

