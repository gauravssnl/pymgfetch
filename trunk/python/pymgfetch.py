import e32
# import the C++ module
if e32.s60_version_info >= (3, 0):
	import imp
	_pymgfetch = imp.load_dynamic('_pymgfetch', 'c:\\sys\\bin\\_pymgfetch.pyd')
	del imp    
else:
	import _pymgfetch
del e32
# Single or Multiple Selection (For now only single works)
#TODO Multiple Selection
ESingle = 0
EMultiple = 1

# Filetypes
ENoMediaFile = 0
EImageFile = 1
EVideoFile = 2
EAudioFile = 3
ERAMFile = 4
EPlaylistFile = 5
EGMSFile = 6
EMusicFile = 7
EPresentationsFile = 8
EAnyMediaFile = 9

def browse (filetype = EAnyMediaFile, title=None, softkey=None):
	useDefaultTitle = 0
	useDefaultSoftkey = 0
	if title is None:
		useDefaultTitle = 1
		title = u""
	if softkey is None:
		useDefaultSoftkey = 1
		softkey = u""
	filename = _pymgfetch.browse(useDefaultTitle, title, filetype, ESingle, useDefaultSoftkey, softkey)
	if (filename == ""):
		return None
	else:
		return unicode(filename)