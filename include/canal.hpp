#ifndef CANAL_H
#define CANAL_H

#include <string>

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
  private:
    std::string nome; /**< Nome do canal. */
  public:
  	Canal();
};

#endif