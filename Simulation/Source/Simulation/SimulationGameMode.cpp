// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SimulationGameMode.h"
#include "SimulationPlayerController.h"
#include "SimulationCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimulationGameMode::ASimulationGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASimulationPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}