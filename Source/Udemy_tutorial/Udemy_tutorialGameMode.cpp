// Copyright Epic Games, Inc. All Rights Reserved.

#include "Udemy_tutorialGameMode.h"
#include "Udemy_tutorialCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "SandboxPown.h"

AUdemy_tutorialGameMode::AUdemy_tutorialGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		//записать в заметки
		DefaultPawnClass = ASandboxPown::StaticClass();
	}
}
