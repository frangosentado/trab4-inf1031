# Casos de teste para a classe gerenciamento financeiro.
# Se não houver falha nos asserts então os casos foram executados com sucesso.
def test_gerenciamento_financeiro():
    # Caso de teste de saldo inicializado corretamente
    gerenciador = GerenciamentoFinanceiro()
    gerenciador.inicializaSaldo()
    assert gerenciador.consultaSaldo() == 0

    # Caso de teste de adicionar saldo
    gerenciador.adicionaSaldo(100)
    assert gerenciador.consultaSaldo() == 100

    # Caso de teste de subtrair saldo
    gerenciador.subtraiSaldo(50)
    assert gerenciador.consultaSaldo() == 50

    # Caso de teste de saldo insuficiente
    gerenciador.subtraiSaldo(100)
    assert gerenciador.consultaSaldo() == 50
    # Verificar se a mensagem de "Saldo insuficiente!" é exibida
    # OBS: Neste caso, você pode modificar o método subtraiSaldo para retornar um valor booleano indicando se a operação foi bem-sucedida ou não

    # Caso de teste de consulta de saldo
    saldo = gerenciador.consultaSaldo()
    assert saldo == 50

    print("Todos os casos de teste foram executados com sucesso!")


# Executar os casos de teste
test_gerenciamento_financeiro()
