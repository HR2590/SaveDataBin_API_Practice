// Copyright Epic Games, Inc. All Rights Reserved.

#include "APICommTestGameMode.h"
#include "APICommTestPlayerController.h"
#include "APICommTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAPICommTestGameMode::AAPICommTestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAPICommTestPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}