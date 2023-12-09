# Utils
## Uma biblioteca tosca em C
Uma Biblioteca idiota e tosca para usar nos meus projetos toscos em C
#
Comando usado para criar a biblioteca: `$ clang -shared -o libutils.so -fPIC utils.c`
#
Coloquei o o arquivo .so em: `/usr/local/lib64`e o arquivo .h em: `/usr/local/include`
#
Compilo os progetos que usam a biblioteca: `clang -Wall -Wextra --pedantic -std=c99 -o projeto projeto.c -lutils`
