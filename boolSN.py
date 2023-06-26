from wrappers import validaSN

@validaSN
def getBoolFromSN(sn: str) -> bool:
    if sn in "Ss":
        return True
    else:
        return False