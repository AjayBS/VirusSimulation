// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UGameManager.generated.h"

/**
 * 
 */
UCLASS()
class SIMULATION_API UUGameManager : public UObject
{
	GENERATED_BODY()
public:
    UUGameManager(const FObjectInitializer& ObjectInitializer);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Social Distancing")
    bool socialDistancing;
};
