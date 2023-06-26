#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/**
 * @file usuario.hpp
 *
 * @brief Este arquivo contém as declarações da classe Usuario.
 */

/**
 * @brief Classe que armazena e gerencia as informações de um usuário.
 * 
 * A classe Usuario armazena e gerencia as informações básicas de um Usuário, incluindo o seu ID,
 * nome, e-mail e senha.
 */
class Usuario {
  private:
    int id; /**< ID do usuário. */
    std::string nome; /**< Nome do usuário. */
    std::string email; /**< E-mail do usuário. */
    std::string senha; /**< Senha do usuário. */
  public:
    /**
    * @brief Construtor da classe Usuario.
    * 
    * Cria um objeto Usuario com o ID, nome, email e senha especificados.
    *
    * @param id O ID do usuário.
    * @param nome O nome do usuário.
    * @param email O e-mail do usuário.
    * @param senha A senha do usuário.
    */
    Usuario(int id, std::string nome, std::string email, std::string senha);

    /**
    * @brief Retorna o ID do usuário.
    * 
    * Essa função retorna o ID do usuário.
    *
    * @return O ID do usuário.
    */
    int getId(void);

    std::string getNome(void);

    /**
    * @brief Retorna o E-mail do usuário.
    * 
    * Essa função retorna o E-mail do usuário.
    *
    * @return O E-mail do usuário.
    */
    std::string getEmail(void);

    /**
    * @brief Retorna a Senha do usuário.
    * 
    * Essa função retorna a Senha do usuário.
    *
    * @return A Senha do usuário.
    */
    std::string getSenha(void);
};

#endif