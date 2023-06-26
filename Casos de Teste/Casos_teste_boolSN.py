# Casos de teste para boolSN
from boolSN import *

# Caso seja recebido S ou s a função retorna True, se não, False.
# Caso True com "S":
valor_ret = getBoolFromSN("S")
assert valor_ret

# Caso True com "s":
valor_ret = getBoolFromSN("s")
assert valor_ret

# Caso False, aplicável para "N" ou "n":
valor_ret = getBoolFromSN("N")
assert valor_ret == False
valor_ret = getBoolFromSN("n")
assert valor_ret == False

# Caso None, aplicável para caracteres que diferem dos citados acima":
valor_ret = getBoolFromSN("@")
assert valor_ret == None

print("Todos os casos executados com sucesso.\n")
