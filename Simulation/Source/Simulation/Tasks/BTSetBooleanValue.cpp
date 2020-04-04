// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSetBooleanValue.h"
#include "Engine/GameEngine.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Simulation/Controller/CivilianController.h"
#include "Simulation/Manager/GameManager.h"
#include "Simulation/Misc/NextTargetPoint.h"

EBTNodeResult::Type UBTSetBooleanValue::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UGameManager* GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());

	ACivilianController* AICon = Cast<ACivilianController>(OwnerComp.GetAIOwner());
	if (GameManager && AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
		if(BlackboardComp)
			BlackboardComp->SetValueAsBool("IsQuarantined", ToQuarantine);

		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}