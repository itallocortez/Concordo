#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

#include "usuario.hpp"
#include "servidor.hpp"
#include "canal.hpp"
#include "canalvoz.hpp"
#include "canaltexto.hpp"
#include "comando.hpp"

/**
 * @file sistema.hpp
 *
 * @brief Este arquivo contém as declarações da classe Sistema.
 */

/**
 * @brief Classe que armazena e gerencia as informações do sistema.
 * 
 * A classe Sistema armazena as informações básicas do sistema, incluindo usuários, servidores e estado atual.
 * Ela fornece métodos para gerenciar os usuários, servidores, executar comandos e controlar o estado do sistema.
 */

class Sistema {
  private:
    std::vector<Usuario *> usuarios; /**< Lista de usuarios contidos no sistema. */
    std::vector<Servidor *> servidores; /**< Lista de servidores contidos no sistema. */
    int usuarioAtualId; /**< ID do usuário atualmente logado no sistema. */
    Servidor *servidorAtual = nullptr; /**< Servidor que o usuário está acessando atualmente. */
    Canal *canalAtual = nullptr; /**< Canal que o usuário está acessando atualmente. */
    Comando comandoAtual; /**< Comando que o sistema está processando atualmente. */
    bool estaLogado = false; /**< Se existe um usuário logado no sistema. */
    bool precisaFechar = false; /**< Se o programa deve ser fechado. */

    /**
     * @brief Carrega os usuários salvos no disco.
     * 
     * Esta função recupera os dados salvos no arquivo "usuarios.txt" e os restaura no sistema,
     * atualizando o estado interno com as informações dos usuários previamente armazenadas.
     */
    void carregarUsuarios(void);

    /**
     * @brief Carrega os servidores salvos no disco.
     * 
     * Esta função recupera os dados salvos no arquivo "servidores.txt" e os restaura no sistema,
     * atualizando o estado interno com as informações dos servidores previamente armazenadas.
     */
    void carregarServidores(void);


    /**
     * @brief Salva os usuários atuais no disco.
     * 
     * Esta função salva os usuários atuais no disco, armazenando as informações dos usuários 
     * em um arquivo específico, possibilitando a recuperação dessas informações posteriormente.
     */
    void salvarUsuarios(void);

    /**
     * @brief Salva os servidores atuais no disco.
     * 
     * Esta função salva os servidores atuais no disco, armazenando as informações dos servidores 
     * em um arquivo específico, possibilitando a recuperação dessas informações posteriormente.
     */
    void salvarServidores(void);
  public:
    /**
     * @brief Construtor padrão da classe Sistema.
     * 
     * Inicializa um objeto Sistema com valores padrão.
     */
    Sistema();

    /**
     * @brief Destrutor padrão da classe Sistema.
     * 
     * Libera toda a memória alocada dinamicamente pelo programa.
     */
    ~Sistema();


    /**
     * @brief Retorna a data atual como uma string.
     * 
     * Esta função retorna a data atual no formato de uma string.
     *
     * @return A data atual no formato "DD/MM/AAAA - HH:MM:SS".
     */
    std::string getDataHoraAtual(void);

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
    * @return Um ponteiro para o objeto Usuario correspondente ao E-mail, ou nullptr se não encontrado.
    */
    Usuario* usuarioPeloEmail(std::string email);

    /**
    * @brief Retorna um ponteiro para o objeto Servidor correspondente ao nome fornecido.
    *
    * @param nome O nome do servidor a ser procurado.
    * @return Um ponteiro para o objeto Servidor correspondente ao nome, ou nullptr se não encontrado.
    */
    Servidor* servidorPeloNome(std::string nome);

    /**
    * @brief Gera um novo ID para um usuário.
    *
    * A função `novoIdUsuario()` gera um novo ID para um usuário, garantindo que o ID seja exclusivo
    * dentro do sistema.
    *
    * @return O novo ID gerado para o usuário.
    */
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
    * É aqui que estão implementados  todos comandos.
    *
    * @note Antes de chamar esta função, certifique-se de que o comando tenha sido lido e armazenado
    * corretamente usando a função `lerComando()`.
    *
    * @see Comando::executar()
    */
    void executarComando(void);

    /**
     * @brief Carrega os usuários e servidores salvos no disco.
     * 
     * Esta função recupera os dados salvos nos arquivos de usuários e servidores e os restaura no sistema,
     * atualizando o estado interno com as informações dos usuários e servidores previamente armazenadas.
     */
    void carregar();

    /**
     * @brief Salva os usuários e servidores atuais no disco.
     * 
     * Esta função salva os usuários e servidores atuais no disco, armazenando as informações em um arquivo 
     * específico, possibilitando a recuperação dessas informações posteriormente.
     */
    void salvar();
};

#endif