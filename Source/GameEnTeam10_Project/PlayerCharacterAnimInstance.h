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
	UAnimMontage* S_AttackMontage_R;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* S_AttackMontage_L;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* W_AttackMontage_R;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* W_AttackMontage_L;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* DodgeMontage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	UAnimMontage* DamageMontage;
	void PlayDodgeMontage();
	void PlayW_Attack_L_Montage();
	void PlayS_Attack_L_Montage();
	void PlayW_Attack_R_Montage();
	void PlayS_Attack_R_Montage();
	void PlayDamageMontage();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void SetisMontagePlayingfalse();
	bool isMontagePlaying = false;
private:
};
