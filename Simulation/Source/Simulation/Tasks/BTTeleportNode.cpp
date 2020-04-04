// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTeleportNode.h"
#include "Engine/GameEngine.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Simulation/Controller/CivilianController.h"
#include "Simulation/Manager/GameManager.h"
#include "Simulation/Misc/NextTargetPoint.h"

EBTNodeResult::Type UBTTeleportNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UGameManager* GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());

	ACivilianController* AICon = Cast<ACivilianController>(OwnerComp.GetAIOwner());
	if (GameManager && AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
		//AActor* MoveToLocation = Cast<AActor>(BlackboardComp->GetValueAsVector("TeleportLocation"));
		ACivilianCharacter* AICharacter = Cast<ACivilianCharacter>(AICon->GetCharacter());

		AICharacter->TeleportTo(BlackboardComp->GetValueAsVector("TeleportLocation"), AICharacter->GetActorRotation());
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;

}