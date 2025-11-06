// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstance.h"
#include "PlayerCharacter.h"


void UPlayerCharacterAnimInstance::PlayDodgeMontage() {
	if (isMontagePlaying) {
		return;
	}
	else {
		if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
		{
			if (Character->WeaponAnimationData)
			{
				Character->Stamina -= 30;
				Character->isUsingStamina = true;
				this->Montage_Play(DodgeMontage, 0.5f);
				if (Direction >= 45 && Direction < 135) {
					this->Montage_JumpToSection(FName(TEXT("Dodge_R")), DodgeMontage);
					isMontagePlaying = true;
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

	}
}

void UPlayerCharacterAnimInstance::PlayAttackMontage_1() {
	if (isMontagePlaying == true) { return; }
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		Character->Stamina -= 70;
		Character->isUsingStamina = true;
		isMontagePlaying = true;
		this->Montage_Play(Character->CurrentWeaponAnims->Attack_Montage_1, 1.5f);
	}
}
void UPlayerCharacterAnimInstance::PlayAttackMontage_2() {
	if (isMontagePlaying == true) { return; }
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		Character->Stamina -= 70;
		Character->isUsingStamina = true;
		isMontagePlaying = true;
		this->Montage_Play(Character->CurrentWeaponAnims->Attack_Montage_2, 1.5f);
	}
}
void UPlayerCharacterAnimInstance::PlayAttackMontage_3() {
	if (isMontagePlaying == true) { return; }
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		Character->Stamina -= 70;
		Character->isUsingStamina = true;
		isMontagePlaying = true;
		this->Montage_Play(Character->CurrentWeaponAnims->Attack_Montage_3, 1.5f);
	}
}
void UPlayerCharacterAnimInstance::PlayAttackMontage_4() {
	if (isMontagePlaying == true) { return; }
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		Character->Stamina -= 70;
		Character->isUsingStamina = true;
		isMontagePlaying = true;
		this->Montage_Play(Character->CurrentWeaponAnims->Attack_Montage_4, 1.5f);
	}
}
void UPlayerCharacterAnimInstance::SetisMontagePlayingfalse() {
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		Character->isUsingStamina = false;
		isMontagePlaying = false;
		this->Montage_Stop(0.25f, nullptr);
	}
}

void UPlayerCharacterAnimInstance::PlayDamageMontage() {

}
void UPlayerCharacterAnimInstance::PlayWeaponChangeMontageStart() {
	if (isMontagePlaying == true) { return; }
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		isMontagePlaying = true;
		this->Montage_Play(Character->CurrentWeaponAnims->UnEquip_Montage, 1.5f);
	}
}
void UPlayerCharacterAnimInstance::PlayWeaponChangeMontageEnd() {
	if (isMontagePlaying == true) { return; }
	if (APlayerCharacter* Character = Cast<APlayerCharacter>(this->GetOwningActor()))
	{
		if (!Character->WeaponAnimationData) { return; }
		isMontagePlaying = true;
		this->Montage_Play(Character->CurrentWeaponAnims->Equip_Montage, 1.5f);
	}
}