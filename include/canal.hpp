#ifndef CANAL_H
#define CANAL_H

#include <string>
#include <vector>

#include "usuario.hpp"
#include "mensagem.hpp"

/**
 * @file canal.hpp
 *
 * @brief Este arquivo contém as declarações da classe Canal.
 */

/**
 * @brief Classe que armazena as informações de um canal.
 * 
 * A classe Canal armazena as informações básicas de um canal.
 */
class Canal {
  protected:
    std::string nome; /**< Nome do canal. */

  public:
    /**
     * @brief Construtor da classe Canal.
     *
     * @param nome O nome do canal.
     */
    Canal(std::string nome);

    /**
     * @brief Destrutor virtual do Canal.
     *
     * Setado para que as classes filhas sejam realmente deletadas.
     */
    virtual ~Canal() = default;

    /**
     * @brief Retorna o nome do canal.
     *
     * @return O nome do canal.
     */
    std::string getNome();

    /**
     * @brief Retorna o tipo do canal.
     *
     * Essa função é sobrescrita nas classes derivadas, funcionando de forma diferente
     * dependendo do seu tipo.
     *
     * @return O tipo do canal: "TEXTO" se for um Canal de Texto. "VOZ" se for um Canal de Voz.
     */
    virtual std::string getTipo() = 0;

    /**
     * @brief Retorna as mensagens contidas no canal.
     *
     * Essa função é sobrescrita nas classes derivadas, funcionando de forma diferente
     * dependendo do seu tipo.
     *
     * @return Um objeto <vector> do tipo Mensagem, com as mensagens dentro.
     */
    virtual std::vector<Mensagem> getMensagens() = 0;

    /**
     * @brief Envia uma mensagem para o canal.
     *
     * Essa função é sobrescrita nas classes derivadas, funcionando de forma diferente
     * dependendo do seu tipo.
     *
     * @param mensagem O objeto do tipo Mensagem a ser enviado ao canal.
     */
    virtual void enviarMensagem(Mensagem mensagem) = 0;

    /**
     * @brief Lista as mensagens do canal.
     *
     * Essa função é sobrescrita nas classes derivadas, funcionando de forma diferente
     * dependendo do seu tipo.
     *
     * Precisa do ponteiro dos usuários para obter o nome deles.
     *
     * @param usuarios Um ponteiro para um vetor de ponteiros de usuários do servidor.
     */
    virtual void listarMensagens(std::vector<Usuario *> *usuarios) = 0;
};

#endif
