# Usage #
Pyfileselect provides methods which launch popup dialogs for file selection, directory browsing, or memory selection. Additionally it provides an interface for quering system paths. To use pyfileselect follow these simple instructions.

First off, we need to import the pyfileselect module:
```
import pyfileselect
```

### The pyfileselect module provides the following methods for file, directory, and memory selection: ###
```
pyfileselect.select_file(path=u"C:\\", title=None)
```
This methods launches a file selection dialog. It returns the unicode filename of the selected file. If no file is selected `None` is returned.

The `path` argument, which defaults to `u"C:\\"`, sets the folder that browsing is started from. The `title` argument may be used to replace the default title text (unicode).


&lt;BR&gt;



&lt;BR&gt;



&lt;BR&gt;



&lt;BR&gt;




```
pyfileselect.select_memory(title=None)
```
This methods launches a pop-up dialog for memory selection. It returns the unicode pathname of the selected memory. If no memory is selected `None` is returned.

The `title` argument may be used to replace the default title text (unicode).


&lt;BR&gt;



&lt;BR&gt;



&lt;BR&gt;



&lt;BR&gt;




```
pyfileselect.select_folder(path = u"C:\\", type=pyfileselect.DialogTypeCopy, title=None, rightRoot = None, leftSelect = None):
```
This methods launches a pop-up dialog for directory/folder selection. It returns the unicode pathname of the selected directory. If no directory is selected `None` is returned.

The `path` argument, which defaults to `u"C:\\"`, sets the folder that browsing is started from.

The `type` argument, which defaults to `DialogTypeCopy`, sets different default values (such as softkey texts and title) depending on the dialog type. Supported dialog types are:
```
DialogTypeSave
DialogTypeMove
DialogTypeCopy
```

The `title` argument may be used to replace the default title text (unicode). The `rightRoot` and `leftSelect` arguments (unicode) may be used to replace the default texts of the right softkey when the user is in the root folder and the left softkey when a directory is focused, respectively.

### The following methods are provided to query system paths: ###
```
memory_card_root_path()
```
returns the root path in Memory Card.

&lt;BR&gt;



&lt;BR&gt;



```
rom_root_path()
```
returns the root path in ROM.

&lt;BR&gt;



&lt;BR&gt;



```
videos_path()
```
returns the videos path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
others_path()
```
returns the others path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
sounds_path()
```
returns the sounds path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
simple_sounds_path()
```
returns the simple sounds path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
presence_logos_path()
```
returns the presence logos path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
phone_memory_root_path()
```
returns the root path in Phone Memory.

&lt;BR&gt;



&lt;BR&gt;



```
mms_background_images_path()
```
returns the MMS background images path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;





```
memory_card_contacts_path()
```
returns the full path of the contacts folder in the memory card.

&lt;BR&gt;



&lt;BR&gt;



```
installs_path()
```
returns the installs path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
images_path()
```
returns the images path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
gms_pictures_path()
```
returns the GMS pictures path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
games_path()
```
returns the games path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;




```
digital_sounds_path()
```
returns the digital sounds path to be appended to a root path.

&lt;BR&gt;



&lt;BR&gt;



```
images_thumbnail_path()
```
returns a thumbnail images path.

# Example #
The following script uses the pyfileselect module to select a memory and browse for a file on that memory.
```
import pyfileselect

#Browse for a memory
memory = pyfileselect.select_memory()

#Check to see if a memory was actually selected
if memory:
   #browse for a file on selected memory
   file = pyfileselect.select_file(path=memory)
   if file:
      #do something with file
      print file
```
# Screenshots #
### select\_file() ###
[http://pymgfetch.googlecode.com/svn/trunk/pyfileselect2/ss/selectFile.JPG](http://pymgfetch.googlecode.com/svn/trunk/pyfileselect2/ss/selectFile.JPG)

&lt;BR&gt;



&lt;BR&gt;


### select\_memory() ###
[http://pymgfetch.googlecode.com/svn/trunk/pyfileselect2/ss/selectMemory.JPG](http://pymgfetch.googlecode.com/svn/trunk/pyfileselect2/ss/selectMemory.JPG)

&lt;BR&gt;



&lt;BR&gt;


### select\_folder() ###
[http://pymgfetch.googlecode.com/svn/trunk/pyfileselect2/ss/selectFolder.JPG](http://pymgfetch.googlecode.com/svn/trunk/pyfileselect2/ss/selectFolder.JPG)

&lt;BR&gt;



&lt;BR&gt;



# Installation #
The easiest way to install pyfileselect is to download the latest unsigned version and head over to [Symbian Open Signed Online](https://www.symbiansigned.com/app/page/public/openSignedOnline.do). Input your phone's IMEI (type `*#06#` on your phone) and your email address, and upload the unsigned version of pyfileselect. Shortly after confirming your email address, you will get another email containing a link to a signed version of pyfileselect. Install it as you would any other .sis file and you are good to go.