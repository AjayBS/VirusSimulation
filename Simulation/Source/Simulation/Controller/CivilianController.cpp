// Fill out your copyright notice in the Description page of Project Settings.


#include "CivilianController.h"
#include "Engine.h"
#include "EngineGlobals.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "Simulation/Manager/GameManager.h"
#include "Simulation/Character/CivilianCharacter.h"

class UAISense_Hearing;
class UAISense_Sight;
//////////////////////////////////////////////////////////////////////

ACivilianController::ACivilianController()
{
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));	
	LocationToGoKey = "LocationToGo";
	
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception Component"));
	//SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	//TouchConfig = CreateDefaultSubobject<UAISenseConfig_Touch>(TEXT("Touch Config"));
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));

	//PerceptionComp->ConfigureSense(*SightConfig);
	PerceptionComp->ConfigureSense(*HearingConfig);

	//SetSightDetails();
	SetHearingDetails();
	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &ACivilianController::SenseStuff);
	//UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, SightConfig->GetSenseImplementation(), GetPawn());
	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, HearingConfig->GetSenseImplementation(), GetPawn());

	SetGenericTeamId(FGenericTeamId(1));
}

//////////////////////////////////////////////////////////////////////

void ACivilianController::BeginPlay()
{
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////

void ACivilianController::OnPossess(APawn* i_Pawn)
{
	Super::OnPossess(i_Pawn);
	CivilianCharacter = Cast<ACivilianCharacter>(i_Pawn);

	if (CivilianCharacter)
	{
		if (CivilianCharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(CivilianCharacter->BehaviorTree->BlackboardAsset));
		}

		if (CivilianCharacter->bIsIntellectual)
		{
			BlackboardComp->SetValueAsBool("IsIntellectual", true);
		}

		if (CivilianCharacter->bIsInfected)
		{
			BlackboardComp->SetValueAsBool("IsInfected", true);
		}
	}
}

//////////////////////////////////////////////////////////////////////

void ACivilianController::SenseStuff(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	if (CivilianCharacter)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			if ((Stimulus.Type.Name.ToString().Contains("Hearing")) && !CivilianCharacter->CheckIfInfected())
			{
				UGameManager* GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());
				GameManager->TotalCharactersInfected.Add(UpdatedActor);
				CivilianCharacter->Infect();
			}

			/*else if (Stimulus.Type.Name.ToString().Contains("Sight"))
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Found someone.")));
				BlackboardComp->SetValueAsBool("FoundSomeone", true);
				BlackboardComp->SetValueAsObject("Friend", UpdatedActor);
				BlackboardComp->SetValueAsVector("FriendLocation", Stimulus.StimulusLocation);
			}*/

		}
	}	
}

//////////////////////////////////////////////////////////////////////

void ACivilianController::SetSightDetails()
{
	SightConfig->SightRadius = 500.f;
	SightConfig->LoseSightRadius = (520.0f);
	SightConfig->PeripheralVisionAngleDegrees = 45.0f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	PerceptionComp->ConfigureSense(*SightConfig);
}

void ACivilianController::SetHearingDetails()
{
	HearingConfig->HearingRange = 70.f;
	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
}

void ACivilianController::StartBehaviorTree()
{
	BehaviorComp->StartTree(*CivilianCharacter->BehaviorTree);
}