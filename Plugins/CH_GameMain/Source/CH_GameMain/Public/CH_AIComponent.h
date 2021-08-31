// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CH_AIComponent.generated.h"

/*
 *AI用的组件
 * BlueprintReadOnly 蓝图可以读取但是不能修改  EditDefaultsOnly只能在蓝图里面细节面板修改
 */

class UBehaviorTree;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) /*AI用的组件，里面放了一些基础的东西*/)
class CH_GAMEMAIN_API UCH_AIComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCH_AIComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintReadOnly ,EditDefaultsOnly,Category=BehaviorTree/*行为树*/)
	UBehaviorTree* BehaviorTree;
		
};
