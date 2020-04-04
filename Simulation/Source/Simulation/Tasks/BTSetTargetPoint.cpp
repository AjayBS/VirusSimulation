// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSetTargetPoint.h"
#include "Engine/GameEngine.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Simulation/Controller/CivilianController.h"
#include "Simulation/Manager/GameManager.h"
#include "Simulation/Misc/NextTargetPoint.h"

EBTNodeResult::Type UBTSetTargetPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UGameManager* GameManager = Cast<UGameManager>(GetWorld()->GetGameInstance());

	ACivilianController* AICon = Cast<ACivilianController>(OwnerComp.GetAIOwner());
	if (GameManager && AICon)
	{
		UBlackboardComponent* BlackboardComp = AICon->GetBlackboardComp();
		TArray<AActor*> AvailablePlaces;
		AvailablePlaces = GameManager->GetPlacesToHang();
		if (AvailablePlaces.Num() > 0)
		{
			AActor* CurrentPoint = Cast<AActor>(BlackboardComp->GetValueAsObject("LocationToGo"));

			int32 RandomIndex;
			AActor* NextTargetPoint = nullptr;
			do
			{
				RandomIndex = FMath::RandRange(0, AvailablePlaces.Num() - 1);

				//Remember that the Array provided by the Controller function contains AActor* objects so we need to cast
				NextTargetPoint = Cast<AActor>(AvailablePlaces[RandomIndex]);
			} while (CurrentPoint == NextTargetPoint);

			//Update the next location in the Blackboard so the bot can move to the next Blackboard value
			BlackboardComp->SetValueAsObject("LocationToGo", NextTargetPoint);
		}
	

		//At this point, the task has been successfully completed
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}