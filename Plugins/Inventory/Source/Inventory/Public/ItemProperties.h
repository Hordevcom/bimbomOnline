// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemProperties.generated.h"

class UInventoryComponent;
class UTexture2D;
class UStaticMesh;
/**
 * 
 */
UENUM(BlueprintType)
enum class EItemCategory : uint8
{
	Everything UMETA(DisplayName = "Everything"),
	Health UMETA(DisplayName = "Health"),
	Weapon UMETA(DisplayName = "Weapon"),
	Armor UMETA(DisplayName = "Armor"),
	Ammo UMETA(DisplayName = "Ammo"),
	Consumable UMETA(DisplayName = "Consumable")

};

USTRUCT(BlueprintType)
struct FItemRowStruct
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Row Struct")
		FName ItemRowName;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Row Struct", meta = (ClampMin = "0"))
		int32 Amount = 1;
};

USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties")
		FString Name = "None";

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties")
		EItemCategory Category = EItemCategory::Everything;

	UPROPERTY(BlueprintReadOnly, Category = "Item Properties")
		bool IsItemInUse = false;

	UPROPERTY(BlueprintReadOnly, Category = "Bag Properties")
		TObjectPtr<UInventoryComponent> ItemBagInventory = nullptr;
};