// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_GameAIController.h"
#include "CH_AICharacterMain.h"
#include "CH_AIComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "DetourCrowdAIController.h"
#include "Navigation/CrowdFollowingComponent.h"


ACH_GameAIController::ACH_GameAIController(const FObjectInitializer& ObjectInitializer) : Super(
	ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
}


void ACH_GameAIController::BeginPlay()
{
	Super::BeginPlay();
	GetDefaultSetting();
}

void ACH_GameAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ACH_GameAIController::GetDefaultSetting()
{
	AiCharacter = Cast<ACH_AICharacterMain>(GetPawn()); //获得当前控制的AI
	const UCH_AIComponent* AIComponent = Cast<UCH_AIComponent>(
		AiCharacter->GetComponentByClass(UCH_AIComponent::StaticClass())); //获得临时的AIComponent组件
	BehaviorTree = AIComponent->BehaviorTree; //设置获得的行为树

	if (BehaviorTree != nullptr)
	{
		RunBehaviorTree(BehaviorTree); //运行行为树
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, TEXT("成功运行行为树"));
	}
	if (AiCharacter == nullptr || AIComponent == nullptr || BehaviorTree == nullptr)
	{
		GetDefaultSetting();
	}
}
