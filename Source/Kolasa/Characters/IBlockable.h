#pragma once



class IBlockable
{
public:
	virtual void ActivateMove();
	virtual void DeactivateMove();
	virtual void ActivateRotation();
	virtual void DeactivateRotation();
	bool IsActiveMove();
	bool IsActiveRotation();
private:
	bool bMoveIsActive;
	bool bRotationIsActive;
};

