# cub3D

**cub3D** é um projeto desenvolvido em C que carrega e interpreta arquivos de mapa no formato `.cub`. Este é um passo fundamental para a construção de um jogo inspirado no clássico Wolfenstein 3D.

## 🚀 Como instalar e executar

1. Clone o repositório:
   ```sh
   git clone https://github.com/eliandrosergio/cub3D
   ```

2. Acesse o diretório do projeto:
   ```sh
   cd cub3D/cub3D
   ```
   ou
   ```sh
   cd cub3D/personal_cub3D
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
- **assets/**: Texturas e sprites
- **inc/**: Arquivo de cabeçalho
- **libft/**: Código-fonte do libft
- **maps/**: Exemplos de mapas .cub
- **src/**: Código-fonte do cub3D
- **Makefile**: Script de compilação
- **minilibx-linux.tgz**: Código-fonte da lib MiniLibX

## 👾 Controles

- WASD : Movimentação
- ← →  : Rotação da visão
- ESC  : Sair do jogo

## 📌 Sobre o Projeto (For 42)

Este projeto faz parte do currículo da Escola 42, explorando conceitos de parsing e manipulação de arquivos como base para um futuro motor gráfico baseado em Raycasting.

## 💙 Sobre o Projeto (Personal)

Uma versão **modificada**, feita para fins de **entretenimento e lazer**, usando texturas no **chão** e no **teto** (em vez de cores), **sprites** adicionais e alguns deles **sólidos** e outros não, movimentação da câmera pelo **mouse** e outras futuras melhorias.

## 📜 Licenças e Agradecimentos

### Texturas de McGravel (Agradecimento)

- Estas texturas foram criadas por **McGravel** e estão licenciadas sob a Creative Commons Attribution-ShareAlike 4.0 International.
Para ver uma cópia da licença, acesse: [Creative Commons BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/).

### Sprites e Texturas de Wolfenstein 3D

- Os sprites e texturas originais de Wolfenstein 3D são propriedade da **id Software**. Seu uso neste projeto é apenas para fins educacionais e sem fins lucrativos.

### Referência para estudo de Raycasting

- Este projeto se baseia nos ensinamentos do artigo de **Lode Vandevenne** (2004-2020), que fornece uma excelente explicação sobre Raycasting. Para mais informações, acesse: [Lode’s Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html).


### 🚀 Desenvolvido com paixão ❤️ por [**eliandrosergio**](https://github.com/eliandrosergio/) 🎮
