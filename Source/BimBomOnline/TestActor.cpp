// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"


// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		DrawDebugSphere(GetWorld(),
			GetTestActorLocation(),
			45.f, 40, FColor::Cyan,
			false, 30.f);
	}
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ATestActor::GetTestActorLocation()
{
	return GetActorLocation();
}

