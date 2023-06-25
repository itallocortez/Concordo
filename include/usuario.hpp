#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

#include <string>

/**
 * @brief Classe que armazena as informações de um usuário.
 * 
 * A classe Usuario armazena as informações básicas de um usuário.
 */
class Usuario {
  private:
    int id; /**< ID do usuário. */
    string nome; /**< Nome do usuário. */
    string email; /**< E-mail do usuário. */
    string senha; /**< Senha do usuário. */
  public:
    Usuario(int id, string nome, string email, string senha);

    /**
    * @brief Retorna o ID do usuário.
    * 
    * Essa função retorna o ID do usuário.
    *
    * @return O ID do usuário.
    */
    int getId(void);

    string getNome(void);

    /**
    * @brief Retorna o E-mail do usuário.
    * 
    * Essa função retorna o E-mail do usuário.
    *
    * @return O E-mail do usuário.
    */
    string getEmail(void);

    /**
    * @brief Retorna a Senha do usuário.
    * 
    * Essa função retorna a Senha do usuário.
    *
    * @return A Senha do usuário.
    */
    string getSenha(void);
};

#endif