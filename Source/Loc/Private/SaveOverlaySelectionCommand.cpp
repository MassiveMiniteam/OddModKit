#include "SaveOverlaySelectionCommand.h"

USaveOverlaySelectionCommand::USaveOverlaySelectionCommand() {
    this->OverlaySelectionMemorizer = NULL;
    this->SelectedOverlayVisualizerClass = NULL;
    this->bIsVisible = false;
    this->bAllowOverlaySelection = false;
}


