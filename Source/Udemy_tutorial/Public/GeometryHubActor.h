// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseGeometryActor.h"
#include "GeometryHubActor.generated.h"


USTRUCT(BlueprintType)
struct FGeometryPayLoad
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere)

		TSubclassOf<ABaseGeometryActor> GeometryConmiro;

	UPROPERTY(EditAnywhere)
		FGeometryDataConmiro Data;

	UPROPERTY(EditAnywhere)
		FTransform InitialTransform;
};

USTRUCT(BlueprintType)
struct FArrayStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, Category = "ArrayElements")
		int32 Column_length = 10;
	UPROPERTY(EditAnywhere, Category = "ArrayElements")
		int32 Row_length = 10;

};

UCLASS()
class UDEMY_TUTORIAL_API AGeometryHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeometryHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)

		TSubclassOf<ABaseGeometryActor> GeometryConmiro;
	
	UPROPERTY(EditAnywhere)
		TArray<FGeometryPayLoad> GeometryPayloads;

	UPROPERTY(EditAnywhere, Category = "ArrayLength")
		FArrayStruct ArrayLength;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void DoActorSpawn1();
	void DoActorSpawn2();
	void DoActorSpawn3();
};
