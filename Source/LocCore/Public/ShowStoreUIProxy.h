#pragma once
#include "CoreMinimal.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "ShowStoreUIProxy.generated.h"

class UShowStoreUIProxy;

UCLASS(Blueprintable)
class LOCCORE_API UShowStoreUIProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate onSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate onFailure;
    
    UShowStoreUIProxy();

    UFUNCTION(BlueprintCallable)
    static UShowStoreUIProxy* ShowStoreUI(const FString& ProductId);
    
};

