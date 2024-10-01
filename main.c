#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <strings.h> 
#include <ctype.h>




// struct dados dos clientes
struct dadosdocliente {

  int codigocliente;
  char nome[100];
  char enderecocliente[100];
  char telefonecliente[15];
  char nacionalidade[50];
  char cidadecliente[20];
  char estadocliente[20];
  char bairrocliente[50];
  char rua[25];
  char cpf[15];
};
// Struct dados dos funcionários
struct dadosdofuncionario {

  int codigofuncionario;
  char telefonefuncionario[15];
  char nomefuncionario[100];
  char cargofuncionario[100];
  float salariofuncionario;
};
// Struct dados das estadias
struct dadosdeestadia {

  int codigoestadia;
  char dataentrada[11];
  char datasaida[11];
  int quantidadediarias;
  int codigocliente;
  int numeroquarto;
};
// Struct dados do quarto cadastrado
struct quarto {

  int numquarto;
  int numhospedes;
  char status[20]; //ocupado ou desocupado
  float valorDiaria;
};

//strucut dados da estadia 
struct estadia{
  int codCliente;
  int numeroQuarto; 
  int quantHospedes;
  int diaComeco;
  int diaFim;
  int mesComeco;
  int mesFim;
  int anoComeco;
  int anoFim;
  int diasdiaria;
  float valorDiarias;
};







// assinatura das funções 

void mensagemdesaida(); 
void cadastrar_cliente(struct dadosdocliente clientehotel);
void cadastrar_funcionario(struct dadosdofuncionario funcionariohotel); 
int verificarcodigocliente(int codigocliente); 
int verificarcodigofuncionario(int codigofuncionario); 
void cadastrar_quarto(struct quarto novoQuarto);
void pesquisar_cliente(struct dadosdocliente pesquisacliente);
void pesquisar_funcionario(struct dadosdofuncionario pesquisafuncionario);
void cadastrar_quarto(struct quarto cadastraQuarto) ;
void cadastrar_estadia(struct estadia novaEstadia) ;
void finalizarEstadia();
void atualizar_status_quarto(int num_quarto_procurado);




void buscaestadias(struct estadia estadia);
//void dar_baixa_estadia() {};


//início da main
int main(void) {

  int opcaomenu;
  struct dadosdocliente cliente;
  struct dadosdofuncionario funcionario;
  struct quarto novoQuarto;
  struct estadia novaEstadia;

  //menu principal do hotel
  do {
    
    printf("\n");
    printf("Seja bem vindo à central de serviços\t\n");
    printf("Hotel Descanso Garantido!\t\n");

    printf("| (1) Cadastro de Cliente\t\n");
    printf("| (2) Cadastro de Funcionário\t\n");
    printf("| (3) Cadastro de Quarto\t\n");
    printf("| (4) Cadastro de Estadia\t\n");
    printf("| (5) Realizar Baixa de Estadia\t\n");
    printf("| (6) Pesquisar Dados do Cliente\t\n");
    printf("| (7) Pesquisar Dados do Funcionário\t\n");
    printf("| (8) Pesquisar Estadias do Cliente\t\n");
    printf("| (9) Sair\t\n\n");
    
    printf("\nSelecione uma opção: ");
    scanf("%d", &opcaomenu);

    // Verificador de opções válidas
    if (opcaomenu <= 0 || opcaomenu >= 10) {
      printf("Opção inválida!\t\nSelecione uma opção válida entre 1 e 9\t\n\n");
    }
    // garantindo que o switch do menu não será executado ao digitar opções menores ou iguais a 0 ou maiores ou iguais a 10
    if (opcaomenu > 0 && opcaomenu < 10) {
      switch (opcaomenu) {
      case 1:
        printf("Cadastro de Cliente\n");
        cadastrar_cliente(cliente);
        break;

      case 2:
        printf("Cadastro de Funcionário\n");
        cadastrar_funcionario(funcionario);
        break;

      case 3:
        printf("Cadastro de Quarto\n");
        cadastrar_quarto(novoQuarto);
        break;

      case 4:
        printf("Cadastro de Estadia\n");
        cadastrar_estadia(novaEstadia);
        break;

      case 5:
        printf("Realizar Baixa de Estadia\n");
        finalizarEstadia();
        break;

      case 6:
        printf("Pesquisar Dados do Cliente");
        pesquisar_cliente(cliente);
        break;

      case 7:
        printf("Pesquisar Dados do Funcionário \n");
        pesquisar_funcionario(funcionario);
        break;

      case 8:
        printf("Pesquisar Estadias do Cliente\n");
        buscaestadias(novaEstadia);
        break;

      default:
        mensagemdesaida();
        break;
      }
    }
  } while (opcaomenu != 9);
  return 0;
}







