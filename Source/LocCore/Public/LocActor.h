#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocActor.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API ALocActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 NameIndex;
    
    ALocActor(const FObjectInitializer& ObjectInitializer);

};

