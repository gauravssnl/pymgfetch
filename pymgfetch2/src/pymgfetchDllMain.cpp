/*
 ============================================================================
 Name		: pymgfetchDll.cpp 
 Author	  : Thomas Reitmaier
 Copyright   : Your copyright notice
 Description : pymgfetchDll.cpp - main DLL source
 ============================================================================
 */

//  Include Files  

#include <e32std.h>		 // GLDEF_C

#ifndef EKA2 // for EKA1 only
EXPORT_C TInt E32Dll(TDllReason /*aReason*/)
// Called when the DLL is loaded and unloaded. Note: have to define
// epoccalldllentrypoints in MMP file to get this called in THUMB.
	{
	return KErrNone;
	}
#endif

