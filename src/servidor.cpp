#include "servidor.hpp"

Servidor::Servidor() {
  
}

Servidor::Servidor(int usuarioDonoId, string nome) {
  this->usuarioDonoId = usuarioDonoId;
  this->nome = nome;
  this->descricao = "";
  this->codigoConvite = "";
}

std::string Servidor::getNome(void) {
  return this->nome;
}

std::string Servidor::getDescricao(void) {
  return this->descricao;
}

int Servidor::getDonoId(void) {
  return this->usuarioDonoId;
}

std::string Servidor::getCodigoConvite(void) {
  return this->codigoConvite;
}

std::vector<int> Servidor::getParticipantes(void) {
  return this->participantesIDs;
}

void Servidor::setCodigoConvite(string codigo) {
  this->codigoConvite = codigo;
}

void Servidor::setDescricao(string descricao) {
  this->descricao = descricao;
}

// Se o usuário participa ou não do servidor
bool Servidor::participa(int id) {
  // Verifica cada usuário no <vector> de ids
  for (int id_vector : participantesIDs) {
    // Se encontrar um com ID informado
    if(id_vector == id) {
      // Ele já participa, então não precisa adicionar
      return true;
    }
  }
  return false;
}

// Adiciona o usuário como participante do servidor
void Servidor::addParticipante(int id) {
  // Se o usuário não participar do servidor
  if(!participa(id)) {
    // Adiicona ele na lista de participantes
    participantesIDs.push_back(id);
  }
}