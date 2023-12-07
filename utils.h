#define _DEFAULT_SOURCE
#define _BSD_SOURCE
#ifndef _UTILS_
#define _UTILS_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <fnmatch.h>
#include <limits.h>
#include <errno.h>


/* Cuida de criar um diretório, com as permissões
 * de umask do sistema. Retorna true tendo sucesso
 * false dando erro */
bool is_directory_created(char *dirname);

/* Cuida de verificar se diretório é válido */
bool is_valid_directory(char *dirname);

/* Cuida de verificar se diretório especifcado é . ou .. */
bool is_dot_directory(char *dirname);

/* Cuida de verificar se arquivo tem extensão,
 * retorna extensão ou NULL */
char *has_extension(char *filename);

/* Implementação de strstr reversa. Recebe a string alvo,
 * a substring para procurar no final da string e o tamanho
 * (quantos caracteres) */
char *rev_strstr(char *haystack, char *needle, size_t len);

/* Implementação de strdup() */
char *duplicate(char *source);

/* Cuida de criar um caminho de arquivo ou diretório.
 * Ex: /home/usuario/Documentos/texto.txt */
char *create_pathname(char *base, char *name);

/* Cuida de remover o(s) ultimo caracter da string */
void remove_last_char(char *itemname, int reject);

/* Cuida de capitalizar primeira letra de palavra
 * ola -> Ola */
void title_case_word(char *word);

/* Cuida de capitalizar primeira letra de cada
 * palavra em uma frase: ola mundo -> Ola Mundo */
void title_case_sentence(char *sentence);


#endif
