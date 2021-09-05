// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CH_CharacterMain.generated.h"


/**
*角色最重要的主类
*/


UCLASS(meta=(Description = "角色最重要的主类"))
class CH_GAMEMAIN_API ACH_CharacterMain : public ACharacter
{
	GENERATED_BODY()

	virtual FString GetDesc() override { return TEXT("角色最重要的主类"); }

public:
	// Sets default values for this character's properties
	ACH_CharacterMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable/*设置角色的速度*/, Category= CharacterMovement)
	virtual void SetWalkSpeed(const float Speed);
	
};
