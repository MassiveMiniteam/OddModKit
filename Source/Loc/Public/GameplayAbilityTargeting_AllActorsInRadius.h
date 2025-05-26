#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayAbilityTargeting.h"
#include "Templates/SubclassOf.h"
#include "GameplayAbilityTargeting_AllActorsInRadius.generated.h"

class AActor;
class ASimulationActor;

UCLASS(Blueprintable)
class LOC_API UGameplayAbilityTargeting_AllActorsInRadius : public UGameplayAbilityTargeting {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AddOwnRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIntVector LocalPositionOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ASimulationActor>> ClassFilter;
    
public:
    UGameplayAbilityTargeting_AllActorsInRadius();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetTargetLocationAndRadius(const AActor* AbilityUser, FIntVector& LocationOut, int32& RadiusOut) const;
    
};

