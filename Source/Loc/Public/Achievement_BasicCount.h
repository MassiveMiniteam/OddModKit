#pragma once
#include "CoreMinimal.h"
#include "Achievement.h"
#include "Achievement_BasicCount.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOC_API UAchievement_BasicCount : public UAchievement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NeededAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentAmount;
    
public:
    UAchievement_BasicCount();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void Add(UObject* WorldContext, int32 Amount);
    
};

