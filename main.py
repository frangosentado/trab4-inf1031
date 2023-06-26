from comunicacao import *
from locadora import *
from cliente import *
from estoque import *

#inicializa arquivo de respostas
with open("saida.xml", "w") as f:
    f.write("")

while True:

    opcao = input("Escolha uma opcao:\n1 - Entrar como locadora\n2 - Entrar como cliente\nOpcao: ")
    
    if opcao == "":
        print("Encerrando programa...")
        break

    if opcao == "1":
        while True:
            opcao = input("Escolha uma opcao:\n1 - Registar/aterar jogo\nOpcao: ")

            if opcao == "":
                print("Saindo do modo locadora...")
                break
            elif opcao == "1":
                registra_jogo()
                

    elif opcao == "2":
        username = input("Digite seu usuário: ")

        if login(username):
            while True:
                    opcao = input("Escolha uma opcao:\n1 - Requisicao de compra\n2 - Busca de Jogo\n3 - Realizar aluguel\n4 - Realizar devolucao\nOpcao: ")

                    if opcao == "":
                        print("Saindo do modo cliente...")
                        break
                    elif opcao == "1":
                        print("Requisicao de compra")
                        nomeJogo = input("Qual o nome do jogo que voce deseja comprar? ")
                        quantidade = input("Quantas unidades desse jogo voce deseja comprar? ")
                        compra(nomeJogo,quantidade)
                        print("Requisicao enviada!")
                    elif opcao == "2":
                        print("Busca de jogo")
                        nomeJogo = input("Qual o nome do jogo que voce deseja buscar? ")
                        busca(nomeJogo)
                        print("Busca enviada!")
                    elif opcao == "3":
                        print("Realizar aluguel")
                        registra_aluguel(username)
                    elif opcao == "4":
                        print("Realizar devolucao")
                        registra_devolucao(username)
        else:
            print("Erro ao realizar login. Saindo do modo cliente...")