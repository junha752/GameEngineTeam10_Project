// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyActorSpawner.h"
#include "PlayerCharacter.generated.h"
class UInputAction;
struct FInputActionValue;
class AMyActorSpawner;
class UAnimMontage;
UCLASS()

class GAMEENTEAM10_PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Params")
	float HealthPoints = 500;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Params")
	float Stamina = 500;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Params")
	int Strength = 50;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Params")
	int Armer = 5;


	FORCEINLINE class USpringArmComponent* GetCameraBoom() {
		return CameraBoom;
	}
	FORCEINLINE class UCameraComponent* GetFollowCamera() {
		return FollowCamera;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
	class USceneComponent* SwordStart;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attack")
	class USceneComponent* SwordEnd;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	bool isDead = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	class UStaticMeshComponent* SwordMesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* S_AttackAction_R;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* S_AttackAction_L;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* W_AttackAction_R;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* W_AttackAction_L;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* DodgeAction;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* MouseLookAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* LockAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	float LockTraceDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	float LockRadius;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lock")
	AActor* TargetActor;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lock")
	bool isLockOn = false;



	void W_Attack_R(const FInputActionValue& Value);
	void S_Attack_R(const FInputActionValue& Value);
	void W_Attack_L(const FInputActionValue& Value);
	void S_Attack_L(const FInputActionValue& Value);

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Dodge(const FInputActionValue& Value);
	void Lock(const FInputActionValue& Value);
	void MouseLook(const FInputActionValue& Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetDamaged(float AttackPoints);
	void StartDash();
	void StopDash();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player Params")
	float DashWalkSpeed = 1000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool isUsingStamina = false;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	AMyActorSpawner* Spawner;

	float NormalWalkSpeed;
	bool isDashing = false;

	void Dead();
};

