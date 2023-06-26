from comunicacao import *
from locadora import *
from cliente import *
from estoque import *

#inicializa arquivo de respostas
with open("saida.xml", "w") as f:
    f.write("")

while True:

    opcao = input("Escolha uma opcao:\n1 - Entrar como locadora\n2 - Entrar como cliente\nENTER - Sair\nOpcao: ")
    
    if opcao == "":
        print("Encerrando programa...")
        break

    if opcao == "1":
        while True:
            opcao = input("Escolha uma opcao:\n1 - Registar/aterar jogo\nENTER - Sair do modo locadora\nOpcao: ")

            if opcao == "":
                print("Saindo do modo locadora...")
                break
            elif opcao == "1":
                try:
                    registra_jogo()
                except Exception as e:
                    print(e)
                    continue
            else:
                print("Comando inválido")
                

    elif opcao == "2":
        username = input("Digite seu usuário: ")

        if login(username):
            while True:
                    opcao = input("Escolha uma opcao:\n1 - Realizar aluguel\n2 - Realizar devolucao\nENTER - Sair do modo cliente\nOpcao: ")

                    if opcao == "":
                        print("Saindo do modo cliente...")
                        break
                    elif opcao == "1":
                        print("Realizar aluguel")
                        registra_aluguel(username)
                    elif opcao == "2":
                        print("Realizar devolucao")
                        registra_devolucao(username)
                    else:
                        print("Comando inválido")
        else:
            print("Erro ao realizar login. Saindo do modo cliente...")

    else:
        print("Comando inválido")