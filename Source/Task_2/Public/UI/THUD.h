// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widgets/TMainScreen.h"
#include "THUD.generated.h"

UCLASS()
class TASK_2_API ATHUD : public AHUD
{
	GENERATED_BODY()

public:
	void Init(const TFunction<void(int32)> DoSpawn) const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> MainScreenWidget;
};
