// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TAICharacter.h"
#include "AI/TAiController.h"


ATAICharacter::ATAICharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

UBehaviorTree* ATAICharacter::GetBehaviourTree() const
{
	check(BehaviorTree)
	return BehaviorTree;
}

ATTargetPoint* ATAICharacter::GetTargetPoint() const
{
	check(TargetPoint);
	return TargetPoint;
}

void ATAICharacter::MoveToTarget() const
{
	const auto AiController = CastChecked<ATAiController>(GetController());
	AiController->MoveToTarget();
}