//Função para exibir mensagem ao escolher opção de saída do menu
void mensagemdesaida() {
  printf("\n\nMenu encerrado!\t\n");
  printf("\nHOTEL DESCANSO GARANTIDO\t\n\n");

}

//função que verifica a existencia do funcionario no arquivo listafuncionarios.txt
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
        return 1; // Caso o código seja encontrado
      }
    }
  }

  fclose(arquivo);
  return 0; // Caso o código não seja encontrado
}

//função que verifica a existencia do cliente no arquivo listaclientes.txt
int verificarcodigocliente(int codigocliente) {

  FILE *arquivo = fopen("listaclientes.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir arquivo.\n");
    exit(1);
  }

  char linha[256];

  while (fgets(linha, sizeof(linha), arquivo)) {
    // Extrai o código
    int codigo_existente;
    if (sscanf(linha, "Código: %d", &codigo_existente) == 1) {
      if (codigo_existente == codigocliente) {
        fclose(arquivo);
        return 1; // Caso o código seja encontrado
      }
    }
  }

  fclose(arquivo);
  return 0; // Caso o código não seja encontrado 
}


//Função executada ao selecionar a opção 1 no menu, para cadastrar o cliente e armazenar seus dados no arquivo listaclientes.txt
void cadastrar_cliente(struct dadosdocliente clientehotel) {
  int codigo;

  printf("Insira o código do cliente (os 6 primeiros dígitos do CPF): ");
//Ao cadastrar o cliente, caso o código deste já esteja cadastrado no sistema do hotel, o loop será acionado e o resto da função não será executada até que um código válido seja escrito para aquele cliente
  do {
    scanf("%d", &clientehotel.codigocliente);
    codigo = verificarcodigocliente(clientehotel.codigocliente);
    if (codigo == 1) {
      printf("Código já existente no sistema do hotel!\nDigite um novo código:");
    }
  } while (codigo == 1);

  printf("Nome do cliente: ");
  scanf(" %[^\n]s", clientehotel.nome);

  printf("Endereço do cliente: ");
  scanf(" %[^\n]s", clientehotel.enderecocliente);

  printf("Telefone do cliente: ");
  scanf(" %[^\n]s", clientehotel.telefonecliente);

  printf("Pais: ");
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

// Abre o arquivo no modo 'a' para continuar a escrita sem apagar os dados já existentes no arquivo
  FILE *arquivoclientes = fopen("listaclientes.txt", "a");
  if (arquivoclientes == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

// Escreve os dados do cliente no arquivo listaclientes.txt
  fprintf(arquivoclientes, "Código: %d\n", clientehotel.codigocliente);
  fprintf(arquivoclientes, "Nome: %s\n", clientehotel.nome);
  fprintf(arquivoclientes, "Endereço: %s\n", clientehotel.enderecocliente);
  fprintf(arquivoclientes, "Telefone: %s\n", clientehotel.telefonecliente);
  fprintf(arquivoclientes, "Nacionalidade: %s\n", clientehotel.nacionalidade);
  fprintf(arquivoclientes, "Cidade: %s\n", clientehotel.cidadecliente);
  fprintf(arquivoclientes, "Estado: %s\n", clientehotel.estadocliente);
  fprintf(arquivoclientes, "Bairro: %s\n", clientehotel.bairrocliente);
  fprintf(arquivoclientes, "Rua: %s\n", clientehotel.rua);
  fprintf(arquivoclientes, "CPF: %s\n", clientehotel.cpf);
  fprintf(arquivoclientes, "\n");

// Fechando o arquivo listaclientes.txt
  fclose(arquivoclientes);

// Confirmando o cadastro do cliente
  printf("\n\nO cliente %s foi cadastrado com sucesso!\n\n",
         clientehotel.nome);
}

//Função executada ao selecionar aopção 2 no menu, para cadastrar o funcionário e armazenar seus dados no arquivo listafuncionarios.txt
void cadastrar_funcionario(struct dadosdofuncionario funcionariohotel) {
  FILE *arquivofuncionarios = fopen("listafuncionarios.txt", "a");

  if (arquivofuncionarios == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
//cadastrando o nome do funcionário
  printf("Insira o nome do(a) Funcionario(a): ");
  scanf(" %[^\n]s", funcionariohotel.nomefuncionario);
//cadastrando o cargo 
  printf("Insira o cargo: ");
  scanf(" %[^\n]s", funcionariohotel.cargofuncionario);

//cadastrando o telefone
  printf("Qual o telefone? ");
  scanf(" %[^\n]s", funcionariohotel.telefonefuncionario);

//cadastrando o salário
  printf("Qual o salário? ");
  scanf(" %f", &funcionariohotel.salariofuncionario);

//cadastrando o código do funcionário 
  int codigo;
  printf("Insira o código do funcionário (6 primeiros dígitos do CPF): ");
//Ao cadastrar o funcionário, caso o código deste já esteja cadastrado no sistema, o loop será acionado e o resto da função não será executada até que um código válido seja escrito para aquele funcionário
  do {
    scanf("%d", &funcionariohotel.codigofuncionario);
    codigo = verificarcodigofuncionario(funcionariohotel.codigofuncionario);

    if (codigo == 1) {
        printf("\nCódigo já existente no sistema do hotel!\nDigite um código váido para o funcionário!");
    }
  } while (codigo == 1);

// Escreve os dados do funcionário no arquivo listafuncionarios.txt
  fprintf(arquivofuncionarios, "Código: %d\n",
          funcionariohotel.codigofuncionario);
  fprintf(arquivofuncionarios, "Nome: %s\n", 
          funcionariohotel.nomefuncionario);
  fprintf(arquivofuncionarios, "Telefone: %s\n",
          funcionariohotel.telefonefuncionario);
  fprintf(arquivofuncionarios, "Cargo: %s\n",
          funcionariohotel.cargofuncionario);
  fprintf(arquivofuncionarios, "Salário: %.2f\n",
          funcionariohotel.salariofuncionario);
  fprintf(arquivofuncionarios, "\n");

  fclose(arquivofuncionarios);

  printf("O funcionário %s, de código: %d foi cadastrado no sistema!\n",
         funcionariohotel.nomefuncionario, funcionariohotel.codigofuncionario);
}

//Função executada ao selecionar a opção 6 no menu, para buscar os dados referentes a um cliente do hotel a partir do arquivo listaclientes.txt
void pesquisar_cliente(struct dadosdocliente pesquisacliente) {
  
  char linha[256];
  int encontrou = 0;

  FILE *arquivo;
  int codigo_pesquisa;

//a partir do código informado, a função irá buscá-lo no arquivo listaclientes.txt e mostrará todas as informações do cliente referentes à esse código
  printf("\n\nInforme o código do cliente: ");
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

      printf("\nInformações do cliente:\n");
      printf("Código: %d\n", codigo_cliente);

// Lendo e imprimindo as linhas contendo as informações do cliente
      for (int i = 0; i < 8; i++) {
        if (fgets(linha, sizeof(linha), arquivo)) {
          printf("%s", linha);
        } else {
          break; // Encerra o loop quando não há mais linhas
        }
      }
      printf("\n");

      break; // Termina a busca ao encontrar o cliente
    }
  }

  if (!encontrou) {
    printf("\nCliente não encontrado!\n");
  }

  fclose(arquivo); // Fechar o arquivo

}

