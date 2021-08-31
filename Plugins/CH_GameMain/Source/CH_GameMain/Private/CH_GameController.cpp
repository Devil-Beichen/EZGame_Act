// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_GameController.h"
#include "CH_Character.h"

ACH_GameController::ACH_GameController()
{
}

void ACH_GameController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//前后移动
	InputComponent->BindAxis("MoveForward", this, &ACH_GameController::MoveForward);
	//左右移动
	InputComponent->BindAxis("MoveRight", this, &ACH_GameController::MoveRight);
	//左右看
	InputComponent->BindAxis("Turn", this, &ACH_GameController::Turn);
	//上下看
	InputComponent->BindAxis("LookUp", this, &ACH_GameController::LookUp);
	//起跳
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACH_GameController::Jump);
	//起跳按键松开
	InputComponent->BindAction("Jump", IE_Released, this, &ACH_GameController::StopJump);
}

void ACH_GameController::BeginPlay()
{
	Super::BeginPlay();
	Ch_Character = Cast<ACH_Character>(ACH_GameController::GetPawn());
}

void ACH_GameController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ACH_GameController::MoveForward(float Value)
{
	if (Ch_Character != nullptr && Value != 0.0f)
	{
		const FRotator Rotator = GetPawn()->GetControlRotation(); //获得当前控制器的朝向
		const FRotator YawRotator(0.0f, Rotator.Yaw, 0.0f); //获得向前的量
		const FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X); //获得向前的向量
		Ch_Character->AddMovementInput(Direction, Value);
	}
}

void ACH_GameController::MoveRight(float Value)
{
	if (Ch_Character != nullptr && Value != 0.0f)
	{
		const FRotator Rotator = GetPawn()->GetControlRotation(); //获得当前控制器的朝向
		const FRotator YawRotator(0.0f, Rotator.Yaw, 0.0f); //获得向前的量
		const FVector Direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y); //获得向右的向量
		Ch_Character->AddMovementInput(Direction, Value);
	}
}

void ACH_GameController::LookUp(float Value)
{
	if (Ch_Character != nullptr && Value != 0.0f)
	{
		Ch_Character->AddControllerPitchInput(Value); //X
	}
}

void ACH_GameController::Turn(float Value)
{
	if (Ch_Character != nullptr && Value != 0.0f)
	{
		Ch_Character->AddControllerYawInput(Value); //Z
	}
}

void ACH_GameController::Jump()
{
	if (Ch_Character != nullptr)
	{
		Ch_Character->Jump();
	}
}

void ACH_GameController::StopJump()
{
	if (Ch_Character != nullptr)
	{
		Ch_Character->StopJumping();
	}
}
