// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementTypeConmiro : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryDataConmiro
{
	GENERATED_USTRUCT_BODY()
	//Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude = 50.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 2.0f;

	//Дефолтное значение перемещения актера
	UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementTypeConmiro MoveType = EMovementTypeConmiro::Static;
};


UCLASS()
class UDEMY_TUTORIAL_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Geometry Data")
	FGeometryDataConmiro GeometryDataCon;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 4;

	UPROPERTY(EditDefaultsOnly, Category = "Kills")
	int32 KillsNum = 7;

	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 34.345;

	UPROPERTY(EditAnywhere, Category = "Dead")
	bool IsDead = false;

	UPROPERTY(VisibleAnywhere, Category = "HasWeapon?")
	bool HasWeapon = true;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//Методы
private:
	void printTypes();
	void printStringTypes();
	void printTransform();

//переменные
private:
	FVector InitlocationConmiro;
};
