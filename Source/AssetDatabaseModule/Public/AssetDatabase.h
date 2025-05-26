#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssetDatabase.generated.h"

UCLASS(Blueprintable)
class ASSETDATABASEMODULE_API UAssetDatabase : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, TWeakObjectPtr<UObject>> LoadedObjects;
    
public:
    UAssetDatabase();

};

