#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#define TAMANHO 10 //Declaração de constante, pode ser alterado conforme a necessidade do usuário de armazenar mais cartas.

char artista[TAMANHO][50];          // Recebe o nome do artista da gravura usada.
char caixa_de_texto[TAMANHO][500];  // Recebe a descricao das habilidades da carta.
char cor[TAMANHO][50];              // Recebe o nome da cor que a carta representa.
char formatos_validos[TAMANHO][50]; // Recebe a descricao de quais formatos de jogo a carta pode ser usada.
char linha_de_tipo[TAMANHO][50];    // Recebe o tipo da carta.
char subtipo[TAMANHO][50];          // Recebe o subtipo da carta.
char titulo[TAMANHO][50];           // Recebe o nome da carta.
char custo_de_mana[TAMANHO][50];    // Recebe o custo para conjurar a mágica.
char ed_numero[TAMANHO][50];        // Recebe o nome da edição e o número que a carta representa na coleção.
char poder[TAMANHO][50];            // Recebe o valor da quantidade de dano que a criatura causar em combate.
char resistencia[TAMANHO][50];      // Recebe o valor da quantidade de dano que ela tem que sofrer em um único turno para ser destruída.
char preco_medio[TAMANHO][50];      // Recebe o valor do preço médio em reais qua a carta custa.
char raridade[TAMANHO][50];         // Recebe a indicacao de qual a raridade da carta.

int opcao;              //Variável usada para escolha de opções do usuário.

void cadastro();        //Códigos da parte de cadastro.
void pesquisa();        //Códigos da parte de pesquisa.
void lista();           //Códigos da parte de lista.
void editar();          //Códigos da parte de edição de dados.

int main(void) {

    setlocale(LC_ALL, "Portuguese");


    do{
        system("cls");      //Como o programa mostra muitos textos, achei melhor limpar a tela frequentemente para ficar mais organizado.

        printf("  --------------------------------------------------------------------------- \n");
        printf(" |             Menu de Cadastro de Cartas de Magic The Gathering             |\n");
        printf("  --------------------------------------------------------------------------- \n\n");


        printf("1 - Cadastrar nova carta\n2 - Listar todas as cartas cadastradas\n3 - Pesquisar carta\n4 - Editar cadastro\n5 - Sair\n");       //Opções principais do programa para escolha do usuário.
        printf("\nSelecione uma opção de 1 a 5 por favor: ");       //Usuário digita um número de 1 a 5.
        scanf("%d", &opcao);        //opcao recebe esse valor digitado.


        switch (opcao) {        //Entra na função referente ao valor digitado.
            case 1:
                cadastro();     //Entra na função cadastro.
                break;
            case 2:
                lista();        //Entra na função lista.
                break;
            case 3:
                pesquisa();     //Entra na função pesquisa.
                break;
            case 4:
                editar();       //Entra na função editar dados.
                break;
            case 5:
                fflush(stdin);      //Limpando o buffer do teclado.
                system("exit");     //Opção de sair do programa.
                break;

            default:

                printf("\nOpção inválida!\n");      //Caso o usuário não digite um número entre as opções dadas.
                getchar();
                getchar();
                break;

        }
    } while (opcao!=5);         //Enquanto o usuário não digitar a opção para sair do programa, o Menu principal será chamado.

} //Fim da função menu

void cadastro() {
    static int linha;
        system("cls");



    do {

        fflush(stdin);
        printf("\nDigite o nome da carta: ");
        gets(titulo[linha]);

        printf("\nDigite o texto da carta: ");
        gets(caixa_de_texto[linha]);

        printf("\nDigite a cor da carta: ");
        gets(cor[linha]);

        printf("\nDigite o tipo da carta: ");
        gets(linha_de_tipo[linha]);

        printf("\nDigite o subtipo da carta: ");
        gets(subtipo[linha]);

        printf("\nDigite a raridade da carta: ");
        gets(raridade[linha]);

        printf("\nDigite o número referente ao poder da carta: ");
        gets(poder[linha]);

        printf("\nDigite o número referente a resistência da carta: ");
        gets(resistencia[linha]);

        printf("\nDigite o custo de mana da carta: ");
        gets(custo_de_mana[linha]);

        printf("\nDigite os formatos válidos da carta: ");
        gets(formatos_validos[linha]);

        printf("\nDigite o nome do artista da carta: ");
        gets(artista[linha]);

        printf("\nDigite o nome da edição e o número da carta: ");
        gets(ed_numero[linha]);

        printf("\nDigite o preço médio da carta R$: ");
        gets(preco_medio[linha]);

        printf("\nA carta foi armazenada na posição %d.\n", linha);

        printf("\n1 - Cadastrar outra carta.\n0 - Voltar ao MENU PRINCIPAL.\n");
        scanf(" %d", &opcao);

        linha++;        //Avança para a próxima posição na memória para novo armazenamento.
        }
        while (opcao==1);       //Se usuário digitar 1 ele continua cadastrando, qualquer outro número ele volta para menu principal.


} //Fim da funcao cadastro

