#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
//Q1

int ArvBinBusca::numNosAltura(int a)
{
    /// Implemente aqui sua solu��o.
    /// Se necess�rio, remova/modifique a linha abaixo.
    return 0;
}

//-Q1

// ----------------------------------------------------------------------------
//Q2

int ArvBinBusca::caminho(int ch)
{
    /// Implemente aqui sua solu��o.
    /// Se necess�rio, remova/modifique a linha abaixo.
    return 0;  //comprimento do caminho � igual ao n�mero de n�s - 1
}

//-Q2

// ----------------------------------------------------------------------------
//Q3

float ArvBinBusca::mediaIntervalo(int a, int b)
{
    /// Implemente aqui sua solu��o.
    /// Se necess�rio, remova/modifique a linha abaixo.
    return 0;
}

//-Q3

// ----------------------------------------------------------------------------
// Restante da classe ArvBinBusca
// ----------------------------------------------------------------------------

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    // destrutor vazio (s� para avalia��o)
}

void ArvBinBusca::insere(int x)
{
    NoArv *p = auxInsere(raiz, x);
    if(raiz == NULL)
        raiz = p;
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(x < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), x));
    else
        p->setDir(auxInsere(p->getDir(), x));
    return p;
}

void ArvBinBusca::imprime()
{
    auxImprime(raiz);
    cout << endl;
}

void ArvBinBusca::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

int ArvBinBusca::impares()
{
    int impa = 0;

    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        return -1;
    }
    else
    {
        auxImpares(raiz, &impa);
        return impa;
    }
}

void ArvBinBusca::auxImpares(NoArv *p, int *impa)
{
    if(p != NULL)
    {
        if(p->getInfo()%2 != 0)
        {
            (*impa)++;
        }
        auxImpares(p->getEsq(), impa);
        auxImpares(p->getDir(), impa);
    }
}

int ArvBinBusca::soma()
{
    int soma = 0;

    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        return -1;
    }
    else
    {
        auxSoma(raiz, &soma);
        return soma;
    }
}

void ArvBinBusca::auxSoma(NoArv *p, int *soma)
{
    if(p != NULL)
    {
        (*soma) += p->getInfo();
        auxSoma(p->getEsq(), soma);
        auxSoma(p->getDir(), soma);
    }
}

int ArvBinBusca::maiorValor()
{
    int maior;
    NoArv *p = raiz;
    if(p == NULL)
    {
        cout << "Arvore vazia! BURRO" << endl;
        return -1;
    }
    else
    {
        maior = raiz->getInfo();

        auxMaiorValor(p, &maior);
        return maior;
    }
}

void ArvBinBusca::auxMaiorValor(NoArv *p, int *maior)
{
    if(p != NULL)
    {
        {
            auxMaiorValor(p->getEsq(), maior);
            if(p->getInfo() > *maior)
                *maior = p->getInfo();
            auxMaiorValor(p->getDir(), maior);
        }
    }
}

int ArvBinBusca::menorValor()
{
    int menor;
    NoArv *p = raiz;
    if(p == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return -1;
    }
    else
    {
        menor = raiz->getInfo();

        auxMenorValor(p, &menor);
        return menor;
    }
}

void ArvBinBusca::auxMenorValor(NoArv *p, int *menor)
{
    if(p != NULL)
    {
        if(p->getInfo() < *menor)
            *menor = p->getInfo();
        auxMenorValor(p->getEsq(), menor);
        auxMenorValor(p->getDir(), menor);
    }
}

int ArvBinBusca::altura()
{
    if(raiz == NULL)
    {
        cout << "Arvore Vazia!" << endl;
        return -1;
    }
    else
        return auxAltura(raiz);
}

int ArvBinBusca::auxAltura(NoArv *p)
{
    if(p!=NULL)
    {
        int he = auxAltura(p->getEsq());
        int hd = auxAltura(p->getDir());

        return 1 + (he > hd ? he : hd);
    }
    else return -1;
}

int ArvBinBusca::numNos()
{
    int nos = 0;
    if(raiz == NULL)
    {
        cout << "Arvore Vazia!" << endl;
        return -1;
    }
    else
    {
        auxNumNos(raiz, &nos);
        return nos;
    }
}

void ArvBinBusca::auxNumNos(NoArv *p, int *nos)
{
    if(p != NULL)
    {
        (*nos)++;
        auxNumNos(p->getEsq(), nos);
        auxNumNos(p->getDir(), nos);
    }
}

