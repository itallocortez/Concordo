/**
 * @file main.cpp
 *
 * @brief Este arquivo contém a função principal do programa.
 */

#include "sistema.hpp"

/**
 * @brief Função principal do programa.
 *
 * Cria um objeto do tipo Sistema e executa um loop de leitura e execução de comandos
 * até que o comando de fechamento (quit) seja dado.
 *
 */
int main(void)
{
    // Cria o objeto sistema;
    Sistema s;

    // Enquanto não mandar fechar fica lendo e executando comandos.
    while (!s.fechar()) {
      // Lê o comando do usuário.
      s.lerComando();

      // Antes de executar, carrega dados dados salvos no disco.
      s.carregar();

      // Executa as operações do comando.
      s.executarComando();

      // Salva qualquer alteração feita no disco.
      s.salvar();
    }
  
    return 0;
}