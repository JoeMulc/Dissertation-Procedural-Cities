// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WaterBoundingBox.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROCEDURAL_CITY_WaterBoundingBox_generated_h
#error "WaterBoundingBox.generated.h already included, missing '#pragma once' in WaterBoundingBox.h"
#endif
#define PROCEDURAL_CITY_WaterBoundingBox_generated_h

#define FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWaterBoundingBox(); \
	friend struct Z_Construct_UClass_UWaterBoundingBox_Statics; \
public: \
	DECLARE_CLASS(UWaterBoundingBox, UBoxComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Procedural_City"), NO_API) \
	DECLARE_SERIALIZER(UWaterBoundingBox)


#define FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWaterBoundingBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UWaterBoundingBox(UWaterBoundingBox&&); \
	UWaterBoundingBox(const UWaterBoundingBox&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWaterBoundingBox); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWaterBoundingBox); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWaterBoundingBox) \
	NO_API virtual ~UWaterBoundingBox();


#define FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_12_PROLOG
#define FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_15_INCLASS_NO_PURE_DECLS \
	FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROCEDURAL_CITY_API UClass* StaticClass<class UWaterBoundingBox>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
