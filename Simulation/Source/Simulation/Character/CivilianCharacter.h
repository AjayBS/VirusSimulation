// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "CivilianCharacter.generated.h"

UENUM(BlueprintType)
enum class EAgeEnum : uint8
{
	VE_Kid UMETA(DisplayName = "Kid"),
	VE_Youngster UMETA(DisplayName = "Youngster"),
	VE_OldAge UMETA(DisplayName = "OldAge")
};

UCLASS()
class SIMULATION_API ACivilianCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACivilianCharacter();

	UPROPERTY(EditAnywhere, Category = "AI")
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Attributes")
	bool bIsInfected = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	EAgeEnum Age;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bIsIntellectual = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool CheckIfInfected() { return bIsInfected; };

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void Infect();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void Intellectual();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void Cure();

	void SetTexture();

	void SetAgeGroup(EAgeEnum AgeGroup) { Age = AgeGroup; };

	UPROPERTY(EditAnywhere, Category = "Materials")
	class UMaterial* InfectedMaterial;

	UPROPERTY(EditAnywhere, Category = "Materials")
	class UMaterial* AlertedMaterial;
};
