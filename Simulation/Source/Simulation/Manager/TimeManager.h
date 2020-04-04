// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "Simulation/Manager/GameManager.h"
#include "TimeManager.generated.h"

UCLASS()
class SIMULATION_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeManager();	
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> wWorkHUD;

	UUserWidget* WorkHUD;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UGameManager* GameManager;
	bool WriteOnceInLog = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Attributes")
	int Days;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Attributes")
	int Hours;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Attributes")
	int Minutes;
};
