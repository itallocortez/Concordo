#include "sistema.hpp"

/**
 * @file sistema.cpp
 *
 * @brief Este arquivo implementa as funções da classe Sistema.
 */

using namespace std;

Sistema::Sistema()
{
  
}

Sistema::~Sistema()
{
  // Desaloca qualquer memória dinâmica dos <vector's>
  for (Usuario *usuario : usuarios) {
    delete usuario;
  }
  for (Servidor *servidor : servidores) {
    delete servidor;
  }
  
  // Apaga os elementos dos <vector's>
  usuarios.clear();
  servidores.clear();
}

std::string Sistema::getDataHoraAtual(void) {
  auto currentTime = std::chrono::system_clock::now();
  std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
  
  std::stringstream ss;
  ss << std::put_time(std::localtime(&time), "%d/%m/%Y - %H:%M:%S");
  
  return ss.str();
}

Usuario* Sistema::usuarioPeloId(int id) 
{
  // Verifica cada usuário no <vector> de usuários
  for (Usuario *usuario : usuarios) {
    // Se encontrar um com ID informado
    if(usuario->getId() == id) {
      // Retorna o ponteiro para esse usuário
      return usuario;
    }
  }
  // Se não encontrar, retorna um ponteiro nulo.
  return nullptr;
}

Usuario* Sistema::usuarioPeloEmail(string email) 
{
  // Verifica cada usuário no <vector> de usuários
  for (Usuario *usuario : usuarios) {
    // Se encontrar um com ID informado
    if(usuario->getEmail() == email) {
      // Retorna o ponteiro para esse usuário
      return usuario;
    }
  }
  // Se não encontrar, retorna um ponteiro nulo.
  return nullptr;
}

int Sistema::novoIdUsuario(void) 
{
  int maiorId = 0;
    
  for (Usuario *usuario : usuarios) {
        int atualId = usuario->getId();
        
        if (atualId > maiorId) {
            maiorId = atualId;
        }
    }
    
  // O ID do novo usuário será o maior ID + 1
  return maiorId + 1;
}

Servidor* Sistema::servidorPeloNome(string nome) 
{
  // Verifica cada usuário no <vector> de usuários
  for (Servidor *servidor : servidores) {
    // Se encontrar um com ID informado
    if(servidor->getNome() == nome) {
      // Retorna o ponteiro para esse usuário
      return servidor;
    }
  }
  // Se não encontrar, retorna um ponteiro nulo.
  return nullptr;
}

bool Sistema::fechar(void) 
{
  return precisaFechar;
}

void Sistema::lerComando(void) 
{
  comandoAtual.ler();
}

