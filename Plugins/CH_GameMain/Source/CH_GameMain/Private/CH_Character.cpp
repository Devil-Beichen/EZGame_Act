// Fill out your copyright notice in the Description page of Project Settings.


#include "CH_Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ACH_Character::ACH_Character()
{
	bUseControllerRotationYaw = false; //由控制器来控制旋转
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision); //Mesh默认没有碰撞

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component"); //SpringArm的默认值
	SpringArm->SetupAttachment(RootComponent); //绑定到RootComponent下面
	SpringArm->TargetArmLength = 450.0f; //摇臂的默认长度
	SpringArm->bUsePawnControlRotation = true; //可以由控制器查看旋转

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera Component"); //Camera的默认值
	Camera->SetupAttachment(SpringArm); //绑定到SpringArm下面

	GetCharacterMovement()->JumpZVelocity = 600.0f;//默认跳跃加速度
	GetCharacterMovement()->AirControl = 0.2f;//默认下落的控制的量0~1
	GetCharacterMovement()->RotationRate = FRotator(0.0f,540.0f,0.0f);//默认旋转速率
	GetCharacterMovement()->bOrientRotationToMovement = true;//角色旋转受旋转速率影响
	
}

void ACH_Character::BeginPlay()
{
	Super::BeginPlay();
}

void ACH_Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
