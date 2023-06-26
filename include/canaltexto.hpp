#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>

#include "canal.hpp"
#include "mensagem.hpp"

/**
 * @file canaltexto.hpp
 *
 * @brief Este arquivo contém as declarações da Sub-Classe CanalTexto.
 */

/**
 * @brief Sub-Classe de Canal para canal de texto.
 * 
 * A classe CanalTexto armazena as mensagens enviadas ao canal de texto.
 */
class CanalTexto : public Canal {
  private:
    std::vector <Mensagem> mensagens; /**< Lista de mensagens do canal de texto. */
  public:
  	CanalTexto();
};

#endif