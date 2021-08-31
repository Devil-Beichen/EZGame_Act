// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CH_CharacterMain.h"
#include "CH_AICharacterMain.generated.h"

/**
 * AI的主类
 */

class UCH_AIComponent;

UCLASS()
class CH_GAMEMAIN_API ACH_AICharacterMain : public ACH_CharacterMain
{
	GENERATED_BODY()

public:
	ACH_AICharacterMain();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category=Component)
	UCH_AIComponent* AIComponent;
};
