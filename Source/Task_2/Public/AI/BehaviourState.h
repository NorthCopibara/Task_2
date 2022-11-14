#pragma once

#include "BehaviourState.generated.h"

UENUM(BlueprintType)
enum class EBehaviourState : uint8
{
	Idle,
	MoveToTarget
};
