#include "comando.hpp"

/**
 * @file comando.cpp
 *
 * @brief Este arquivo implementa as funções da classe Comando.
 */

using namespace std;

Comando::Comando()
{
  
}

std::vector<std::string> Comando::splitString(std::string str, char delimiter)
{
    std::vector<std::string> substrings; // Cria um stringstream a partir da string de entrada
    std::stringstream ss(str);
    std::string substring;

    // Loop para obter cada substring usando getline() com o delimitador especificado
    while (std::getline(ss, substring, delimiter)) {
        substrings.push_back(substring); // Adiciona a substring ao vetor de substrings
    }

    return substrings; // Retorna o vetor de substrings resultante
}

std::string Comando::getComando(void) 
{
  return this->comando;
}

std::string Comando::getArgumento(int i) 
{
  return this->argumentos[i];
}

int Comando::getNumeroArgumentos(void) 
{
  return this->numeroArgumentos;
}

bool Comando::existe() 
{
  std::unordered_set<std::string> strings = {
    "quit",
    "create-user",
    "login",
    "disconnect",
    "create-server",
    "set-server-desc",
    "set-server-invite-code",
    "list-servers",
    "remove-server", 
    "enter-server" , 
    "leave-server", 
    "list-participants"
  };

  return strings.count(this->comando) > 0;
}

void Comando::ler(void) 
{
  std::string entrada; // String que armazena a entrada do usuário

  // Loop enquanto não digitar uma entrada válida.
  do {
    // Pega a entrada digitada pelo usuário
    //std::cout << "Digite o comando: " << std::endl;
    std::getline(std::cin, entrada);

    // Se a entrada não for nula
    if (!entrada.empty()) {
      // Como os argumentos são separados por espaços, seta isso como delimitador
      char delimitador = ' ';

      // Usa a função splitString() para separar a string em várias partes.
      std::vector < std::string > substrings = splitString(entrada, delimitador);

      // Seta o comando como a primeira parte encontrada
      this->comando = substrings[0];

      // Remove possíveis argumentos de comandos anteriores.
      this->argumentos.clear();
      
      // Se existirem argumentos no comando
      if (substrings.size() > 1) {
        // Adiciona cada argumento na lista de argumentos do comando.
        for (int i = 1; i < substrings.size(); i++) {
          this->argumentos.push_back(substrings[i]);
        }
      }

      // Pega o número de argumentos a partir da lista
      this->numeroArgumentos = this->argumentos.size();

      break; // Sai do loop já que uma entrada válida foi fornecida.
    }

    //std::cout << "Entrada nula. Digite novamente." << std::endl;
  } while (true);
}