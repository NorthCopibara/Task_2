// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TPlayerController.h"

#include "AI/TTargetPoint.h"
#include "Algo/ForEach.h"
#include "UI/THUD.h"


ATPlayerController::ATPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitInput();
	InitHUD();
	InitPool(SpawnPoints);
	InitPool(TargetPoints);
}

void ATPlayerController::InitInput()
{
	SetInputMode(FInputModeUIOnly());
	SetShowMouseCursor(true);
}

void ATPlayerController::InitHUD() const
{
	const auto HUD = CastChecked<ATHUD>(GetHUD());
	HUD->Init([&](const int32 Id)
	{
		ATSpawnPoint* SpawnPoint = *SpawnPoints.FindByPredicate([&Id](const ATSpawnPoint* InternalSpawnPoint)
		{
			return InternalSpawnPoint->GetSpawnPointId() == Id;
		});

		if (!SpawnPoint)
		{
			UE_LOG(LogTPlayerController, Error, TEXT("Spawn point not found"))
			return;
		}

		const auto AiCharacter = SpawnPoint->SpawnAiCharacter();
		if (!AiCharacter)
		{
			UE_LOG(LogTPlayerController, Error, TEXT("AI character not spawned"))
			return;
		}

		ATTargetPoint* TargetPoint = *TargetPoints.FindByPredicate([&Id](const ATTargetPoint* Point)
		{
			return Point->GetTargetPointId() == Id;
		});

		if (!TargetPoint)
		{
			UE_LOG(LogTPlayerController, Error, TEXT("Target point not found"))
			return;
		}

		AiCharacter->InitAiCharacter(TargetPoint);
	});
}