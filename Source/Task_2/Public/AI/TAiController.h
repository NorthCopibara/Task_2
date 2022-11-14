// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TAiController.generated.h"

UCLASS()
class TASK_2_API ATAiController : public AAIController
{
	GENERATED_BODY()

public:
	ATAiController();

	void MoveToTarget();
	
protected:
	virtual void OnPossess(APawn* InPawn) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	FName BehaviourStateKeyName = "BehaviourState";
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	FName TargetPointKeyName = "TargetPoint";
};
