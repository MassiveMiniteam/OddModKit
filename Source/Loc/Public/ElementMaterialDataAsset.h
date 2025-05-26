#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "ElementMaterialDataAsset.generated.h"

class UElementDataAsset;
class UGameplayEffect;

UCLASS(Blueprintable)
class LOC_API UElementMaterialDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UElementDataAsset*> ElementsThatCanBeApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementDataAsset* NaturalElement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameplayEffect> InitialGameplayEffect;
    
    UElementMaterialDataAsset();

};

