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
    std::string dataHora; /**< Data e hora em que a mensagem foi enviada. */
    int enviadaPor; /**< ID do usuário que enviou a mensagem. */
    std::string conteudo; /**< Conteúdo da mensagem. */

  public:
    /**
     * @brief Construtor padrão da classe Mensagem.
     */
    Mensagem();

    /**
     * @brief Construtor da classe Mensagem.
     *
     * @param enviadaPor O ID do usuário que enviou a mensagem.
     * @param dataHora A data e hora em que a mensagem foi enviada.
     * @param conteudo O conteúdo da mensagem.
     */
    Mensagem(int enviadaPor, std::string dataHora, std::string conteudo);

    /**
     * @brief Retorna a data e hora da mensagem.
     *
     * @return A data e hora da mensagem.
     */
    std::string getDataHora();

    /**
     * @brief Define a data e hora da mensagem.
     *
     * @param dataHora A data e hora da mensagem.
     */
    void setDataHora(std::string dataHora);

    /**
     * @brief Retorna o ID do usuário que enviou a mensagem.
     *
     * @return O ID do usuário que enviou a mensagem.
     */
    int getIdEnviou();

    /**
     * @brief Define o ID do usuário que enviou a mensagem.
     *
     * @param id O ID do usuário que enviou a mensagem.
     */
    void setIdEnviou(int id);

    /**
     * @brief Retorna o nome do usuário que enviou a mensagem.
     *
     * @param id O ID do usuário.
     * @param usuarios Um ponteiro para um vetor de ponteiros de usuários.
     * @return O nome do usuário que enviou a mensagem.
     */
    std::string getNomeEnviou(int id, std::vector<Usuario *> *usuarios);

    /**
     * @brief Retorna o conteúdo da mensagem.
     *
     * @return O conteúdo da mensagem.
     */
    std::string getConteudo();

    /**
     * @brief Define o conteúdo da mensagem.
     *
     * @param conteudo O conteúdo da mensagem.
     */
    void setConteudo(std::string conteudo);
};

#endif
