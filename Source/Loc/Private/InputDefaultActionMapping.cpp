#include "InputDefaultActionMapping.h"

UInputDefaultActionMapping::UInputDefaultActionMapping() {
    this->UIAccept = NULL;
    this->UICancel = NULL;
    this->UIMoveLeft = NULL;
    this->UIMoveRight = NULL;
    this->UIMoveUp = NULL;
    this->UIMoveDown = NULL;
    this->UIActionTop = NULL;
    this->UIActionLeft = NULL;
    this->UIActionTabLeft = NULL;
    this->UIActionTabRight = NULL;
    this->OnButtonClickSound = NULL;
    this->OnButtonHoverSound = NULL;
    this->OnHoldButtonStartedSound = NULL;
    this->OnHoldButtonClickSound = NULL;
    this->OnHoverForceFeedbackEffect = NULL;
    this->OnHoverAudioBasedVibration = NULL;
    this->OnClickForceFeedbackEffect = NULL;
    this->OnClickAudioBasedVibration = NULL;
}


