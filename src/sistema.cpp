#include "sistema.hpp"

using namespace std;

Usuario* Sistema::usuarioPeloId(int id) {
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

Usuario* Sistema::usuarioPeloEmail(string email) {
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

int Sistema::novoIdUsuario(void) {
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

Servidor* Sistema::servidorPeloNome(string nome) {
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

Sistema::Sistema() {
  
}

bool Sistema::fechar(void) {
  return precisaFechar;
}

void Sistema::lerComando(void) {
  comandoAtual.ler();
}

void Sistema::executarComando(void) {
  // Antes de tudo, verifica se o comando digitado existe
  if(comandoAtual.existe()) {
    // Se o comando existir, verifica qual foi e executa as operações.
  
    // == Comando para Sair do Sistema ==
    // Pode ser executado a qualquer momento.
    if(comandoAtual.getComando() == "quit") {
      // Mensagem para o usuário
      cout << "Saindo..." << endl;
  
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
      if(estaLogado) {
        // Se estiver visualizando um servidor
        if(servidorAtual != nullptr) {
          std::cout << "Saindo do servidor '" << servidorAtual->getNome() << "'" << std::endl;
          
          // Seta que não está mais visualizando nenhum servidor.
          servidorAtual = nullptr;
        } else {
           std::cout << "Você não está visualizando nenhum servidor." << std::endl;
        }
      } else {
        // Se estiver deslogado
        std::cout << "Precisa estar logado para usar esse comando!" << std::endl;
      }
    }
  
    // Comando para Listar Pessoas em Um Servidor
    // Preciso estar logado e conectado a um servidor
    if(comandoAtual.getComando() == "list-participants") {
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
  } else {
    // Se o comando digitado não existir
    std::cout << "Comando inválido. Tente novamente." << std::endl;
  }
}