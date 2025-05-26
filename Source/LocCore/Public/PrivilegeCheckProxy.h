#pragma once
#include "CoreMinimal.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "EMyUserPrivileges.h"
#include "PrivilegeCheckProxy.generated.h"

class UPrivilegeCheckProxy;

UCLASS(Blueprintable)
class LOCCORE_API UPrivilegeCheckProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSuccess_BP;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnFailure_BP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EMyUserPrivileges> MyPrivilegesToCheck;
    
    UPrivilegeCheckProxy();

    UFUNCTION(BlueprintCallable)
    static UPrivilegeCheckProxy* CheckUserPrivileges(TArray<EMyUserPrivileges> PrivilegesToCheck, int32 ControllerId);
    
};

