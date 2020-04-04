// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "EngineGlobals.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PController = GetWorld()->GetFirstPlayerController();
	GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());

	if (wWorkHUD && PController)
	{
		WorkHUD = CreateWidget<UUserWidget>(PController, wWorkHUD);

		if (WorkHUD)
		{
			WorkHUD->AddToViewport();
		}
	}
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Hours == 0 && WriteOnceInLog == false)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Days: %d Infected: %d"), Days, GameManager->GetCountOfInfectCharacters()));
		UE_LOG(LogTemp, Warning, TEXT("Day: %d --- Infected: %d"), Days, GameManager->GetCountOfInfectCharacters());
		WriteOnceInLog = true;
	}
	else
	{
		WriteOnceInLog = false;
	}
}

