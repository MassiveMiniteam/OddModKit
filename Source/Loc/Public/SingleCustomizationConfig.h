#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterCustomizationPart.h"
#include "SingleCustomizationConfig.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class LOC_API USingleCustomizationConfig : public UDataAsset {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* TargetDataTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterCustomizationPart Part;
    
public:
    USingleCustomizationConfig();

    UFUNCTION(BlueprintCallable)
    void Unload();
    
    UFUNCTION(BlueprintCallable)
    void Load();
    
};