//Função executada ao selecionar a opção 7 no menu, para buscar os dados referentes a um funcionário do hotel a partir do arquivo listafuncionarios.txt
void pesquisar_funcionario(struct dadosdofuncionario pesquisafuncionario){
  
  char linha[256];
  int encontrou = 0;

  FILE *arquivo;



  int codigo_pesquisa;
  printf("\n\nInforme o código do funcionario: ");
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

      printf("\nInformações do funcionário:\n");
      printf("Código: %d\n", codigo_funcionario);

// Lendo e imprimindo as linhas contendo as informações do funcionário
      for (int i = 0; i < 4; i++) {
        if (fgets(linha, sizeof(linha), arquivo)) {
          printf("%s", linha);
        } else {
          break; // Encerra o loop quando não há mais linhas
        }
      }
      printf("\n");

      break; // Termina a busca ao encontrar o funcionário
    }
  }

  if (!encontrou) {
    printf("\nFuncionário não encontrado!4\n");
  }

  fclose(arquivo); // Fechar o arquivo após o uso
}

//Verificador se o número de quarto cadastrado já exitse no arquivo listaquartos.txt
int verificaNumQuarto(int numeroquarto) {
    FILE *arquivo = fopen("listaquartos.txt","r");
    if (arquivo == NULL) {
        return 0; // Arquivo não existe, então o quarto não foi cadastrado
    }

    char linha[256];
  
    while (fgets(linha, sizeof(linha), arquivo)) {
        int numero_existente;
        if (sscanf(linha, "Num quarto:%d", &numero_existente) == 1) {
            if (numero_existente == numeroquarto) {
                fclose(arquivo);
                return 1; //quarto cadastrado 
            }
        }
    }

    fclose(arquivo);
    return 0; 
}

