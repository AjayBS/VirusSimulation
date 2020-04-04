// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTeleportNode.generated.h"

/**
 * 
 */
UCLASS()
class SIMULATION_API UBTTeleportNode : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
