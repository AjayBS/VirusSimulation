// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "Perception/AISense.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Touch.h"
#include "Simulation/Character/CivilianCharacter.h"
#include "Simulation/Misc/NextTargetPoint.h"
#include "CivilianController.generated.h"


/**
 * 
 */
UCLASS()
class SIMULATION_API ACivilianController : public AAIController
{
	GENERATED_BODY()
private:
	
	virtual void OnPossess(APawn* i_Pawn) override;

	UFUNCTION()
	void SenseStuff(AActor* UpdatedActor, FAIStimulus Stimulus);
	UBehaviorTreeComponent* BehaviorComp;

	UBlackboardComponent* BlackboardComp;

	/*Blackboard keys*/
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName LocationToGoKey;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UAIPerceptionComponent* PerceptionComp;

	UAISenseConfig_Sight* SightConfig;
	UAISenseConfig_Hearing* HearingConfig;/*
	UAISenseConfig_Touch* TouchConfig;*/

	ACivilianCharacter* CivilianCharacter;
public:
	ACivilianController();

	virtual void BeginPlay() override;

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

	void SetSightDetails();
	void SetHearingDetails();

	UFUNCTION(BlueprintCallable)
	void StartBehaviorTree();

};
