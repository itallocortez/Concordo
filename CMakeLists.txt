# Versão mínima do CMake
cmake_minimum_required(VERSION 3.5)

# Informações básicas do projeto.
project(Concordo
        VERSION 1.0
        DESCRIPTION "Um sistema similar ao Discord, porém em modo de texto e sem recursos de rede."
        HOMEPAGE_URL "https://github.com/itallocortez/Concordo"
        LANGUAGES CXX)

# Incluir informações para depuração no executável
set(CMAKE_CXX_FLAGS "-g")

# Informa o diretório dos arquivos de cabeçalho
include_directories( include )

# Cria um executável a partir dos códigos fonte
add_executable( concordo
                src/main.cpp
                src/usuario.cpp
                src/mensagem.cpp
                src/canal.cpp
                src/canaltexto.cpp
                src/canalvoz.cpp
                src/servidor.cpp
                src/sistema.cpp
                src/comando.cpp )