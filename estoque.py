from boolSN import getBoolFromSN
from jsonFuncs import *

def registra_jogo():
    jogos = readJson("jogos.json")
    nome = input("Qual o nome do jogo que você deseja registrar? ")
    if jogos.get(nome):
        opcao = getBoolFromSN(input(f"O jogo {nome} já existe no registro. Deseja adicionar ao seu estoque? (s/n) "))
        while opcao == None:
            opcao = getBoolFromSN(input("Opcao inválida! Deseja adicionar ao seu estoque? (s/n) "))
        if opcao:
            qtd = int(input("Quantidade: "))
            add_estoque_jogo(jogos,nome,qtd)
    else:
        jogos[nome] = {}
        jogos[nome]["qtd"] = int(input(f"Qual a quantidade em estoque que você deseja registrar do jogo {nome}? "))
        jogos[nome]["preco"] = float(input(f"Qual o preco que você deseja registrar para o jogo {nome}? ")) 
        writeJson("jogos.json",jogos)


def add_estoque_jogo(jogos,nomeJogo,qtd:int):
    try:
        jogos[nomeJogo]["qtd"] += qtd
        writeJson("jogos.json",jogos)
        print(f"{qtd} unidades do jogo {nomeJogo} adicionadas com sucesso!")
        return 0
    except Exception:
        print("Quantidade inválida")
        return 1
    
def remove_estoque_jogo(jogos,nomeJogo,qtd):
    try:
        jogos[nomeJogo]["qtd"] -= qtd
        writeJson("jogos.json",jogos)
        print(f"{qtd} unidades do jogo {nomeJogo} removidas com sucesso!")
        return 0
    except KeyError:
        print("Jogo nao existe")
        return 1

def remove_jogo(nomeJogo):
    jogos = readJson("jogos.json")
    if jogos.get(nomeJogo):
        jogos.pop(nomeJogo)
        writeJson("jogos.json",jogos)
        print("Jogo removido!")
    else:
        print("Jogo inexistente no catalogo!")
        return
    
def catalogo():
    jogos = readJson("jogos.json")
    print("CATÁLOGO:")
    for jogo,dictJogo in jogos.items():
        print("Nome:", jogo, "- Preço: R$", dictJogo["preco"], "- Quantidade disponivel:",dictJogo["qtd"])