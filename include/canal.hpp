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
 * A classe Canal armazena as informações básicas de uma canal.
 */
class Canal {
  protected:
    std::string nome; /**< Nome do canal. */
  public:
  	Canal(std::string nome);

    // Destrutor virtual do Canal
	  virtual ~Canal() = default;

    std::string getNome();

    /*
     * @brief retorna o tipo do Canal. Sobrescrita nas classes derivadas
     * @return GERAL, se for um Canal Geral, TEXTO se for um Canal de Texto, VOZ se 
     * for um Canal de voz.
     */
    virtual std::string getTipo(void) = 0;

    virtual void enviarMensagem(Mensagem mensagem) = 0;

    virtual void listarMensagens(std::vector<Usuario *> *usuarios) = 0;
};

#endif