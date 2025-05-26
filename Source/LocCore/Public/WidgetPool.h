#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "WidgetArray.h"
#include "WidgetPool.generated.h"

class UUserWidget;
class UWorld;

USTRUCT(BlueprintType)
struct LOCCORE_API FWidgetPool {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UUserWidget>, FWidgetArray> Pool;
    
public:
    FWidgetPool();
};

