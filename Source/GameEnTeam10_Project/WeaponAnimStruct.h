// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponAnimStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FWeaponAnimStruct : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Attack_Montage_1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Attack_Montage_2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Attack_Montage_3;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Attack_Montage_4;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Equip_Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* UnEquip_Montage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Hit_Montage_1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")

	UAnimMontage* Hit_Montage_2;
};
