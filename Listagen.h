#ifndef ListaGEN
#define ListaGEN
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listagen Listagen;

/**
 * @brief Inicia a lista vazia.
 *
 * @return Listagen* - Lista alocada
 */
Listagen *IniciaListaGen();

/**
 * @brief Insere um item no inicio da lista.
 *
 * @param lista - Lista válida
 * @param item - Item Válido
 */
void InsereItemGen(Listagen *lista, void *item);

/**
 * @brief Retira um item da lista comparando com uma função
 *        de callback do tipo de item.
 *
 * @param lista - Lista
 * @param chave - Chave de busca
 * @param Comparador - Função de comparacao
 * @return void * - Elemento da Célula removida
 */
void *RetiraDaListaGen(Listagen *lista, void *chave, int (*Comparador)(void *, void *));

/**
 * @brief Imprime a Lista Generica, dada a funcao para a impressao de um elemento
 *
 * @param lista - Lista a ser impressa
 * @param Imprime - Funcao para a impressao de um elemento
 */
void ImprimeListaGen(Listagen *lista, void (*Imprime)(void *));

/**
 * @brief Libera a lista dando free também no item dela caso
 *        a função de destruir do tipo seja passada como argumento.
 *
 * @param lista - Lista válida
 * @param Destroi - Funcao para a liberacao de um elemento
 */
void LiberaListaGen(Listagen *lista, void (*Destroi)(void *));

/**
 * @brief Função para organizar a lista dependendo da função passada como
 *        argumento, (Cria uma nova lista incluindo itens da antiga na nova, de acordo
 *        com a ordem estabelecida pela função de callback).
 *
 * @param lista - Lista válida
 * @param MenorQ - Função válida
 * @return Listagen* - Lista organizada
 */
Listagen *ReorganizaLista(Listagen *lista, int (*MenorQ)(void *, void *));

/**
 * @brief Retorna 1 se a lista esta vazia, 0 caso contrário.
 *
 * @param lista - Lista válida
 * @return int - 1 se vazia, 0 caso contrario
 */
int VaziaLista(Listagen *lista);

/**
 * @brief Percorre a lista executando a funcao passada como parametro
 *
 * @param lista - Lista valida
 * @param cb - Funcao a ser executada
 * @return int - Retorna 1 caso a funcao tenha sido executada para toda a lista,
 *               0 caso contrario
 */
int PercorreLista(Listagen *lista, int (*cb)(void *));

/**
 * @brief Retorna item presente no primeiro elemento da lista
 *
 * @param lista - Lista valida
 * @return void* - Elemento presente no primeiro elemento
 */
void *RetornaPrimeiro(Listagen *lista);

/**
 * @brief Retorna item presente no ultimo elemento da lista
 *
 * @param lista - Lista valida
 * @return void* - Elemento presente no ultimo elemento
 */
void *RetornaUlt(Listagen *lista);

// Funcoes de grande utilidade p uso de pilha //

/**
 * @brief Retira o primeiro item da lista, retornando o objeto ligado a ele
 *
 * @param lista - Lista valida
 * @return void* - Objeto presente na lista//Null caso vazia
 */
void *RetiraPrimeiro(Listagen *lista);

/**
 * @brief Insere um item no final da lista.
 *
 * @param lista - Lista valida
 * @param item - Item a ser inserido no final
 */
void InsereUltItemGen(Listagen *lista, void *item);

/**
 * @brief Busca o elemento na lista dada a chave de busca, caso ache o elemento eh retornado
 *        caso contrario, retorna-se null
 *
 * @param lista - Lista onde sera executada a busca
 * @param Compara - Funcao utilizada para comparacao
 * @param chave - Chave de busca
 * @return void* - Elemento achado na lista
 */
void *BuscaLista(Listagen *lista, int (*Compara)(void *, void *), void *chave);

#endif