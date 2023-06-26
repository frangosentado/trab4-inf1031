from time import sleep

def busca(nomeJogo):
    with open("./entrada.xml","w") as f:
        f.writelines(f"<busca>{nomeJogo}</busca>\n")

def compra(nomeJogo,quantidade):
    with open("./entrada.xml", "w") as f:
        f.writelines(f"<compra>{nomeJogo}-{quantidade}</compra>\n")

def sugestao(nomeJogo):
    with open("./entrada.xml", "w") as f:
        f.writelines(f"<sugestao>{nomeJogo}</sugestao>\n")

def parseResponse():
    while True:
        try:
            with open("./saida.xml", "r") as f:        
                response = f.readlines()
                if response == []:
                    raise Exception
                print(response)
                statusCode = response[0].strip("<status>").strip("</status>\n")
                print(statusCode) 
                body = response[1]
                print(body)
                with open("./saida.xml", "w") as f2:
                    sleep(5)
                    f2.write("")
                break
        except Exception:
            print("esperando resposta..." , end="\r")
            sleep(2)

    return interpretaResposta(statusCode,body)

def interpretaResposta(statusCode:int,body:str):
    if int(statusCode) == 0:
        if body.startswith("<rbs>"):
            print("rbs recebida")
            body =  body.strip("<rbs>").strip("</rbs>\n").split("-")
            print("rbs filtrada: ",body[0],body[1])
            return {"nome": body[0],"preco":body[1]}   
        elif body.startswith("<rcs>"):
            print("rcs recebida")
            return body.strip("<rcs>").strip("</rcs>\n")
        elif body.startswith("<rss>"):
            print("rss recebida")
            pass
        else:
            print("Formato de resposta inválido")
            return
    else:
        return body.strip("<err>%s</err>")