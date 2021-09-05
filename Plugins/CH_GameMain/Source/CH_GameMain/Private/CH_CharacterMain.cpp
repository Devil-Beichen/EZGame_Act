// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_CharacterMain.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACH_CharacterMain::ACH_CharacterMain()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACH_CharacterMain::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACH_CharacterMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACH_CharacterMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACH_CharacterMain::SetWalkSpeed(const float Speed) /*设置角色的速度*/
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}
