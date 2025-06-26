#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemStackData.h"
#include "ItemStackData_GameplayTagContainer.generated.h"

UCLASS(Blueprintable)
class LOC_API UItemStackData_GameplayTagContainer : public UItemStackData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UItemStackData_GameplayTagContainer();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGameplayTagContainer GetTags() const;
    
};

