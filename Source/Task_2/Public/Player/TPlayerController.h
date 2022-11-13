// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/TAICharacter.h"
#include "AI/TSpawnPoint.h"
#include "GameFramework/PlayerController.h"
#include "TPlayerController.generated.h"

UCLASS()
class TASK_2_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATPlayerController();

protected:
	virtual void BeginPlay() override;

private:
	void InitInput();
	void InitHUD() const;
	void InitSpawnPoints();

private:
	UPROPERTY(VisibleAnywhere, Category = "Game")
	TMap<int32, ATSpawnPoint*> SpawnPointsMap; 
};
