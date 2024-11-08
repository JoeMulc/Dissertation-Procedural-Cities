// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "stdlib.h"
#include "RoadGenerator.generated.h"

 
USTRUCT(BlueprintType)
struct FRoad
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector End;
	//terrible name
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector turnPoint;
};

struct FProposedRoad
{
	FRoad* segment;
	FRotator rotator;
	FRotator varianceRotor;

	//Number of segments on this road line
	int32 roadLength;
};

UCLASS()
class PROCEDURAL_CITY_API ARoadGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARoadGenerator();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 maxRoads = 10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector roadStep = FVector(200, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 branchCap = 15;

	int32 branchCounter = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float roadBranchChance = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float maxMainRoadLength = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float intensity = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<AActor*> water;



	UFUNCTION(BlueprintCallable) TArray<FRoad> GenerateRoads();

	void AddRoads(TArray<FProposedRoad*>& segQ, FProposedRoad* current);

	void AddForwardRoad(TArray<FProposedRoad*>& segQ, FProposedRoad* previous);

	void AddRoadSide(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, bool left);

	bool CheckConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current);

	bool CheckGlobalConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current);


	float randFloat();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
