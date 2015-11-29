# Usage #
Using pymgfetch is really simple. In fact, only two lines of code are needed.

First off, we need to import the pymgfetch module:
```
import pymgfetch
```


&lt;HR&gt;


The pymgfetch module only has one method:
```
pymgfetch.browse(filetype=pymgfetch.EAnyMediaFile, title=None, softkey=None)
```
It returns the unicode filename of the selected file. If no file is selected `None` is returned. The `filetype` argument, which defaults to `EAnyMediaFile`, filters the media files shown in the dialog to those of a certain type. Supported filetypes are:
```
ENoMediaFile
EImageFile	
EVideoFile	
EAudioFile	
ERAMFile	
EPlaylistFile	
EGMSFile
EMusicFile	
EPresentationsFile	
EAnyMediaFile
```

The `title` and `softkey` arguments may be used to replace the default title and left softkey texts (unicode).
# Example #
The following script uses the pymgfetch module to browse for audio files. If a file is selected, it is played.
```
import pymgfetch, audio

#Show only audio files in dialog
#Title is "Audio:"
#Left softkey reads "Play"
filename = pymgfetch.browse(pymgfetch.EAudioFile, title = u"Audio:", softkey=u"Play")

#Check to see if a file was actually selected
if filename:
   #Open the file...
   audiofile = audio.Sound.open(filename)

   #...and play it.
   audiofile.play()
```

# Installation #
The easiest way to install pymgfetch is to download the latest unsigned version and head over to [Symbian Open Signed Online](https://www.symbiansigned.com/app/page/public/openSignedOnline.do). Input your phone's IMEI (type `*#06#` on your phone) and your email address, and upload the unsigned version of pymgfetch. Shortly after confirming your email address, you will get another email containing a link to a signed version of pymgfetch. Install it as you would any other .sis file and you are good to go.