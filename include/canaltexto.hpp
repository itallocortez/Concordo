#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>
#include <iostream>

#include "canal.hpp"
#include "mensagem.hpp"

/**
 * @file canaltexto.hpp
 *
 * @brief Este arquivo contém as declarações da sub-classe CanalTexto.
 */

/**
 * @brief Sub Classe de Canal para canais de texto.
 * 
 * A classe CanalTexto armazena as mensagens enviadas ao canal de texto.
 */
class CanalTexto : public Canal {
  private:
    std::vector<Mensagem> mensagens; /**< Lista de mensagens do canal de texto. */

  public:
    /**
     * @brief Construtor da classe CanalTexto.
     *
     * @param nome O nome do canal de texto.
     */
    CanalTexto(std::string nome);

    /**
     * @brief Retorna o tipo do canal.
     *
     * @return "TEXTO".
     */
    std::string getTipo() override;

    /**
     * @brief Retorna as mensagens contidas no canal de texto.
     *
     * @return Um objeto <vector> do tipo Mensagem, com as mensagens dentro.
     */
    std::vector<Mensagem> getMensagens() override;

    /**
     * @brief Envia uma mensagem para o canal de texto.
     *
     * @param mensagem O objeto do tipo Mensagem a ser enviado ao canal.
     */
    void enviarMensagem(Mensagem mensagem) override;

    /**
     * @brief Lista as mensagens do canal de texto.
     *
     * Precisa do ponteiro dos usuários para obter o nome deles.
     *
     * @param usuarios Um ponteiro para um vetor de ponteiros de usuários do servidor.
     */
    void listarMensagens(std::vector<Usuario *> *usuarios) override;
};

#endif
