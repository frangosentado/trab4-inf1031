from jsonFuncs import *

def realiza_operacao(tipo, valor:float):

    # Lê os dados financeiros do arquivo JSON
    financeiro = readJson("financeiro.json")

    # Obtém o valor atual do saldo
    saldo = financeiro.get("saldo", 0.0)

    if tipo == "aluguel":
        saldo += valor  # Adiciona o valor do aluguel ao saldo
    elif tipo == "compra": # Subtrai o valor da compra do saldo
        if saldo <= valor:
            saldo -= valor  
        else:
            print("saldo insuficiente para realizar esta operacao!")
            return 1
    else:
        print("Tipo de operacao invalida")
        return 1

    print("Operação financeira realizada com sucesso.")
    print("Saldo: R$", saldo)

    # Atualiza o valor do saldo no arquivo JSON
    financeiro["saldo"] = saldo

    writeJson("financeiro.json",financeiro)

    return 0

def consulta_saldo():
    financeiro = readJson("financeiro.json")
    saldo = financeiro.get("saldo", 0.0)
    return saldo

def add_saldo(valor:float) -> float:
    financeiro = readJson("financeiro.json")
    saldo = financeiro.get("saldo", 0.0)
    saldo += valor
    writeJson("financeiro.json",financeiro)