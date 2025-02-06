// Fill out your copyright notice in the Description page of Project Settings.


#include "RoadGenerator.h"
#include "Kismet/GameplayStatics.h"

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

	stream.Initialize(seed);
}

// Called every frame
void ARoadGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<FRoad> ARoadGenerator::GenerateRoads()
{
	UE_LOG(LogTemp, Warning, TEXT("Started!"));

	TArray<FRoad> finalNetwork;

	TArray<FProposedRoad*> propQ;
	TArray<FProposedRoad*> secondQ;

	FProposedRoad* initRoad = new FProposedRoad();
	FRoad* initSeg = new FRoad();

	//Create initial segment
	initSeg->Start = FVector(0, 0, 0);
	initSeg->End = initSeg->Start + roadStep;
	initSeg->turnPoint = roadStep;
	initSeg->roadType = ERoadType::Main;

	//Create initial proposed road
	initRoad->segment = initSeg;
	initRoad->rotator = FRotator(0, 0, 0);
	initRoad->varianceRotor = FRotator(0, 0, 0);
	initRoad->roadLength = 1.f;

	propQ.Push(initRoad);

	//While proposed roads isnt empty and the number of semgments in the final network is less than the allowed max roads
	while (propQ.Num() > 0 && finalNetwork.Num() < maxRoads)
	{
		FProposedRoad* current = propQ.Last();

		propQ.Pop();

		if (current->segment->roadType == ERoadType::Secondary && current->roadLength > 1)
		{
			secondQ.Push(current);
		}

		//Check constraints for current road
		if (CheckConstraints(finalNetwork, current, propQ) && (current->segment->roadType != ERoadType::Secondary || mainRoadsComplete == true || current->roadLength == 1))
		{
			//if passes constraint check push to the final network
			finalNetwork.Push(*current->segment);

			//Add roads the to the road
			AddRoads(propQ, current);
		}


		if (propQ.Num() == 0 && mainCheck == false)
		{
			UE_LOG(LogTemp, Display, TEXT("We in here!"));
			mainRoadsComplete = true;
			mainCheck = true;
			while (secondQ.Num() != 0)
			{
				//propQ.Push(secondQ.Top());
				UE_LOG(LogTemp, Display, TEXT("Bongin! - %i"), secondQ.Top()->roadLength);
				propQ.Push(secondQ.Top());
				secondQ.Pop();
			}
		}

		
		
	
		//UE_LOG(LogTemp, Display, TEXT("Q size - %i"), propQ.Num());
		//UE_LOG(LogTemp, Display, TEXT("Rand - %f"), randFloat());
	}

	UE_LOG(LogTemp, Warning, TEXT("Finished!"));
	return finalNetwork;
}

void ARoadGenerator::AddRoads(TArray<FProposedRoad*>& segQ, FProposedRoad* current)
{
	//Generate forward road if max length not reached		added some variance in size dont know if i like this + FMath::RandRange(-5, 5)

	//Switch on road type for adding a forward road
	switch (current->segment->roadType)
	{
	//Add forward road if main has not reached max length
	case(ERoadType::Main):

		//Added some variance to distance of roads
		if (current->roadLength <= maxMainRoadLength + stream.RandRange(-maxMainRoadLength / 10, maxMainRoadLength/ 10))
		{
			AddForwardRoad(segQ, current, ERoadType::Main);
		}
		break;
	//Add forward road
	case(ERoadType::Secondary):

		if (current->roadLength <= MaxSecondaryRoadLength)
		{
			AddForwardRoad(segQ, current, ERoadType::Secondary);
		}
		break;
	//Add forward road
	case(ERoadType::Coastal):
		UE_LOG(LogTemp, Display, TEXT("Coastal!"));
		if (current->roadLength <= maxCoastalRoadLength)
		{
			AddForwardRoad(segQ, current, ERoadType::Coastal);
		}
		break;
	}

	//Road branching logic
	if (randFloat() < mainRoadBranchChance && branchCounter <= branchCap && current->segment->roadType == ERoadType::Main && mainLengthBeforeIntersection < current->roadLength)
	{
		//Flip flop for deciding left or right road to be added
		if (randFloat() < 0.5)
		{
			//Chance for main or secondary road to be added
			if (stream.RandRange(0, 100) > 90)
			{
				UE_LOG(LogTemp, Display, TEXT("Main - Left"));
				AddRoadSide(segQ, current, true, ERoadType::Main);
			}																							//SHOULD BE A FUNCTION REUSED LOGIC
			else
			{
				AddRoadSide(segQ, current, true, ERoadType::Secondary);
			}
		}
		else
		{
			if (stream.RandRange(0, 100) > 90)
			{
				UE_LOG(LogTemp, Display, TEXT("Main - Right"));
				AddRoadSide(segQ, current, false, ERoadType::Main);
			}
			else
			{
				AddRoadSide(segQ, current, false, ERoadType::Secondary);
			}
		}
	}
	//Secondary road branching
	else if (randFloat() < secondaryRoadBranchChance && branchCounter <= branchCap && current->segment->roadType == ERoadType::Secondary && secondaryLengthBeforeIntersection < current->roadLength)
	{
		if (randFloat() < 0.5)
		{
			AddRoadSide(segQ, current, true, ERoadType::Secondary);
		}
		else
		{
			AddRoadSide(segQ, current, false, ERoadType::Secondary);
		}
	}
	
}

