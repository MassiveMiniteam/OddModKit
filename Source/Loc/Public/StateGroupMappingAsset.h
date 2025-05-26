#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Templates/SubclassOf.h"
#include "StateGroupMappingAsset.generated.h"

class UStateGroup;

UCLASS(Blueprintable)
class LOC_API UStateGroupMappingAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, TSubclassOf<UStateGroup>> StateGroupsNew;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTransitionToMostDesiredState_WhenAttackedWhileNotInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag TargetStateGroup_WhenAttackedWhileNotInCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag TargetStateGroup_WhenLeavingCombat;
    
    UStateGroupMappingAsset();

};

