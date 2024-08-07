// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeWeapon.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

void ARangeWeapon::ShootLineTrace()
{
	if (ShootStartSocket.IsNone())
	{
		UE_LOG(LogTemp, Warning, TEXT("ARangeWeapon: ShootStartSocket.IsNone()"));
		return;
	}

	FHitResult HitResult;
	FVector Start = Mesh->GetSocketLocation(ShootStartSocket);
	FVector End = Start + GetActorRightVector() * 2000;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_GameTraceChannel1);
	DrawDebugLine(GetWorld(), Start,	End,
		FColor::Red, true, 0.3f, 0,1.f);

	PlayMuzzleEffect();

	if (!HitResult.IsValidBlockingHit())
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(1, 2.f, 
				FColor::Emerald, "Hit result not blocking anything!");
		return;
	}
		

	PlayImpactEffect(HitResult.Location);
	

	if (AActor* TargetActor = HitResult.GetActor())
		ApplyDamageToActor(TargetActor);
}

void ARangeWeapon::Attack()
{
	AWeaponBase::Attack();

	ShootLineTrace();
}

void ARangeWeapon::PlayImpactEffect(const FVector& ImpactLocation)
{
	FTransform ParticleTransform;
	ParticleTransform.SetLocation(ImpactLocation);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, ParticleTransform);
}

void ARangeWeapon::PlayMuzzleEffect()
{
	FTransform ParticleTransform;
	ParticleTransform.SetLocation(Mesh->GetSocketLocation(ShootStartSocket));
	//ParticleTransform = Mesh->GetSocketTransform(ShootStartSocket);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleFireParticles, ParticleTransform);
}
