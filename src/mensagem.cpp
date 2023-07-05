#include "mensagem.hpp"

/**
 * @file mensagem.cpp
 *
 * @brief Este arquivo implementa as funções da classe Mensagem.
 */

using namespace std;

Mensagem::Mensagem() {
}

Mensagem::Mensagem(int enviadaPor, string dataHora, string conteudo) {
  this->enviadaPor = enviadaPor;
  this->dataHora = dataHora;
  this->conteudo = conteudo;
}

string Mensagem::getDataHora(void) {
  return this->dataHora;
}
void Mensagem::setDataHora(string dataHora) {
  this->dataHora = dataHora;
}

int Mensagem::getIdEnviou(void) {
  return this->enviadaPor;
}
void Mensagem::setIdEnviou(int id) {
  this->enviadaPor = id;
}

std::string Mensagem::getNomeEnviou(int id, std::vector<Usuario *> *usuarios){
  // Verifica cada usuário no <vector> de usuários
  for (Usuario *usuario : *usuarios) {
    // Se encontrar um com ID informado
    if(usuario->getId() == id) {
      // Retorna o ponteiro para esse usuário
      return usuario->getNome();
    }
  }
  // Se não encontrar, retorna um ponteiro nulo.
  return nullptr;
}

string Mensagem::getConteudo(void) {
  return this->conteudo;
}
void Mensagem::setConteudo(string conteudo) {
  this->conteudo = conteudo;
}