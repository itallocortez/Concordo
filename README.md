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
- CMake (3.24.3 ou superior)
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

## Interface do Usuário
(Em construção)

## Limitações
### Precisa melhorar
 - Tenho certeza que existe uma forma melhor de armazenar os comandos sem ter que usar uma sequencia de ifs.
 - Pode existir uma forma melhor para verificar se o comando existe ou não.

## Autor
- Itallo Muriel Moreira Cortez