bool ArvBinBusca::eCheia()
{
    if(raiz != NULL)
    {
        if((numNos() == pow(2,(altura()+1) - 1)))
        {
            return true;
        }
        else
            return false;
    }
}

float ArvBinBusca::media()
{
    int cont;
    float soma;

    if (raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return -1;
    }
    else
        auxMedia(raiz, &cont, &soma);
        return soma/(float)cont;
}

void ArvBinBusca::auxMedia(NoArv *p, int *cont, float *media)
{
    if(p != NULL)
    {
        *media = *media + p->getInfo();
        (*cont)++;
    }
    auxMedia(p->getEsq(), cont, media);
    auxMedia(p->getDir(), cont, media);
}

int ArvBinBusca::maiores(int val)
{
    int maior = 0;
    if(raiz == NULL)
    {
        cout << "Arvore vazia! " << endl;
        return -1;
    }
    else
    {
        auxMaiores(raiz, val, &maior);
        return maior;
    }
}

void ArvBinBusca::auxMaiores(NoArv *p, int val, int *maior)
{
    if(p != NULL)
    {
        if(p->getInfo() > val)
        {
            (*maior)++;
        }
        auxMaiores(p->getEsq(), val, maior);
        auxMaiores(p->getDir(), val, maior);
    }
}

void ArvBinBusca::imprimeNivel(int k)
{
    int cont = 0;
    if(raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return;
    }
    else
        auxImprimeNivel(raiz, cont, k);
}

void ArvBinBusca::auxImprimeNivel(NoArv *p, int cont, int k)
{
    if(p != NULL)
    {
        if(cont == k)
            cout << p->getInfo() << ", " << endl;
        auxImprimeNivel(p->getEsq(), cont+1, k);
        auxImprimeNivel(p->getDir(), cont+1, k);
    }
}

///atual funciona como o cont do exerc. anterior
float ArvBinBusca::mediaNivel(int k)
{
    float soma = 0;
    int cont = 0, atual = 0;
    if(raiz == NULL)
    {
        cout << "Arvore vazia!" << endl;
        return -1;
    }
    else
        auxMediaNivel(raiz, atual, &cont, &soma, k);
    return soma/(float)cont;
}

float ArvBinBusca::auxMediaNivel(NoArv *p, int atual, int *cont, float *soma, int k)
{
    if(p == NULL)
    {
        return 0;
    }
    else if(atual == k)
    {
        *soma = *soma + p->getInfo();
        (*cont)++;
    }
    auxMediaNivel(p->getEsq(), atual + 1, cont, soma, k);
    auxMediaNivel(p->getDir(), atual + 1, cont, soma, k);
}

void ArvBinBusca::imprimeFilhos(int x)
{
    NoArv *p = raiz;
    if(p == NULL)
    {
        cout << "Arvore vazia! " << endl;
        return;
    }
    else
    {
        while(p != NULL)
        {
            if(p->getInfo() == x)
            {
                cout << "Filho do no " << x << " a esquerda: " << ((p->getEsq())->getInfo()) << endl;
                cout << "Filho do no " << x << " a direita: " << ((p->getDir())->getInfo()) << endl;
                p = NULL;
            }
            else if(p->getInfo() > x)
            {
                p = p->getEsq();
            }
            else if(p->getInfo() < x)
            {
                p = p->getDir();
            }
        }
        return;
    }
}

void ArvBinBusca::imprimeIntervalo(int x, int y)
{
    if(raiz == NULL)
    {
        cout << "Arvore vazia! " << endl;
        return;
    }
    else
        cout << "Imprimindo nos no intervalo " << x << " a " << y << endl;
        auxImprimeIntervalo(raiz, x, y);
}

void ArvBinBusca::auxImprimeIntervalo(NoArv *p, int x, int y)
{
    if(p != NULL)
    {
        if(p->getInfo() < x)
        {
            auxImprimeIntervalo(p->getDir(), x, y);
        }
        else if(p->getInfo() > y)
        {
            auxImprimeIntervalo(p->getEsq(), x, y);
        }
        else if((p->getInfo()) >= x && (p->getInfo() <= y))
        {
            auxImprimeIntervalo(p->getEsq(), x, y);
            cout << p->getInfo() << ", " << endl;
            auxImprimeIntervalo(p->getDir(), x, y);
        }
    }
}

void ArvBinBusca::imprimeCrescente()
{
    if(raiz == NULL)
    {
        return;
    }
    else
    {
        cout << "Imprimindo os valores em ordem crescente: ";
        auxImprimeCrescente(raiz);
    }
}

