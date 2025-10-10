// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorSpawner.h"
#include "Engine/World.h"
#include "TargetLockActor.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AMyActorSpawner::AMyActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	World = GetWorld();
}

// Called when the game starts or when spawned
void AMyActorSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorSpawner::SpawnLockOnWidget(AActor* Character) {
	if (!Character || !ActorToSpawn) { 
			return; }
	if (!World) {
		return;
	}
	FVector EndLocation = Character->GetActorLocation();
	EndLocation.Z += 30;
	ATargetLockActor* lockOnWidget = World->SpawnActor<ATargetLockActor>(ActorToSpawn, EndLocation,FRotator::ZeroRotator);
	lockOnWidget->MoveLockOnWidget(Character);
}

void AMyActorSpawner::DestroyLockOnWidget() {
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetLockActor::StaticClass(), FoundActors);
	for (AActor* Actor : FoundActors) {
		if (Actor) {
			Actor->Destroy();
		}
	}
}