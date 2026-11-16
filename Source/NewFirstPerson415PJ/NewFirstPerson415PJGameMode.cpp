// Copyright Epic Games, Inc. All Rights Reserved.

#include "NewFirstPerson415PJGameMode.h"
#include "NewFirstPerson415PJCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANewFirstPerson415PJGameMode::ANewFirstPerson415PJGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
