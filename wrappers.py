def validaSN(f):
    def validaEntrada(entrada):
        if type(entrada) == str:
            if entrada in "sSnN":
                return f(entrada)
        else:
            return 0
        
    return validaEntrada

