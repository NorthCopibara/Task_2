// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TAiController.h"

#include "AI/BehaviourState.h"
#include "AI/TAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogTAiController, All, All);

ATAiController::ATAiController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATAiController::MoveToTarget()
{
	const auto GameAiCharacter = CastChecked<ATAICharacter>(GetPawn());
	const auto BlackboardComponent = GetBlackboardComponent();
	if (!BlackboardComponent)
	{
		UE_LOG(LogTAiController, Error, TEXT("Blackboard component not found"));
		return;
	}

	const auto TargetPoint = GameAiCharacter->GetTargetPoint();
	if(!TargetPoint)
	{
		UE_LOG(LogTAiController, Error, TEXT("Target point not found"));
		return;
	}
	
	BlackboardComponent->SetValueAsVector(TargetPointKeyName, TargetPoint->GetActorLocation());
}

void ATAiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const auto GameAiCharacter = CastChecked<ATAICharacter>(InPawn);
	const auto BehaviourTree = GameAiCharacter->GetBehaviourTree();
	if (!BehaviourTree)
	{
		UE_LOG(LogTAiController, Error, TEXT("Behaviour tree not found"));
		return;
	}

	RunBehaviorTree(BehaviourTree);

	const auto BlackboardComponent = GetBlackboardComponent();
	if (!BlackboardComponent)
	{
		UE_LOG(LogTAiController, Error, TEXT("Blackboard component not found"));
		return;
	}

	BlackboardComponent->SetValueAsEnum(BehaviourStateKeyName, static_cast<uint8>(EBehaviourState::Idle));
}
