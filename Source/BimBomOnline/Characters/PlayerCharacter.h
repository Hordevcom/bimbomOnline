// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class AWeaponBase;

UCLASS(config = Game)
class BIMBOMONLINE_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* AimAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* AttackAction;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<AWeaponBase> DefaultWeaponClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
		FName WeaponAttachSocketName;
	
public:
	APlayerCharacter();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for attack input */
	void Attack(const FInputActionValue& Value);

	void Aim(const FInputActionValue& Value);
	void StopAim(const FInputActionValue& Value);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void BeginPlay();

	virtual void Tick(float DeltaTime) override;
	
private:
	void EquipDefaultWeapon();

	TObjectPtr<AWeaponBase> EquippedWeapon;
};
