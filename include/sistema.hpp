#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include <algorithm>

#include "usuario.hpp"
#include "servidor.hpp"
#include "canal.hpp"
#include "comando.hpp"

/**
 * @brief Classe que armazena as informações do sistema.
 * 
 * A classe Sistema armazena as informações básicas do sistema.
 */

class Sistema {
  private:
    std::vector<Usuario *> usuarios; /**< Lista de usuarios contidos no sistema. */
    std::vector<Servidor *> servidores; /**< Lista de servidores contidos no sistema. */
    int usuarioAtualId; /**< ID do usuário atualmente logado no sistema. */
    Servidor *servidorAtual = nullptr; /**< Servidor que o usuário está acessando atualmente. */
    Canal canalAtual; /**< Canal que o usuário está acessando atualmente. */
    Comando comandoAtual; /**< Comando que o sistema está processando atualmente. */
    bool estaLogado = false; /**< Se existe um usuário logado no sistema. */
    bool precisaFechar = false; /**< Se o programa deve ser fechado. */
  public:
    Sistema();

    /**
    * @brief Retorna um ponteiro para o objeto Usuario correspondente ao ID fornecido.
    *
    * @param id O ID do usuário a ser procurado.
    * @return Um ponteiro para o objeto Usuario correspondente ao ID, ou nullptr se não encontrado.
    */
    Usuario* usuarioPeloId(int id);

    /**
    * @brief Retorna um ponteiro para o objeto Usuario correspondente ao Email fornecido.
    *
    * @param email O Email do usuário a ser procurado.
    * @return Um ponteiro para o objeto Usuario correspondente ao Email, ou nullptr se não encontrado.
    */
    Usuario* usuarioPeloEmail(string email);

    Servidor* servidorPeloNome(string nome);

    int novoIdUsuario(void);

    /**
    * @brief Verifica se o sistema precisa ser fechado.
    *
    * A função `fechar()` verifica se o sistema precisa ser fechado, retornando o valor
    * da variável `precisaFechar` do objeto `Sistema`.
    *
    * @return Valor booleano indicando se o sistema precisa ser fechado.
    */
    bool fechar(void);

    /**
    * @brief Lê o comando digitado pelo usuário.
    *
    * A função `lerComando()` chama a função `ler()` do objeto `comandoAtual` para ler
    * o comando digitado pelo usuário e interpretar o que é comando e argumento. O comando
    * e seus argumentos são armazenados nas variáveis privadas da classe `Comando`.
    * 
    * @see Comando::ler()
    */
    void lerComando(void);

    /**
    * @brief Executa o comando atualmente armazenado.
    *
    * A função `executarComando()` chama a função `executar()` do objeto `comandoAtual` para
    * executar o comando armazenado, passando os parâmetros necessários.
    *
    * @note Antes de chamar esta função, certifique-se de que o comando tenha sido lido e armazenado
    * corretamente usando a função `lerComando()`.
    *
    * @see Comando::executar()
    */
    void executarComando(void);
};

#endif