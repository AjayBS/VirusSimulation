// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetBooleanValue.generated.h"

/**
 * 
 */
UCLASS()
class SIMULATION_API USetBooleanValue : public UBTTaskNode
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "TargetPoints")
	bool ToQuarantine = false;
};
