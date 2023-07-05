#include "canaltexto.hpp"

/**
 * @file canaltexto.cpp
 *
 * @brief Este arquivo contém as declarações da Sub-Classe CanalTexto.
 */

using namespace std;

CanalTexto::CanalTexto(std::string nome) : Canal(nome) 
{
}

string CanalTexto::getTipo(void) {
  return "TEXTO";
}

void CanalTexto::enviarMensagem(Mensagem mensagem) {
  mensagens.push_back(mensagem);
}

void CanalTexto::listarMensagens(std::vector<Usuario *> *usuarios) {
  // Para mensagem armazenada no canal
  for (Mensagem m : mensagens) {
    // Imprime cada mensagem
    
    int id = m.getIdEnviou();
    string dataHora = m.getDataHora();
    string nome = m.getNomeEnviou(id, usuarios);
    string mensagem = m.getConteudo();
    
    cout << nome << " <" << dataHora << ">: " << mensagem << endl;
  }
}

