// Fill out your copyright notice in the Description page of Project Settings.


#include "CivilianCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "EngineGlobals.h"
#include "Perception/AISense_Hearing.h"
#include "Simulation/Manager/TimeManager.h"
#include "Simulation/Manager/GameManager.h"
#include "Simulation/Controller/CivilianController.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
ACivilianCharacter::ACivilianCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GetWorldTimerManager().SetTimer(SneezeHandler, this, &ACivilianCharacter::Sneeze, 1.0f, true, 1.0f);
}

// Called when the game starts or when spawned
void ACivilianCharacter::BeginPlay()
{
	Super::BeginPlay();
	/*if(bIsInfected)
		Infect();*/
}

// Called every frame
void ACivilianCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACivilianCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACivilianCharacter::Infect()
{
	bIsInfected = true;	
	GetMesh()->SetMaterial(0, InfectedMaterial);
	ACivilianController* CivilianController = Cast<ACivilianController>(GetController());
	if (CivilianController)
	{
		UBlackboardComponent* BlackboardComp = CivilianController->GetBlackboardComp();

		if (BlackboardComp)
			BlackboardComp->SetValueAsBool("IsInfected", true);
	}

	//SetTexture();
}


void ACivilianCharacter::Cure()
{
	bIsInfected = false;
	GetMesh()->SetMaterial(0, AlertedMaterial);
}

void ACivilianCharacter::Intellectual()
{
	bIsIntellectual = true;
	ACivilianController* CivilianController = Cast<ACivilianController>(GetController());
	if (CivilianController)
	{
		UBlackboardComponent* BlackboardComp = CivilianController->GetBlackboardComp();

		if (BlackboardComp)
			BlackboardComp->SetValueAsBool("IsIntellectual", true);
	}
	/*SetTexture();*/
}

void ACivilianCharacter::SetTexture()
{
	if (bIsInfected && bIsIntellectual)
		GetMesh()->SetMaterial(0, AlertedMaterial);
	else if (bIsInfected)
		GetMesh()->SetMaterial(0, InfectedMaterial);
}

