#include "servidor.hpp"

/**
 * @file servidor.cpp
 *
 * @brief Este arquivo implementa as funções da classe Servidor.
 */

using namespace std;

Servidor::Servidor(int usuarioDonoId, string nome) 
{
  this->usuarioDonoId = usuarioDonoId;
  this->nome = nome;
  this->descricao = "";
  this->codigoConvite = "";
}

Servidor::~Servidor()
{
  // Desaloca qualquer memória dinâmica dos <vector's>
  for (Canal *canal : canais) {
    delete canal;
  }

  // Apaga os elementos dos <vector's>
  canais.clear();
}

std::string Servidor::getNome(void) 
{
  return this->nome;
}

std::string Servidor::getDescricao(void) 
{
  return this->descricao;
}

int Servidor::getDonoId(void) 
{
  return this->usuarioDonoId;
}

std::string Servidor::getCodigoConvite(void) 
{
  return this->codigoConvite;
}

std::vector<int> Servidor::getParticipantes(void) 
{
  return this->participantesIDs;
}

std::vector<Canal *> Servidor::getCanais(void)
{
  return this->canais;
}

void Servidor::setCodigoConvite(string codigo) 
{
  this->codigoConvite = codigo;
}

void Servidor::setDescricao(string descricao) 
{
  this->descricao = descricao;
}

// Se o usuário participa ou não do servidor
bool Servidor::participa(int id) 
{
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
void Servidor::addParticipante(int id) 
{
  // Se o usuário não participar do servidor
  if(!participa(id)) {
    // Adiicona ele na lista de participantes
    participantesIDs.push_back(id);
  }
}

void Servidor::addCanal(Canal *c)
{
  canais.push_back(c);
}

Canal* Servidor::canalPeloNome(string nome)
{
  // Verifica cada canal no <vector> de canais
  for (Canal *c : canais) {
    // Se encontrar um com ID informado
    if(c->getNome() == nome) {
      // Ele já participa, então não precisa adicionar
      return c;
    }
  }
  return nullptr;
}

void Servidor::listarCanais()
{
  std::cout << "#canais de texto" << std::endl;

  // Para cada canal no <vector> de canais
  for (Canal *c : canais) {
    // Verifica se é do tipo TEXTO e imprime
    if(c->getTipo() == "TEXTO") {
      std::cout << c->getNome() << std::endl;
    }
  }

  std::cout << "#canais de voz" << std::endl;
  
  // Para cada canal no <vector> de canais
  for (Canal *c : canais) {
    // Verifica se é do tipo TEXTO e imprime
    if(c->getTipo() == "VOZ") {
      std::cout << c->getNome() << std::endl;
    }
  }
}