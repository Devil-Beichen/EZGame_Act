// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManager.h"
#include "SkillComponent.h"

// Sets default values for this component's properties
USkillManager::USkillManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillManager::BeginPlay()
{
	Super::BeginPlay();
	if(GetOwner()&&GetOwner()->InputComponent)
	{
		GetOwner()->InputComponent->BindAction("MouseLeft",EInputEvent::IE_Pressed,this,&USkillManager::CastSkill1);
		GetOwner()->InputComponent->BindAction("MouseRight",EInputEvent::IE_Pressed,this,&USkillManager::CastSkill2);
		GetOwner()->InputComponent->BindAction("G",EInputEvent::IE_Pressed,this,&USkillManager::CastSkill3);
	}
	// ...
}


// Called every frame
void USkillManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

USkillComponent* USkillManager::AddSkill(TSubclassOf<USkillComponent> SkillClass)
{
	USkillComponent* NewSkill = NewObject<USkillComponent>(GetOwner(), SkillClass); //对USkillComponent实例化
	NewSkill->RegisterComponent(); //注册
	SkillArray.Add(NewSkill); //添加到技能数组
	NewSkill->OnInit(this); //初始化自己
	return NewSkill; //回传
}

void USkillManager::BinSkill(USkillComponent* InBindSkill, USkillComponent*& TargetSkill)
{
	if (!InBindSkill) //判断非空
		return;
	TargetSkill = InBindSkill;
}

void USkillManager::CastSkill(USkillComponent* Skill)
{
	if (!Skill)
		return;
	Skill->OnCast();
}
