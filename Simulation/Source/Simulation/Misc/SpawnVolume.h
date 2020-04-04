// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class SIMULATION_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int InfectedAndIntellectual;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int InfectedAndNotIntellectual;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int NotInfectedAndIntellectual;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int NotInfectedAndNotIntellectual;
	UPROPERTY(EditAnywhere, Category = "Age Group")
	int KidGroup;
	UPROPERTY(EditAnywhere, Category = "Age Group")
	int YoungsterGroup;
	UPROPERTY(EditAnywhere, Category = "Age Group")
	int OldGroup;
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
	int KidGroupCount;
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
	int YoungsterGroupCount;
	UPROPERTY(BlueprintReadWrite, Category = "Attributes")
	int OldGroupCount;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
