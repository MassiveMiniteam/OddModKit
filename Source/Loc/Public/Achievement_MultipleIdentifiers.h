#pragma once
#include "CoreMinimal.h"
#include "Achievement.h"
#include "Achievement_MultipleIdentifiers.generated.h"

class UObject;

UCLASS(Blueprintable)
class LOC_API UAchievement_MultipleIdentifiers : public UAchievement {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> NeededIdentifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FName> SeenIdentifiers;
    
public:
    UAchievement_MultipleIdentifiers();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    void AddIdentifier(UObject* WorldContext, FName Identifier);
    
};

