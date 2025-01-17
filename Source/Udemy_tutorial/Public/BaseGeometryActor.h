// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnColorChanged, const FLinearColor&,
	Color, const FString&, Name);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTimerFinished, AActor*);

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
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Amplitude = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Frequency = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Rotate = 2.0f;

	//Дефолтное значение перемещения актера
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		EMovementTypeConmiro MoveType = EMovementTypeConmiro::Static;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Design")
		FLinearColor Color = FLinearColor::Black;

	UPROPERTY(EditAnywhere, Category = "Design")
	float TimerConmiroRate = 3.0f; //частота срабатывания таймера

	UPROPERTY(EditAnywhere, Category = "Design")
	int32 MaxTimerCount = 10; //сколько сработает таймер

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
	
	void SetGeometryData(const FGeometryDataConmiro& Data) {GeometryDataCon = Data;}

	UFUNCTION(BlueprintCallable)
	FGeometryDataConmiro GetGeometryData() const { return GeometryDataCon; }

	UPROPERTY(BlueprintAssignable)
	FOnColorChanged OnColorChanged;

	FOnTimerFinished OnTimerFinished;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	 
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Geometry Data")
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

	void SetColor(const FLinearColor& Color);
	void OnTimerFired();
	void HandleMovement();

	//переменные
private:

	int32  TimerCount = 0;

	FVector InitlocationConmiro;
	FRotator InitRotationConmiro;
	FTimerHandle TimerHandleConmiro;
};
