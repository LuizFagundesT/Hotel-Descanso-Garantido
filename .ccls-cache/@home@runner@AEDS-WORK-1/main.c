#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <strings.h> 



// STRUCKT CLIENTES
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
// Struct FUNCIONARIO
struct dadosdofuncionario {

  int codigofuncionario;
  char telefonefuncionario[15];
  char nomefuncionario[100];
  char cargofuncionario[100];
  float salariofuncionario;
};
// Struct ESTADIA
struct dadosdeestadia {

  int codigoestadia;
  char dataentrada[11];
  char datasaida[11];
  int quantidadediarias;
  int codigocliente;
  int numeroquarto;
};
// Struct QUARTO
struct quarto {

  int numeroquarto;
  int quantidadehospedes;
  float valordiaria;
  char status[20]; //OCUPADO OU DESOCUPADO
};







// ASSINATURA DAS FUNÇÕES

void mensagemdesaida(); // ok
void cadastrar_cliente(struct dadosdocliente clientehotel);// ok
void cadastrar_funcionario(struct dadosdofuncionario funcionariohotel); // ok
int verificarcodigocliente(int codigocliente); // ok 
int verificarcodigofuncionario(int codigofuncionario); // ok
void pesquisar_cliente(struct dadosdocliente pesquisacliente); // ok
void pesquisar_funcionario(struct dadosdofuncionario pesquisafuncionario);


// FUNÇÕES FALTANTES

void cadastrar_estadia() {}
void cadastrar_quarto() {}
void dar_baixa_estadia() {}
void mostrar_estadias_cliente() {}




