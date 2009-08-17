/*
 ============================================================================
 Name		: pyinfobox.h
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : pyinfobox.h - Cpyinfobox class header
 ============================================================================
 */

// This file defines the API for pyinfobox2.dll

#ifndef __PYINFOBOX_H__
#define __PYINFOBOX_H__

//  Include Files

#include <e32base.h>	// CBase
#include <e32std.h>	 // TBuf
#include <avkon.rsg> //InfoBox
#include <aknmessagequerydialog.h> //InfoBox
#include "Python.h" //Python
#include "symbian_python_ext_util.h" //Python

//  Constants



//  Class Definitions

class Cpyinfobox : public CBase
	{
public:
	// new functions
	static Cpyinfobox* NewL();
	static Cpyinfobox* NewLC();
	~Cpyinfobox();

public:
	TInt InfoBoxDlg(const TDesC& aHeader, const TDesC& aText);
private:
	// new functions
	Cpyinfobox();
	void ConstructL();
	};

#endif  // __PYINFOBOX_H__

