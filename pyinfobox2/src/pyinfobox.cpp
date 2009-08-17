/*
 ============================================================================
 Name		: pyinfobox.cpp
 Author	  : Thomas Reitmaier
 Copyright   : Copyright Thomas Reitmaier.
 Description : Cpyinfobox DLL source
 ============================================================================
 */

//  Include Files  

#include "pyinfobox.h"	// Cpyinfobox
//  Member Functions

Cpyinfobox* Cpyinfobox::NewLC()
	{
	Cpyinfobox* self = new (ELeave) Cpyinfobox;
	CleanupStack::PushL(self);
	self->ConstructL();
	return self;
	}

Cpyinfobox* Cpyinfobox::NewL()
	{
	Cpyinfobox* self = Cpyinfobox::NewLC();
	CleanupStack::Pop(self);
	return self;
	}

Cpyinfobox::Cpyinfobox()
// note, CBase initialises all member variables to zero
	{
	}

void Cpyinfobox::ConstructL()
	{
	// second phase constructor, anything that may leave must be constructed here

	}

Cpyinfobox::~Cpyinfobox()
	{
	}
TInt Cpyinfobox::InfoBoxDlg(const TDesC& aHeader, const TDesC& aText)
{
   CAknMessageQueryDialog* dlg=
      CAknMessageQueryDialog::NewL(const_cast<TDesC&>(aText));
   CleanupStack::PushL(dlg);
   dlg->SetHeaderTextL(aHeader);
   CleanupStack::Pop(dlg); 
   // ExecuteLD loads, displays, and deletes the dialog.
   // it returns the id of the selected softkey or zero for cancel
   return dlg->ExecuteLD(R_AVKON_MESSAGE_QUERY_DIALOG);
}

static PyObject* display_dialog(PyObject* /*self*/, PyObject* args)
	{
	char *htext = NULL; // header text
	TInt htextlen = 0;
	char *btext = NULL; // body text
	TInt btextlen = 0;

	if (!PyArg_ParseTuple(args, "u#u#", &htext, &htextlen, &btext, &btextlen))
		{
		return Py_BuildValue("s", "Cannot parse arguments.");
		}

	TPtrC header((TUint16*) htext, htextlen);
	TPtrC body((TUint16*) btext, btextlen);
	Cpyinfobox* obj = Cpyinfobox::NewL();
	TInt res;
	TRAPD( err, res = obj->InfoBoxDlg(header, body) );
	PyObject* result;

	if (err != KErrNone)
		{
		result = SPyErr_SetFromSymbianOSErr(err);
		}
	else
		{
		result = Py_BuildValue("i", res);
		}
	delete obj;
	return result;
	}

static const PyMethodDef pyinfobox_methods[] =
	{
		{
				"dialog",
				(PyCFunction) display_dialog,
				METH_VARARGS,
				"display a dialog box."
		},
		{
		0, 0
		}
	};
DL_EXPORT(void) init_pyinfobox()
	{
	Py_InitModule("_pyinfobox", (PyMethodDef*) pyinfobox_methods);
	}
