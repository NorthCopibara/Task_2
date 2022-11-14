// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TAiController.h"

#include "AI/BehaviourState.h"
#include "AI/TAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


ATAiController::ATAiController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATAiController::MoveToTarget()
{
	const auto GameAiCharacter = CastChecked<ATAICharacter>(GetPawn());
	const auto BlackboardComponent = GetBlackboardComponent();
	if (!BlackboardComponent) return; //TODO: log
	BlackboardComponent->SetValueAsVector(TargetPointKeyName, GameAiCharacter->GetTargetPoint()->GetActorLocation());
}

void ATAiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const auto GameAiCharacter = CastChecked<ATAICharacter>(InPawn);
	const auto BehaviourTree = GameAiCharacter->GetBehaviourTree();
	if (!BehaviourTree)
	{
		//TODO: log
		return;
	}

	RunBehaviorTree(BehaviourTree);

	const auto BlackboardComponent = GetBlackboardComponent();
	if (!BlackboardComponent) return; //TODO: log

	BlackboardComponent->SetValueAsEnum(BehaviourStateKeyName, static_cast<uint8>(EBehaviourState::Idle));
}