//Função executada ao selecionar a opção 3 no menu, irá cadastrar um novo quarto no arquivo listaquartos.txt
void cadastrar_quarto(struct quarto novoQuarto) {
  int verificador;
  printf("Digite o numero do quarto: ");
  do{
    scanf("%d", &novoQuarto.numquarto);

    verificador = verificaNumQuarto(novoQuarto.numquarto);

    
    if (verificador==1) {
      printf("Quarto já existente! Cadastre o quarto com um numero diferente.\n");
      verificador=1;
    }
    
  }while(verificador==1);
    

  printf("Capacidade do quarto: ");
  scanf("%d", &novoQuarto.numhospedes);

  printf("Informe o status do quarto(Desocupado/Ocupado): ");
  scanf("%s", novoQuarto.status);
  //passando todas as letras do status do quanto para maiusculo 
  for (int i = 0; novoQuarto.status[i] != '\0'; i++) {
      novoQuarto.status[i] = toupper(novoQuarto.status[i]);
  }
  printf("Valor da diaria deste quarto: ");
  scanf("%f", &novoQuarto.valorDiaria);

  //abrindo arquivo de quartos
  FILE *arquivoQuartos = fopen("listaquartos.txt","a");

  //colocando dados no arquivo de quartos
  fprintf(arquivoQuartos, "Quant de hospedes: %d\n", novoQuarto.numhospedes);
  fprintf(arquivoQuartos, "Nº do quarto: %d\n", novoQuarto.numquarto);
  fprintf(arquivoQuartos, "Stat: %s\n", novoQuarto.status);
  fprintf(arquivoQuartos, "Valor diaria: %f\n", novoQuarto.valorDiaria);
  fprintf(arquivoQuartos, "\n");//saltando uma linha de quarto em quarto 
  
  fclose(arquivoQuartos);
}


//Busca os quartos disponíveis a partir do número de hóspedes fornecido ao iniciar o cadastro de estadia

void buscaQuartoDisponivel(int numHospedes) {
    char linha[256];
    int encontrou = 0;

    FILE *arquivo = fopen("listaquartos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        int capacidadeQuarto, numeroQuarto;
        char status[20];
        float valorDiaria;

        // Ler capacidade de hóspedes
        if (sscanf(linha, "Quantidade de hospedes: %d", &capacidadeQuarto) == 1) {
            // Ler o número do quarto
            if (fgets(linha, sizeof(linha), arquivo) && sscanf(linha, "Nº quarto: %d", &numeroQuarto) == 1) {
                // Ler o status do quarto
                if (fgets(linha, sizeof(linha), arquivo) && sscanf(linha, "Status: %s", status) == 1) {
                  //le o valor da diaria
                    if(fgets(linha, sizeof(linha), arquivo) && sscanf(linha, "Valor diaria: %f", &valorDiaria) == 1)
                    {
                      if (capacidadeQuarto == numHospedes && strcmp(status, "DESOCUPADO") == 0)   {
                          encontrou = 1;
                          printf("\nInformações do quarto encontrado:\n");
                          printf("Capacidade do quarto: %d\n", capacidadeQuarto);        
                          printf("Numero do quarto: %d\n", numeroQuarto);
                          printf("Status do quarto: %s\n", status);
                          printf("Valor da diaria do quarto: %f\n",valorDiaria);
                      }
                    }
                }
            }
        }
    }

//caso não seja encontrado nenhum quarto com a capacidadede hóspedes informada
    if (!encontrou) {
        printf("\nNão encontramos nenhum quarto com esta capacidade de hóspedes!\n");
    }

    fclose(arquivo); // Fechar o arquivo após o uso
}


