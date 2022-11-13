// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "UI/THUD.h"

DEFINE_LOG_CATEGORY_STATIC(LogTPlayerController, All, All);

ATPlayerController::ATPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitInput();
	InitHUD();
	InitSpawnPoints();
}

void ATPlayerController::InitInput()
{
	SetInputMode(FInputModeUIOnly());
	SetShowMouseCursor(true);
}

void ATPlayerController::InitHUD() const
{
	const auto HUD = Cast<ATHUD>(GetHUD());
	if (!HUD)
	{
		//TODO: error
		return;
	}

	HUD->Init([&](int32 Id)
	{
		if(SpawnPointsMap.Contains(Id)) {
			SpawnPointsMap[Id]->SpawnAiCharacter();
		}
	});
}

void ATPlayerController::InitSpawnPoints()
{
	TArray<AActor*> SpawnPointsActors;
	UGameplayStatics::GetAllActorsOfClass(this, ATSpawnPoint::StaticClass(), SpawnPointsActors);

	for (const auto SpawnPointActor : SpawnPointsActors)
	{
		const auto SpawnPoint = Cast<ATSpawnPoint>(SpawnPointActor);
		if(!SpawnPoint) continue;

		const auto SpawnPointId = SpawnPoint->GetSpawnPointId();
		SpawnPointsMap.Emplace(SpawnPointId, SpawnPoint);
		
		UE_LOG(LogTPlayerController, Display, TEXT("Spawn point %i added"), SpawnPointId);
	}
}
