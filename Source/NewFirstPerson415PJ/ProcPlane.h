// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProcPlane.generated.h"

class UProceduralMeshComponent;

UCLASS()
class NEWFIRSTPERSON415PJ_API AProcPlane : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*calls our create mesh function before loading the game*/
	virtual void PostActorCreated() override;

	virtual void PostLoad() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	/*Array of Vectors*/
	UPROPERTY(EditAnywhere)
		TArray<FVector> Vertices;
	
	/*Array of Int*/
	UPROPERTY(EditAnywhere)
		TArray<int> Triangles;

	UPROPERTY(EditAnywhere)
		TArray<FVector2D> UV0;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* PlaneMat;

	UFUNCTION()
		void CreateMesh();



private:
	UProceduralMeshComponent* procMesh;

};
