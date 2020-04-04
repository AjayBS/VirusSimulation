// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckInfectedAndQuarantineState.h"
#include "Simulation/Manager/GameManager.h"
#include "Simulation/Controller/CivilianController.h"

void UCheckInfectedAndQuarantineState::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UGameManager* GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());

	ACivilianController* AICon = Cast<ACivilianController>(OwnerComp.GetAIOwner());
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
		if (GameManager->GetCountOfInfectCharacters() >= InfectedLimit && (BlackboardComp->GetValueAsBool("IsInfected") != true))
		{
			if (BlackboardComp->GetValueAsBool("IsIntellectual"))
			{
				BlackboardComp->SetValueAsBool("TerminateTask", true);
			}
		}
	
	}
}
 