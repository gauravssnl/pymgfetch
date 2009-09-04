/*
 ============================================================================
 Name		: pyfileselect.pan
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : Panic codes
 ============================================================================
 */

#ifndef __PYFILESELECT_PAN__
#define __PYFILESELECT_PAN__

//  Data Types

enum TpyfileselectPanic
	{
	EpyfileselectNullPointer
	};

//  Function Prototypes

GLREF_C void Panic(TpyfileselectPanic aPanic);

#endif  // __PYFILESELECT_PAN__

