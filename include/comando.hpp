#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>

#include "usuario.hpp"
#include "servidor.hpp"

/**
 * @file comando.hpp
 *
 * @brief Este arquivo contém as declarações da classe Comando.
 */

/**
 * @brief Classe que armazena as informações de um comando.
 * 
 * A classe Comando armazena as informações básicas de um comando e fornece métodos para ler e executar comandos.
 */
class Comando {
  private:
    std::string comando; /**< Primeiro argumento da linha de comando. Exemplo: create-user, quit, login */
    std::vector<std::string> argumentos; /**< Os outros argumentos da linha de comando. */
    int numeroArgumentos; /**< Número de argumentos (tirando o primeiro argumento da linha de comando) */
  public:
    /**
     * @brief Construtor padrão da classe Comando.
     * 
     * Inicializa um objeto Comando com valores padrão.
     */
    Comando();

    /**
     * @brief Divide uma string em subtrings usando um delimitador.
     *
     * Essa função recebe uma string e um caractere delimitador e divide a string em substrings com base no delimitador. As substrings são     
       retornadas como um vetor de strings.
     * @param str A string de entrada a ser dividida.
     * @param delimiter O caractere usado para delimitar as substrings.
     * @return Um vetor de strings contendo as substrings.
     */
    std::vector<std::string> splitString(std::string str, char delimiter);

     /**
     * @brief Retorna o comando. (Primeiro argumento na linha de comando)
     *
     * @return O comando como uma string.
     */
    std::string getComando(void);

    /**
     * @brief Retorna o argumento na posição especificada (excluindo o comando).
     *
     * @param i A posição do argumento a ser retornado.
     * @return O argumento na posição especificada como uma string.
     */
    std::string getArgumento(int i);

    /**
     * @brief Retorna o número de argumentos (excluindo o comando).
     *
     * @return O número de argumentos.
     */
    int getNumeroArgumentos(void);

    /**
     * @brief Verifica se o comando existe.
     *
     * @return True se o comando existe e False se o comando não existe.
     */
    bool existe(void);

   /**
    * @brief Lê o comando digitado pelo usuário.
    *
    * Essa função lê o comando digitado pelo usuário e interpreta o que é comando e argumento. Armazenando o comando e seus argumentos nas     
      variáveis privadas da classe Comando.
    */
    void ler(void);
};

#endif