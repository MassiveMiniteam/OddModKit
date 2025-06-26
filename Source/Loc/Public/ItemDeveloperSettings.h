#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "ItemDeveloperSettings.generated.h"

class UItemConfig;

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class LOC_API UItemDeveloperSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, TSoftObjectPtr<UItemConfig>> GameplayTagToItemMapping;
    
public:
    UItemDeveloperSettings();

    UFUNCTION(BlueprintCallable)
    static FGameplayTag GetTagForItemConfig(UItemConfig* ItemConfig);
    
    UFUNCTION(BlueprintCallable)
    static UItemConfig* GetItemConfigForTag(FGameplayTag Tag);
    
};

