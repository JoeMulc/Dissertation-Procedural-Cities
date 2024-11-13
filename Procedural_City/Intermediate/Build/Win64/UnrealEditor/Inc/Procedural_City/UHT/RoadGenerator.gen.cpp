// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Procedural_City/RoadGenerator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRoadGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
PROCEDURAL_CITY_API UClass* Z_Construct_UClass_ARoadGenerator();
PROCEDURAL_CITY_API UClass* Z_Construct_UClass_ARoadGenerator_NoRegister();
PROCEDURAL_CITY_API UEnum* Z_Construct_UEnum_Procedural_City_ERoadType();
PROCEDURAL_CITY_API UScriptStruct* Z_Construct_UScriptStruct_FRoad();
UPackage* Z_Construct_UPackage__Script_Procedural_City();
// End Cross Module References

// Begin Enum ERoadType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERoadType;
static UEnum* ERoadType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ERoadType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ERoadType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Procedural_City_ERoadType, (UObject*)Z_Construct_UPackage__Script_Procedural_City(), TEXT("ERoadType"));
	}
	return Z_Registration_Info_UEnum_ERoadType.OuterSingleton;
}
template<> PROCEDURAL_CITY_API UEnum* StaticEnum<ERoadType>()
{
	return ERoadType_StaticEnum();
}
struct Z_Construct_UEnum_Procedural_City_ERoadType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Coastal.DisplayName", "Coastal" },
		{ "Coastal.Name", "ERoadType::Coastal" },
		{ "Main.DisplayName", "Main" },
		{ "Main.Name", "ERoadType::Main" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
		{ "Secondary.DisplayName", "Secondary" },
		{ "Secondary.Name", "ERoadType::Secondary" },
		{ "Tertiary.DisplayName", "Tertiary" },
		{ "Tertiary.Name", "ERoadType::Tertiary" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ERoadType::Main", (int64)ERoadType::Main },
		{ "ERoadType::Secondary", (int64)ERoadType::Secondary },
		{ "ERoadType::Tertiary", (int64)ERoadType::Tertiary },
		{ "ERoadType::Coastal", (int64)ERoadType::Coastal },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Procedural_City_ERoadType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Procedural_City,
	nullptr,
	"ERoadType",
	"ERoadType",
	Z_Construct_UEnum_Procedural_City_ERoadType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Procedural_City_ERoadType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Procedural_City_ERoadType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Procedural_City_ERoadType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Procedural_City_ERoadType()
{
	if (!Z_Registration_Info_UEnum_ERoadType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERoadType.InnerSingleton, Z_Construct_UEnum_Procedural_City_ERoadType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ERoadType.InnerSingleton;
}
// End Enum ERoadType

// Begin ScriptStruct FRoad
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Road;
class UScriptStruct* FRoad::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Road.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Road.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoad, (UObject*)Z_Construct_UPackage__Script_Procedural_City(), TEXT("Road"));
	}
	return Z_Registration_Info_UScriptStruct_Road.OuterSingleton;
}
template<> PROCEDURAL_CITY_API UScriptStruct* StaticStruct<FRoad>()
{
	return FRoad::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRoad_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Start_MetaData[] = {
		{ "Category", "Road" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_End_MetaData[] = {
		{ "Category", "Road" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_turnPoint_MetaData[] = {
		{ "Category", "Road" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//terrible name\n" },
#endif
		{ "ModuleRelativePath", "RoadGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "terrible name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_roadType_MetaData[] = {
		{ "Category", "Road" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Start;
	static const UECodeGen_Private::FStructPropertyParams NewProp_End;
	static const UECodeGen_Private::FStructPropertyParams NewProp_turnPoint;
	static const UECodeGen_Private::FBytePropertyParams NewProp_roadType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_roadType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoad>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoad_Statics::NewProp_Start = { "Start", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoad, Start), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Start_MetaData), NewProp_Start_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoad_Statics::NewProp_End = { "End", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoad, End), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_End_MetaData), NewProp_End_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FRoad_Statics::NewProp_turnPoint = { "turnPoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoad, turnPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_turnPoint_MetaData), NewProp_turnPoint_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FRoad_Statics::NewProp_roadType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FRoad_Statics::NewProp_roadType = { "roadType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoad, roadType), Z_Construct_UEnum_Procedural_City_ERoadType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_roadType_MetaData), NewProp_roadType_MetaData) }; // 151541504
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoad_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoad_Statics::NewProp_Start,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoad_Statics::NewProp_End,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoad_Statics::NewProp_turnPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoad_Statics::NewProp_roadType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoad_Statics::NewProp_roadType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoad_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoad_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Procedural_City,
	nullptr,
	&NewStructOps,
	"Road",
	Z_Construct_UScriptStruct_FRoad_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoad_Statics::PropPointers),
	sizeof(FRoad),
	alignof(FRoad),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoad_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoad_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRoad()
{
	if (!Z_Registration_Info_UScriptStruct_Road.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Road.InnerSingleton, Z_Construct_UScriptStruct_FRoad_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Road.InnerSingleton;
}
// End ScriptStruct FRoad

// Begin Class ARoadGenerator Function GenerateRoads
struct Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics
{
	struct RoadGenerator_eventGenerateRoads_Parms
	{
		TArray<FRoad> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRoad, METADATA_PARAMS(0, nullptr) }; // 55979343
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoadGenerator_eventGenerateRoads_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 55979343
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ARoadGenerator, nullptr, "GenerateRoads", nullptr, nullptr, Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::PropPointers), sizeof(Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::RoadGenerator_eventGenerateRoads_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::Function_MetaDataParams), Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::RoadGenerator_eventGenerateRoads_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ARoadGenerator_GenerateRoads()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ARoadGenerator_GenerateRoads_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ARoadGenerator::execGenerateRoads)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FRoad>*)Z_Param__Result=P_THIS->GenerateRoads();
	P_NATIVE_END;
}
// End Class ARoadGenerator Function GenerateRoads

// Begin Class ARoadGenerator
void ARoadGenerator::StaticRegisterNativesARoadGenerator()
{
	UClass* Class = ARoadGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateRoads", &ARoadGenerator::execGenerateRoads },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARoadGenerator);
UClass* Z_Construct_UClass_ARoadGenerator_NoRegister()
{
	return ARoadGenerator::StaticClass();
}
struct Z_Construct_UClass_ARoadGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RoadGenerator.h" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxRoads_MetaData[] = {
		{ "Category", "Road Generation|General" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_roadStep_MetaData[] = {
		{ "Category", "Road Generation|General" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_branchCap_MetaData[] = {
		{ "Category", "Road Generation|General" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxMainRoadLength_MetaData[] = {
		{ "Category", "Road Generation|Main Roads" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mainRoadBranchChance_MetaData[] = {
		{ "Category", "Road Generation|Main Roads" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mainRoadIntensity_MetaData[] = {
		{ "Category", "Road Generation|Main Roads" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSecondaryRoadLength_MetaData[] = {
		{ "Category", "Road Generation|Secondary Roads" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_secondaryRoadBranchChance_MetaData[] = {
		{ "Category", "Road Generation|Secondary Roads" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_secondaryRoadIntensity_MetaData[] = {
		{ "Category", "Road Generation|Secondary Roads" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_water_MetaData[] = {
		{ "Category", "Road Generation|World Constraints" },
		{ "ModuleRelativePath", "RoadGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_maxRoads;
	static const UECodeGen_Private::FStructPropertyParams NewProp_roadStep;
	static const UECodeGen_Private::FIntPropertyParams NewProp_branchCap;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_maxMainRoadLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_mainRoadBranchChance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_mainRoadIntensity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSecondaryRoadLength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_secondaryRoadBranchChance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_secondaryRoadIntensity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_water_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_water;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ARoadGenerator_GenerateRoads, "GenerateRoads" }, // 4179671619
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARoadGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_maxRoads = { "maxRoads", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, maxRoads), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxRoads_MetaData), NewProp_maxRoads_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_roadStep = { "roadStep", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, roadStep), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_roadStep_MetaData), NewProp_roadStep_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_branchCap = { "branchCap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, branchCap), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_branchCap_MetaData), NewProp_branchCap_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_maxMainRoadLength = { "maxMainRoadLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, maxMainRoadLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxMainRoadLength_MetaData), NewProp_maxMainRoadLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_mainRoadBranchChance = { "mainRoadBranchChance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, mainRoadBranchChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mainRoadBranchChance_MetaData), NewProp_mainRoadBranchChance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_mainRoadIntensity = { "mainRoadIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, mainRoadIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mainRoadIntensity_MetaData), NewProp_mainRoadIntensity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_MaxSecondaryRoadLength = { "MaxSecondaryRoadLength", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, MaxSecondaryRoadLength), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSecondaryRoadLength_MetaData), NewProp_MaxSecondaryRoadLength_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_secondaryRoadBranchChance = { "secondaryRoadBranchChance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, secondaryRoadBranchChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_secondaryRoadBranchChance_MetaData), NewProp_secondaryRoadBranchChance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_secondaryRoadIntensity = { "secondaryRoadIntensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, secondaryRoadIntensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_secondaryRoadIntensity_MetaData), NewProp_secondaryRoadIntensity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_water_Inner = { "water", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ARoadGenerator_Statics::NewProp_water = { "water", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ARoadGenerator, water), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_water_MetaData), NewProp_water_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARoadGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_maxRoads,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_roadStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_branchCap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_maxMainRoadLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_mainRoadBranchChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_mainRoadIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_MaxSecondaryRoadLength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_secondaryRoadBranchChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_secondaryRoadIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_water_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARoadGenerator_Statics::NewProp_water,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARoadGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ARoadGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Procedural_City,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARoadGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ARoadGenerator_Statics::ClassParams = {
	&ARoadGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ARoadGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ARoadGenerator_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARoadGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_ARoadGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ARoadGenerator()
{
	if (!Z_Registration_Info_UClass_ARoadGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARoadGenerator.OuterSingleton, Z_Construct_UClass_ARoadGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ARoadGenerator.OuterSingleton;
}
template<> PROCEDURAL_CITY_API UClass* StaticClass<ARoadGenerator>()
{
	return ARoadGenerator::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ARoadGenerator);
ARoadGenerator::~ARoadGenerator() {}
// End Class ARoadGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ERoadType_StaticEnum, TEXT("ERoadType"), &Z_Registration_Info_UEnum_ERoadType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 151541504U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRoad::StaticStruct, Z_Construct_UScriptStruct_FRoad_Statics::NewStructOps, TEXT("Road"), &Z_Registration_Info_UScriptStruct_Road, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoad), 55979343U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARoadGenerator, ARoadGenerator::StaticClass, TEXT("ARoadGenerator"), &Z_Registration_Info_UClass_ARoadGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARoadGenerator), 2180344607U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_676985540(TEXT("/Script/Procedural_City"),
	Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_RoadGenerator_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
