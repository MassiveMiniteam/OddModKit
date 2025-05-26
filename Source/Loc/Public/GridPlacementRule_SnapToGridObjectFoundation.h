#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GridPlacementRuleConfig.h"
#include "PlacementRuleParameter.h"
#include "Templates/SubclassOf.h"
#include "GridPlacementRule_SnapToGridObjectFoundation.generated.h"

class AActor;
class AGridObject;

UCLASS(Blueprintable)
class LOC_API UGridPlacementRule_SnapToGridObjectFoundation : public UGridPlacementRuleConfig {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> WhiteListClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ForbiddenTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AGridObject>> GridObjectTypes;
    
public:
    UGridPlacementRule_SnapToGridObjectFoundation();

protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTileAvailableAsAdditionalTile(FPlacementRuleParameter& PlacementRuleParameter, TArray<AGridObject*> GridObjectsOnTile, AActor* FoundActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOfMatchingType(AGridObject* GridObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsClassWhitelisted(UClass* Class);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreActorsWhitelistedOrIgnored(const TArray<AGridObject*>& GridObjectsOnTile, AActor*& IgnoreActor);
    
};

