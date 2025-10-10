// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PlayerCharacterAnimInstance.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimMontage.h"
#include "Components/CapsuleComponent.h"
// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	auto characterMovement = GetCharacterMovement();
	characterMovement->bOrientRotationToMovement = true;
	characterMovement->RotationRate = FRotator(0.f, 500.f, 0.f);


	static ConstructorHelpers::FObjectFinder<UInputAction>
		MOVE_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_Move.IA_Move' "));
	if (MOVE_ACTION.Object) {
		MoveAction = MOVE_ACTION.Object;
			}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		LOOK_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_Look.IA_Look' "));
	if (LOOK_ACTION.Object) {
		LookAction = LOOK_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		MOUSELOOK_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_MouseLook.IA_MouseLook' "));
	if (MOUSELOOK_ACTION.Object) {
		MouseLookAction = MOUSELOOK_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		DODGE_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_Dodge.IA_Dodge' "));
	if (DODGE_ACTION.Object) {
		DodgeAction = DODGE_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		W_ATTACK_R_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_WeakAttack_R.IA_WeakAttack_R' "));
	if (W_ATTACK_R_ACTION.Object) {
		W_AttackAction_R = W_ATTACK_R_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		W_ATTACK_L_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_WeakAttack_L.IA_WeakAttack_L' "));
	if (W_ATTACK_L_ACTION.Object) {
		W_AttackAction_L = W_ATTACK_L_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		S_ATTACK_R_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_StrongAttack_R.IA_StrongAttack_R' "));
	if (S_ATTACK_R_ACTION.Object) {
		S_AttackAction_R = S_ATTACK_R_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		S_ATTACK_L_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_StrongAttack_L.IA_StrongAttack_L' "));
	if (S_ATTACK_L_ACTION.Object) {
		S_AttackAction_L = S_ATTACK_L_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		LOCK_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_Lock.IA_Lock' "));
	if (LOCK_ACTION.Object) {
		LockAction = LOCK_ACTION.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction>
		DASH_ACTION(TEXT("/ Script / EnhancedInput.InputAction'/Game/Input/Action/IA_Dash.IA_Dash' "));
	if (DASH_ACTION.Object) {
		DashAction = DASH_ACTION.Object;
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	Spawner = Cast<AMyActorSpawner>(UGameplayStatics::GetActorOfClass(GetWorld(), AMyActorSpawner::StaticClass()));
		// 캐릭터의 캡슐 컴포넌트 가져오기

	UStaticMeshComponent* Sword = SwordMesh;
	if (Sword)
	{
		// Pawn 채널에 대한 충돌을 무시합니다.
		Sword->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	}
	GetCharacterMovement()->PushForceFactor = 0.f;
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		if (USkeletalMeshComponent* Mymesh = GetMesh()) {
			if (auto animInst = Cast<UPlayerCharacterAnimInstance>(Mymesh->GetAnimInstance())) {
				animInst->Speed = GetCharacterMovement()->Velocity.Size2D();
				FVector Velocity = this->GetVelocity();
				FRotator BaseRotation = this->GetActorRotation();
				if (Velocity.IsNearlyZero()) { animInst->Direction = 0; }
				animInst->Direction = animInst->CalculateDirection(Velocity, BaseRotation);
				}

			}
		if (isLockOn ) {
			FRotator ResultRotator = UKismetMathLibrary::FindLookAtRotation(GetFollowCamera()->GetComponentLocation() , TargetActor->GetActorLocation());
			if (Cast<APlayerCharacter>(TargetActor)->isDead == false)
			{
				ResultRotator.Pitch -= 15.f;
				ResultRotator.Pitch = FMath::ClampAngle(ResultRotator.Pitch, -30.f, 70.f);
				GetController()->SetControlRotation(ResultRotator);
			}
			else {
				isLockOn = false;
				bUseControllerRotationYaw = false;
				GetCharacterMovement()->bOrientRotationToMovement = true;
				Spawner->DestroyLockOnWidget();
			}
		}
		else {
			FRotator NormalRotator = GetController()->GetControlRotation();
			NormalRotator.Pitch = FMath::ClampAngle(NormalRotator.Pitch, -30.0f, 30.0f);
			GetController()->SetControlRotation(NormalRotator);
		}
		if (!isUsingStamina) { 
			Stamina = FMath::Clamp(Stamina + 80 * DeltaTime, 0.f, 500.f); 
		}
		else if(isDashing) {
			Stamina = FMath::Clamp(Stamina - 80 * DeltaTime, 0.f, 500.f);
			if (Stamina < 10.f) {
				StopDash();
			}
		}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Dodge);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::MouseLook);
		EnhancedInputComponent->BindAction(S_AttackAction_R, ETriggerEvent::Started, this, &APlayerCharacter::S_Attack_R);
		EnhancedInputComponent->BindAction(W_AttackAction_R, ETriggerEvent::Started, this, &APlayerCharacter::W_Attack_R);
		EnhancedInputComponent->BindAction(S_AttackAction_L, ETriggerEvent::Started, this, &APlayerCharacter::S_Attack_L);
		EnhancedInputComponent->BindAction(W_AttackAction_L, ETriggerEvent::Started, this, &APlayerCharacter::W_Attack_L);
		EnhancedInputComponent->BindAction(LockAction, ETriggerEvent::Started, this, &APlayerCharacter::Lock);
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &APlayerCharacter::StartDash);
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Completed, this, &APlayerCharacter::StopDash);
	}

}

void APlayerCharacter::Move(const FInputActionValue& Value) {
	FVector2D MovementVector = Value.Get<FVector2D>();
	if (GetController() != nullptr) {
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0); // z-축회전값
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		if (USkeletalMeshComponent* Mymesh = GetMesh()) {
			if (auto animInst = Cast<UPlayerCharacterAnimInstance>(Mymesh->GetAnimInstance())) {
				if (animInst->isMontagePlaying == false) {
					AddMovementInput(ForwardDirection, MovementVector.Y);
					AddMovementInput(RightDirection, MovementVector.X);
				}
			}
		}
	}
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}

}
void APlayerCharacter::MouseLook(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput( - LookAxisVector.Y);
	}

}
void APlayerCharacter::W_Attack_R(const FInputActionValue& Value) {
	if (Stamina < 50) { return; }
	auto animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->PlayW_Attack_R_Montage();
}

