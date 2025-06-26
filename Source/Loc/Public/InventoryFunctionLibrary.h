#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ItemStack.h"
#include "InventoryFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class LOC_API UInventoryFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UInventoryFunctionLibrary();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsValidStack(const FItemStack& ItemStack);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSameStack(const FItemStack& ItemStackA, const FItemStack& ItemStackB);
    
};

