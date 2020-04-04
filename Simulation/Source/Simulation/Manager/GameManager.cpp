// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include <Simulation/Character/CivilianCharacter.h>

void UGameManager::Init()
{
	Super::Init();
	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANextTargetPoint::StaticClass(), PlacesToHang);
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Found someone. %d"), PlacesToHang.Num()));
}

void UGameManager::SetAgeOfCharacters(AActor* Character, EAgeEnum AgeGroup)
{
	ACivilianCharacter* CivilianCharacter = Cast<ACivilianCharacter>(Character);
	CivilianCharacter->SetAgeGroup(AgeGroup);
}
