import e32
# import the C++ module
if e32.s60_version_info >= (3, 0):
    import imp
    _pyfileselect = imp.load_dynamic('_pyfileselect', 'c:\\sys\\bin\\_pyfileselect.pyd')
    del imp    
else:
    import _pyfileselect
del e32

from _pyfileselect import videos_path, others_path, sounds_path, simple_sounds_path, rom_root_path, presence_logos_path, phone_memory_root_path
from _pyfileselect import mms_background_images_path, memory_card_root_path, memory_card_contacts_path, installs_path
from _pyfileselect import images_path, gms_pictures_path, games_path, digital_sounds_path, images_thumbnail_path

DialogTypeSave = 0
DialogTypeMove = 1
DialogTypeCopy = 2
def select_file(path=u"C:\\", title=None):
    useDefaultTitle = 0
    if title is None:
        useDefaultTitle = 1
        title = u""
    filename = _pyfileselect.select_file(path, title, useDefaultTitle)
    if (filename == ""):
        return None
    else:
        return unicode(filename)

def select_memory(title=None):
    useDefaultTitle = 0
    if title is None:
        useDefaultTitle = 1
        title = u""
    filename = _pyfileselect.select_memory(title, useDefaultTitle)
    if (filename == ""):
        return None
    else:
        return unicode(filename)
    
def select_folder(path = u"C:\\", type=DialogTypeCopy, title=None, rightRoot = None, leftSelect = None):
    useDefaultTitle = 0
    if title is None:
        useDefaultTitle = 1
        title = u""
    useDefaultRight = 0
    if rightRoot is None:
        useDefaultRight = 1
        rightRoot = u""
    useDefaultLeft = 0
    if leftSelect is None:
        useDefaultLeft = 1
        leftSelect = u""
    folder = _pyfileselect.select_folder(type, path, title, useDefaultTitle, rightRoot, useDefaultRight, leftSelect, useDefaultLeft)
    if (folder == ""):
        return None
    else:
        return unicode(folder)