#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <string>
#include <vector>
#include <iostream>

#include "canal.hpp"
#include "canalvoz.hpp"
#include "canaltexto.hpp"

/**
 * @file servidor.hpp
 *
 * @brief Este arquivo contém as declarações da classe Servidor.
 */

/**
 * @brief Classe que armazena e gerencia as informações de um servidor.
 * 
 * A classe Servidor armazena e gerencia as informações básicas de um servidor, incluindo o ID do dono,
 * nome, descrição, código de convite, lista de canais contidos no servidor e lista de participantes.
 */
class Servidor {
  private:
    int usuarioDonoId; /**< ID do usuário que é dono do servidor. */
    std::string nome; /**< Nome do servidor. */
    std::string descricao; /**< Descrição do servidor. */
    std::string codigoConvite; /**< Código necessário para entrar no servidor. */
    std::vector<Canal *> canais; /**< Lista de canais contidos no servidor. */
    std::vector<int> participantesIDs; /**< Listas de Ids dos usuários participantes do servidor. */
  public:
    /**
    * @brief Construtor da classe Servidor.
    *
    * Cria um objeto Servidor com o usuário dono e o nome especificados.
    *
    * @param usuarioDonoId O ID do usuário dono do servidor.
    * @param nome O nome do servidor.
    */
    Servidor(int usuarioDonoId, std::string nome);

    /**
    * @brief Destrutor da classe Servidor.
    */
    ~Servidor();

    /**
    * @brief Retorna o nome do servidor.
    * 
    * Esta função retorna o nome do servidor.
    *
    * @return O nome do servidor.
    */
    std::string getNome(void);


    /**
    * @brief Retorna a descrição do servidor.
    * 
    * Esta função retorna a descrição do servidor.
    *
    * @return A descrição do servidor.
    */
    std::string getDescricao(void);

    /**
    * @brief Retorna o ID do usuário dono do servidor.
    * 
    * Esta função retorna o ID do usuário dono do servidor.
    *
    * @return O ID do usuário dono do servidor.
    */
    int getDonoId(void);

    /**
    * @brief Retorna o código de convite do servidor.
    * 
    * Esta função retorna o código de convite do servidor.
    *
    * @return O código de convite do servidor.
    */
    std::string getCodigoConvite(void);

    /**
    * @brief Retorna a lista de IDs dos participantes do servidor.
    * 
    * Esta função retorna a lista de IDs dos participantes do servidor.
    *
    * @return A lista de IDs dos participantes do servidor.
    */
    std::vector<int> getParticipantes(void);

    /**
    * @brief Retorna a lista com os ponteiros dos Canais do servidor.
    * 
    * Esta função retorna a lista com os ponteiros dos Canais do servidor.
    *
    * @return A lista de ponteiros dos Canais do servidor.
    */
    std::vector<Canal *> getCanais(void);

    /**
    * @brief Define o código de convite do servidor.
    * 
    * Esta função define o código de convite do servidor.
    *
    * @param codigo O código de convite a ser definido.
    */
    void setCodigoConvite(std::string codigo);

    /**
    * @brief Define a descrição do servidor.
    * 
    * Esta função define a descrição do servidor.
    *
    * @param descricao A descrição a ser definida.
    */
    void setDescricao(std::string descricao);

    /**
    * @brief Verifica se um usuário participa do servidor.
    * 
    * Esta função verifica se um usuário, identificado pelo seu ID, é um participante do servidor.
    *
    * @param id O ID do usuário a ser verificado.
    * @return true se o usuário é um participante, false caso contrário.
    */
    bool participa(int id);

    /**
    * @brief Adiciona um participante ao servidor.
    * 
    * Esta função adiciona um usuário, identificado pelo seu ID, à lista de participantes do servidor.
    *
    * @param id O ID do usuário a ser adicionado.
    */
    void addParticipante(int id);

    /**
    * @brief Adiciona um canal ao servidor.
    * 
    * Esta função adiciona um canal à lista de canais do servidor.
    *
    * @param c Um ponteiro para o canal a ser adicionado.
    */
    void addCanal(Canal *c);

    /**
    * @brief Retorna um canal pelo nome.
    * 
    * Esta função retorna um ponteiro para um canal com o nome especificado, se existir no servidor.
    *
    * @param nome O nome do canal a ser obtido.
    * @return Um ponteiro para o canal, ou nullptr se o canal não existir.
    */
    Canal* canalPeloNome(std::string nome);

    /**
    * @brief Lista os canais do servidor.
    * 
    * Esta função lista os canais do servidor no console.
    */
    void listarCanais();
};

#endif