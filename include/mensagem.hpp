#ifndef MENSAGEM_H
#define MENSAGEM_H

using namespace std;

#include <string>

/**
 * @brief Classe que armazena as informações de uma mensagem.
 * 
 * A classe Mensagem armazena as informações básicas de uma mensagem.
 */
class Mensagem {
  private:
    string dataHora; /**< Data e hora que a mensagem foi enviada. */
    int enviadaPor; /**< ID do usuário que enviou. */
    string conteudo; /**< Conteúdo da mensagem. */
};

#endif