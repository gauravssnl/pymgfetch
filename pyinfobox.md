# Usage #
Using pyinfobox is really simple. In fact, only two lines of code are needed.

First off, we need to import the pyinfobox module:
```
import pyinfobox
```


&lt;HR&gt;


The pyinfobox module only has one method:
```
pyinfobox.dialog(header=u"", text=u"")
```
It returns `False` if Cancel is selected; otherwise, it returns `True`. The `header` and `text` arguments (unicode) are used to set the header and text body of the dialog.

# Example #
The following script uses the pyinfobox module to show a text dialog.
```
import pyinfobox

#Show the dialog
if pyinfobox.dialog(u"Title", u"Hello World"):
   print "OK selected."
else:
   print "Cancel selected."

```
# Screenshot #
![![](http://pymgfetch.googlecode.com/svn/trunk/pyinfobox2/ss/pyinfobox_ss.jpg)](http://pymgfetch.googlecode.com/svn/trunk/pyinfobox2/ss/pyinfobox_ss.jpg)
# Installation #
The easiest way to install pyinfobox is to download the latest unsigned version and head over to [Symbian Open Signed Online](https://www.symbiansigned.com/app/page/public/openSignedOnline.do). Input your phone's IMEI (type `*#06#` on your phone) and your email address, and upload the unsigned version of pyinfobox. Shortly after confirming your email address, you will get another email containing a link to a signed version of pyinfobox. Install it as you would any other .sis file and you are good to go.