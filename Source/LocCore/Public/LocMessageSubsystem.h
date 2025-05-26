#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Message.h"
#include "LocMessageSubsystem.generated.h"

class UObject;
class UUserWidget;

UCLASS(Blueprintable)
class LOCCORE_API ULocMessageSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMessage> Messages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UUserWidget> ActiveDialogMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsShowing;
    
    ULocMessageSubsystem();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void Open(UObject* WorldContext, TEnumAsByte<EAppMsgType::Type> MessageType, const FText& Title, const FText& Message, float Delay);
    
    UFUNCTION(BlueprintCallable)
    void MessageHasBeenProccessed();
    
};

