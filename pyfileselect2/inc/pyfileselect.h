/*
 ============================================================================
 Name		: pyfileselect.h
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : pyfileselect.h - Cpyfileselect class header
 ============================================================================
 */

// This file defines the API for pyfileselect.dll

#ifndef __PYFILESELECT_H__
#define __PYFILESELECT_H__

//  Include Files

#include <e32base.h>	// CBase
#include <e32std.h>	 // TBuf
#include <mgfetch.h> //MGFetch
#include <caknfileselectiondialog.h> 
#include <caknmemoryselectiondialog.h>
#include <PathInfo.h>
#include "Python.h" //Python
#include "symbian_python_ext_util.h" //Python

//  Class Definitions

class Cpyfileselect : public CBase
	{

public:
	// new functions
	static Cpyfileselect* NewL();
	static Cpyfileselect* NewLC();
	~Cpyfileselect();

public:
	// new functions, example API
	const char* FileSelectionDlg(const TFileName& aPath, const TDesC& title);
	const char* MemorySelectionDlg(const TDesC& heading);
	const char* FolderSelectionDlg(TCommonDialogType dialogType,
			TDesC& memory, const TDesC& heading, const TDesC& rightRoot, const TDesC& left);
	const char* descriptorToStringL(const TDesC& aDescriptor);
	
	const char* DigitalSoundsPath();
	const char* GamesPath();
	const char* GmsPicturesPath();
	const char* ImagesPath();
	const char* ImagesThumbnailPath();
	const char* InstallsPath();
	const char* MemoryCardContactsPath();
	const char* MemoryCardRootPath();
	const char* MmsBackgroundImagesPath();
	const char* OthersPath();
	const char* PhoneMemoryRootPath();
	const char* PresenceLogosPath();
	const char* RomRootPath();
	const char* SimpleSoundsPath();
	const char* SoundsPath();
	const char* VideosPath();
	
private:
	// new functions
	Cpyfileselect();
	void ConstructL();

	};

#endif  // __PYFILESELECT_H__
