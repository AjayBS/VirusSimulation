// Fill out your copyright notice in the Description page of Project Settings.


#include "BTResetFoundState.h"
#include "Simulation/Controller/CivilianController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTResetFoundState::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACivilianController* AICon = Cast<ACivilianController>(OwnerComp.GetAIOwner());
	if (AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
		BlackboardComp->ClearValue("Friend");
		BlackboardComp->SetValueAsBool("FoundSomeone", false);
	}

	//At this point, the task has been successfully completed
	return EBTNodeResult::Succeeded;
}