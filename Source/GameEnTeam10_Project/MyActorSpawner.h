// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "MyActorSpawner.generated.h"
class ATargetLockActor;
class UWorld;
UCLASS()
class GAMEENTEAM10_PROJECT_API AMyActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorSpawner();
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category="Spawn")
	TSubclassOf<class ATargetLockActor> ActorToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Lock")
	void SpawnLockOnWidget(AActor* Character);
	UFUNCTION(BlueprintCallable, Category = "Lock")
	void DestroyLockOnWidget();
private:
	UWorld* World;

};
