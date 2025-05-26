#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TickBucketCollection.h"
#include "TickCollectionSubsystem.generated.h"

UCLASS(Blueprintable)
class LOCCORE_API UTickCollectionSubsystem : public UTickableWorldSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UClass*, FTickBucketCollection> TickableCollections;
    
public:
    UTickCollectionSubsystem();

};

