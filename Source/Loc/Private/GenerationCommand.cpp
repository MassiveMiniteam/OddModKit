#include "GenerationCommand.h"

FGenerationCommand::FGenerationCommand() {
    this->Type = EGenerationCommandType::GenerateTile;
    this->Generator = NULL;
    this->Priority = 0;
    this->BiomeCellInstance = NULL;
    this->Chunk = NULL;
}

