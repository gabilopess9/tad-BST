/** ******************************************************************
 TAD Árvore BST
 Estrutura de Dados II
 GRUPO
 Nome: Gabriela Lopes Francisco
 TIA: 31744591
 Nome: 
 TIA: 

****************************************************************** */

using namespace std;

class ArvoreBST {

private:
    No *raiz;

public:
    ArvoreBST();

    No *getRaiz();

    void insereElemento(int chave);

    void insereAux(No *no, int chave);

    void emOrdem(No *no);

    void preOrdem(No *no);

    void posOrdem(No *no);

    int imprimeAlturaArvore(No *no);

    No *pesquisaElemento(No *no, int chave);

    int contaNos(No *no);

    int contaFolhas(No *no);

    int valorMinimo(No *no);

    int valorMaximo(No *no);

    bool removeElemento(int chave);
};
