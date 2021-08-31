// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CH_CharacterMain.h"
#include "CH_Character.generated.h"

/**
 * 角色主类
 */

class USpringArmComponent;
class UCameraComponent;


UCLASS()
class CH_GAMEMAIN_API ACH_Character : public ACH_CharacterMain
{
	GENERATED_BODY()
public:
	ACH_Character();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	//创建一个相机摇臂
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=MyCamera)
	USpringArmComponent * SpringArm;
	//创建一个相机
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category=MyCamera)
	UCameraComponent * Camera;
	
};
