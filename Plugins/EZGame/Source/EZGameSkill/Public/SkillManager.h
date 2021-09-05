// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManager.generated.h"

class USkillComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class EZGAMESKILL_API USkillManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USkillManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite/*技能数组*/)
	TArray<USkillComponent*> SkillArray;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite/*当前的动画技能*/)
	USkillComponent*NowAnimSkill;

	UFUNCTION(BlueprintCallable/*添加技能的函数*/)
	virtual USkillComponent* AddSkill(TSubclassOf<USkillComponent> SkillClass);

	UFUNCTION(BlueprintCallable/*绑定技能函数*/)
	virtual void BinSkill(USkillComponent* InBindSkill, USkillComponent* & TargetSkill);

	UFUNCTION(BlueprintCallable/*释放技能函数*/)
	virtual void CastSkill(USkillComponent* Skill);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite/*技能栏位一*/)
	USkillComponent* Skill1;

	UFUNCTION(BlueprintCallable/*技能一的绑定*/)
	virtual void BinSkill1(USkillComponent* Skill) { BinSkill(Skill, Skill1); }

	UFUNCTION(BlueprintCallable/*技能一的释放*/)
	virtual void CastSkill1() { CastSkill(Skill1); }
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite/*技能栏位二*/)
	USkillComponent* Skill2;

	UFUNCTION(BlueprintCallable/*技能二的绑定*/)
	virtual void BinSkill2(USkillComponent* Skill) { BinSkill(Skill, Skill2); }

	UFUNCTION(BlueprintCallable/*技能二的释放*/)
	virtual void CastSkill2() { CastSkill(Skill2); }

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite/*技能栏位三*/)
	USkillComponent* Skill3;

	UFUNCTION(BlueprintCallable/*技能三的绑定*/)
	virtual void BinSkill3(USkillComponent* Skill) { BinSkill(Skill, Skill3); }

	UFUNCTION(BlueprintCallable/*技能三的释放*/)
	virtual void CastSkill3() { CastSkill(Skill3); }

	
};
