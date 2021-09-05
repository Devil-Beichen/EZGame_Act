// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Skill.generated.h"

/**
 * 
 */
UCLASS(/*自定义的技能通知*/)
class EZGAMESKILL_API UAnimNotify_Skill : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite/*函数名称*/)
	FName FunctionName;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
