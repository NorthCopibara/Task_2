// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/TSpawnPoint.h"
#include "AI/TTargetPoint.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "TPlayerController.generated.h"

DEFINE_LOG_CATEGORY_STATIC(LogTPlayerController, All, All);

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

	template<typename T>
	void InitPool(TArray<T*>& Pool)
	{
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(this, T::StaticClass(), Actors);

		for (const auto Actor : Actors)
		{
			const auto GameActor = Cast<T>(Actor);
			if(!GameActor) continue;
			Pool.Emplace(GameActor);
		}
	}

private:
	UPROPERTY(VisibleAnywhere, Category = "Game")
	TArray<ATSpawnPoint*> SpawnPoints;

	UPROPERTY(VisibleAnywhere, Category = "Game")
	TArray<ATTargetPoint*> TargetPoints;
};
