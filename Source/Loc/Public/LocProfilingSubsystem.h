#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WorldGeneratorProfilerDelegateDelegate.h"
#include "LocProfilingSubsystem.generated.h"

UCLASS(Blueprintable)
class LOC_API ULocProfilingSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldGeneratorProfilerDelegate ProfilerDelegate;
    
    ULocProfilingSubsystem();

};

