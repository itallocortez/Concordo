#include "canalvoz.hpp"

/**
 * @file canalvoz.cpp
 *
 * @brief Este arquivo contém as declarações da Sub-Classe CanalVoz.
 */
using namespace std;

CanalVoz::CanalVoz(std::string nome) : Canal(nome)
{
  
}

std::string CanalVoz::getTipo(void) {
  return "VOZ";
}

void CanalVoz::enviarMensagem(Mensagem mensagem) {
  this->ultimaMensagem = mensagem;
}

void CanalVoz::listarMensagens(std::vector<Usuario *> *usuarios) {
  Mensagem m = ultimaMensagem;
  
  if(m.getConteudo() != "") {
    int id = m.getIdEnviou();
    string dataHora = m.getDataHora();
    string nome = m.getNomeEnviou(id, usuarios);
    string mensagem = m.getConteudo();
    
    cout << nome << " <" << dataHora << ">: " << mensagem << endl;
  } else {
    std::cout << "Sem mensagens para exibir" << std::endl;
  }
}