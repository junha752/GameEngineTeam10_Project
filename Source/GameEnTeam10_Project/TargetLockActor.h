// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "TargetLockActor.generated.h"

UCLASS()
class GAMEENTEAM10_PROJECT_API ATargetLockActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetLockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category= "Lock")
	void MoveLockOnWidget(AActor* TargetCharacter);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lock")
	AActor* TargetActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	UWidgetComponent* LockOnWidgetComponent;
};
