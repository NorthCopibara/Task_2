// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_2/Public/UI/Widgets/TMainScreen.h"

void UTMainScreen::Init(const TFunction<void(int32)> DoSpawn)
{
	DoSpawnAction = DoSpawn;
}

void UTMainScreen::OnClick_DoSpawn(int32 ButtonId)
{
	DoSpawnAction.CheckCallable();
	DoSpawnAction(ButtonId);
}
