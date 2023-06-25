#include "usuario.hpp"

#include <string>

Usuario::Usuario(int id, string email, string senha, string nome)
{
  this->id = id;
  this->email = email;
  this->senha = senha;
  this->nome = nome;
}

int Usuario::getId(void)
{
  return this->id;
}

string Usuario::getNome(void) {
  return this->nome;
}

std::string Usuario::getEmail(void)
{
  return this->email;
}

std::string Usuario::getSenha(void)
{
  return this->senha;
}