void Sistema::executarComando(void) 
{
  // Antes de tudo, verifica se o comando digitado existe
  if(comandoAtual.existe()) {
    // Se o comando existir, verifica qual foi e executa as operações.
  
    // == Comando para Sair do Sistema ==
    // Pode ser executado a qualquer momento.
    if(comandoAtual.getComando() == "quit") {
      cout << "Saindo..." << endl;
  
      // Avisa ao sistema para fechar após esse comando.
      precisaFechar = true;
    }
  
    // ==== COMANDOS USUÁRIO ====
    // == Comando para Criar Usuário ==
    // Só pode ser executado caso não esteja logado.
    if(comandoAtual.getComando() == "create-user") {
      // Verifica se não está logado
      if(!estaLogado) {
        // Verifica se forneceu os três argumentos necessários
        if(comandoAtual.getNumeroArgumentos() >= 3) {
          // Se fornecer continua com o cadastro
  
          // Pega o e-mail
          string email = comandoAtual.getArgumento(0);
  
          // Se não existir uma conta com esse e-mail
          if(usuarioPeloEmail(email) == nullptr) {
            // Pega a senha
            string senha = comandoAtual.getArgumento(1);
  
            // Vamos pegar o nome agora
            string nome;
            
            // Junta os argumentos para formar o nome completo
            for (int i = 2; i < comandoAtual.getNumeroArgumentos(); i++) {
              nome += comandoAtual.getArgumento(i);
    
              // Adiciona um espaço entre as partes do nome
              if (i < comandoAtual.getNumeroArgumentos() - 1) {
                nome += " ";
              }
            }
    
            std::cout << "Criando usuário " << nome << " (" << email << ")" << std::endl;
  
            // Calcula o ID do novo usuário
            int novoId = novoIdUsuario();
            
            // Cria o objeto do tipo usuário
            Usuario *u = new Usuario(novoId, email, senha, nome);
      
            // Coloca ele na lista de usuários do sistema.
            usuarios.push_back(u);
      
            // Manda mensagem dizendo que o cadastro foi feito.
            std::cout << "Usuário criado" << std::endl;
          } else {
            // Se já existir um usuário com esse e-mail.
            std::cout << "Já existe um usuário com esse e-mail!" << std::endl;
          }
        } else {
          // Se faltou argumentos.
          std::cout << "Use: create-user <email> <senha_sem_espaços> <nome com espaços>" << std::endl;
        }
      } else {
        // Se o usuário usuário tentar usar o comando logado.
        std::cout << "Precisa desconectar para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Entrar no sistema
    // Só pode ser executado caso não esteja logado.
    if(comandoAtual.getComando() == "login") {
      // Verifica se não está logado
      if(!estaLogado) {
        // Verifica se forneceu os dois argumentos necessários
        if(comandoAtual.getNumeroArgumentos() == 2) {
          // Se fornecer continua com o login
          string email = comandoAtual.getArgumento(0); // Pega o e-mail.
          string senha = comandoAtual.getArgumento(1); // Pega a senha.
    
          bool usuarioExiste = false;
          int usuarioId;
          // Verifica se existe uma conta com esse e-mail e senha.
          for(int i = 0; i < usuarios.size(); i++) {
             if(email == usuarios.at(i)->getEmail() && senha == usuarios.at(i)->getSenha()) {
               usuarioExiste = true;
               usuarioId = usuarios.at(i)->getId();
               break;
             }
          }
          
          // Se a conta não for encontrada
          if(!usuarioExiste) {
            // Mostra mensagem de erro
            std::cout << "Senha ou usuário inválidos!" << std::endl;
          } else {
            // Seta o usuarioAtualId para o sistema o usuário atualmente logado
            usuarioAtualId = usuarioId;
    
            // Avisa ao sistema que está logado
            estaLogado = true;
    
            // Manda mensagem mostrando que logou com sucesso
            std::cout << "Logado como " << email << std::endl;
          }
        } else {
          // Se faltou ou sobrou argumentos
          std::cout << "Use: login <email> <senha_sem_espaços>" << std::endl;
        }
      } else {
        std::cout << "Precisa desconectar para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Desconectar usuário
    // Só pode ser executado caso esteja logado.
    if(comandoAtual.getComando() == "disconnect") {
      // Verifica se está logado
      if(estaLogado) {
        // Seta que não está mais logado no sistema.
        estaLogado = false;
  
        // Seta que não está mais visualizando nenhum servidor.
        servidorAtual = nullptr;

        // Seta que não está mais visualizando nenhum canal.
        canalAtual = nullptr;
  
        // Pega o usuário atualmente logado
        Usuario *tempUsuario = usuarioPeloId(usuarioAtualId);
        
        // Avisa ao usuário que foi desconectado
        std::cout << "Desconectando usuário " << tempUsuario->getEmail() << std::endl;
      } else {
        // Avisa ao usuário que já está desconectado
        std::cout << "Não está conectado" << std::endl;
      }
    }
  
    // ==== COMANDOS SERVIDOR ====
  
    // Comando para Criar Servidor
    // Só pode ser executado caso esteja logado.
    if(comandoAtual.getComando() == "create-server") {
      // Verifica se está logado
      if(estaLogado) {
        // Verifica se forneceu o argumento necessário
        if(comandoAtual.getNumeroArgumentos() == 1) {
          // Pega o argumento do usuário.
          string nome = comandoAtual.getArgumento(0);
  
          // Se não existir um servidor com esse nome
          if(servidorPeloNome(nome) == nullptr) {
            // Cria o objeto do tipo Servidor
            Servidor *s = new Servidor(usuarioAtualId, nome);

            // Adiciona o dono como participante
            s->addParticipante(usuarioAtualId);
    
            // Coloca ele na lista de servidores do sistema.
            servidores.push_back(s);
    
            // Retorna que o servidor foi criado.
            std::cout << "Servidor Criado" << std::endl;
          } else {
            // Avisa que já existe um servidor com esse nome.
            std::cout << "Servidor com esse nome já existe" << std::endl;
          }
        } else {
          // Se sobrou ou faltou argumentos, mostra a sintaxe correta.
          std::cout << "Use: create-server <nome-do-servidor>" << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Mudar a Descrição do Servidor
    // Só pode ser executado caso esteja logado e servidor for seu.
    if(comandoAtual.getComando() == "set-server-desc") {
      // Se estiver logado
      if(estaLogado) {
        // Se forneceu os argumentos corretamente
        if(comandoAtual.getNumeroArgumentos() > 0) {
          // Pega o nome do servidor
          string nome = comandoAtual.getArgumento(0);
  
          // Procura o ponteiro do servidor pelo nome
          Servidor *s = servidorPeloNome(nome);
  
          // Se o servidor existir
          if(s != nullptr) {
            // Se o usuário for o dono
            if(s->getDonoId() == usuarioAtualId) {
              // Pega a descrição dada pelo usuário
  
              // Vamos pegar a descrição agora
              string desc;
  
              // Vai funcionar se usou aspas ou não na descrição.
              
              // Junta os argumentos para formar a descrição completa
              for (int i = 1; i < comandoAtual.getNumeroArgumentos(); i++) {
                desc += comandoAtual.getArgumento(i);
      
                // Adiciona um espaço entre as partes da descrição
                if (i < comandoAtual.getNumeroArgumentos() - 1) {
                  desc += " ";
                }
              }
  
              // Se o usuário colocou a descrição entre aspas 
              // Tira a aspa do começo e final
  
              // Seta a descrição do servidor para a informada
              s->setDescricao(desc);
  
              std::cout << "Descrição do servidor '" << nome <<  "' modificada!" << std::endl;
            } else {
              std::cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << std::endl;
            }
          } else {
            std::cout << "Servidor '" << nome <<  "' não existe" << std::endl;
          }
          
        } else {
          // Se sobrou ou faltou argumentos, mostra a sintaxe correta.
          std::cout << "Use: set-server-desc <nome-do-servidor> <descrição>" << std::endl;
        }
      } else {
        // Se não estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Setar Código de Convite Para o Servidor
    // Precisa estar logado e ser dono do servidor para utilizar
    if(comandoAtual.getComando() == "set-server-invite-code") {
      // Verifica se está logado
      if(estaLogado) {
        // Verifica se informou pelo menos o nome
        if(comandoAtual.getNumeroArgumentos() > 0) {
          // Pega o nome do servidor
          string nome = comandoAtual.getArgumento(0);
  
          Servidor *s = servidorPeloNome(nome);
          
          // Verifica se existe um servidor com esse nome
          if(s != nullptr) {
            // Se o usuário logado é dono do servidor
            if(s->getDonoId() == usuarioAtualId) {
              // Pega o código do servidor
              if(comandoAtual.getNumeroArgumentos() == 2) {
                // Coloca o código de convite informado
                s->setCodigoConvite(comandoAtual.getArgumento(1));
  
                std::cout << "Código de convite do servidor '" << s->getNome() <<  "' modificado!" << std::endl;
              } else {
                s->setCodigoConvite("");
  
                std::cout << "Código de convite do servidor '" << s->getNome() <<  "' removido!" << std::endl;
              }
            } else {
              std::cout << "Somente o dono do servidor pode alterar o código de convite." << std::endl;
            }
          } else {
            std::cout << "Servidor '" << nome <<  "' não encontrado." << std::endl;
          }
        } else {
          // Se faltou ou sobrou argumentos
          std::cout << "Use: set-server-invite-code <nome-do-servidor> <codigo>" << std::endl;
        }
      } else {
        // Se estiver desconectado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para listar servidores do sistema
    // Precisa estar logado para executar.
    if(comandoAtual.getComando() == "list-servers") {
      if(estaLogado) {
        if(servidores.size() > 0) {
          // Para cada servidor do sistema
          for (Servidor *servidor : servidores) {
            // Exibe o nome do servidor
            std::cout << servidor->getNome() << std::endl;
          }
        } else {
          // Se não existirem servidores
          std::cout << "Nenhum servidor cadastrado." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para remover servidor do sistema
    // Precisa estar logado e ser dono do servidor.
    if(comandoAtual.getComando() == "remove-server") {
      // Verifica se está logado
      if(estaLogado) {
        // Se forneceu o nome do servidor
         if(comandoAtual.getNumeroArgumentos() == 1) {
           // Pega o nome do servidor informado
           string nome = comandoAtual.getArgumento(0);
  
           // Procura o ponteiro do servidor pelo nome
           Servidor *s = servidorPeloNome(nome);
  
           // Se o servidor existir
           if(s != nullptr) {
             // Verifica se o usuário logado é dono
             if(s->getDonoId() == usuarioAtualId) {
               // Remove o servidor do <vector> de servidores.
               
               // Encontrar o iterador para o elemento com base no valor
               auto it = std::find(servidores.begin(), servidores.end(), s);
                
               // Verificar se o elemento foi encontrado
               if (it != servidores.end()) {
                  // Apagar o elemento do vetor
                  delete *it;
                  servidores.erase(it);
               }
  
               // Se o usuário estiver visualizando o servidor removido
               if(servidorAtual == s) {
                  // Seta que não está mais visualizando nenhum servidor.
                 servidorAtual = nullptr;
               }
               
               std::cout << "Servidor '" << nome <<  "' removido." << std::endl;
             } else {
               // Se não for dono
               std::cout << "Somente o dono do servidor pode remover o servidor." << std::endl;
             }
           } else {
             std::cout << "Servidor '" << nome <<  "' não encontrado." << std::endl;
           }
           
         } else {
           // Se faltou ou sobrou argumentos
           std::cout << "Use: remove-server <nome-do-servidor>" << std::endl;
         }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Entrar em um Servidor 
    // Só pode ser usado se estiver logado
    if(comandoAtual.getComando() == "enter-server") {
      // Verifica se está logado
      if(estaLogado) {
        // Verifica se o usuário não está visualizando a nenhum servidor
        if(servidorAtual == nullptr) {
          // Verifica se forneceu o nome do servidor
          if(comandoAtual.getNumeroArgumentos() > 0) {
            // Pega o nome do servidor informado
            string nome = comandoAtual.getArgumento(0);
    
            // Procura o ponteiro do servidor
            Servidor *s = servidorPeloNome(nome);
    
            // Se o servidor existir
            if(s != nullptr) {
              // Verifica se não exige código de convite
              if(s->getCodigoConvite() == "") {
                // Caso não exigir
    
                // Se o usuário não for participante do servidor
                if(!s->participa(usuarioAtualId)) {
                  // Adiciona como participante
                  s->addParticipante(usuarioAtualId);
                }
    
                // Seta o servidorAtual que o usuário está visualizando.
                servidorAtual = s;
                
                std::cout << "Entrou no servidor com sucesso" << std::endl;
              } else {
                // Caso exigir código de convite
    
                // Se o usuário for o dono
                if(s->getDonoId() == usuarioAtualId) {
                  // Entra no servidor sem verificar nada
                  
                  // Se o usuário não for participante do servidor
                  if(!s->participa(usuarioAtualId)) {
                    // Adiciona como participante
                    s->addParticipante(usuarioAtualId);
                  }
    
                  // Seta o servidorAtual que o usuário está visualizando.
                  servidorAtual = s;
                    
                  std::cout << "Entrou no servidor com sucesso" << std::endl;
                } else {
                  // Se não for o dono
    
                  // Caso já seja participante não precisa informar o código de novo
                  if(s->participa(usuarioAtualId)) {
                      // Seta o servidorAtual que o usuário está visualizando.
                      servidorAtual = s;
    
                      std::cout << "Entrou no servidor com sucesso" << std::endl;
                  } else {
                    // Se não for participante 
                    
                    // Verifica se o usuário informou o código
                    if(comandoAtual.getNumeroArgumentos() == 2) {
                      // Pega o código
                      string codigo = comandoAtual.getArgumento(1);
        
                      // Caso o código esteja correto
                      if(s->getCodigoConvite() == codigo) {
                        // Se o usuário não for participante do servidor
                        if(!s->participa(usuarioAtualId)) {                      
                          // Adiciona como participante
                          s->addParticipante(usuarioAtualId);
                        }
    
                        // Seta o servidorAtual que o usuário está visualizando.
                        servidorAtual = s;
                        
                        std::cout << "Entrou no servidor com sucesso" << std::endl;
                      }
                    } else {
                      std::cout << "Esse servidor exige código de convite para entrar." << std::endl;
                    }
                  }
                }
              }
            } else {
              std::cout << "Servidor '" << nome <<  "' não encontrado." << std::endl;
            }
          } else {
            // Se faltou ou sobrou argumentos
            std::cout << "Use: enter-server <nome-do-servidor> <codigo-do-servidor>" << std::endl;
          }
        } else {
          // Se já estiver conectado a um servidor
          std::cout << "Você já está conectado a um servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Sair do Servidor, deconecta o usuário do servidor
    // Precisa estar logado e conectado a um servidor
    if(comandoAtual.getComando() == "leave-server") {
      // Verifica se está logado
      if(estaLogado) {
        // Se estiver visualizando um servidor
        if(servidorAtual != nullptr) {
          std::cout << "Saindo do servidor '" << servidorAtual->getNome() << "'" << std::endl;
          
          // Seta que não está mais visualizando nenhum servidor.
          servidorAtual = nullptr;

          // Seta que não está mais visualizando nenhum canal.
          canalAtual = nullptr;
        } else {
           std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Listar Participantes do Servidor
    // Preciso estar logado e conectado a um servidor
    if(comandoAtual.getComando() == "list-participants") {
      // Verifica se está logado
      if(estaLogado) {
        // Se estiver visualizando um servidor
        if(servidorAtual != nullptr) {
          // Para cada participante no servidorAtual
          for (int participanteId : servidorAtual->getParticipantes()) {
            // Exibe o nome do servidor
            std::cout << usuarioPeloId(participanteId)->getNome() << std::endl;
          }
        } else {
           std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }

    // ==== COMANDOS CANAIS ====

    // Comando para Listar Canais do servidor
    // Precisa estar logado e visualizando um servidor
    if(comandoAtual.getComando() == "list-channels") {
      // Verifica se está logado
      if(estaLogado) {
        // Se estiver visualizando um servidor
        if(servidorAtual != nullptr) {
          servidorAtual->listarCanais();
        } else {
          std::cout << "Entre em um servidor para listar seus canais." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }

    // Comando para Criar um Canal no servidor
    // Precisa estar logado pra usar
    if(comandoAtual.getComando() == "create-channel") {
      // Verifica se está logado
      if(estaLogado) {
        // Se estiver visualizando um servidor
        if(servidorAtual != nullptr) {
          if(servidorAtual->getDonoId() == usuarioAtualId) {
            // Verifica se forneceu os dois argumentos {nome, tipo}
            if(comandoAtual.getNumeroArgumentos() == 2) {
              // Pega o nome do canal
              std:string nome = comandoAtual.getArgumento(0);
  
              // Se não existir um canal com esse nome
              if(servidorAtual->canalPeloNome(nome) == nullptr) {
                // Pega o tipo do canal
                string tipo = comandoAtual.getArgumento(1);
  
                if(tipo == "texto") {
                  // Cria um objeto do tipo CanalTexto com esse nome
                  CanalTexto *c = new CanalTexto(nome);
                  
                  // Adiciona esse canal no servidor
                  servidorAtual->addCanal(c);
  
                  // Mostra mensagem que criou com sucesso
                  std::cout << "Canal de texto '" << nome << "' criado" << std::endl;
                } else if(tipo == "voz") {
                  // Cria um objeto do tipo CanalVoz com esse nome
                  CanalVoz *c = new CanalVoz(nome);
                  
                  // Adiciona esse canal no servidor
                  servidorAtual->addCanal(c);
  
                  // Mostra mensagem que criou com sucesso
                  std::cout << "Canal de voz '" << nome << "' criado" << std::endl;
                } else {
                  std::cout << "Esse tipo de canal não existe. Use: {Texto} ou {Voz}." << std::endl;
                }
              } else {
                std::cout << "O canal '" << nome << "' já existe!" << std::endl;
              }
            } else {
              std::cout << "Use: create-channel <nome_sem_espaços> <tipo>" << std::endl;
            }
          } else {
            std::cout << "Somente o dono do servidor pode criar canais." << std::endl;
          }
        } else {
          std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }    
    }

    // Função para Entrar em Canal do servidor
    // Precisa estar logado e visualizando um servidor
    if(comandoAtual.getComando() == "enter-channel") {
      // Verifica se está logado
      if(estaLogado) {
        // Verifica se está visualizando um servidor
        if(servidorAtual != nullptr) {
          // Se não estiver visualizando nenhum canal
          if(canalAtual == nullptr) {
            // Se o usuário forneceu o {nome} do canal
            if(comandoAtual.getNumeroArgumentos() == 1) {
              // Pega o nome do canal
              std::string nome = comandoAtual.getArgumento(0);
  
              // Procura o ponteiro do Canal no servidor atual
              Canal *c = servidorAtual->canalPeloNome(nome);
  
              // Se o canal existir
              if(c != nullptr) {
                // Seta o canalAtual que o usuário está visualizando
                canalAtual = c;
  
                std::cout << "Entrou no canal '" << nome << "'" << std::endl;
              } else {
                std::cout << "O canal '" << nome << "' não existe." << std::endl;
              }
            } else {
              std::cout << "Use: enter-channel <nome_do_servidor>" << std::endl;
            }
          } else {
            std::cout << "Você já está visualizando um canal." << std::endl;
          }
        } else {
          std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }

    // Comando para Sair Do Canal do servidor
    if(comandoAtual.getComando() == "leave-channel") {
      if(estaLogado) {
        if(servidorAtual != nullptr) {
          if(canalAtual != nullptr) {
            std::cout << "Saindo do canal '" << canalAtual->getNome() << "'" << std::endl;

            // Seta que não está mais visualizando nenhum canal.
            canalAtual = nullptr;
          } else {
            std::cout << "Não está em um canal." << std::endl;
          }
        } else {
          std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }

    // MENSAGENS EM CANAL
    
    // Comando para Enviar Mensagem no canal
    // Precisa estar em um servidor e dentro de um canal
    if(comandoAtual.getComando() == "send-message") {
      if(estaLogado) {
        if(servidorAtual != nullptr) {
          if(canalAtual != nullptr) {
            // Se de fato digitou a mensagem
            if(comandoAtual.getNumeroArgumentos() > 0) {
              // Vamos pegar a mensagem agora
              string mensagem;
              
              // Junta os argumentos para formar o nome completo
              for (int i = 0; i < comandoAtual.getNumeroArgumentos(); i++) {
                mensagem += comandoAtual.getArgumento(i);
      
                // Adiciona um espaço entre as partes do nome
                if (i < comandoAtual.getNumeroArgumentos() - 1) {
                  mensagem += " ";
                }
              }

              // Cria um objeto do tipo Mensagem com os dados do usuário atual
              Mensagem m = Mensagem(usuarioAtualId, getDataHoraAtual(), mensagem);

              // Envia a mensagem para o canalAtual
              canalAtual->enviarMensagem(m);
            } else {
              std::cout << "Use: send-message <mensagem>" << std::endl;
            }
          } else {
            std::cout << "Não está em um canal." << std::endl;
          }
        } else {
          std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }

    // Comando para Listar as Mensagens do Canal
    // Precisa estar em um servidor e dentro de um canal
    if(comandoAtual.getComando() == "list-messages") {
      if(estaLogado) {
        if(servidorAtual != nullptr) {
          if(canalAtual != nullptr) {
            canalAtual->listarMensagens(&usuarios); 
          } else {
            std::cout << "Não está em um canal." << std::endl;
          }
        } else {
          std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  } else {
    // Se o comando digitado não existir
    std::cout << "Comando inválido. Tente novamente." << std::endl;
  }
}

void Sistema::salvarUsuarios(void) 
{
  // Cria um objeto do tipo OFSTREAM, pois posso sobrescrever o arquivo.
  ofstream arquivo("usuarios.txt");

  // Se o arquivo usuarios.txt não existir
  if (!arquivo.is_open()) {
    // Cria um arquivo no caminho padrão
    arquivo.open("usuarios.txt", ios::app);

    // Se não der certo mesmo assim
    if (!arquivo.is_open()) {
      cout << "ERRO: Não foi possível salvar os usuários." << endl;
      return;
    }
  }

  // Primeira linha - Quantidade de Usuários
  arquivo << usuarios.size() << std::endl;

  // Para cada usuário do sistema
  for (Usuario *usuario : usuarios) {
    arquivo << usuario->getId() << std::endl;
    arquivo << usuario->getNome() << std::endl;
    arquivo << usuario->getEmail() << std::endl;
    arquivo << usuario->getSenha() << std::endl;
  }

  arquivo.close();
}

void Sistema::salvarServidores(void) 
{
  // Cria um objeto do tipo OFSTREAM, pois posso sobrescrever o arquivo.
  ofstream arquivo("servidores.txt");

  // Se o arquivo servidores.txt não existir
  if (!arquivo.is_open()) {
    // Cria um arquivo no caminho padrão
    arquivo.open("servidores.txt", ios::app);

    // Se não der certo mesmo assim
    if (!arquivo.is_open()) {
      cout << "ERRO: Não foi possível salvar os servidores." << endl;
      return;
    }
  }

  // Primeira linha - Quantidade de Servidores
  arquivo << servidores.size() << std::endl;

  // Para cada servidor do sistema
  for (Servidor *servidor : servidores) {
    arquivo << servidor->getDonoId() << std::endl;
    arquivo << servidor->getNome() << std::endl;
    arquivo << servidor->getDescricao() << std::endl;
    arquivo << servidor->getCodigoConvite() << std::endl;
    arquivo << servidor->getParticipantes().size() << std::endl;

    // Para cada participante do servidor
    for(int participante_id : servidor->getParticipantes()) {
      // Imprime seu ID
      arquivo << participante_id << std::endl;
    }

    // Informa a quantidade de canais do servidor
    arquivo << servidor->getCanais().size() << std::endl;

    // Para cada canal do servidor
    for(Canal *canal : servidor->getCanais()) {
      arquivo << canal->getNome() << std::endl;
      arquivo << canal->getTipo() << std::endl;
      arquivo << canal->getMensagens().size() << std::endl;

      // Para cada mensagem no canal
      for(Mensagem m : canal->getMensagens()) {
        arquivo << m.getIdEnviou() << std::endl;
        arquivo << m.getDataHora() << std::endl;
        arquivo << m.getConteudo() << std::endl;
      }
    }
  }

  arquivo.close();
}

void Sistema::salvar(void) {
  salvarUsuarios();
  salvarServidores();
}

void Sistema::carregarUsuarios(void) 
{
  // Apaga os dados antigos do sistema antes da leitura
  
  // Desaloca qualquer memória dinâmica dos <vector's>
  for (Usuario *usuario : usuarios) {
    delete usuario;
  }

  // Apaga os elementos dos <vector's>
  usuarios.clear();

  // Cria um objeto do tipo IFSTREAM, pois vou ler o arquivo.
  ifstream arquivo("usuarios.txt");
 
  string linha; // Linha atual que está sendo lida.
  int numeroUsuarios = 0; // Número de usuários no arquivo
  
  // Se conseguir abrir o arquivo
  if(arquivo.is_open()) {
    getline(arquivo, linha); // Lê a primeira linha - Número de Usuários
    numeroUsuarios = stoi(linha); // Converte para inteiro e salva.

    // VARIÁVEIS TEMPORÁRIAS PARA LEITURA
    int id = 0;
    string nome;
    string email;
    string senha;

    // Para cada usuário cadastrado no arquivo
    for (int i = 0; i < numeroUsuarios; i++) {
      // ID do usuário  
      getline(arquivo, linha);
      id = stoi(linha);

      // Nome do usuário 
      getline(arquivo, linha);
      nome = linha;

      // E-mail do usuário 
      getline(arquivo, linha);
      email = linha;

      // Senha do usuário 
      getline(arquivo, linha);
      senha = linha;
    
      // Cria o objeto do tipo usuário
      Usuario* u = new Usuario(id, email, senha, nome);
    
      // Coloca ele na lista de usuários do sistema.
      usuarios.push_back(u);
    }
    
    arquivo.close();
  }
}

void Sistema::carregarServidores(void) 
{
  // Precisa guardar o nome do servidor e do canal atual.
  // para procurar o novo ponteiro deles no final.
  string servidorAtualNome;
  string canalAtualNome;

  // Se estiver visualizando um Servidor
  if(servidorAtual != nullptr) {
    // Armazena o nome do servidor para procurar o ponteiro depois.
    servidorAtualNome = servidorAtual->getNome();
  }
  
  // Se estiver visualizando um Canal
  if(canalAtual != nullptr) {
    // Armazena o nome do canal para procurar o ponteiro depois.
    canalAtualNome = canalAtual->getNome();
  }

  // Apaga os dados antigos do sistema antes da leitura

  // Desaloca qualquer memória dinâmica dos <vector's>
  for (Servidor *servidor : servidores) {
    delete servidor;
  }

  // Apaga os elementos dos <vector's>
  servidores.clear();
  
  // Cria um objeto do tipo IFSTREAM, pois vou ler o arquivo.
  ifstream arquivo("servidores.txt");

  string linha; // Linha atual que está sendo lida.
  int numeroServidores = 0; // Número de servidores no arquivo

  // Se conseguir abrir o arquivo
  if(arquivo.is_open()) {
    getline(arquivo, linha); // Lê a primeira linha - Número de Servidores
    numeroServidores = stoi(linha); // Converte para inteiro e salva.

    // VARIÁVEIS TEMPORÁRIAS PARA LEITURA
    int usuarioDonoId = 0;
    int numeroParticipantes = 0;
    int numeroMensagens = 0;
    int numeroCanais = 0;
    string nomeServidor;
    string nomeCanal;
    string tipoCanal;
    
    
    // Para cada servidor cadastrado no arquivo
    for (int i = 0; i < numeroServidores; i++) {
      // ID do dono do servidor
      getline(arquivo, linha);
      usuarioDonoId = stoi(linha); // Converte para inteiro e salva.

      // Nome do servidor
      getline(arquivo, linha);
      nomeServidor = linha;

      // Cria o objeto do tipo Servidor
      Servidor *s = new Servidor(usuarioDonoId, nomeServidor);

      // Descrição do servidor
      getline(arquivo, linha);
      s->setDescricao(linha);

      // Código de convite
      getline(arquivo, linha);
      s->setCodigoConvite(linha);

      // Número de participantes
      getline(arquivo, linha);
      numeroParticipantes = stoi(linha); // Converte para inteiro e salva.

      // Cadastra os IDs dos participantes
      for (int i = 0; i < numeroParticipantes; i++) {
        getline(arquivo, linha);
        s->addParticipante(stoi(linha));
      }

      // Número de canais
      getline(arquivo, linha);
      numeroCanais = stoi(linha); // Converte para inteiro e salva.

      // Para cada canal presente no arquivo.
      for (int i = 0; i < numeroCanais; i++) {
        // Nome do canal
        getline(arquivo, linha);
        nomeCanal = linha;

        // Tipo do canal
        getline(arquivo, linha);
        tipoCanal = linha;

        if(tipoCanal == "TEXTO") {
          // Cria um objeto do tipo CanalTexto com esse nome
          CanalTexto *c = new CanalTexto(nomeCanal);

          // Número de mensagens
          getline(arquivo, linha);
          numeroMensagens = stoi(linha); // Converte para inteiro e salva.

          // Para cada mensagem cadastrada no arquivo.
          for (int i = 0; i < numeroMensagens; i++) {
            // Cria objeto do tipo mensagem
            Mensagem m;

            // ID de quem enviou
            getline(arquivo, linha);
            m.setIdEnviou(stoi(linha));

            // Data e Hora que foi enviada
            getline(arquivo, linha);
            m.setDataHora(linha);

            // Conteúdo da mensagem
            getline(arquivo, linha);
            m.setConteudo(linha);

            c->enviarMensagem(m);
          }

          // Adiciona esse canal no servidor
          s->addCanal(c);
        } else if(tipoCanal == "VOZ") {
          // Cria um objeto do tipo CanalVoz com esse nome
          CanalVoz *c = new CanalVoz(nomeCanal);

          // Número de mensagens
          getline(arquivo, linha);
          numeroMensagens = stoi(linha); // Converte para inteiro e salva.

          if(numeroMensagens != 0) {
            // Cria objeto do tipo mensagem
            Mensagem m;

            // ID de quem enviou
            getline(arquivo, linha);
            m.setIdEnviou(stoi(linha));

            // Data e Hora que foi enviada
            getline(arquivo, linha);
            m.setDataHora(linha);

            // Conteúdo da mensagem
            getline(arquivo, linha);
            m.setConteudo(linha);

            c->enviarMensagem(m);
          }
          
          // Adiciona esse canal no servidor
          s->addCanal(c);
        }
      }

      // Coloca o servidor na lista de servidores do sistema.
      servidores.push_back(s);
    }

    if(servidorAtual != nullptr) {
      servidorAtual = servidorPeloNome(servidorAtualNome);
    }
    if(canalAtual != nullptr) {
      canalAtual = servidorAtual->canalPeloNome(canalAtualNome);
    }

    arquivo.close();
  }
}

void Sistema::carregar(void) {
  carregarUsuarios();
  carregarServidores();
}