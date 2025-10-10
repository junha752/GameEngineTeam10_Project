// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"


void UPlayerCharacterAnimInstance::PlayDodgeMontage() {
	if (isMontagePlaying) {
		return;
	}
	else {
		APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor());
		Character->Stamina -= 130;
		Character->isUsingStamina = true;
		this->Montage_Play(DodgeMontage, 0.5f);
		if (Direction >= 45 && Direction < 135) {
			this->Montage_JumpToSection(FName(TEXT("Dodge_R")), DodgeMontage);
		}
		else if (Direction <= -45 && Direction > -135)
		{
			this->Montage_JumpToSection(FName(TEXT("Dodge_L")), DodgeMontage);
			isMontagePlaying = true;
		}
		else if (Direction > -45 && Direction < 45)
		{
			this->Montage_JumpToSection(FName(TEXT("Dodge_F")), DodgeMontage);
			isMontagePlaying = true;
		}
		else
		{
			this->Montage_JumpToSection(FName(TEXT("Dodge_B")), DodgeMontage);
			isMontagePlaying = true;
		}

	}
}

void UPlayerCharacterAnimInstance::PlayW_Attack_L_Montage() {
	if (isMontagePlaying) {
		return;
	}
	else {
		this->Montage_Play(W_AttackMontage_L, 2.f);
		isMontagePlaying = true;
		APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor());
		Character->Stamina -= 140;
		Character->isUsingStamina = true;
	}

}
void UPlayerCharacterAnimInstance::PlayS_Attack_L_Montage() {
	if (isMontagePlaying) {
		return;
	}
	else {
		this->Montage_Play(S_AttackMontage_L, 2.f);
		isMontagePlaying = true;
		APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor());
		Character->Stamina -= 200;
		Character->isUsingStamina = true;
	}
}
void UPlayerCharacterAnimInstance::PlayW_Attack_R_Montage() {
	if (isMontagePlaying) {
		return;
	}
	else {
		this->Montage_Play(W_AttackMontage_R, 2.f);
		isMontagePlaying = true;
		APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor());
		Character->Stamina -= 140;
		Character->isUsingStamina = true;
	}
}
void UPlayerCharacterAnimInstance::PlayS_Attack_R_Montage() {
	if (isMontagePlaying) {
		return;
	}
	else {
		this->Montage_Play(S_AttackMontage_R, 2.f);
		isMontagePlaying = true;
		APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor());
		Character->Stamina -= 200;
		Character->isUsingStamina = true;
	}
}

void UPlayerCharacterAnimInstance::SetisMontagePlayingfalse() {
	isMontagePlaying = false;
	this->Montage_Stop(0.25f,  nullptr);
}

void UPlayerCharacterAnimInstance::PlayDamageMontage() {
	this->Montage_Play(DamageMontage, 2.f);
}