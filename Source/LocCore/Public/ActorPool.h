#pragma once
#include "CoreMinimal.h"
#include "ActorArray.h"
#include "ActorPool.generated.h"

class AActor;
class UWorld;

USTRUCT(BlueprintType)
struct LOCCORE_API FActorPool {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AActor>, FActorArray> Pool;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetActor;
    
    FActorPool();
};

