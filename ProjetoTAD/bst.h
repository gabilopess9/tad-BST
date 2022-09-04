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
    
    No *pesquisarRec(No *no, int chave);
    
    No *pesquisarIter(No *no, int chave);
    
    int qdeNos(No *no);

    int alturaBST(No *no);

    int min(No *no);

    int max(No *no);
    
    int folhas(No *no);
    
    bool removerFolha(int chave);
};
