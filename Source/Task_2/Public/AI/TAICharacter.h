// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TTargetPoint.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "TAICharacter.generated.h"

UCLASS()
class TASK_2_API ATAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATAICharacter();

	void SetTargetPoint(ATTargetPoint* NewTargetPoint) { TargetPoint = NewTargetPoint; }

	UBehaviorTree* GetBehaviourTree() const;
	
	UFUNCTION(BlueprintGetter, Category = "Game")
	ATTargetPoint* GetTargetPoint() const;

	void MoveToTarget() const;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTree;

private:
	UPROPERTY(BlueprintGetter=GetTargetPoint)
	ATTargetPoint* TargetPoint = nullptr;
};
