// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Simulation/Misc/NextTargetPoint.h"
#include "Simulation/Misc/SafeTargetPoint.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class SIMULATION_API UGameManager : public UGameInstance
{
	GENERATED_BODY()
	
private:
	virtual void Init() override;
	

public:
	FORCEINLINE TArray<AActor*> GetPlacesToHang() { return PlacesToHang; }

	TArray<AActor*> TotalCharactersInfected;
	TArray<AActor*> TotalCharacters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalCharacterCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalInfectedCharacterCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> PlacesToHang;


	UFUNCTION(BlueprintCallable)
	int GetCountOfInfectCharacters() { return TotalCharactersInfected.Num(); }
	UFUNCTION(BlueprintCallable)
	void SetCountOfInfectCharacters(AActor* Character) { TotalCharactersInfected.Add(Character); }
	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetTotalCharacters() { return TotalCharacters; }
	UFUNCTION(BlueprintCallable)
	void SetTotalCharacters(AActor* Character) { TotalCharacters.Add(Character); }
	UFUNCTION(BlueprintCallable)
	void SetAgeOfCharacters(AActor* Character, EAgeEnum AgeGroup);
};