void ARoadGenerator::AddForwardRoad(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, ERoadType newType)
{
	//UE_LOG(LogTemp, Display, TEXT("ForwardRoad"));

	FProposedRoad* newPropRoad = new FProposedRoad();
	FRoad* newSeg = new FRoad();

	FRoad* prevSeg = previous->segment;

	//Set the correct intensity based on road type
	intensity = newType == ERoadType::Main ? mainRoadIntensity : secondaryRoadIntensity;

	//Sprinkles some randomness on the rotation
	newPropRoad->varianceRotor = previous->varianceRotor + FRotator(0, intensity * (randFloat() - 0.5f), 0);
	//Sets rotator based on previous
	newPropRoad->rotator = previous->rotator + newPropRoad->varianceRotor;

	//Initialise road with new values
	newSeg->Start = prevSeg->End;
	newSeg->End = newSeg->Start + newPropRoad->rotator.RotateVector(roadStep);
	newSeg->turnPoint = prevSeg->End - prevSeg->Start;
	newSeg->roadType = newType;
	
	//Defines new segment
	newPropRoad->segment = newSeg;
	newPropRoad->roadLength = previous->roadLength + 1;

	//Pushed road to queue
	segQ.Push(newPropRoad);
}

void ARoadGenerator::AddRoadSide(TArray<FProposedRoad*>& segQ, FProposedRoad* previous, bool left, ERoadType newType)
{
	FProposedRoad* newPropRoad = new FProposedRoad();
	FRoad* newSeg = new FRoad();

	FRoad* prevSeg = previous->segment;

	intensity = newType == ERoadType::Main ? mainRoadIntensity : secondaryRoadIntensity;

	//Sprinles some randomness
	newPropRoad->varianceRotor = FRotator(0, intensity * (randFloat() - 0.5f), 0);
	//Sets direction based on left/right
	FRotator direction = left ? FRotator(0, 270, 0) : FRotator(0, 90, 0);
	UE_LOG(LogTemp, Display, TEXT("Direction - %f"), direction.Yaw);
	newPropRoad->rotator = previous->rotator + newPropRoad->varianceRotor + direction;

	//Initialise new road values
	FVector offsetDirection = newPropRoad->rotator.RotateVector(FVector(200, 0, 0));
	newSeg->Start = (prevSeg->End - prevSeg->Start) / 2 + prevSeg->Start + offsetDirection;
	newSeg->End = newSeg->Start + newPropRoad->rotator.RotateVector(roadStep);
	newSeg->turnPoint = newSeg->End - newSeg->Start;
	newSeg->roadType = newType;

	//Defines new segment
	newPropRoad->segment = newSeg;
	newPropRoad->roadLength = 1;
	
	//Pushes new segment to the queue
	segQ.Push(newPropRoad);

}

bool ARoadGenerator::CheckConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current, TArray<FProposedRoad*>& segQ)
{
	return CheckGlobalConstraints(finalNetwork, current, segQ);
}

bool ARoadGenerator::CheckGlobalConstraints(TArray<FRoad> finalNetwork, FProposedRoad* current, TArray<FProposedRoad*>& segQ)
{
	//Get centre of proposed road
	FVector propMid = (current->segment->End - current->segment->Start) / 2 + current->segment->Start;

	// For each road in the final network
	for (const FRoad road : finalNetwork)
	{
		//get centre of final road to be compared
		FVector finalMid = (road.End - road.Start) / 2 + road.Start;
		
		//Check distance based on road size - magic number here fix me!!!!!!!
		if (FVector::Dist(finalMid, propMid) < 150)												//TERRIBLE DIST CHECK MAKE BETTER!!!!!!!
		{
			UE_LOG(LogTemp, Display, TEXT("OVERLAP"));
			return false;
		}
	}
														//REALLY SHOULD BE CHECKING FOR NULLPTRS
	//For each water volume
	for (AActor* w : water)
	{
		AVolume* waterVolume = Cast<AVolume>(w);
		
		//If proposed road is within the volume
		if (waterVolume->EncompassesPoint(current->segment->End + (current->segment->End - current->segment->Start) * 50, 75.f))
		{
			//UE_LOG(LogTemp, Display, TEXT("Water!"));
			if (current->segment->roadType == ERoadType::Main || current->segment->roadType == ERoadType::Coastal)
			{
				double angle = 0;
				int checker = 0;

				while (angle < 360)
				{
					current->segment->End = current->segment->Start + FRotator(0, angle, 0).RotateVector(current->segment->End - current->segment->Start);
					for (AActor* wat : water)
					{
						AVolume* wV = Cast<AVolume>(wat);
						if (!wV->EncompassesPoint(current->segment->End + (current->segment->End - current->segment->Start) * 50, 75.f))
						{
							//UE_LOG(LogTemp, Warning, TEXT("Checker LEFT %i!"), checker);
							checker++;
						}
						
					}

					//ensures all volumes have been checked
					if (checker >= 10)					//MAGIC NUMBER
					{
						current->segment->turnPoint = current->segment->End - current->segment->Start;
						current->roadLength = current->segment->roadType == ERoadType::Coastal ? current->roadLength++ : 0;
						current->segment->roadType = ERoadType::Coastal;
						UE_LOG(LogTemp, Warning, TEXT("Angle %f!"), angle);
						return true;
					}

					checker = 0;
					angle++;
				}
				UE_LOG(LogTemp, Warning, TEXT("Splitting"));
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

float ARoadGenerator::randFloat()
{
	//UE_LOG(LogTemp, Display, TEXT("Rand - %f"), stream.GetFraction());
	return stream.GetFraction();
}
