#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ModManifest.h"
#include "ModInstance.generated.h"

class UModBase;
class UTexture2D;

UCLASS(Blueprintable)
class LOC_API UModInstance : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModManifest Manifest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModBase* ModBaseInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UModInstance();

    UFUNCTION(BlueprintCallable)
    bool IsCompatibleWithGameVersion(const FString& GameVersion);
    
    UFUNCTION(BlueprintCallable)
    FString GetSummaryString();
    
};

