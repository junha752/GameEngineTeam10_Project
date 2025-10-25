// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterNotifyState.h"
#include "PlayerCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/CapsuleComponent.h"

void UPlayerCharacterNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) {
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);
	isNotifyStatePlaying = true;
	HittedActors.Empty();
}


void UPlayerCharacterNotifyState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float DeltaTime, const FAnimNotifyEventReference& EventReference) {
	Super::NotifyTick(MeshComp, Animation, DeltaTime, EventReference);

	APlayerCharacter* Character = Cast<APlayerCharacter>(MeshComp->GetOwner());
	if (Character != nullptr &&  Character->SwordStart != nullptr && Character->SwordEnd != nullptr)
	{FVector StartLocation = Character->SwordStart->GetComponentLocation();
		FVector EndLocation = Character->SwordEnd->GetComponentLocation();
		TArray<AActor*> ActorsIgnore;
		ActorsIgnore.Add(Character);
		TArray<FHitResult> HitResults;
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));
		bool bHIt = UKismetSystemLibrary::SphereTraceMultiForObjects(
			Character->GetWorld(),
			StartLocation,
			EndLocation,
			20.f,
			ObjectTypes,
			true,
			ActorsIgnore,
			EDrawDebugTrace::ForOneFrame,
			HitResults,
			true
		);
		if (HitResults.Num() > 0) {
			for (const FHitResult& Hit : HitResults) {
				AActor* Target = Hit.GetActor();
				if(Target && !HittedActors.Contains(Target))
					{HittedActors.Add(Target);
						APlayerCharacter * Enemy = Cast<APlayerCharacter>(Target);
						Enemy->GetDamaged(float(Character->Strength));
						if (GEngine) {
							GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("GetDameged"));
						}
				}
			}
		}
	}
}
void UPlayerCharacterNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) {
	Super::NotifyEnd(MeshComp, Animation, EventReference);
	isNotifyStatePlaying = false;
}