//Função para calculo dos dias da estadia de um cliente
int calcular_dias(int diaInicio, int mesInicio, int anoInicio, int diaFim, int mesFim, int anoFim) {
  struct tm inicio = {0, 0, 0, diaInicio, mesInicio - 1, anoInicio - 1900};
  struct tm fim = {0, 0, 0, diaFim, mesFim - 1, anoFim - 1900};
  time_t inicio_t = mktime(&inicio);
  time_t fim_t = mktime(&fim);
  double diff = difftime(fim_t, inicio_t) / (60 * 60 * 24);
  return (int)diff;
}

//Função que vai buscar dados do quarto e adicionar o valor da estadia conforme o quarto escolhido, para base dde calculo do valor total da estadia
float buscaQuarto(int numeroQuarto){

  char linha[256];
  int encontrou = 0;
  float valorDiaria;
  FILE *arquivo;


  arquivo = fopen("listaquartos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  while (fgets(linha, sizeof(linha), arquivo)) {
    int numeroEncontrado;
    if (sscanf(linha, "Num quarto: %d", &numeroEncontrado) == 1 &&
      numeroEncontrado == numeroQuarto) {
      encontrou = 1;
      printf("\nQuarto vinculado a estadia!\n");
      
      printf("Numero do quarto: %d\n", numeroEncontrado);

// Lendo e imprimindo as próximas linhas que contêm outras informações
      for (int i = 0; i < 2; i++) {
        if (fgets(linha, sizeof(linha), arquivo)) {
          printf("%s", linha);
//Verificando o valor da diaria e guardando o mesmo em uma variável
          if (sscanf(linha, "Valor diaria: %f", &valorDiaria) == 1) {
              return valorDiaria;
          }
        } else {
          break; // Encerra o loop se não houver mais linhas
        }
      }
      printf("\n");

      break; // Termina a busca assim que encontra o cliente
    }
  }

  if (!encontrou) {
    printf("\nDiaria não encontrda\n");
  }

  fclose(arquivo); // Fechar o arquivo após o uso
  return valorDiaria;
}





