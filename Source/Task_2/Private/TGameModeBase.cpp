// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_2/Public/TGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ATGameModeBase::ATGameModeBase()
{
	HUDClass = ATHUD::StaticClass();
}

void ATGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	const auto HUD = GetHud();
	if(!HUD)
	{
		//TODO: error
		return;
	}
	
	HUD->Init([](int32 Id)
	{
		UE_LOG(LogTemp, Warning, TEXT("Test: %i"), Id);
	});

	const auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	auto Mode = FInputModeUIOnly();
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	
	PlayerController->SetInputMode(Mode);
	PlayerController->SetShowMouseCursor(true);
}

ATHUD* ATGameModeBase::GetHud() const
{
	const auto PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	const auto HUD = PlayerController->GetHUD();
	return Cast<ATHUD>(HUD);
}
