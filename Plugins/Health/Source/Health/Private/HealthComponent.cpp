// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!GetOwner())
		return;

	CurrentHealth = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeAnyDamage);
}

void UHealthComponent::Death()
{
	GetOwner()->Destroy();
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::TakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("HealthComp damage %f"), Damage));
	ReceiveDamage(Damage);
}

void UHealthComponent::ReceiveDamage(float Damage)
{
	if (Damage < 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("UHealthComponent::ReceiveDamage(): Damage < 0"));
		return;
	}
	
	CurrentHealth = FMath::Max(0.f, (CurrentHealth - Damage));
	if (CurrentHealth == 0.f)
		Death();
}

