// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Task_2/Public/UI/THUD.h"
#include "TGameModeBase.generated.h"

UCLASS()
class TASK_2_API ATGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATGameModeBase();

	virtual void BeginPlay() override;

private:
	ATHUD* GetHud() const;
};
