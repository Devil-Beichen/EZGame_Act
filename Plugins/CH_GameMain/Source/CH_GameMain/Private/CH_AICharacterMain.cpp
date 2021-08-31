// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_AICharacterMain.h"
#include "CH_AIComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACH_AICharacterMain::ACH_AICharacterMain()
{
	AIComponent = CreateDefaultSubobject<UCH_AIComponent>("AIComponent");

	bUseControllerRotationYaw = false; //有控制器的Yaw控制
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned; //生成之后自动被AI控制器所控制
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision); //Mesh默认没有碰撞
	GetCharacterMovement()->JumpZVelocity = 600.0f; //默认跳跃加速度
	GetCharacterMovement()->AirControl = 0.2f; //默认下落的控制的量0~1
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); //默认旋转速率
	GetCharacterMovement()->bOrientRotationToMovement = true; //角色旋转受旋转速率影响
	GetCharacterMovement()->bUseRVOAvoidance = true; //开启回避
	GetCharacterMovement()->AvoidanceConsiderationRadius = 120.0f; //回避的默认半径为150
	GetCharacterMovement()->AvoidanceWeight = 0.5f;
}

void ACH_AICharacterMain::BeginPlay()
{
	Super::BeginPlay();
}

void ACH_AICharacterMain::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