void pesquisa(){
    system("cls");      //Limpando a tela.
    fflush(stdin);      //Limpando o Buffer do teclado.

    char pesquisatitulo[50];
    int i;

                printf("\nDigite o nome da carta já cadastrada que você deseja encontrar: ");
                gets(pesquisatitulo);
                for(i=0;i<TAMANHO;i++){         //Percorre o vetor.

                        if(strcmp(titulo[i],pesquisatitulo)==0)         //Compara o que está nos vetores, com o que foi digitado pelo usuário.
                        printf("\n\nSeguem os dados da carta cadastrada:\n\nPosição de cadastro: %d\nNome: %s\nTexto: %s\nCor: %s\nTipo: %s\nSubtipo: %s\nCusto de mana: %s\nRaridade: %s\nPoder: %s\nResistência: %s\nArtista: %s\nNome e número da edição: %s\nFormatos válidos: %s\nPreço médio R$ %s\n\n", i, titulo[i],caixa_de_texto[i],cor[i],linha_de_tipo[i],subtipo[i],custo_de_mana[i],raridade[i],poder[i],resistencia[i],artista[i],ed_numero[i],formatos_validos[i],preco_medio[i]);
                        }
                        getchar();
                        getchar();

} //Fim da função pesquisa

void lista(){
    system("cls");
    fflush(stdin);

    int i;
    for(i=0;i<TAMANHO;i++) {
        if (titulo[i][0] != '\0') {         //Lista todas as cartas que não tem um espaço vazio na primeira posição.
            printf("\n\nSeguem os dados da carta cadastrada na posição %d:\n\nNome: %s\nTexto: %s\nCor: %s\nTipo: %s\nSubtipo: %s\nCusto de mana: %s\nRaridade: %s\nPoder: %s\nResistência: %s\nArtista: %s\nNome e número da edição: %s\nFormatos válidos: %s\nPreço médio R$ %s\n\n", i, titulo[i], caixa_de_texto[i], cor[i], linha_de_tipo[i], subtipo[i], custo_de_mana[i],raridade[i], poder[i], resistencia[i], artista[i], ed_numero[i], formatos_validos[i], preco_medio[i]);
        }
        else{
            printf("Não há mais cartas cadastradas na base de dados.");
            getchar();

            break;
            }

        }
    }

main();


 //Fim da função lista

void editar(){
    system("cls");
    fflush(stdin);

    int i;
    printf("\nDigite o número da posição da carta que você deseja substituir os dados armazendos.\n");
    printf("Obs. Verificar a posição de cada carta já armazenada na opção 'lista' do menu principal\n\n");
    scanf("%d", &i);

    printf("\n\nFoi escolhida a posição %d.\n\n", i);

        if(titulo[i][0]!='\0'){     //Caso a posição 0 esteja vazia, ele considera que não tem carta cadastrada alí.
        fflush(stdin);

        printf("\nDigite o nome da nova carta: ");
        gets(titulo[i]);

        printf("\nDigite o texto da nova carta: ");
        gets(caixa_de_texto[i]);

        printf("\nDigite a cor da nova carta: ");
        gets(cor[i]);

        printf("\nDigite o tipo da nova carta: ");
        gets(linha_de_tipo[i]);

        printf("\nDigite o subtipo da nova carta: ");
        gets(subtipo[i]);

        printf("\nDigite a raridade da nova carta: ");
        gets(raridade[i]);

        printf("\nDigite o número referente ao poder da nova carta: ");
        gets(poder[i]);

        printf("\nDigite o número referente a resistência da nova carta: ");
        gets(resistencia[i]);

        printf("\nDigite o custo de mana da nova carta: ");
        gets(custo_de_mana[i]);

        printf("\nDigite os formatos válidos da nova carta: ");
        gets(formatos_validos[i]);

        printf("\nDigite o nome do artista da nova carta: ");
        gets(artista[i]);

        printf("\nDigite o nome da edição e o número da nova carta: ");
        gets(ed_numero[i]);

        printf("\nDigite o preço médio da nova carta R$: ");
        gets(preco_medio[i]);

        printf("\nA nova carta foi armazenada na posição %d.\n", i);

        getchar();

        }else{          //Caso não exista carta cadastrada na posição digitada, segue uma mensagem informando como proceder.
        printf("\n\nNão existe carta cadastrada na posição %d. Por favor verifique o valor correto e tente novamente.\n",i);
        getchar();
        getchar();
        }

        main();

} //Fim da função editar


