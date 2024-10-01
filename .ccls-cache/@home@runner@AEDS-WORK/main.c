#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mensagemdesaida() {
  printf("\n");
  printf("===========================================\n");
  printf("|                                         |\n");
  printf("|     Obrigado por utilizar nossos        |\n");
  printf("|          serviços. Até logo!            |\n");
  printf("|                                         |\n");
  printf("===========================================\n");
}

void cadastrar_cliente() {

  
// printf("\n\nO cliente fulano foi cadastrado com sucesso!\n\n\n");
}

void cadastrar_funcionario() {}

void cadastrar_estadia() {}

void cadastrar_quarto() {}

void dar_baixa_estadia() {}

void pesquisar_cliente() {}

void pesquisar_funcionario() {}

void mostrar_estadias_cliente() {}

// Struct responsável pelas informações do cliente
struct dadosdocliente {
  int codigocliente;
  char nomecliente[100];
  char enderecocliente[100];
  int telefonecliente;
  char nacionalidade[50];
  char cidadecliente[20];
  char estadocliente[20];
  char bairrocliente[50];
  char rua[25];
  char cpf[15];
};

// Struct responsável pelas informações do funcionário
struct dadosdofuncionario {
  int codigofuncionario;
  int telefonefuncionario;
  char nomefuncionario[100];
  char cargofuncionario[100];
  float salariofuncionario;
};

// Struct para informações de estadia
struct dadosdeestadia {
  int codigoestadia;
  char dataentrada[11];
  char datasaida[11];
  int quantidadediarias;
  int codigocliente;
  int numeroquarto;
};

// Struct para informações do quarto
struct quarto {
  int numeroquarto;
  int quantidadehospedes;
  float valordiaria;
  char status[20]; // Ex: "Disponível", "Ocupado", etc.
};

int main(void) {

  
  // -----------------------------------//
  int opcaomenu;

  // ------------------------------------- //

  
  // aqui abaixo começa o MENU //
  
  do {
    printf("===========================================\n");
    printf("|                                         |\n");
    printf("|      HOTEL DESCANSO GARANTIDO           |\n");
    printf("|                                         |\n");
    printf("===========================================\n");
    printf("|                                         |\n");
    printf("|  1. Cadastrar um Cliente                |\n");
    printf("|  2. Cadastrar um Funcionario            |\n");
    printf("|  3. Cadastrar Quarto                    |\n");
    printf("|  4. Cadastrar Estadia                   |\n");
    printf("|  5. Dar Baixa Estadia                   |\n");
    printf("|  6. Pesquisar Cliente                   |\n");
    printf("|  7. Pesquisar Funcionário               |\n");
    printf("|  8. Mostrar Estadias de um Cliente      |\n");
    printf("|  9. Sair                                |\n");
    printf("===========================================\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcaomenu);

    // validação para valores do menu inválidos
    if (opcaomenu <= 0 || opcaomenu >= 10) {
      printf("OPÇÃO INVÁLIDA\nINFORME UMA OPÇÃO VÁLIDA ENTRE 1 e 9\n\n");
    }
    // Garantindo que o menu só será executado com valores válidos entre 1 e 9
    if (opcaomenu > 0 && opcaomenu < 10) {
      switch (opcaomenu) {
      case 1:
        printf("Você escolheu cadastrar um cliente\n");
        cadastrar_cliente();
        break;

      case 2:
        printf("Você escolheu cadastrar um funcionário\n");
        cadastrar_funcionario();
        break;

      case 3:
        printf("Você escolheu cadastrar quarto\n");
        cadastrar_quarto();
        break;

      case 4:
        printf("Você escolheu cadastrar estadia\n");
        cadastrar_estadia();
        break;

      case 5:
        printf("Você escolheu dar baixa na estadia\n");
        dar_baixa_estadia();
        break;

      case 6:
        printf("Você escolheu pesquisar cliente\n");
        pesquisar_cliente();
        break;

      case 7:
        printf("Você escolheu pesquisar funcionário\n");
        pesquisar_funcionario();
        break;

      case 8:
        printf("Você escolheu mostrar estadias de um cliente\n");
        mostrar_estadias_cliente();
        break;

      default:
        mensagemdesaida();
        break;
      }
    }
  } while (opcaomenu != 9);
  

  return 0;
}