//COMEÇO DA MAIN
int main(void) {

  //INICIO DAS VARIAVEIS
  int opcaomenu;
  struct dadosdocliente cliente;
  struct dadosdofuncionario funcionario;

  //MENU DE FUNÇÕES
  do {
    
    
    printf("BEM VINDO AO HOTEL DESCANSO GARANTIDO\n");
    
    printf("[1] Cadastrar um Cliente\n");
    printf("[2] Cadastrar um Funcionario\n");
    printf("[3] Cadastrar Quarto\n");
    printf("[4]Cadastrar Estadia\n");
    printf("[5] Dar Baixa Estadia\n");
    printf("[6] Pesquisar Cliente\n");
    printf("[7] Pesquisar Funcionário\n");
    printf("[8] Mostrar Estadias de um Cliente\n");
    printf("[9] Sair\n\n");
    ;
    printf("\nEscolha uma opção: ");
    scanf("%d", &opcaomenu);

    // SELETOR DE OPÇÕES INVALIDAS
    if (opcaomenu <= 0 || opcaomenu >= 10) {
      printf("OPÇÃO INVÁLIDA\nINFORME UMA OPÇÃO VÁLIDA ENTRE 1 e 9\n\n");
    }
    // Garantindo que o menu só será executado com valores válidos entre 1 e 9
    if (opcaomenu > 0 && opcaomenu < 10) {
      switch (opcaomenu) {
      case 1:
        printf("CADASTRO DE CLIENTE\n");
        cadastrar_cliente(cliente);
        break;

      case 2:
        printf("CADASTRO DE FUNCIONARIO\n");
        cadastrar_funcionario(funcionario);
        break;

      case 3:
        printf("CASATRO DE QUARTO\n");
        cadastrar_quarto();
        break;

      case 4:
        printf("CADASTRAR ESTADIA\n");
        cadastrar_estadia();
        break;

      case 5:
        printf("DAR BAIXA NA ESTADIA\n");
        dar_baixa_estadia();
        break;

      case 6:
        printf("PESQUISAR CLIENTE");
        pesquisar_cliente(cliente);
        break;

      case 7:
        printf("PESQUIS FUNCIONARIO \n");
        pesquisar_funcionario(funcionario);
        break;

      case 8:
        printf("MOSTRA ESTADIA DO CLIENTE\n");
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
// -------- FIM MAIN ----------- //






// -------- aqui abaixo começa as funcoes --------- //
void mensagemdesaida() {
  printf("\n\nOBRIGADO POR UTILIZAR NOSSOS SERVIÇOS\n\n");

}





int verificarcodigofuncionario(int codigofuncionario) {
  FILE *arquivo = fopen("listafuncionarios.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  char linha[256];

  while (fgets(linha, sizeof(linha), arquivo)) {
    // Extrai o código da linha
    int codigo_existente;
    if (sscanf(linha, "Código: %d", &codigo_existente) == 1) {
      if (codigo_existente == codigofuncionario) {
        fclose(arquivo);
        return 1; // Código encontrado
      }
    }
  }

  fclose(arquivo);
  return 0; // Código não encontrado
}





int verificarcodigocliente(int codigocliente) {

  FILE *arquivo = fopen("listaclientes.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
  }

  char linha[256];

  while (fgets(linha, sizeof(linha), arquivo)) {
    // Extrai o código da linha
    int codigo_existente;
    if (sscanf(linha, "Código: %d", &codigo_existente) == 1) {
      if (codigo_existente == codigocliente) {
        fclose(arquivo);
        return 1; // Código encontrado
      }
    }
  }

  fclose(arquivo);
  return 0; // Código não encontrado
}





void cadastrar_cliente(struct dadosdocliente clientehotel) {
  int codigo;

  printf("Insira o código do cliente (os 6 primeiros dígitos do CPF): ");
  do {
    scanf("%d", &clientehotel.codigocliente);
    codigo = verificarcodigocliente(clientehotel.codigocliente);

    if (codigo == 1) {
      printf("ESTE CODIGO JA EXISTE. INSIRA UM NOVO CODIGO ""CPF:");
    }
  } while (codigo == 1);

  printf("Nome do cliente: ");
  scanf(" %[^\n]s", clientehotel.nomecliente);

  printf("Endereço do cliente: ");
  scanf(" %[^\n]s", clientehotel.enderecocliente);

  printf("Telefone do cliente: ");
  scanf("%d", &clientehotel.telefonecliente);

  printf("Pais:");
  scanf(" %[^\n]s", clientehotel.nacionalidade);

  printf("Insira a cidade do cliente: ");
  scanf(" %[^\n]s", clientehotel.cidadecliente);

  printf("Insira o estado do cliente: ");
  scanf(" %[^\n]s", clientehotel.estadocliente);

  printf("Insira o bairro do cliente: ");
  scanf(" %[^\n]s", clientehotel.bairrocliente);

  printf("Insira a rua do cliente: ");
  scanf(" %[^\n]s", clientehotel.rua);

  printf("Insira o CPF do cliente: ");
  scanf(" %[^\n]s", clientehotel.cpf);

  // Abre o arquivo no modo 'a' para continuar a escrita sem apagar dados
  // existentes
  FILE *arquivoclientes = fopen("listaclientes.txt", "a");
  if (arquivoclientes == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Escreve os dados do cliente no arquivo
  fprintf(arquivoclientes, "Código: %d\n", clientehotel.codigocliente);
  fprintf(arquivoclientes, "Nome: %s\n", clientehotel.nomecliente);
  fprintf(arquivoclientes, "Endereço: %s\n", clientehotel.enderecocliente);
  fprintf(arquivoclientes, "Telefone: %d\n", clientehotel.telefonecliente);
  fprintf(arquivoclientes, "Nacionalidade: %s\n", clientehotel.nacionalidade);
  fprintf(arquivoclientes, "Cidade: %s\n", clientehotel.cidadecliente);
  fprintf(arquivoclientes, "Estado: %s\n", clientehotel.estadocliente);
  fprintf(arquivoclientes, "Bairro: %s\n", clientehotel.bairrocliente);
  fprintf(arquivoclientes, "Rua: %s\n", clientehotel.rua);
  fprintf(arquivoclientes, "CPF: %s\n", clientehotel.cpf);
  //colocando divisão de itens
  fprintf(arquivoclientes, "\n");

  // Fecha o arquivo
  fclose(arquivoclientes);

  // Confirmação de cadastro
  printf("\n\nO cliente %s foi cadastrado com sucesso!\n\n",
         clientehotel.nomecliente);
}










void cadastrar_funcionario(struct dadosdofuncionario funcionariohotel) {
  FILE *arquivofuncionarios = fopen("listafuncionarios.txt", "a");

  if (arquivofuncionarios == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Insira o nome do(a) Funcionario(a)
  printf("Insira o nome do(a) Funcionario(a): ");
  scanf(" %[^\n]s", funcionariohotel.nomefuncionario);

  // Insira agora o cargo
  printf("Insira agora o cargo: ");
  scanf(" %[^\n]s", funcionariohotel.cargofuncionario);

  // Insira o telefone
  printf("Qual o telefone? ");
  scanf(" %[^\n]s", funcionariohotel.telefonefuncionario);

  // Insira o salário
  printf("Qual o salário? ");
  scanf(" %f", &funcionariohotel.salariofuncionario);

  int codigo;
  printf("Insira o código do funcionário (6 primeiros dígitos do CPF): ");

  do {
    scanf("%d", &funcionariohotel.codigofuncionario);
    codigo = verificarcodigofuncionario(funcionariohotel.codigofuncionario);

    if (codigo == 1) {
        printf("\nCODIGO JA EXISTENTE. DIGITE UM NOVO CODIGO "
             "a mais do CPF: ");
    }
  } while (codigo == 1);

  // Escreve os dados do funcionário no arquivo
  fprintf(arquivofuncionarios, "Código: %d\n",
          funcionariohotel.codigofuncionario);
  fprintf(arquivofuncionarios, "Nome: %s\n", funcionariohotel.nomefuncionario);
  fprintf(arquivofuncionarios, "Telefone: %s\n",
          funcionariohotel.telefonefuncionario);
  fprintf(arquivofuncionarios, "Cargo: %s\n",
          funcionariohotel.cargofuncionario);
  fprintf(arquivofuncionarios, "Salário: %.2f\n",
          funcionariohotel.salariofuncionario);
  fprintf(arquivofuncionarios, "\n");

  fclose(arquivofuncionarios);

  printf("O funcionário %s com o código %d foi cadastrado com sucesso!\n",
         funcionariohotel.nomefuncionario, funcionariohotel.codigofuncionario);
}
















void pesquisar_cliente(struct dadosdocliente pesquisacliente) {
  
  char linha[256];
  int encontrou = 0;

  FILE *arquivo;
  


  int codigo_pesquisa;
  printf("\n\nDigite o código do cliente: ");
  scanf("%d", &codigo_pesquisa);

  arquivo = fopen("listaclientes.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  while (fgets(linha, sizeof(linha), arquivo)) {
    int codigo_cliente;
    if (sscanf(linha, "Código: %d", &codigo_cliente) == 1 &&
        codigo_cliente == codigo_pesquisa) {
      encontrou = 1;

      printf("\nInformações do cliente encontrado:\n");
      printf("Código: %d\n", codigo_cliente);

      // Lendo e imprimindo as próximas 8 linhas que contêm outras
      // informações
      for (int i = 0; i < 8; i++) {
        if (fgets(linha, sizeof(linha), arquivo)) {
          printf("%s", linha);
        } else {
          break; // Encerra o loop se não houver mais linhas
        }
      }
      printf("\n");

      break; // Termina a busca assim que encontra o cliente
    }
  }

  if (!encontrou) {
    printf("\nCliente não encontrado com o código especificado.\n");
  }

  fclose(arquivo); // Fechar o arquivo após o uso

}












void pesquisar_funcionario(struct dadosdofuncionario pesquisafuncionario){
  char linha[256];
  int encontrou = 0;

  FILE *arquivo;



  int codigo_pesquisa;
  printf("\n\nDigite o código do funcionario: ");
  scanf("%d", &codigo_pesquisa);

  arquivo = fopen("listafuncionarios.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  while (fgets(linha, sizeof(linha), arquivo)) {
    int codigo_funcionario;
    if (sscanf(linha, "Código: %d", &codigo_funcionario) == 1 &&
      codigo_funcionario == codigo_pesquisa) {
      encontrou = 1;

      printf("\nInformações do cliente encontrado:\n");
      printf("Código: %d\n", codigo_funcionario);

      // Lendo e imprimindo as próximas 8 linhas que contêm outras
      // informações
      for (int i = 0; i < 4; i++) {
        if (fgets(linha, sizeof(linha), arquivo)) {
          printf("%s", linha);
        } else {
          break; // Encerra o loop se não houver mais linhas
        }
      }
      printf("\n");

      break; // Termina a busca assim que encontra o cliente
    }
  }

  if (!encontrou) {
    printf("\nCliente não encontrado com o código especificado.\n");
  }

  fclose(arquivo); // Fechar o arquivo após o uso
}





  
