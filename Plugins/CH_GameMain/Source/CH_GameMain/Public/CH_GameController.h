// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CH_GameController.generated.h"

/**
 * 游戏主角控制器
 */

class ACH_Character;

UCLASS(meta= (ReqviredInput= "false", ToolTip = "游戏主角控制器"))
class CH_GAMEMAIN_API ACH_GameController : public APlayerController
{
	GENERATED_BODY()
public:
	ACH_GameController(); //构造脚本

	virtual void BeginPlay() override; //游戏开始的时候
	virtual void Tick(float DeltaSeconds) override; //每针都运行

	virtual void SetupInputComponent() override; //绑定按键控制

	//玩家控制角色
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category=Character/*玩家控制角色*/)
	ACH_Character* Ch_Character;

	//定义一个前后移动
	void MoveForward(float Value);
	//定义一个左右移动
	void MoveRight(float Value);
	//定义一个上下看
	void LookUp(float Value);
	//定义一个左右看
	void Turn(float Value);
	//定义一个跳跃
	void Jump();
	//定义一个起跳按键结束
	void StopJump();
};
