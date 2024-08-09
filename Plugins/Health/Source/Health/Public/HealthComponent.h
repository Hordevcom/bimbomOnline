// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);

UCLASS( ClassGroup=(Health), meta=(BlueprintSpawnableComponent) )
class HEALTH_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(BlueprintAssignable)
		FOnDeath OnDeath;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void Death();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void TakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION(BlueprintCallable)
		void ReceiveDamage(float Damage);

private:
	UPROPERTY(EditAnywhere, Category = "Health", meta = (AllowPrivateAccess = "true"))
		float MaxHealth = 100.f;

		float CurrentHealth;
	
};
