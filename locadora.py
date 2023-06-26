import json
from boolSN import getBoolFromSN
from jsonFuncs import *
from datetime import datetime
from comunicacao import *
from gerenciamento_financeiro import *
from estoque import *


def registra_aluguel(username):
    alugueis = readJson("alugueis.json")
    jogos = readJson("jogos.json")

    nomeJogo = input("Digite o nome do jogo que você deseja alugar: ")

    alugueis["realizados"] = alugueis.get("realizados", {})
    alugueisUser = alugueis["realizados"].get(username,{})
    
    if alugueisUser.get(nomeJogo):
        print("Voce ja possui um aluguel desse jogo em andamento.")
        return

    if jogos.get(nomeJogo):
        qtd = jogos[nomeJogo]["qtd"]
        preco = jogos[nomeJogo]["preco"]
        print("Quantidade disponível: {}".format(qtd))
        print("Preco: {}".format(preco))

        if qtd > 0:
            opcao = getBoolFromSN(input("Deseja realizar o aluguel desse jogo? (s/n) "))
            while opcao == None:
                opcao = getBoolFromSN(input("Opcao inválida! Deseja realizar o aluguel desse jogo? (s/n) "))
            if opcao:
                alugueisUser[nomeJogo] = {"data": f"{datetime.now()}"}
                alugueis["realizados"][username] = alugueisUser
                remove_estoque_jogo(jogos,nomeJogo,1)
                print(f"Aluguel do {nomeJogo} realizado com sucesso!")
            else:
                print("Operacao cancelada")
                return
        else:
            print("Jogo indisponível no momento por falta de estoque. Tente novamente mais tarde")
            # interpretar logica de falha
            falhas = alugueis.get("falhas",{})
            falhasJogo = falhas.get(nomeJogo,0)
            if falhasJogo >= 2:
                busca(nomeJogo=nomeJogo)
                respostaBusca = parseResponse()
                try:
                    preco = respostaBusca["preco"]
                    if realiza_operacao("compra",float(preco)) == 0:
                        compra(nomeJogo,2)
                        falhasJogo = 0
                    else:
                        print("Operacao cancelada!")
                except Exception as e:
                    print(e)
                    print("resposta recebida: ", respostaBusca)
                    sugestao(nomeJogo)
            else:
                falhasJogo += 1
            
            falhas[nomeJogo] = falhasJogo
            alugueis["falhas"] = falhas
    else:
        print("Jogo indisponível no catálogo")
        return

    writeJson("alugueis.json",alugueis)

def registra_devolucao(username):
    alugueis = readJson("alugueis.json")
    jogos = readJson("jogos.json")

    if alugueis["realizados"].get(username):
        print("ALUGUEIS EM ANDAMENTO:")
        for jogo,dados in alugueis["realizados"][username].items():
            print("{} - realizado em {}".format(jogo,dados["data"]))

        nomeJogo = input("Digite o nome do jogo que você deseja devolver: ")

        if alugueis["realizados"][username].get(nomeJogo):
            alugueis["realizados"][username].pop(nomeJogo)
            jogos[nomeJogo]["qtd"] += 1
            
    else:
        print("Voce não possui alugueis em andamento!")
        return
    
    with open("alugueis.json", "w") as f:
        json.dump(alugueis,f,ensure_ascii=False,indent=4)
    with open("jogos.json", "w") as f:
        json.dump(jogos,f,ensure_ascii=False,indent=4)

    print(f"Devolucao do {nomeJogo} realizada com sucesso!")


