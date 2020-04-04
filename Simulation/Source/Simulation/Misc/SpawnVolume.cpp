// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Simulation/Manager/GameManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	UGameManager* GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());

	int TotalCharacters = NotInfectedAndIntellectual + InfectedAndIntellectual + NotInfectedAndNotIntellectual + InfectedAndNotIntellectual;
	GameManager->TotalCharacterCount = TotalCharacters;

	KidGroupCount = (KidGroup / 100) * TotalCharacters;
	YoungsterGroupCount = (YoungsterGroup / 100) * TotalCharacters;
	OldGroupCount = (OldGroupCount / 100) * TotalCharacters;
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

