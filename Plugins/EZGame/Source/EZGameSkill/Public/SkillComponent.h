// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillComponent.generated.h"

class USkillManager;
class UAnimMontage;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class EZGAMESKILL_API USkillComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USkillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="技能相关"/*技能管理器对象*/)
	USkillManager* SkillManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite/*蒙太奇动画*/)
	UAnimMontage* SkillMontage;

	UFUNCTION(BlueprintCallable/*初始化函数*/)
	virtual void OnInit(USkillManager* InSkillManager) { SkillManager = InSkillManager; }

	UFUNCTION(BlueprintCallable/*释放技能函数*/)
	virtual void OnCast();

	UFUNCTION(BlueprintImplementableEvent/*释放技能蓝图接口*/)
	void OnCastImp();

	UFUNCTION(BlueprintCallable/*播放动画的函数*/)
	void PlayAnimation();
};
