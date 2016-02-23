// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Characters/DirectionMovementComponent.h"
#include "ForwardMovementComponent.h"
#include "GravityMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class KOLASA_API UGravityMovementComponent : public UDirectionMovementComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void SetForward(MoveSwitch* forward);
protected:
	virtual void Move(FVector value, float DeltaTime) override;
	virtual void RotateOrtogonalToPlane(FHitResult & OutHit) override;
	virtual FVector GetDisplacement(float DeltaTime) override;
private:
	MoveSwitch* _forwardMovement;
};
