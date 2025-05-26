#include "LocSaveGameLoadOperation.h"

FLocSaveGameLoadOperation::FLocSaveGameLoadOperation() {
    this->bIsCompatibleVersion = false;
    this->EditorSaveUnixTime = 0;
    this->bIsEditorVersion = false;
    this->CheckinNumber = 0;
    this->GenerationVersion = 0;
    this->bIsDemo = false;
}

