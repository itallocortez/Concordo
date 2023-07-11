#ifndef CANAL_VOZ_H
#define CANAL_VOZ_H

#include "canal.hpp"

#include <iostream>

/**
 * @file canalvoz.hpp
 *
 * @brief Este arquivo contém as declarações da sub-classe CanalVoz.
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
     * @brief Retorna o tipo do canal.
     *
     * @return "VOZ".
     */
    std::string getTipo() override;

    /**
     * @brief Retorna a mensagem contida no canal de voz.
     *
     * @return Um objeto <vector> do tipo Mensagem, com a mensagem dentro.
     */
    std::vector<Mensagem> getMensagens() override;

    /**
     * @brief Envia uma mensagem para o canal de voz.
     *
     * @param mensagem O objeto do tipo Mensagem a ser enviado ao canal.
     */
    void enviarMensagem(Mensagem mensagem) override;

    /**
     * @brief Lista as mensagens do canal de voz.
     *
     * Precisa do ponteiro dos usuários para obter o nome deles.
     *
     * @param usuarios Um ponteiro para um vetor de ponteiros de usuários do servidor.
     */
    void listarMensagens(std::vector<Usuario *> *usuarios) override;
};

#endif
