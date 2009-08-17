import imp
_pyinfobox = imp.load_dynamic('_pyinfobox', '\\sys\\bin\\kf__pyinfobox.pyd')
del imp

def dialog(header=u"", text = u""):
    res = _pyinfobox.dialog(header, text)
    return res != 0