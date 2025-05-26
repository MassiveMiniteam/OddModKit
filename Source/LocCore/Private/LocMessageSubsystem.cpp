#include "LocMessageSubsystem.h"

ULocMessageSubsystem::ULocMessageSubsystem() {
    this->bIsShowing = false;
}

void ULocMessageSubsystem::Open(UObject* WorldContext, TEnumAsByte<EAppMsgType::Type> MessageType, const FText& Title, const FText& Message, float Delay) {
}

void ULocMessageSubsystem::MessageHasBeenProccessed() {
}


