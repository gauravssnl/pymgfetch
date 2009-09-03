/*
 ============================================================================
 Name		: pyfileselect.cpp
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : Cpyfileselect DLL source
 ============================================================================
 */

//  Include Files  

#include "pyfileselect.h"	// Cpyfileselect

//  Member Functions

Cpyfileselect* Cpyfileselect::NewLC()
	{
	Cpyfileselect* self = new (ELeave) Cpyfileselect;
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

Cpyfileselect* Cpyfileselect::NewL()
	{
	Cpyfileselect* self = Cpyfileselect::NewLC();
	CleanupStack::Pop(self);
	return self;
	}

Cpyfileselect::Cpyfileselect()
// note, CBase initialises all member variables to zero
	{
	}

void Cpyfileselect::ConstructL()
	{
	// second phase constructor, anything that may leave must be constructed here

	}

Cpyfileselect::~Cpyfileselect()
	{
	}
const char* Cpyfileselect::MemorySelectionDlg(const TDesC& heading)
	{
	CAknMemorySelectionDialog::TMemory memory =
			CAknMemorySelectionDialog::EPhoneMemory;

	TBool ret = CAknMemorySelectionDialog::RunDlgLD(memory, // on return, contains the selected memory's name
			heading, // Dialog's title
			NULL // Pointer to class implementing 
			// MAknFileSelectionObserver. 
			);

	// "return" is true, if user has selected a file
	if (ret)
		{
		if (memory == CAknMemorySelectionDialog::EMemoryCard)
			{
			return descriptorToStringL(PathInfo::MemoryCardRootPath());
			}
		else
			{
			return descriptorToStringL(PathInfo::PhoneMemoryRootPath());
			}
		}
	char* emptystring = new (ELeave) char[1];
	emptystring[0] = '\0';
	return emptystring;
	}
const char* Cpyfileselect::FolderSelectionDlg(TCommonDialogType dialogType,
		TDesC& memory, const TDesC& heading, const TDesC& rightRoot, const TDesC& left)
	{
	TFileName folder;
	folder.Append(memory);
	// Create select folder dialog
	CAknFileSelectionDialog* dlg = CAknFileSelectionDialog::NewL(dialogType);

	// some dialog customizations:
	dlg->SetTitleL(heading);
	dlg->SetRightSoftkeyRootFolderL(rightRoot); // for root folder
	dlg->SetLeftSoftkeyFileL(left);
	//dlg->SetLeftSoftkeyFolderL(left);
	TBool result = EFalse;
	if (dlg->ExecuteL(folder))
		{
		// we got our folder and finish loop
		result = ETrue;
		}

	delete dlg;

	if (result)
		{
		return descriptorToStringL(folder);
		}

	char* emptystring = new (ELeave) char[1];
	emptystring[0] = '\0';
	return emptystring;
	}
const char* Cpyfileselect::FileSelectionDlg(const TFileName& aPath,
		const TDesC& heading)
	{
	TFileName filename;

	// Create default filename. (contains only the folder, 
	// e.g. C:\Data\Images\) This is used as a starting folder for browsing image files.

	filename.Append(aPath);

	TBool ret = CAknFileSelectionDialog::RunDlgLD(filename, // on return, contains the selected file's name
			PathInfo::PhoneMemoryRootPath(), // default root path for browsing
			heading, // Dialog's title
			NULL // Pointer to class implementing 
			// MAknFileSelectionObserver. 
			);

	// "return" is true, if user has selected a file
	if (ret)
		{
		return descriptorToStringL(filename);
		}
	char* emptystring = new (ELeave) char[1];
	emptystring[0] = '\0';
	return emptystring;
	}
const char* Cpyfileselect::descriptorToStringL(const TDesC& aDescriptor)
	{
	TInt length = aDescriptor.Length();

	HBufC8* buf = HBufC8::NewLC(length);
	buf->Des().Copy(aDescriptor);

	char* str = new (ELeave) char[length + 1];
	Mem::Copy(str, buf->Ptr(), length);
	str[length] = '\0';

	CleanupStack::PopAndDestroy(buf);

	return str;
	}
const char* Cpyfileselect::DigitalSoundsPath()
	{
	return descriptorToStringL(PathInfo::DigitalSoundsPath());
	}
const char* Cpyfileselect::GamesPath()
	{
	return descriptorToStringL(PathInfo::GamesPath());
	}
const char* Cpyfileselect::GmsPicturesPath()
	{
	return descriptorToStringL(PathInfo::GmsPicturesPath());
	}
const char* Cpyfileselect::ImagesPath()
	{
	return descriptorToStringL(PathInfo::ImagesPath());
	}
const char* Cpyfileselect::ImagesThumbnailPath()
	{
	return descriptorToStringL(PathInfo::ImagesThumbnailPath());
	}
const char* Cpyfileselect::InstallsPath()
	{
	return descriptorToStringL(PathInfo::InstallsPath());
	}
const char* Cpyfileselect::MemoryCardContactsPath()
	{
	return descriptorToStringL(PathInfo::MemoryCardContactsPath());
	}
const char* Cpyfileselect::MemoryCardRootPath()
	{
	return descriptorToStringL(PathInfo::MemoryCardRootPath());
	}
const char* Cpyfileselect::MmsBackgroundImagesPath()
	{
	return descriptorToStringL(PathInfo::MmsBackgroundImagesPath());
	}
const char* Cpyfileselect::OthersPath()
	{
	return descriptorToStringL(PathInfo::OthersPath());
	}
const char* Cpyfileselect::PhoneMemoryRootPath()
	{
	return descriptorToStringL(PathInfo::PhoneMemoryRootPath());
	}
const char* Cpyfileselect::PresenceLogosPath()
	{
	return descriptorToStringL(PathInfo::PresenceLogosPath());
	}
const char* Cpyfileselect::RomRootPath()
	{
	return descriptorToStringL(PathInfo::RomRootPath());
	}
const char* Cpyfileselect::SimpleSoundsPath()
	{
	return descriptorToStringL(PathInfo::SimpleSoundsPath());
	}
const char* Cpyfileselect::SoundsPath()
	{
	return descriptorToStringL(PathInfo::SoundsPath());
	}
const char* Cpyfileselect::VideosPath()
	{
	return descriptorToStringL(PathInfo::VideosPath());
	}

static PyObject* getDigitalSoundsPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->DigitalSoundsPath());
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
static PyObject* getGamesPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->GamesPath());
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
static PyObject* getGmsPicturesPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->GmsPicturesPath());
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
static PyObject* getImagesPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->ImagesPath());
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
static PyObject* getImagesThumbnailPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->ImagesThumbnailPath());
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
static PyObject* getInstallsPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->InstallsPath());
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
static PyObject* getMemoryCardContactsPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->MemoryCardContactsPath());
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
static PyObject* getMemoryCardRootPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->MemoryCardRootPath());
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
static PyObject* getMmsBackgroundImagesPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->MmsBackgroundImagesPath());
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
static PyObject* getOthersPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->OthersPath());
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
static PyObject* getPhoneMemoryRootPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->PhoneMemoryRootPath());
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
static PyObject* getPresenceLogosPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->PresenceLogosPath());
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
static PyObject* getRomRootPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->RomRootPath());
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
static PyObject* getSimpleSoundsPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->SimpleSoundsPath());
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
static PyObject* getSoundsPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->SoundsPath());
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
static PyObject* getVideosPath(PyObject* /*self*/, PyObject* args)
	{
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TRAPD( err, res = obj->VideosPath());
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

static PyObject* select_file(PyObject* /*self*/, PyObject* args)
	{
	TInt32 useDefaultTitle;
	char *ttext = NULL;
	TInt ttextlen = 0;

	char *ptext = NULL;
	TInt ptextlen = 0;

	TInt err = KErrNone;
	if (!PyArg_ParseTuple(args, "u#u#i", &ptext, &ptextlen, &ttext, &ttextlen,
			&useDefaultTitle))
		{
		return Py_BuildValue("s", "Cannot parse arguments.");
		}

	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TPtrC path((TUint16*) ptext, ptextlen);
	if (useDefaultTitle == 1)
		{
		TRAPD( err, res = obj->FileSelectionDlg(path, KNullDesC) );
		}
	else
		{
		TPtrC title((TUint16*) ttext, ttextlen);
		TRAPD( err, res = obj->FileSelectionDlg(path, title));
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

static PyObject* select_memory(PyObject* /*self*/, PyObject* args)
	{
	TInt32 useDefaultTitle;
	char *ttext = NULL;
	TInt ttextlen = 0;

	TInt err = KErrNone;
	if (!PyArg_ParseTuple(args, "u#i", &ttext, &ttextlen, &useDefaultTitle))
		{
		return Py_BuildValue("s", "Cannot parse arguments.");
		}

	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	if (useDefaultTitle == 1)
		{
		TRAPD( err, res = obj->MemorySelectionDlg(KNullDesC) );
		}
	else
		{
		TPtrC title((TUint16*) ttext, ttextlen);
		TRAPD( err, res = obj->MemorySelectionDlg(title));
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

static PyObject* select_folder(PyObject* /*self*/, PyObject* args)
	{
	
	
	char *ttext = NULL;
	TInt ttextlen = 0;
	TInt32 useDefaultTitle;
	
	char *rtext = NULL;
	TInt rtextlen = 0;
	TInt32 useDefaultRight;
	
	char *ltext = NULL;
	TInt ltextlen = 0;
	TInt32 useDefaultLeft;
	
	char *mtext = NULL;
	TInt mtextlen = 0;
	
	TInt32 type;
	TCommonDialogType dialogType = ECFDDialogTypeSave;
	
	
	if (!PyArg_ParseTuple(args, "iu#u#iu#iu#i", &type, &mtext, &mtextlen, &ttext, &ttextlen,&useDefaultTitle, &rtext, &rtextlen,&useDefaultRight, &ltext, &ltextlen, &useDefaultLeft))
		{
		return Py_BuildValue("s", "Cannot parse arguments.");
		}
	switch (type)
		{
		case 0:
			{
			dialogType = ECFDDialogTypeSave;
			}
		break;
		case 1:
			{
			dialogType = ECFDDialogTypeMove;
			}
		break;
		case 2:
			{
			dialogType = ECFDDialogTypeCopy;
			}
		break;
		}
	Cpyfileselect* obj = Cpyfileselect::NewL();
	const char* res;
	TPtrC titleP((TUint16*) ttext, ttextlen);
	TPtrC memory((TUint16*) mtext, mtextlen);
	TPtrC leftP((TUint16*) ltext, ltextlen);
	TPtrC rightP((TUint16*) rtext, rtextlen);
	TBuf <20> title;
	title.Append(titleP);
	TBuf <20> right;
	right.Append(rightP);
	TBuf <20> left;
	left.Append(leftP);
	if(useDefaultTitle == 1)
		{
			title = KNullDesC;
		}
	if(useDefaultRight == 1)
		{
			right = KNullDesC;
		}
	if(useDefaultLeft == 1)
		{
			left = KNullDesC;
		}
	TRAPD( err, res = obj->FolderSelectionDlg(dialogType,memory, title, right, left) );

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
static const PyMethodDef
		pyfileselect_methods[] =
			{
						{
								"select_file",
								(PyCFunction) select_file,
								METH_VARARGS, "Returns the path of the selected file."
						},
						{
								"select_memory",
								(PyCFunction) select_memory,
								METH_VARARGS, "Returns the path of the selected memory."
						},
						{
								"select_folder",
								(PyCFunction) select_folder,
								METH_VARARGS, "Returns the path of the selected folder."
						},
						{
								"videos_path",
								(PyCFunction) getVideosPath,
								METH_NOARGS, "This method returns the videos path to be appended to a root path."
						},
						{
								"others_path",
								(PyCFunction) getOthersPath,
								METH_NOARGS, "This method returns the others path to be appended to a root path."
						},
						{
								"sounds_path",
								(PyCFunction) getSoundsPath,
								METH_NOARGS, "This method returns the sounds path to be appended to a root path."
						},
						{
								"simple_sounds_path",
								(PyCFunction) getSimpleSoundsPath,
								METH_NOARGS, "This method returns the simple sounds path to be appended to a root path."
						},
						{
								"rom_root_path",
								(PyCFunction) getRomRootPath,
								METH_NOARGS, "This method returns the root path in ROM."
						},
						{
								"presence_logos_path",
								(PyCFunction) getPresenceLogosPath,
								METH_NOARGS, "This method returns the presence logos path to be appended to a root path."
						},
						{
								"phone_memory_root_path",
								(PyCFunction) getPhoneMemoryRootPath,
								METH_NOARGS, "This method returns the root path in Phone Memory."
						},
						{
								"mms_background_images_path",
								(PyCFunction) getMmsBackgroundImagesPath,
								METH_NOARGS, "This method returns the MMS background images path to be appended to a root path."
						},
						{
								"memory_card_root_path",
								(PyCFunction) getMemoryCardRootPath,
								METH_NOARGS, "This method returns the root path in Memory Card."
						},
						{
								"memory_card_contacts_path",
								(PyCFunction) getMemoryCardContactsPath,
								METH_NOARGS, "This method returns the full path of the contacts folder in the memory card."
						},
						{
								"installs_path",
								(PyCFunction) getInstallsPath,
								METH_NOARGS, "This method returns the installs path to be appended to a root path."
						},
						{
								"images_path",
								(PyCFunction) getImagesPath,
								METH_NOARGS, "This method returns the images path to be appended to a root path."
						},
						{
								"gms_pictures_path",
								(PyCFunction) getGmsPicturesPath,
								METH_NOARGS, "This method returns the GMS pictures path to be appended to a root path."
						},
						{
								"games_path",
								(PyCFunction) getGamesPath,
								METH_NOARGS, "This method returns the games path to be appended to a root path."
						},
						{
								"digital_sounds_path",
								(PyCFunction) getDigitalSoundsPath,
								METH_NOARGS, "This method returns the digital sounds path to be appended to a root path."
						},
						{
								"images_thumbnail_path",
								(PyCFunction) getImagesThumbnailPath,
								METH_NOARGS, "This method returns a thumbnail images path."
						},

						{
						0, 0
						}
			};
DL_EXPORT(void) init_pyfileselect()
	{
	Py_InitModule("_pyfileselect", (PyMethodDef*) pyfileselect_methods);
	}
