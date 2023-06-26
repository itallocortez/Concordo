#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

/**
 * @file mensagem.hpp
 *
 * @brief Este arquivo contém as declarações da classe Mensagem.
 */

/**
 * @brief Classe que armazena as informações de uma mensagem.
 * 
 * A classe Mensagem armazena as informações básicas de uma mensagem.
 * Ainda não foi completamente implementada.
 */
class Mensagem {
  private:
    std::string dataHora; /**< Data e hora que a mensagem foi enviada. */
    int enviadaPor; /**< ID do usuário que enviou. */
    std::string conteudo; /**< Conteúdo da mensagem. */
};

#endif