//Função executada ao selecionar a opção 4 no menu, que irá cadastrar uma nova estadia para o código de cliente fornecido 
void cadastrar_estadia(struct estadia novaEstadia) {
  
  //struct de um novo clinete se necessario 
  struct dadosdocliente novoClienteEstadia;
  //variaveis
  int returnverificaCodigo,
  escolhaCadastrar,
  quatidadeDiaria,
  diastotais;

  int dia1, mes1, ano1;//variaveis para armazenar a data de inicio da estadia
  int dia2, mes2, ano2;//variaveis para armazenar a data final da estadia
 
  //solicitando codigo do cliente 
  
  do{

    printf("\nDigite o codigo do cliente para vincularmos a estádia: ");
    scanf("%d",&novaEstadia.codCliente);
    //atribuindo a variavel o retono da função
    returnverificaCodigo = verificarcodigocliente(novaEstadia.codCliente);
    //se retornar 0 significa que não foi achado nosso cliente no arquivo de clientes
    if(returnverificaCodigo == 0){
      printf("\nCliente não cadastrado!\nDeseja cadastra-lo no sistema?\n[1]Sim\n[2]Nao\n Selecione uma opcao: ");
      scanf("%d",&escolhaCadastrar);



      //ja que nosso cliente não esta cadastrado em função da escolha do nosso usuario vamos entrar ou não no if de cadastro
      if(escolhaCadastrar==1){
        printf("\n\nVamos cadastra-lo!\n");
        cadastrar_cliente( novoClienteEstadia);//neste caso eu criei uma struct de clientes e chamo a função para cadastrar o meu novo cliente.

      }else{
        printf("\nVoltando ao menu preincipal...\n\n");
        return;//este comando faz com que a função finalize, retornando ao menu inicial 
      }
      
    }
    //neste ponto ja temos um cliente cadstrado e com isso voltamos a solicitar o codigo para o usuario visando que ele digite um codigo que acabou de cadastrar ! a var returnverificaCodigo == 0 vai fazer com ue o codigo cicle novamente. 
  }while(returnverificaCodigo==0);


  //SOLICITANDO A QUANTIDADE DE HOSPEDES
  printf("\nDigite a quantidade de hospedes: ");
  scanf("%d",&novaEstadia.quantHospedes);
  
  //CHAMA A FUNÇÃO QUE VAI LISTAR OS QUARTOS DISPONIVEIS EM FUNÇÃO DO NUMERO DE PESSOAS QUE PRECISA PARA O QUARTO E TAMBEM SEU ESTATUS
  buscaQuartoDisponivel(novaEstadia.quantHospedes);

  printf("\n\nQual quarto deseja?\nDIGITE O NUMERO DO QUARTO: ");
  scanf("%d",&novaEstadia.numeroQuarto);

  // buscando dados do quarto e trocando de desocupado para ocupado
  novaEstadia.valorDiarias = buscaQuarto(novaEstadia.numeroQuarto);

  //CALCULANDO O NUMERO DE DIARIAS

  //solicitando a data de entrada 
  printf("Insira a data de início no seguinte formato: dd/mm/aaaa! ");
  scanf("%d %d %d", &dia1, &mes1, &ano1);
  novaEstadia.diaComeco = dia1;
  novaEstadia.mesComeco = mes1;
  novaEstadia.anoComeco = ano1;

  //solicitando a data de saida
  printf("Insira a data de saída no seguinte formato: dd/mm/aaaa! ");
  scanf("%d %d %d", &dia2, &mes2, &ano2);
  novaEstadia.diaFim = dia2;
  novaEstadia.mesFim = mes2;
  novaEstadia.anoFim = ano2;
   
  diastotais = calcular_dias( dia1,  mes1,  ano1,  dia2,  mes2,  ano2);
  novaEstadia.diasdiaria = diastotais ;
  novaEstadia.valorDiarias = diastotais *novaEstadia.valorDiarias;

  //ESCREVENDO NO ARQUIVO 
  //abrindo o arquivo
  FILE *arquivoEstadias = fopen("estadias.txt", "a");
  fprintf(arquivoEstadias, "Codigo cliente: %d\n", novaEstadia.codCliente);
  fprintf(arquivoEstadias, "Num quarto: %d\n", novaEstadia.numeroQuarto);
  fprintf(arquivoEstadias, "Num pessoas no quarto: %d\n", novaEstadia.quantHospedes);
  fprintf(arquivoEstadias, "Num de dias: %d\n", novaEstadia.diasdiaria);
  fprintf(arquivoEstadias, "Valor das diarias: %f\n", novaEstadia.valorDiarias);
  fprintf(arquivoEstadias, "\n");
  //fechando o arquivo
  fclose(arquivoEstadias);
  printf("\n\nDiaria cadastrada com sucesso!\nVinculada ao cliente de codigo %d\n",novaEstadia.codCliente);
}



//Função executada ao selecionar a opção 8 no menu, irá buscar as estadias de um cliente a partir do código fornecido
void buscaestadias(struct estadia estadia) {
      int codigoCliente;
      printf("Digite o codigo do cliente para ver as estadias em seu titulo: ");
      scanf("%d", &codigoCliente);

      FILE *arquivoEstadias = fopen("estadias.txt", "r");
      if (arquivoEstadias == NULL) {
          printf("Erro ao abrir o arquivo de estadias.\n");
          return;
      }

      char linha[256];
      int encontrou = 0;

      while (fgets(linha, sizeof(linha), arquivoEstadias)) {
          if (sscanf(linha, "Codigo cliente: %d\n", &estadia.codCliente) == 1) {
              // Lê as linhas seguintes para obter todas as informações da estadia
              if (fgets(linha, sizeof(linha), arquivoEstadias) &&
                  sscanf(linha, "Num quarto: %d\n", &estadia.numeroQuarto) == 1 &&
                  fgets(linha, sizeof(linha), arquivoEstadias) &&
                  sscanf(linha, "Num pessoas no quarto: %d\n", &estadia.quantHospedes) == 1 &&
                  fgets(linha, sizeof(linha), arquivoEstadias) &&
                  sscanf(linha, "Num de dias: 2 %d\n", &estadia.diasdiaria) == 1 &&
                  fgets(linha, sizeof(linha), arquivoEstadias) &&
                  sscanf(linha, "Valor das diarias: %f\n", &estadia.valorDiarias) == 1 ) {

                  // Verifica se o código do cliente corresponde ao fornecido
                  if (estadia.codCliente == codigoCliente) {
                      encontrou = 1;
                      printf("\nEstadia Encontrada:\n");
                      printf("Código do Cliente: %d\n", estadia.codCliente);
                      printf("Número do Quarto: %d\n", estadia.numeroQuarto);
                      printf("Número de Pessoas no Quarto: %d\n", estadia.quantHospedes);
                      printf("Número de Dias: %d\n", estadia.diasdiaria);
                      printf("Valor a ser pago: %f\n", estadia.valorDiarias);
                      
                  }
              }
          }
      }

      if (!encontrou) {
          printf("Nenhuma estadia encontrada para o cliente com código %d.\n", codigoCliente);
      }

      fclose(arquivoEstadias);
}

