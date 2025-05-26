#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Net/Core/Connection/NetEnums.h"
#include "EMyUserPrivileges.h"
#include "LocNetworkEventDelegate.h"
#include "LocNetworkingSubsystem.generated.h"

class UNetDriver;
class UWorld;

UCLASS(Blueprintable)
class LOCCORE_API ULocNetworkingSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SessionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bJoinSessionWhenInMainMenu;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EMyUserPrivileges> UserPrivileges;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentRoomCode;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocNetworkEvent OnLoginCompleted;
    
    ULocNetworkingSubsystem();

    UFUNCTION(BlueprintCallable)
    void UpdateSession(bool bAllowPresenceJoin);
    
    UFUNCTION(BlueprintCallable)
    void StopSession();
    
    UFUNCTION(BlueprintCallable)
    void StartSession(bool bAllowPresenceJoin);
    
    UFUNCTION(BlueprintCallable)
    void OpenURLInExternalUI(const FString& URL);
    
    UFUNCTION(BlueprintCallable)
    void OpenInviteUI();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPrivilegeCheckSuccessful();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnNetworkFailureEvent(UWorld* World, UNetDriver* NetDriver, TEnumAsByte<ENetworkFailure::Type> FailureType, const FString& ErrorString);
    
    UFUNCTION(BlueprintCallable)
    void JoinSessionWithRoomCode(const FString& RoomCode);
    
    UFUNCTION(BlueprintCallable)
    FString GetUniquePlayerIdAsString();
    
    UFUNCTION(BlueprintCallable)
    FString FetchUserID();
    
    UFUNCTION(BlueprintCallable)
    bool CanOpenInviteUI();
    
};

