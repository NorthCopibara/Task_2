// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TMainScreen.generated.h"

UCLASS()
class TASK_2_API UTMainScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init(const TFunction<void(int32)> DoSpawn);
	
public:
	UFUNCTION(BlueprintCallable, Category = "Buttons")
	void OnClick_DoSpawn(int32 ButtonId);

private:
	TFunction<void(int32)> DoSpawnAction;
};
