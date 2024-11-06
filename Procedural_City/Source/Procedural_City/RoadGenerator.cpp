// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadGenerator.h"

// Sets default values
ARoadGenerator::ARoadGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoadGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoadGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FRoad> ARoadGenerator::GenerateRoads()
{
	TArray<FRoad> finalNetwork;

	TArray<FProposedRoad*> propQ;

	FProposedRoad* initRoad = new FProposedRoad();
	FRoad* initSeg = new FRoad();

	initSeg->Start = FVector(0, 0, 0);
	initSeg->End = initSeg->Start + roadStep;
	initSeg->turnPoint = roadStep;

	initRoad->segment = initSeg;
	initRoad->rotator = FRotator(0, 0, 0);
	initRoad->varianceRotor = FRotator(0, 0, 0);
	initRoad->roadLength = 1.f;

	propQ.Push(initRoad);

	while (propQ.Num() > 0 && finalNetwork.Num() < maxRoads)
	{
		FProposedRoad* current = propQ.Last();

		propQ.Pop();

		//Need a placement check

		finalNetwork.Push(*current->segment);
		AddRoads(propQ, current);

		delete(current->segment);
		delete(current);
		UE_LOG(LogTemp, Display, TEXT("Q size - %i"), propQ.Num());
		UE_LOG(LogTemp, Display, TEXT("Rand - %f"), randFloat());
	}

	return finalNetwork;
}

void ARoadGenerator::AddRoads(TArray<FProposedRoad*>& segQ, FProposedRoad* current)
{
	//Generate forward road if max length not reached
	if (current->roadLength < maxMainRoadLength)
	{
		AddForwardRoad(segQ, current);
	}

	//Randomly crates branching road based on chance		Branch cap to limit number of branches for generation time
	if (randFloat() < roadBranchChance && branchCounter <= branchCap)
	{
		//flip flop for left and right roads
		if (randFloat() < 0.5)
		{
			UE_LOG(LogTemp, Display, TEXT("left road"));
			AddRoadSide(segQ, current, true);
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("left road"));
			AddRoadSide(segQ, current, false);
		}

		branchCounter++;
	}
}

void ARoadGenerator::AddForwardRoad(TArray<FProposedRoad*>& segQ, FProposedRoad* previous)
{
	UE_LOG(LogTemp, Display, TEXT("ForwardRoad"));

	FProposedRoad* newPropRoad = new FProposedRoad();
	FRoad* newSeg = new FRoad();

	FRoad* prevSeg = previous->segment;

	newPropRoad->varianceRotor = previous->varianceRotor + FRotator(0, intensity * (randFloat() - 0.5f), 0);
	newPropRoad->rotator = previous->rotator + newPropRoad->varianceRotor;

	newSeg->Start = prevSeg->End;
	newSeg->End = newSeg->Start + newPropRoad->rotator.RotateVector(roadStep);
	newSeg->turnPoint = prevSeg->End - prevSeg->Start;
	
	newPropRoad->segment = newSeg;
	newPropRoad->roadLength = previous->roadLength + 1;
	segQ.Push(newPropRoad);
}

void ARoadGenerator::AddRoadSide(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, bool left)
{
	FProposedRoad* newPropRoad = new FProposedRoad();
	FRoad* newSeg = new FRoad();

	FRoad* prevSeg = previous->segment;

	newPropRoad->varianceRotor = FRotator(0, intensity * (randFloat() - 0.5f), 0);
	FRotator direction = left ? FRotator(0, 270, 0) : FRotator(0, 90, 0);
	newPropRoad->rotator = previous->rotator + newPropRoad->varianceRotor + direction;

	FVector offsetDirection = left ? newPropRoad->rotator.RotateVector(FVector(200, 0, 0)) : newPropRoad->rotator.RotateVector(FVector(200, 0, 0));
	newSeg->Start = (prevSeg->End - prevSeg->Start) / 2 + prevSeg->Start + offsetDirection;
	newSeg->End = newSeg->Start + newPropRoad->rotator.RotateVector(roadStep);
	newSeg->turnPoint = newSeg->End - newSeg->Start;

	newPropRoad->segment = newSeg;
	newPropRoad->roadLength = 1;
	segQ.Push(newPropRoad);

}

float ARoadGenerator::randFloat()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

