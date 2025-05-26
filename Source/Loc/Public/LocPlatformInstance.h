#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LocPlatformInstance.generated.h"

class UProductEntitlementDataAsset;

UCLASS(Blueprintable)
class LOC_API ULocPlatformInstance : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UProductEntitlementDataAsset*> QueuedEntitlements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UProductEntitlementDataAsset*> AllEntitlementAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> EntitledIDS;
    
    ULocPlatformInstance();

};

