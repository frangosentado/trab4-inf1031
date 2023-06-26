# Casos de teste para estoque
from estoque import *
from jsonFuncs import *

# Caso a entrada na main seja 1, o módulo estoque é acessado.

def registra_jogo():
    jogos = readJson("jogos.json")
    print("Qual o nome do jogo que você deseja registrar? CTjogo")
    nome = 'CTjogo'
    if jogos.get(nome):
        print(f"O jogo {nome} já existe no registro. Deseja adicionar ao seu estoque? (s/n) @")
        opcao = getBoolFromSN("@")
        while opcao == None:
            print("Opcao inválida! Deseja adicionar ao seu estoque? (s/n) n")
            opcao = getBoolFromSN("n")
        if opcao:
            print("Quantidade: 2")
            qtd = int(2)
            add_estoque_jogo(jogos, nome, qtd)
    else:
        jogos[nome] = {}
        print(f"Qual a quantidade em estoque que você deseja registrar do jogo {nome}? 2")
        jogos[nome]["qtd"] = int(2)
        print(f"Qual o preco que você deseja registrar para o jogo {nome}? 23")
        jogos[nome]["preco"] = float(23)
        writeJson("jogos.json", jogos)


# Caso o jogo não esteja registrado:
# Nome hipotético: CTjogo.
# Quantidade hipotética: 2
# Valor hipotético: 23
registra_jogo()
# Caso o jogo esteja registrado:
# Nome hipotético: CTjogo.
# Quantidade hipotética: 2
registra_jogo()
# Mensagem especifica esperada: O jogo CTjogo já existe no registro. Deseja adicionar ao seu estoque? (s/n).
# Caso um caracter diferente de S, s, n, N:
# Mensagem especifica esperada: Opcao inválida! Deseja adicionar ao seu estoque? (s/n).
# Caso n ou N seja precionado retorna ao menu da locadora.

