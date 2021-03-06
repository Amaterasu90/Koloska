// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PawnMovementComponent.h"
#include "MoveSwitch.h"
#include "RayProvider.h"
#include "DirectionMovementComponent.generated.h"

/**
 * 
 */
UCLASS(abstract)
class KOLASA_API UDirectionMovementComponent : public UPawnMovementComponent, public MoveSwitch
{
	GENERATED_BODY()
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void SetDirection(FVector newDirection);
	void SetMoveFactor(float newMoveFactor);
protected:
	FVector GetDisplacement(float DeltaTime);
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcces = "true"))
	float MoveFactor = 100.0f;
	FVector Direction;
};
