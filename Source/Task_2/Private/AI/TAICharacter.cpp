// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TAICharacter.h"
#include "AI/TAiController.h"


ATAICharacter::ATAICharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATAICharacter::InitAiCharacter(ATTargetPoint* NewTargetPoint)
{
	TargetPoint = NewTargetPoint;
	const auto AiController = CastChecked<ATAiController>(GetController());
	AiController->MoveToTarget();
}

UBehaviorTree* ATAICharacter::GetBehaviourTree() const
{
	return BehaviorTree;
}

ATTargetPoint* ATAICharacter::GetTargetPoint() const
{
	return TargetPoint;
}