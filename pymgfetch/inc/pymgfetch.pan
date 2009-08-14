/*
 ============================================================================
 Name		: pymgfetch.pan
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : Panic codes
 ============================================================================
 */

#ifndef __PYMGFETCH_PAN__
#define __PYMGFETCH_PAN__

//  Data Types

enum TpymgfetchPanic
	{
	EpymgfetchNullPointer
	};

//  Function Prototypes

GLREF_C void Panic(TpymgfetchPanic aPanic);

#endif  // __PYMGFETCH_PAN__

