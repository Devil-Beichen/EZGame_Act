// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_Skill.h"
#include "SkillComponent.h"
#include "SkillManager.h"

void UAnimNotify_Skill::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (!MeshComp)
		return;
	TInlineComponentArray<USkillManager*> Components(MeshComp->GetOwner());
	for (const USkillManager* a : Components)
	{
		USkillComponent* NowSkill = a->NowAnimSkill;
		if (!NowSkill)
			return;
		UFunction* TFunc = NowSkill->FindFunction(FunctionName);
		if (TFunc)
			NowSkill->ProcessEvent(TFunc, nullptr);
	}
}
