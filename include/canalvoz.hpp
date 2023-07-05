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
 * @brief Sub-Classe de Canal para canal de voz.
 * 
 * A classe CanalVoz armazena a última mensagem enviada ao canal de voz.
 */
class CanalVoz : public Canal {
  private:
    Mensagem ultimaMensagem; /**< Última mensagem enviada. */
  public:
  	CanalVoz(std::string nome);

    /*
     * @brief Classe virtual de Canal. Retorna o Tipo do Canal
     * @return VOZ, para Canal de Texto
     */
    std::string getTipo(void) override;

    void enviarMensagem(Mensagem mensagem) override;

    void listarMensagens(std::vector<Usuario *> *usuarios) override;
};

#endif