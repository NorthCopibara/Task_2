// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TSpawnPoint.h"

DEFINE_LOG_CATEGORY_STATIC(LogTSpawnPoint, All, All);

ATSpawnPoint::ATSpawnPoint()
{
	PrimaryActorTick.bCanEverTick = false;
}

ATAICharacter* ATSpawnPoint::SpawnAiCharacter()
{
	check(GetWorld());
	
	const auto Character = GetWorld()->SpawnActor<ATAICharacter>(AiCharacter, GetActorLocation(), GetActorRotation());

	UE_LOG(LogTSpawnPoint, Display, TEXT("Ai character spawned"));
	
	//TODO: play spawn effect
	return Character;
}

