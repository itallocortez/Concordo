#include "sistema.hpp"

int main() {
    // Cria o objeto sistema;
    Sistema s;

    // Enquanto não mandar fechar fica lendo e executando comandos.
    while (!s.fechar()) {
      s.lerComando();
      s.executarComando();
    }
  
    return 0;
}