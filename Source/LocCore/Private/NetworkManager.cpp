#include "NetworkManager.h"

ANetworkManager::ANetworkManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
}

void ANetworkManager::MulticastHandlePlayerJoin_Implementation(bool bReenableSendOut) {
}


