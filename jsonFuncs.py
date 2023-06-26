import json

def readJson(nomeArq):
    with open(nomeArq,"r") as f:
        try:
            iterable = json.load(f)
        except Exception as e:
            iterable = {}

    return iterable

def writeJson(nomeArq, iterable):
    with open(nomeArq,"w") as f:
        json.dump(iterable,f,ensure_ascii=False,indent=4)
    return 0