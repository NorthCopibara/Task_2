// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_2/Public/TGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Player/TPlayerController.h"
#include "UI/THUD.h"

ATGameModeBase::ATGameModeBase()
{
	HUDClass = ATHUD::StaticClass();
	PlayerControllerClass = ATPlayerController::StaticClass();
}
