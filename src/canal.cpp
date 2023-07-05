#include "canal.hpp"

/**
 * @file canal.cpp
 *
 * @brief Este arquivo implementa as funções da classe Canal.
 */

using namespace std;

Canal::Canal(string nome) {
  this->nome = nome;
}

string Canal::getNome() {
  return this->nome;
}