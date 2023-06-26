import json
import hashlib
from getpass import getpass
from jsonFuncs import readJson
from datetime import datetime
from boolSN import getBoolFromSN

def login(username):

    clientes = readJson("clientes.json")

    if clientes.get(username):
        print(f"Bem vindo de volta {username}!")
        for i in range(3):
            pwd = getpass("Senha: ").encode("ascii")
            if hashlib.sha256(pwd).hexdigest() == clientes[username]["password"]:
                print(f"Login realizado com sucesso!")
                return True
            else:
                print(f"Senha incorreta. Tente novamente ({i+1}/3)")
        return False
    else:
        print(f"Seja bem vindo à Jogos Vorazes, {username}!")
        clientes[username] = {}
        for i in range(3):
            pwd = getpass("Crie uma senha: ")
            confirmPwd = getpass("Confirmar senha: ")
            if pwd == confirmPwd:
                clientes[username]["password"] = hashlib.sha256(pwd.encode("ascii")).hexdigest()
                with open("clientes.json", "w") as f2:
                    json.dump(clientes,f2,ensure_ascii=False,indent=4)
                print(f"Cliente {username} registrado com sucesso!")
                return True
            else:
                print(f"As senhas não batem! Tente novamente ({i+1}/3)")
        return False
 