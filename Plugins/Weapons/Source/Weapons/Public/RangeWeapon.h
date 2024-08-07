// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBase.h"
#include "RangeWeapon.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class WEAPONS_API ARangeWeapon : public AWeaponBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UParticleSystem> MuzzleFireParticles;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Effects", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<UParticleSystem> ImpactParticles;

	UPROPERTY(EditDefaultsOnly, Category = "Shooting", meta = (AllowPrivateAccess = "true"))
		FName ShootStartSocket;

private:
	void ShootLineTrace();

public:
	virtual void Attack() override;

	void PlayImpactEffect(const FVector& ImpactLocation);
	void PlayMuzzleEffect();
};
