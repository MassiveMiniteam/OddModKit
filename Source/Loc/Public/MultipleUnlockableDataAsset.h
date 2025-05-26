#pragma once
#include "CoreMinimal.h"
#include "UnlockableDataAsset.h"
#include "MultipleUnlockableDataAsset.generated.h"

UCLASS(Blueprintable)
class LOC_API UMultipleUnlockableDataAsset : public UUnlockableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnlockableDataAsset*> UnlockableChilds;
    
    UMultipleUnlockableDataAsset();

};

