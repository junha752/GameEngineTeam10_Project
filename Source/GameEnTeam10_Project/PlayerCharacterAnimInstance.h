// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GAMEENTEAM10_PROJECT_API UPlayerCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Params")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Params")
	float Direction = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* DodgeMontage;

	void PlayDodgeMontage();
	void PlayAttackMontage_1();
	void PlayAttackMontage_2();
	void PlayAttackMontage_3();
	void PlayAttackMontage_4();
	void PlayDamageMontage();
	void PlayWeaponChangeMontageStart();
	void PlayWeaponChangeMontageEnd();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetisMontagePlayingfalse();
	bool isMontagePlaying = false;
private:
};
