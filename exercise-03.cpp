/*
Nama : Aprischa Nauva
NPM  : 140810180063
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Simpul{
    int info;
    Simpul* kiri;
    Simpul* kanan;
};

typedef Simpul* pointer;
typedef pointer Tree;

void createTree(Tree& Root){
    Root=NULL;
}

void CreateSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cout << "Input angka : ";
    cin >> pBaru->info;
    pBaru->kiri = NULL;
    pBaru->kanan = NULL;
}

void insertBST (Tree& Root, pointer pBaru){
    if ( Root == NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->kiri,pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->kanan, pBaru);
    else
        cout << "Sudah ada";
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<endl;
        preOrder(Root->kiri);
        preOrder(Root->kanan);
    }
}

void inOrder (Tree Root) {
     if (Root != NULL){
          inOrder(Root->kiri);
          cout<< Root->info <<endl;
          inOrder(Root->kanan);
     }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->kiri);
        postOrder(Root->kanan);
        cout<< Root->info <<endl;
    }
}

void notasiKurung(Tree Root){
    if(Root!=NULL){
        cout << "(";
        cout << Root->info;
        notasiKurung(Root->kiri);
        notasiKurung(Root->kanan);
        cout << ")";
    }
}

int main()
{
    Tree Root;
    pointer pBaru;
    int pil;
    createTree(Root);
    int n;
    cout << "Input banyak elemen : ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
            CreateSimpul(pBaru);
            insertBST(Root,pBaru);
    }
    notasiKurung(Root);
    system("pause");
     do{
      system("cls");
      cout << "1. Insert" << endl;
      cout << "2. Preorder" << endl;
      cout << "3. Inorder" << endl;
      cout << "4. Postorder "<< endl;
      cout << "5. Exit "<<endl;
      cout << "Input pilihan : ";
      cin >> pil;
      switch(pil){
           case 1:
            CreateSimpul(pBaru);
            insertBST(Root,pBaru);
            notasiKurung(Root);
            system("pause");
           break;
           case 2:
            preOrder(Root);
            system("pause");
           break;
           case 3:
            inOrder(Root);
            system("pause");
            break;
           case 4:
            postOrder(Root);
            system("pause");
           break;
           case 5:
            return 0;
           break;
          }
    }while(pil!=5);

    return 0;
}
