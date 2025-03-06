# cub3D

**cub3D** é um projeto desenvolvido em C que carrega e interpreta arquivos de mapa no formato `.cub`. Este é um passo fundamental para a construção de um jogo inspirado no clássico Wolfenstein 3D.

## 📜 Estado do Projeto

Atualmente, o projeto conta com um **parser funcional** para arquivos `.cub`, permitindo carregar mapas dinamicamente e definir suas dimensões automaticamente.

## 🚀 Como instalar e executar

1. Clone o repositório:
   ```sh
   git clone https://github.com/eliandrosergio/cub3D
   ```

2. Acesse o diretório do projeto:
   ```sh
   cd cub3D/cub3D
   ```

3. Compile o projeto:
   ```sh
   make
   ```

4. Execute com um mapa:
   ```sh
   ./cub3D map.cub
   ```

## 🛠️ Dependências

- Compilador C (gcc/clang)
- Make
- Biblioteca MiniLibX (arquivo minilibx-linux.tgz)

## 📂 Estrutura do Projeto

cub3D/
│── assets/              # Texturas e sprites (futuro)
│── inc/                 # Arquivo de cabeçalho
│── libft/               # Código-fonte do libft
│── maps/                # Exemplos de mapas .cub
│── src/                 # Código-fonte do cub3D
│── Makefile             # Script de compilação
│── minilibx-linux.tgz   # Código-fonte da lib MiniLibX

## 👾 Controles (Futuro)

- WASD → Movimentação
- ← → → Rotação da visão
- ESC → Sair do jogo

## 📌 Sobre o Projeto

Este projeto faz parte do currículo da Escola 42, explorando conceitos de parsing e manipulação de arquivos como base para um futuro motor gráfico baseado em Raycasting.

Feito com ❤️ por eliandrosergio
### 🚀 Feito com ❤️ por **EliandroSergio** 🎮
Feito com <kbd>❤️</kbd> por <kbd>EliandroSergio</kbd>