void ArvBinBusca::auxImprimeCrescente(NoArv *p)
{
    if(p!=NULL)
    {
        auxImprimeCrescente(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprimeCrescente(p->getDir());
    }
}

void ArvBinBusca::imprimeDecrescente()
{
    if(raiz == NULL)
    {
        return;
    }
    else
    {
        cout << "Imprimindo os valores em ordem decrescente: ";
        auxImprimeDecrescente(raiz);
    }
}

void ArvBinBusca::auxImprimeDecrescente(NoArv *p)
{
    if(p!=NULL)
    {
        auxImprimeDecrescente(p->getDir());
        cout << p->getInfo() << " ";
        auxImprimeDecrescente(p->getEsq());
    }
}

///inserindo do vetor em uma matriz degenerada:
void ArvBinBusca::insereDoVetor1(int n, int *vet)
{
    NoArv *p = raiz;
    int i = 0;
    if(raiz == NULL)
    {
        while(i < n)
        {
            insere(vet[i]);;
            i++;
        }
    }
}

///inserindo do vetor em uma matriz completa:
/*void ArvBinBusca::insereDoVetor2(int n, int *vet)
{
    NoArv *p = raiz;
    int meio = (n/2)+1;
    int i = 0;
    int j = meio + 1;
    if(raiz == NULL)
    {
        p->setInfo(vet[meio]);
        while(i < meio)
        {
            insere(vet[i]);
            i++;
        }
        while(j < n)
        {
            insere(vet[j]);
            j++;
        }
    }
    return;
}*/

NoArv* ArvBinBusca::buscaValor(int val)
{
    NoArv* p = raiz;
    if(raiz == NULL)
    {
        cout << "Arvore vazia!";
    }
    else
    {
        while(p != NULL)
        {
            if(p->getInfo() == val)
            {
                return p;
            }
            else if(p->getInfo() < val)
                p = p->getEsq();
            else if(p->getInfo() > val)
                p = p->getDir();
        }
        return NULL;
    }
}

int ArvBinBusca::classificaNo(int val)
{
    NoArv *noVal = raiz;
    if(noVal != NULL)
    {
        while(noVal != NULL)
        {
            if(noVal->getInfo() == val)
            {
                if(noVal->getEsq() == NULL && noVal->getDir() != NULL)
                {
                    return 1;
                }
                else if(noVal->getDir() == NULL && noVal->getEsq() != NULL)
                {
                    return 1;
                }
                else if(noVal->getDir() == NULL && noVal->getEsq() == NULL)
                {
                    return 0;
                }
                else if(noVal->getDir() != NULL && noVal->getEsq() != NULL)
                {
                    return 2;
                }
            }
            else if(noVal->getInfo() < val)
                noVal = noVal->getDir();
            else if(noVal->getInfo() > val)
                noVal = noVal->getEsq();
        }
    }
}

void ArvBinBusca::remove(int x)
{
    raiz = auxRemove(raiz, x);
}

NoArv* ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv* ArvBinBusca::removeNo1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir(); //filho �nico � da direita
    else
        aux = p->getEsq(); //filho �nico � da esquerda
    delete p;
    return aux;
}

NoArv* ArvBinBusca::menorSubArvDireita(NoArv *p)
{
    NoArv *aux = p->getDir(); //n� � direita de p
    while(aux->getEsq() != NULL)
        aux = aux->getEsq();
    return aux;
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int x)
{
    if(p == NULL)
        return NULL;
    else if(x < p->getInfo())//remove na sub. esquerda
        p->setEsq(auxRemove(p->getEsq(), x));
    else if(x > p->getInfo())// remove na sub. direita
        p->setDir(auxRemove(p->getDir(), x));
    else
    {// achou o n� a ser removido, p->getInfo() == x
        if((p->getEsq() == NULL)&&(p->getDir() == NULL))
            p = removeFolha(p);// p aponta para uma folha
        else if((p->getEsq() == NULL)||(p->getDir() == NULL))
            p = removeNo1Filho(p); //p tem s� um filho
        else
        {
            //p tem dois filhos
            NoArv *aux = menorSubArvDireita(p);
            // troca as informa��es
            int auxInt = aux->getInfo();
            p->setInfo(auxInt);
            aux->setInfo(x);
            // recurs�o: para a subarv. direita
            p->setDir(auxRemove(p->getDir(), x));
        }
    }
    return p;
}
