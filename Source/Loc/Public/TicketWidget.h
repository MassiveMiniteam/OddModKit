#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TicketWidget.generated.h"

class UButton;
class UTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class LOC_API UTicketWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UserTicketEmail;
    
public:
    UTicketWidget();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetUserData(FString& ReturnName, FString& ReturnMail, FString& ReturnMessage);
    
    UFUNCTION(BlueprintCallable)
    void CheckUserEmail(FText InputMail, FText InputName, FText InputMessage, UTextBlock* EmailTextBlock, UTextBlock* NameTextBlock, UTextBlock* MessageTextBlock, UButton* SendTicket);
    
};

