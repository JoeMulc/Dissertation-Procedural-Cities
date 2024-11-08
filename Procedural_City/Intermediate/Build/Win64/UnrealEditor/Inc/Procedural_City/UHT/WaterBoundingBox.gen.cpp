// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Procedural_City/WaterBoundingBox.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaterBoundingBox() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent();
PROCEDURAL_CITY_API UClass* Z_Construct_UClass_UWaterBoundingBox();
PROCEDURAL_CITY_API UClass* Z_Construct_UClass_UWaterBoundingBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_Procedural_City();
// End Cross Module References

// Begin Class UWaterBoundingBox
void UWaterBoundingBox::StaticRegisterNativesUWaterBoundingBox()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWaterBoundingBox);
UClass* Z_Construct_UClass_UWaterBoundingBox_NoRegister()
{
	return UWaterBoundingBox::StaticClass();
}
struct Z_Construct_UClass_UWaterBoundingBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger VirtualTexture" },
		{ "IncludePath", "WaterBoundingBox.h" },
		{ "ModuleRelativePath", "WaterBoundingBox.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWaterBoundingBox>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UWaterBoundingBox_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBoxComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Procedural_City,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWaterBoundingBox_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWaterBoundingBox_Statics::ClassParams = {
	&UWaterBoundingBox::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWaterBoundingBox_Statics::Class_MetaDataParams), Z_Construct_UClass_UWaterBoundingBox_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWaterBoundingBox()
{
	if (!Z_Registration_Info_UClass_UWaterBoundingBox.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWaterBoundingBox.OuterSingleton, Z_Construct_UClass_UWaterBoundingBox_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWaterBoundingBox.OuterSingleton;
}
template<> PROCEDURAL_CITY_API UClass* StaticClass<UWaterBoundingBox>()
{
	return UWaterBoundingBox::StaticClass();
}
UWaterBoundingBox::UWaterBoundingBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWaterBoundingBox);
UWaterBoundingBox::~UWaterBoundingBox() {}
// End Class UWaterBoundingBox

// Begin Registration
struct Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWaterBoundingBox, UWaterBoundingBox::StaticClass, TEXT("UWaterBoundingBox"), &Z_Registration_Info_UClass_UWaterBoundingBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWaterBoundingBox), 3001917242U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_3917222404(TEXT("/Script/Procedural_City"),
	Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Procedural_City_Source_Procedural_City_WaterBoundingBox_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
