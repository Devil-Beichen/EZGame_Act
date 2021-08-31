// Copyright Epic Games, Inc. All Rights Reserved.

#include "CH_GameMain.h"

#define LOCTEXT_NAMESPACE "FCH_GameMainModule"

void FCH_GameMainModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FCH_GameMainModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCH_GameMainModule, CH_GameMain)