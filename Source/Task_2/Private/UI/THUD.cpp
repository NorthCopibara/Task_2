// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_2/Public/UI/THUD.h"

void ATHUD::Init(const TFunction<void(int32)> DoSpawn) const
{
	check(GetWorld());

	const auto MainScreen = CreateWidget<UTMainScreen>(GetWorld(), MainScreenWidget);
	MainScreen->AddToViewport();
	MainScreen->Init(DoSpawn);
}
