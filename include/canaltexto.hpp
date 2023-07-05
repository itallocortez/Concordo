#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>
#include <iostream>

#include "canal.hpp"
#include "mensagem.hpp"

/**
 * @file canaltexto.hpp
 *
 * @brief Este arquivo contém as declarações da Sub-Classe CanalTexto.
 */

/**
 * @brief Sub Classe de Canal para canal de texto.
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
     * @brief Retorna o tipo do canal de texto.
     *
     * @return Retorna o tipo do canal de texto: "TEXTO".
     */
    std::string getTipo() override;

    /**
     * @brief Envia uma mensagem para o canal de texto.
     *
     * @param mensagem A mensagem a ser enviada.
     */
    void enviarMensagem(Mensagem mensagem) override;

    /**
     * @brief Lista as mensagens do canal de texto.
     *
     * @param usuarios Um ponteiro para um vetor de ponteiros de usuários.
     */
    void listarMensagens(std::vector<Usuario *> *usuarios) override;
};

#endif
