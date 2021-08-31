// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CH_GameAIController.generated.h"

//~=============================================================================
/**
* AI的控制器
*/

class ACH_AICharacterMain;
class UAIPerceptionComponent;
class UBehaviorTree;

UCLASS()
class CH_GAMEMAIN_API ACH_GameAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	ACH_GameAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); //大规模人群绕行避让的最优解

	/*AI感知组件*/
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "AIPerception"/*AI感知组件*/)
	UAIPerceptionComponent* AIPerception;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = Behaviorrre/*行为树*/)
	UBehaviorTree* BehaviorTree;

	/*需要控制的AI*/
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category=Character/*AI角色*/)
	ACH_AICharacterMain* AiCharacter;

	UFUNCTION(/*默认基础配置，并运行行为树*/)
	void GetDefaultSetting();
};
