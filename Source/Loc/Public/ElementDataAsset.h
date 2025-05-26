#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "EElementInteractionBehavior.h"
#include "TagAndGameplayEffectClass.h"
#include "Templates/SubclassOf.h"
#include "ElementDataAsset.generated.h"

class UElementDataAsset;
class UGameplayEffect;

UCLASS(Blueprintable)
class LOC_API UElementDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UElementDataAsset*, EElementInteractionBehavior> ElementInteractions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EElementInteractionBehavior DefaultInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EElementInteractionBehavior SourceEqualTargetInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> DefaultGameplayEffectClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTagAndGameplayEffectClass> GameplayEffectClassOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredTagsOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ForbiddenTagsOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDecaysIfNotNaturalElement;
    
    UElementDataAsset();

};

