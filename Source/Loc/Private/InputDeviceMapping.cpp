#include "InputDeviceMapping.h"

UInputDeviceMapping::UInputDeviceMapping() {
    this->DeviceType = EInputDeviceType::None;
    this->DefaultTexture = NULL;
}

UTexture2D* UInputDeviceMapping::GetTextureForKey(FKey Key) {
    return NULL;
}

FInputKeySpriteMapping UInputDeviceMapping::GetSpriteMappingForSpecificKey(FInputActionKeyMapping KeyMapping, bool& bHasModifier, FInputKeySpriteMapping& ModifierSprite) {
    return FInputKeySpriteMapping{};
}

FInputKeySpriteMapping UInputDeviceMapping::GetSpriteMappingForInputAction(UInputActionData* InputAction, bool& bHasModifier, FInputKeySpriteMapping& ModifierSprite) {
    return FInputKeySpriteMapping{};
}

FInputKeySpriteMapping UInputDeviceMapping::GetModifierSpriteMapping(FInputActionKeyMapping KeyMapping) {
    return FInputKeySpriteMapping{};
}