void APlayerCharacter::S_Attack_R(const FInputActionValue& Value) {
	if (Stamina < 50) { return; }
	auto animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->PlayS_Attack_R_Montage();
}

void APlayerCharacter::W_Attack_L(const FInputActionValue& Value) {
	if (Stamina < 50) { return; }
	auto animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->PlayW_Attack_L_Montage();
}

void APlayerCharacter::S_Attack_L(const FInputActionValue& Value) {
	if (Stamina < 50) { return; }
	auto animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	animInst->PlayS_Attack_L_Montage();
}

void APlayerCharacter::Dodge(const FInputActionValue& Value) {
	if (Stamina > 30)
	{
		auto animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
		animInst->PlayDodgeMontage();
	}
}

void APlayerCharacter::Lock(const FInputActionValue& Value) {
	if (isLockOn) { 
		isLockOn = false; 
		bUseControllerRotationYaw = false;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		Spawner->DestroyLockOnWidget();
		return; }
	FVector StartLocation = GetFollowCamera()->GetComponentLocation();
	StartLocation.Z += 30;
	FVector EndLocation = StartLocation + GetFollowCamera()->GetForwardVector() * LockTraceDistance;
	TArray<FHitResult> HitResults;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(this);
	bool bHit = UKismetSystemLibrary::SphereTraceMultiForObjects(
		GetWorld(),
		StartLocation,
		EndLocation,
		LockRadius,
		ObjectTypes,
		true,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		HitResults,
		true
	);
	if (bHit && HitResults.Num() > 0) {
		TargetActor = HitResults[0].GetActor();
		isLockOn = true;
		bUseControllerRotationYaw = true;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		Spawner->SpawnLockOnWidget(TargetActor);

	}
}

void APlayerCharacter::GetDamaged(float AttackPoints) {
	HealthPoints -= 10.f * AttackPoints / Armer;
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("HealthPoints : %.2f"), HealthPoints));
	}
	auto animInst = Cast<UPlayerCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	if (HealthPoints <= 0)
	{
		isDead = true;
	}
	else {
		animInst->PlayDamageMontage();
	}
}

void APlayerCharacter::StartDash() {
	if (GetCharacterMovement() && Stamina > 30.f) {
		NormalWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = DashWalkSpeed;
		isUsingStamina = true;
		isDashing = true;
	}
}
void APlayerCharacter::StopDash() {
	if (GetCharacterMovement()) {
		GetCharacterMovement()->MaxWalkSpeed = NormalWalkSpeed;
		isUsingStamina = false;
		isDashing = false;
	}
}
void APlayerCharacter::Dead() {
	;
}