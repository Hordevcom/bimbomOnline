// Copyright Epic Games, Inc. All Rights Reserved.

#include "BimBomOnlineGameMode.h"
#include "BimBomOnlineCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABimBomOnlineGameMode::ABimBomOnlineGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
