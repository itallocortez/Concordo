#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>
#include <vector>

#include "usuario.hpp"

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
  public:
    Mensagem();
    Mensagem(int enviadaPor, std::string dataHora, std::string conteudo);

    std::string getDataHora(void);
    void setDataHora(std::string dataHora);

    int getIdEnviou(void);
    void setIdEnviou(int id);

    std::string getNomeEnviou(int id, std::vector<Usuario *> *usuarios);

    std::string getConteudo(void);
    void setConteudo(std::string conteudo);
};

#endif