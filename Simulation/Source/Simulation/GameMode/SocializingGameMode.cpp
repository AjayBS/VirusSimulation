// Fill out your copyright notice in the Description page of Project Settings.


#include "SocializingGameMode.h"
#include "Engine.h"
#include "Simulation/Character/CivilianCharacter.h"

void ASocializingGameMode::BeginPlay()
{
	Super::BeginPlay();
	/*GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red,TEXT("Actor Spawning"));
	FTransform SpawnLocation;
	ACivilianCharacter* Civilian = GetWorld()->SpawnActor<ACivilianCharacter>(ACivilianCharacter::StaticClass());
	Civilian->SetActorLocation(SpawnLocation.GetLocation());*/
}