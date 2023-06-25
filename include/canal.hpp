#ifndef CANAL_H
#define CANAL_H

using namespace std;

#include <string>
#include <vector>
#include <mensagem.hpp>

/**
 * @brief Classe que armazena as informações de um canal.
 * 
 * A classe Canal armazena as informações básicas de uma canal.
 */
class Canal {
  private:
    string nome; /**< Nome do canal. */
};


/**
 * @brief Sub-Classe de Canal para canal de texto.
 * 
 * A classe CanalTexto armazena as mensagens enviadas ao canal de texto.
 */
class CanalTexto : public Canal {
  private:
    std::vector <Mensagem> mensagens; /**< Lista de mensagens do canal de texto. */
};

/**
 * @brief Sub-Classe de Canal para canal de voz.
 * 
 * A classe CanalVoz armazena a última mensagem enviada ao canal de voz.
 */
class CanalVoz : public Canal {
  private:
    Mensagem ultimaMensagem; /**< Últimqa mensagem enviada. */
};

#endif