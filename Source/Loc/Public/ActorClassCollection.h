#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorClassCollection.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActorClassCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> Data;
    
    LOC_API FActorClassCollection();
};

