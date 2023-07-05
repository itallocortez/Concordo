# Concordo
 Clone do Discord, para humanos mais civilizados.

## O que é?
 O Concordo é um sistema que se assemelha ao Discord em termos de funcionalidade, porém, diferentemente do Discord, ele opera exclusivamente em 
 formato de texto, sem suporte a recursos de rede.

## Motivação
 Esse projeto foi desenvolvido como parte da disciplina de Linguagem de Programação do curso de Tecnologia da Informação da Universidade Federal do Rio Grande do
 Norte (UFRN).

## Documentação
 A documentação do projeto foi feita usando o Doxygen. Você pode acessá-la na [página](https://itallocortez.github.io/Concordo) de documentação.

## Instalação

### Requisitos
- Compilador C++
- CMake
- Git (opcional)
- Doxygen (opcional)

### Compilação
Para começar, clone o projeto usando o seguinte comando:
``` 
git clone https://github.com/itallocortez/Concordo.git
```

Então, abra o diretório do projeto:
```
cd ./Concordo
```

Agora crie uma pasta onde o programa será compilado e entre nela:
```
mkdir build && cd ./build
```

Como o projeto usa CMake, basta usar esse comando para gerar um Makefile na pasta:
```
cmake ../CMakeLists.txt -B ./
```

Por fim, compile o programa usando o Makefile:
```
make
```

## Execução
Após compilar o programa, basta usar o seguinte comando para executá-lo:
```
./concordo
```

## Comandos
O programa é operado através de comandos executados no terminal.

![Mostrando os comandos do programa](./assets/usando_comandos.gif)

Esses comandos podem ser usados juntos com argumentos para realizar diversas ações. 
Por exemplo, o comando `login <e-mail> <senha>` é utilizado para fazer o login no sistema, substituindo `<e-mail>` pelo seu endereço de e-mail e `<senha>` pela sua senha.
O que resulta no comando `login itallocortez@gmail.com 12345`

### Lista de Comandos
A seguir, estão listados todos os comandos disponíveis para interagir com o sistema:

- ### `quit`
  Fecha o programa.
  - Pode ser utilizado a qualquer momento.
  
- ### `create-user <email> <senha> <nome>`
  Cadastra um novo usuário no sistema. É necessário informar o e-mail, a senha e o nome do usuário.
  - A senha não pode conter espaços.
  - O nome do usuário pode conter espaços.

  Exemplo de uso:
  ```
  create-user itallocortez@gmail.com 12345 Itallo Cortez
  ```
  
- ### `login <e-mail> <senha>`
  Efetua o login de um usuário cadastrado. É necessário informar o e-mail e a senha do usuário.

  Exemplo de uso:
  ```
  login itallocortez@gmail.com 12345
  ```
  
- ### `disconnect`
  Desconecta da conta atual.
  - Precisa estar logado.

- ### `create-server <nome>`
  Cria um servidor com o nome informado.
  - Precisa estar logado para utilizar.
  - O usuário atual será o dono do servidor.
  - O nome do servidor não pode conter espaços.

  Exemplo de uso:
  ```
  create-server jogos
  ```
  
- ### `set-server-desc <nome> "<descrição>"`
  Altera a descrição de um servidor especifico. É necessário informar o nome do servidor e a nova descrição.
  - Precisa estar logado para utilizar.
  - Somente o dono do servidor pode alterar sua descrição.
  - A descrição pode estar entre aspas se quiser.

  Exemplo de uso:
  ```
  set-server-desc jogos "Servidor de Jogos"
  ```
  
- ### `set-server-invite-code <nome> <código>`
  Altera o código de convite um servidor especifico. É necessário informar o nome do servidor e a novo código.
  - Precisa estar logado para utilizar.
  - Somente o dono do servidor pode alterar seu código.
  - Pode ser usado sem o argumento <código> para remover o código.

  Exemplo de uso:
  ```
  set-server-invite-code jogos 4567
  set-server-invite-code jogos
  ```
  
- ### `list-servers`
  Imprime o nome de todos os servidores cadastrados no sistema.
  - Precisa estar logado para utilizar.

- ### `remove-server <nome>`
  Remove um servidor especifico do sistema. É necessário informar o nome do servidor.
  - Precisa estar logado para utilizar.
  - Somente o dono do servidor pode removê-lo.

  Exemplo de uso:
  ```
  remove-server jogos
  ```
  
- ### `enter-server <nome> <código>`
  Entra em um servidor. É necessário informar o nome do servidor.
  - Precisa estar logado para utilizar.
  - Caso o servidor exija um código de convite, será necessário informá-lo.
  - O dono do servidor nunca precisa informar o código de convite.
  - Se o usuário já entrou no servidor antes, o código de convite não é necessário.

  Exemplo de uso:
  ```
  enter-server jogos
  enter-server jogos 4567
  ```
  
- ### `leave-server`
  Sai do servidor atual.
  - Precisa estar logado para utilizar.
  - Precisa estar dentro de um servidor.

- ### `list-participants`
  Lista o nome dos participantes do servidor atual.
  - Precisa estar logado para utilizar.
  - Precisa estar dentro de um servidor.
 
- ### `create-channel <nome> <tipo>`
  Cria um canal no servidor atual.
  - Precisa estar dentro de um servidor.
  - Somente o dono do servidor pode criar canais.
  - Existem dois tipos de canais: `TEXTO` e `VOZ`.

  Exemplo de uso:
  ```
  create-channel chat-1 texto
  create-channel callzinha-1 voz
  ```

- ### `enter-channel <nome>`
  Entra em um canal do servidor.
  - Precisa estar dentro de um servidor.

  Exemplo de uso:
  ```
  enter-channel chat-1
  enter-channel callzinha-1
  ```

- ### `leave-channel`
  Sai do canal atual.
  - Precisa estar dentro de um canal.
 
- ### `list-channels`
  Lista o nome dos canais do servidor atual.
  - Precisa estar dentro de um servidor.
 
- ### `send-message <mensagem>`
  Envia uma mensagem no canal atual.
  - Precisa estar dentro de um canal.

  Exemplo de uso:
  ```
  send-message Ei, gent
  send-message Um apartamento em nova parnamirim é barato?
  send-message to pensando em me mudar pra lá
  ```

- ### `list-messages`
  Visualiza as mensagens do canal atual.
  - Precisa estar dentro de um canal.
 
  Exemplo de Saída:
  ```
  Itallo Cortez <05/07/2023 - 01:18:26>: Ei, gent
  Itallo Cortez <05/07/2023 - 01:18:26>: Um apartamento em nova parnamirim é barato?
  Itallo Cortez <05/07/2023 - 01:18:26>: to pensando em me mudar pra lá
  Francisco Gabriel <05/07/2023 - 01:18:26>: Cara
  Francisco Gabriel <05/07/2023 - 01:18:26>: Conheco uns condominios baratinhos por lá
  ```
  
## Limitações
### Precisa melhorar
 - Tenho certeza que existe uma forma melhor de armazenar os comandos sem ter que usar uma sequencia de ifs.
 - Pode existir uma forma melhor para verificar se o comando existe ou não.

## Autor
- Itallo Muriel Moreira Cortez