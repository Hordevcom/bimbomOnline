// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class INVENTORY_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(Category = "Item Actor")
		void OnItemBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);

	UFUNCTION(Category = "Item Actor")
		void OnItemEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// TODO: Uncomment when create FItemRowStruct!!
	//UPROPERTY(Replicated, BlueprintReadWrite, Category = "Item Actor", meta = (ExposeOnSpawn = true))
		//FItemRowStruct HeldItem;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item Actor", meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ItemMesh;
	
};
