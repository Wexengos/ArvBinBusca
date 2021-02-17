// ############################################################################
// TVC 3 -- ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO II
// DATA: 26/11/2018
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO:
// MATRICULA:
// ############################################################################
#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    cout << "TVC3 -- ESTRUTURA DE DADOS e LAB. DE PROG. II" << endl;
    cout << "FAVOR PREENCHER OS SEUS DADOS" << endl;
    cout << "Exemplo de ABB: " << endl;
    ArvBinBusca abb;
    // ARVORE DE TESTE
    abb.insere(40); abb.insere(15); abb.insere(10);
    abb.insere(20); abb.insere(19); abb.insere(35);
    abb.insere(75); abb.insere(50); abb.insere(45);
    abb.insere(60); abb.insere(66); abb.insere(68);
    abb.imprime();

    // SUGESTAO: TESTE COM OUTRAS ARVORES BINARIAS TAMBEM!

    // TESTE DA QUESTAO 1 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 1" << endl;
    cout << "Numero nohs altura 0 c/ 1 filho: " << abb.numNosAltura(0) << endl;
    cout << "Numero nohs altura 2 c/ 1 filho: " << abb.numNosAltura(2) << endl;
    cout << "Numero nohs altura 100 c/ 1 filho: " << abb.numNosAltura(100) << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 2 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 2" << endl;
    cout << "Comprimento do caminho: " << abb.caminho(66) << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 3 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 3" << endl;
    cout << "Media no intervalo: " << abb.mediaIntervalo(10, 48) << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    cout << "Numero de nos impares: " << abb.impares() << endl;
    cout << "Soma dos valores dos nos: " << abb.soma() << endl;
    cout << "No com o maior valor: " << abb.maiorValor() << endl;
    cout << "No com o menor valor: " << abb.menorValor() << endl;
    cout << "Altura: " << abb.altura() << endl;
    cout << "Numero de nos: " << abb.numNos() << endl;
    cout << "A arvore e cheia? " << endl;
    (abb.eCheia() ? cout<<"Sim."<<endl : cout<<"Nao."<<endl);

    cout << abb.maiores(25) << endl;
    cout << "Imprimindo nivel 3: " << endl;
    abb.imprimeNivel(3);
    cout << "Imprimindo nivel 2: " << endl;
    abb.imprimeNivel(2);
    abb.imprimeFilhos(50);
    abb.imprimeFilhos(15);
    abb.imprimeIntervalo(20, 68);
    abb.imprimeCrescente();
    cout << endl;
    abb.imprimeDecrescente();
    cout << endl;
    cout << endl << "Classificacao do no 75: " << abb.classificaNo(75) << endl;
    cout << "Classificacao do no 50: " << abb.classificaNo(50) << endl;
    cout << "Classificacao do no 19: " << abb.classificaNo(19) << endl;

    int vet[7] = {2,4,5,6,8,10,12};
    int n = 7;

    ArvBinBusca LR1;
    LR1.insereDoVetor1(n, vet);
    for(int i=0; i < n; i++)
    {
        cout << "Arvore LR, Nivel " << i+1 << ": ";
        LR1.imprimeNivel(i);
        cout << endl;
    }

    /*ArvBinBusca LR2;
    LR2.insereDoVetor2(n, vet);

    for(int j=0; j < n; j++)
    {
        cout << "Arvore LR, Nivel " << j+1 << ": ";
        LR2.imprimeNivel(j);
        cout << endl;
    } */

    return 0;
}
