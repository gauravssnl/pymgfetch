/*
 ============================================================================
 Name		: pymgfetch.h
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : pymgfetch.h - Cpymgfetch class header
 ============================================================================
 */

// This file defines the API for pymgfetch.dll

#ifndef __PYMGFETCH_H__
#define __PYMGFETCH_H__

//  Include Files

#include <e32base.h>	// CBase
#include <e32std.h>	 // TBuf
#include <mgfetch.h> //MGFetch
#include "Python.h" //Python
#include "symbian_python_ext_util.h" //Python

//  Class Definitions

class Cpymgfetch : public CBase
	{
public:
	// new functions
	static Cpymgfetch* NewL();
	static Cpymgfetch* NewLC();
	~Cpymgfetch();

public:
	// new functions, example API
	const char* BrowseUsingMGFetchL(TMediaFileType aMediaType,
				TBool allowMultiple, const TDesC& heading, const TDesC& softkey);

private:
	// new functions
	Cpymgfetch();
	void ConstructL();
	};

#endif  // __PYMGFETCH_H__
