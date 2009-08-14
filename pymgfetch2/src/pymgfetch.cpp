/*
 ============================================================================
 Name		: pymgfetch.cpp
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : Cpymgfetch DLL source
 ============================================================================
 */

//  Include Files  

#include "pymgfetch.h"	// Cpymgfetch
//  Member Functions

Cpymgfetch* Cpymgfetch::NewLC()
	{
	Cpymgfetch* self = new (ELeave) Cpymgfetch;
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

Cpymgfetch* Cpymgfetch::NewL()
	{
	Cpymgfetch* self = Cpymgfetch::NewLC();
	CleanupStack::Pop(self);
	return self;
	}

Cpymgfetch::Cpymgfetch()
// note, CBase initialises all member variables to zero
	{
	}

void Cpymgfetch::ConstructL()
	{
	// second phase constructor, anything that may leave must be constructed here

	}

Cpymgfetch::~Cpymgfetch()
	{
	}
const char* Cpymgfetch::BrowseUsingMGFetchL(TMediaFileType aMediaType,
		TBool allowMultiple, const TDesC& heading, const TDesC& softkey)
	{
	// Create array of descriptors for the selected files
	CDesCArrayFlat* fileArray = new (ELeave) CDesCArrayFlat(1);
	CleanupStack::PushL(fileArray);
	// Open the dialog. this is overloaded
	TBool ret = MGFetch::RunL(*fileArray, // When dialog is closed, fileArray contains selected files
			aMediaType, // Displays only media files of type aMediaType
			allowMultiple, // Not used in S60 2.0 (single or multiple file selection)
			softkey, //Softkey text
			heading //heading text
			);

	// "ret" is true, if user has selected file(s)
	if (ret)
		{
		//Read selected file to aDescriptor
		const TDesC& aDescriptor = fileArray->MdcaPoint(0);
		
		//Convert it to a string
		TInt length = aDescriptor.Length();
		HBufC8* buffer = HBufC8::NewLC(length);
		buffer->Des().Copy(aDescriptor);
		char* str = new (ELeave) char[length + 1];
		Mem::Copy(str, buffer->Ptr(), length);
		str[length] = '\0';
		
		//Cleanup and return
		CleanupStack::PopAndDestroy(buffer);
		CleanupStack::PopAndDestroy(fileArray);
		return str;
		}
	//Cleanup and return emptystring
	CleanupStack::PopAndDestroy(fileArray);
	char* emptystring = new (ELeave) char[1];
	emptystring[0] = '\0';
	return emptystring;
	}

static PyObject* browse_media(PyObject* /*self*/, PyObject* args)
	{
	TInt32 defaultTitle;
	TInt32 defaultSoftkey;
	TInt32 type;
	TInt32 multi;
	char *ttext = NULL;
	TInt ttextlen = 0;
	char *stext = NULL;
	TInt stextlen = 0;
	TMediaFileType mediaType = EAnyMediaFile;
	TBool allowMultiple = EFalse;
	TInt err = KErrNone;

	if (!PyArg_ParseTuple(args, "iu#iiiu#", &defaultTitle, &ttext, &ttextlen,
			&type, &multi, &defaultSoftkey, &stext, &stextlen))
		{
		return Py_BuildValue("s", "Cannot parse arguments.");
		}

	switch (type)
		{
		case 0:
			{
			mediaType = ENoMediaFile;
			}
			break;
		case 1:
			{
			mediaType = EImageFile;
			}
			break;
		case 2:
			{
			mediaType = EVideoFile;
			}
			break;
		case 3:
			{
			mediaType = EAudioFile;
			}
			break;
		case 4:
			{
			mediaType = ERAMFile;
			}
			break;
		case 5:
			{
			mediaType = EPlaylistFile;
			}
			break;
		case 6:
			{
			mediaType = EGMSFile;
			}
			break;
		case 7:
			{
			mediaType = EMusicFile;
			}
			break;
		case 8:
			{
			mediaType = EPresentationsFile;
			}
			break;
		case 9:
			{
			mediaType = EAnyMediaFile;
			}
			break;

		}
	switch (multi)
		{
		case 0:
			{
			allowMultiple = EFalse;
			}
			break;
		case 1:
			{
			allowMultiple = ETrue;
			}
			break;
		}

	Cpymgfetch* obj = Cpymgfetch::NewL();
	const char* res;
	if (defaultTitle == 0)
		{
		TPtrC title((TUint16*) ttext, ttextlen);
		if (defaultSoftkey == 0)
			{
			TPtrC softkey((TUint16*) stext, stextlen);
			TRAPD( err, res = obj->BrowseUsingMGFetchL(mediaType,allowMultiple,title, softkey) );
			}
		else
			{
			TRAPD( err, res = obj->BrowseUsingMGFetchL(mediaType,allowMultiple,title, KNullDesC ) );
			}
		}
	else
		{
		if (defaultSoftkey == 0)
			{
			TPtrC softkey((TUint16*) stext, stextlen);
			TRAPD( err, res = obj->BrowseUsingMGFetchL(mediaType,allowMultiple,KNullDesC, softkey) );
			}
		else
			{
			TRAPD( err, res = obj->BrowseUsingMGFetchL(mediaType,allowMultiple,KNullDesC, KNullDesC) );
			}
		}

	PyObject* result;

	if (err != KErrNone)
		{
		result = SPyErr_SetFromSymbianOSErr(err);
		}
	else
		{
		result = Py_BuildValue("s", res);
		}
	delete obj;
	return result;
	}

static const PyMethodDef pymgfetch_methods[] =
	{
		{
				"browse",
				(PyCFunction) browse_media,
				METH_VARARGS,
				"browse for media files."
		},
		{
		0, 0
		}
	};
DL_EXPORT(void) init_pymgfetch()
	{
	Py_InitModule("_pymgfetch", (PyMethodDef*) pymgfetch_methods);
	}
