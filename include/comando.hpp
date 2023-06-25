#ifndef COMANDO_H
#define COMANDO_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>

#include "usuario.hpp"
#include "servidor.hpp"

using namespace std;

/**
 * @brief Classe que armazena as informações de um comando.
 * 
 * A classe Comando armazena as informações básicas de um comando, 
   além de permitir a leitura e execução do comando.
 */
class Comando {
  private:
    string comando; /**< Primeiro argumento da linha de comando. Exemplo: create-user, quit, login */
    std::vector<std::string> argumentos; /**< Os outros argumentos da linha de comando. */
    int numeroArgumentos; /**< Número de argumentos (tirando o primeiro argumento da linha de comando) */
  public:
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

    std::string getComando(void);

    std::string getArgumento(int i);

    int getNumeroArgumentos(void);

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