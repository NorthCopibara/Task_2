// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TAICharacter.h"
#include "GameFramework/Actor.h"
#include "TSpawnPoint.generated.h"

UCLASS()
class TASK_2_API ATSpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	ATSpawnPoint();

	int32 GetSpawnPointId() const { return SpawnPointId; }

	ATAICharacter* SpawnAiCharacter();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 SpawnPointId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	TSubclassOf<ATAICharacter> AiCharacter;
};
