#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include "canal.hpp"

using namespace std;

/**
 * @brief Classe que armazena as informações de um servidor.
 * 
 * A classe Servidor armazena as informações básicas de uma servidor.
 */
class Servidor {
  private:
    int usuarioDonoId; /**< ID do usuário que é dono do canal */
    string nome; /**< Nome do canal. */
    string descricao; /**< Descrição do canal. */
    string codigoConvite; /**< Código necessário para entrar no servidor. */
    std::vector<Canal *> canais; /**< Lista de canais contidos ao servidor. */
    std::vector<int> participantesIDs; /**< Listas de Ids dos usuários participantes do servidor. */
  public:
    Servidor();
    Servidor(int usuarioDonoId, string nome);

    /**
    * @brief Retorna o nome do servidor.
    * 
    * Essa função retorna o nome do servidor.
    *
    * @return O Nome do servidor.
    */
    string getNome(void);

    string getDescricao(void);

    int getDonoId(void);

    string getCodigoConvite(void);

    std::vector<int> getParticipantes(void);

    void setCodigoConvite(string codigo);

    void setDescricao(string descricao);

    bool participa(int id);

    void addParticipante(int id);
};

#endif