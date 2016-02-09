// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "NGPawnMovementComponent.h"
#include "CharacterWithoutGravity.generated.h"

UCLASS()
class KOLASA_API ACharacterWithoutGravity : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* BoomCamera;

	UPROPERTY(EditAnywhere)
	UCameraComponent* PlayerCamera;

	UPROPERTY(EditAnywhere)
	UNGPawnMovementComponent* MovementComponent;

	UArrowComponent* DownTrace;
	UArrowComponent* ForwardTrace;

	// Sets default values for this pawn's properties
	ACharacterWithoutGravity();

	ACharacterWithoutGravity(TCHAR* skeletalMeshPath, TCHAR* animBlueprintPath);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual UPawnMovementComponent* GetMovementComponent() const override;

private:
	void InitializeCapsule();
	void InitializeStaticMesh(TCHAR* skeletalMeshPath);
	void InitializeSpringArm();
	void InitializeCamera();
	void InitializeAnimationClass(TCHAR* animBlueprintPath);
	void InitializeAnimationBlueprint(TCHAR* animBlueprintPath);
	void InitializeMovementComponent();
	void InitializeForwardTrace();
	void InitializeDownTrace();

	void EventMoveRight(float AxisValue);
	void EventTurn(float AxisValue);
	void EventLookUp(float AxisValue);
	
	FRotator GetYawRotator();
	void RotateOrtogonalToPlane(FHitResult & OutHit);
	bool IsHitObstacle(const UArrowComponent* arm, float armLenght, FHitResult& outResult);
	void MoveForward(float DeltaTime);
};