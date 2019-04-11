/**
@file clientes.h
\brief Módulo de tratamento de clientes.
*/
#ifndef ___CLIENTES_H___
#define ___CLIENTES_H___

#include "glibW.h"
#include "cliente.h"

/**
\brief Clientes Lidos.
*/
typedef struct clientes* Clientes;

/**
@brief Verifica se um dado cliente existe.

@param p Todos os clientes
@param id String a procurar
@return int Devolve se existe
*/
int searchClient(const Clientes p, const char* id);

/**
 * @brief Devolve o número de clientes armazenados.
 * 
 * @param p Todos os clientes
 * @return int Devolve o número de clientes
 */
int getClientNumber(const Clientes p);

int getComprador(const Clientes p, char*** array);
/**
@brief Obter o array de strings de Cliente começadas por uma letra

@param p Todos os clientes
@param id O primeiro caracter
@param array Onde vão ser guardadas as strings
@return int Número de clientes com o caracter
*/
int getClientLetter(const Clientes p, const char id, char*** array);

/**
@brief Inicializar os clientes todos

@return Clientes Struct com memória alocada
*/
Clientes initClients();

/**
@brief Adicionar um cliente

@param p cliente a adicionar
@param l onde adicionar
@return Clientes Clientes editados
*/
Clientes addClient(const Cliente p, Clientes l);

/**
 * \brief Atualiza um cliente com informacoes de uma venda
 *
 * @param id Id do cliente a atualizar
 * @param filial Filial onde efetuou uma compra
 * @param r Catalogo de produtos
 */
void clientesUpdateCompra(const char* id, int filial, Clientes r);

/**
 * \brief Calcula o numero de clientes registados que nunca
 * fizeram compras
 *
 * @param p Catalogo de clientes
 *
 * @return Numero de clientes que nunca efetuaram compras
 */
int getClientesNaoCompradores(const Clientes p);

/**
@brief Libertar uma struct de clientes

@param p struct a libertar
*/
void clearClients(Clientes p);

#endif
