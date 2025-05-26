#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UnlockableUtilities.generated.h"

class UDataTable;
class UObject;

UCLASS(Blueprintable)
class LOC_API UUnlockableUtilities : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UUnlockableUtilities();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void UnlockAllFromShopTable(UObject* WorldContext, UDataTable* DataTable);
    
};

