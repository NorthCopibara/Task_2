// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTargetPoint.generated.h"

UCLASS()
class TASK_2_API ATTargetPoint : public AActor
{
	GENERATED_BODY()

public:
	ATTargetPoint();

	int32 GetTargetPointId() const { return TargetPointId; }
	
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	int32 TargetPointId;
};
