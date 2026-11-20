// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"
#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NewFirstPerson415PJProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config=Game)
class ANewFirstPerson415PJProjectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	//Visible mesh for the projectile
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ballMesh;

	//Base decal material spawned when projectile hits something
	UPROPERTY(EditAnywhere)
		UMaterial* baseMat;

	//Stores a randomly generated color
	UPROPERTY()
		FLinearColor randColor;

	//Material used by projectile mesh
	UPROPERTY(EditAnywhere)
		UMaterialInterface* projMat;

	//Dynamic material used to change color for gameplay
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;
	UPROPERTY(EditAnywhere)
	UNiagaraSystem* colorP;

//constructor for default values
public:
	ANewFirstPerson415PJProjectile();

protected:
	//called when the projectile first spawns into the level
	virtual void BeginPlay();

//called whenever the projectile collides with something
public:
	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

