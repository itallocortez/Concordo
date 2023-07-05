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
 * @brief Sub-Classe de Canal para canal de texto.
 * 
 * A classe CanalTexto armazena as mensagens enviadas ao canal de texto.
 */
class CanalTexto : public Canal {
  private:
    std::vector <Mensagem> mensagens; /**< Lista de mensagens do canal de texto. */
  public:
  	CanalTexto(std::string nome);

    /*
     * @brief Classe virtual de Canal. Retorna o Tipo do Canal
     * @return TEXTO, para Canal de Texto
     */
    std::string getTipo(void) override;

    void enviarMensagem(Mensagem mensagem) override;

    void listarMensagens(std::vector<Usuario *> *usuarios) override;
};

#endif