//função executada ao selecionar a opção 5 no menu principal, irá dar baixa na estadia de um quarto
void finalizarEstadia() {

  int num_quarto_procurado,decisaoFinalizar;
  printf("Digite o numero do quarto que deseja finalizar a estadia\nDIGITE O NUMERO DO QUARTO :");
  scanf("%d",&num_quarto_procurado);


    FILE *file = fopen("estadias.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct estadia estadia;
    char linha[100];
    int num_quarto_atual,verificador =0 ;

    while (fgets(linha, sizeof(linha), file)) {
        if (sscanf(linha, "Num quarto: %d", &num_quarto_atual) == 1) {
      estadia.numeroQuarto = num_quarto_atual;
          verificador=1;
        } else if (sscanf(linha, "Codigo cliente: %d", &estadia.codCliente) == 1) {
            // nada a fazer aqui
        } else if (sscanf(linha, "Num pessoas no quarto: %d", &estadia.quantHospedes) == 1) {
            // nada a fazer aqui
        } else if (sscanf(linha, "Num de dias: %d", &estadia.diasdiaria) == 1) {
            // nada a fazer aqui
        } else if (sscanf(linha, "Valor das diarias: %f", &estadia.valorDiarias) == 1) {
            // Verifica se o número do quarto corresponde ao procurado
            if (estadia.numeroQuarto == num_quarto_procurado) {
                printf("Num quarto: %d\n", estadia.numeroQuarto);
                printf("Valor das diarias: %.2lf\n\n", estadia.valorDiarias);
            }
        }
    }

    fclose(file);
  printf("\n\nDeseja desocupar o quarto?\n[1]Sim\n[2]Nao");
  scanf("%d",&decisaoFinalizar);
  if(decisaoFinalizar==1){
    atualizar_status_quarto(estadia.numeroQuarto);
  }
    
  //mudando o estatus do quarto conforme o numero do quarto

  //não achou o quarto
  if(verificador==0){
    printf("Quanto não foi encotrado !!");
  }
}


void atualizar_status_quarto(int num_quarto_procurado) {
    FILE *file = fopen("listaquartos.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct quarto quarto;
    char linha[100];
    long pos;
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), file)) {
        pos = ftell(file); // Armazena a posição atual no arquivo

        if (sscanf(linha, "Num quarto: %d", &quarto.numquarto) == 1) {
            if (quarto.numquarto == num_quarto_procurado) {
                encontrou = 1;
                // Continua a leitura das linhas seguintes para completar a estrutura
                fseek(file, pos - strlen(linha), SEEK_SET); // Volta para a linha inicial do quarto
                fgets(linha, sizeof(linha), file);
                sscanf(linha, "Quant de hospedes: %d", &quarto.numhospedes);
                fgets(linha, sizeof(linha), file); // Pula a linha do número do quarto
                fgets(linha, sizeof(linha), file);
                sscanf(linha, "Stat: %s", quarto.status);
                fgets(linha, sizeof(linha), file);
                sscanf(linha, "Valor diaria: %f", &quarto.valorDiaria);

                // Se o status for "OCUPADO", atualiza para "DESOCUPADO"
                if (strcmp(quarto.status, "OCUPADO") == 0) {
                    strcpy(quarto.status, "DESOCUPADO");

                    // Move o ponteiro de arquivo para a posição onde está o status
                    fseek(file, pos, SEEK_SET);
                    fgets(linha, sizeof(linha), file); // Pula a linha "Num quarto: ..."
                    pos = ftell(file); // Armazena a posição atual do status

                    // Atualiza o status no arquivo
                    fseek(file, pos, SEEK_SET);
                    fprintf(file, "Stat: %s\n", quarto.status);
                }

                break;
            }
        }
    }

    if (!encontrou) {
        printf("Quarto %d não encontrado.\n", num_quarto_procurado);
    }

    fclose(file);
}



