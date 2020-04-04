// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SocializingGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMULATION_API ASocializingGameMode : public AGameMode
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
};
