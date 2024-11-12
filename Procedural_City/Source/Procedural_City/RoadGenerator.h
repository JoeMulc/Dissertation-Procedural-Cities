// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "stdlib.h"
#include "RoadGenerator.generated.h"

UENUM(BlueprintType)
enum class ERoadType : uint8 {
	Main       UMETA(DisplayName = "Main"),
	Secondary        UMETA(DisplayName = "Secondary"),
	Tertiary        UMETA(DisplayName = "Tertiary"),
};


USTRUCT(BlueprintType)
struct FRoad
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Start;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector End;
	//terrible name
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector turnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) ERoadType roadType;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Road Generation|General") int32 maxRoads = 10000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|General") FVector roadStep = FVector(200, 0, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|General") int32 branchCap = 15;

	int32 branchCounter = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|Main Roads") float maxMainRoadLength = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|Main Roads") float mainRoadBranchChance = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|Secondary Roads") float secondaryRoadBranchChance = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|Secondary Roads") float MaxSecondaryRoadLength = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|General") float intensity = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Road Generation|World Constraints") TArray<AActor*> water;



	UFUNCTION(BlueprintCallable) TArray<FRoad> GenerateRoads();

	void AddRoads(TArray<FProposedRoad*>& segQ, FProposedRoad* current);

	void AddForwardRoad(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, ERoadType newType);

	void AddRoadSide(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, bool left, ERoadType newType);

	bool CheckConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current, TArray<FProposedRoad*>& segQ);

	bool CheckGlobalConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current, TArray<FProposedRoad*>& segQ);


	float randFloat();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
