# Concordo
 Clone do Discord, para humanos mais civilizados.

## O que é?
 O Concordo é um sistema que se assemelha ao Discord em termos de funcionalidade, porém, diferentemente do Discord, ele opera exclusivamente em 
 formato de texto, sem suporte a recursos de rede.

## Motivação
 Esse projeto foi desenvolvido como parte da disciplina de Linguagem de Programação do curso de Tecnologia da Informação da Universidade Federal do Rio Grande do
 Norte (UFRN).

## Documentação
 A documentação do projeto foi feita usando o Doxygen. Você pode acessá-la na [página](https://itallocortez.github.io/Concordo) da documentação.

## Instalação

### Requisitos
- Compilador C++
- CMake (3.24.3 ou superior)
- Git (opcional)
- Doxygen (opcional)

### Compilação
Para começar, clone o projeto usando os seguintes comandos:
``` 
git clone https://github.com/itallocortez/Concordo.git
cd ./concordo
```

Agora crie uma pasta onde o programa será compilado e entre nela:
```
mkdir build
cd build
```

O projeto foi feito usando CMake, basta usar o comando para montar um Makefile:
```
cmake ../CMakeLists.txt
```

Por fim, monte o Makefile usando make:
```
make
```

## Uso
Após compilar o programa, basta usar o seguinte comando:
```
./concordo
```