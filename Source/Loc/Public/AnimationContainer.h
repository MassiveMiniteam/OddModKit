#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimationContainer.generated.h"

class UAnimMontage;

UCLASS(Blueprintable)
class LOC_API UAnimationContainer : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAnimMontage>> AnimationMontages;
    
    UAnimationContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDuration() const;
    
};

