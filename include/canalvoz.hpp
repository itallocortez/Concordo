#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "canal.hpp"

#include <iostream>

/**
 * @file canalvoz.hpp
 *
 * @brief Este arquivo contém as declarações da Sub-Classe CanalVoz.
 */

/**
 * @brief Sub Classe de Canal para canal de voz.
 * 
 * A classe CanalVoz armazena a última mensagem enviada ao canal de voz.
 */
class CanalVoz : public Canal {
  private:
    Mensagem ultimaMensagem; /**< Última mensagem enviada. */

  public:
    /**
     * @brief Construtor da classe CanalVoz.
     *
     * @param nome O nome do canal de voz.
     */
    CanalVoz(std::string nome);

    /**
     * @brief Retorna o tipo do canal de voz.
     *
     * @return Retorna o tipo do canal de voz: "VOZ".
     */
    std::string getTipo() override;

    std::vector<Mensagem> getMensagens() override;

    /**
     * @brief Envia uma mensagem para o canal de voz.
     *
     * @param mensagem A mensagem a ser enviada.
     */
    void enviarMensagem(Mensagem mensagem) override;

    /**
     * @brief Lista as mensagens do canal de voz.
     *
     * @param usuarios Um ponteiro para um vetor de ponteiros de usuários.
     */
    void listarMensagens(std::vector<Usuario *> *usuarios) override;
};

#endif
