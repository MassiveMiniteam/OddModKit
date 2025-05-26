#include "LocNetworkingSubsystem.h"

ULocNetworkingSubsystem::ULocNetworkingSubsystem() {
    this->SessionName = TEXT("GameSession");
    this->bJoinSessionWhenInMainMenu = false;
}

void ULocNetworkingSubsystem::UpdateSession(bool bAllowPresenceJoin) {
}

void ULocNetworkingSubsystem::StopSession() {
}

void ULocNetworkingSubsystem::StartSession(bool bAllowPresenceJoin) {
}

void ULocNetworkingSubsystem::OpenURLInExternalUI(const FString& URL) {
}

void ULocNetworkingSubsystem::OpenInviteUI() {
}

void ULocNetworkingSubsystem::OnPrivilegeCheckSuccessful() {
}

void ULocNetworkingSubsystem::OnNetworkFailureEvent(UWorld* World, UNetDriver* NetDriver, TEnumAsByte<ENetworkFailure::Type> FailureType, const FString& ErrorString) {
}

void ULocNetworkingSubsystem::JoinSessionWithRoomCode(const FString& RoomCode) {
}

FString ULocNetworkingSubsystem::GetUniquePlayerIdAsString() {
    return TEXT("");
}

FString ULocNetworkingSubsystem::FetchUserID() {
    return TEXT("");
}

bool ULocNetworkingSubsystem::CanOpenInviteUI() {
    return false;
}


