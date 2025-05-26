#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ESaveCategory.h"
#include "SaveContainerBase.generated.h"

UCLASS(Blueprintable)
class USaveContainerBase : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FileEnding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESaveCategory ContainerCategory;
    
public:
    USaveContainerBase();

};

