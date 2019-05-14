/*
	Nama 	  : Muhamad Fahrul Azimi
	NPM		  : 140810180027
	Deskripsi : Program ini dibuat untuk binary search tree
	Tanggal	  : 14 Mei 2019
*/

// nama file : exercise-03.cpp
#include <iostream>
#include <conio.h>
using namespace std;

struct Simpul{
    int info;
    Simpul *right;
    Simpul *left;
};

typedef Simpul *pointer;
typedef pointer Tree;

void insertBST(Tree &Root, pointer pBaru){
    if (Root == NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->left, pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->right, pBaru);
    else
        cout << "sudah ada";
}

void CreateSimpul(pointer &pBaru){
    pBaru = new Simpul;
    cout << "Masukkan satu angka : ";
    cin >> pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void preOrder(Tree Root){
    if (Root != NULL){
        cout << Root->info  << " ";
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder(Tree Root){
    if (Root != NULL){
        inOrder(Root->left);
        cout << Root->info  << " ";
        inOrder(Root->right);
    }
}

void postOrder(Tree Root){
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout << Root->info << " ";
    }
}

void notasiKurung(Tree Root){
    if (Root != NULL){
        cout << "(" << Root->info << " ";
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout << ")";
    }
}

int main(){
	int n,pil;
    pointer p;
    Tree root;
    root = NULL;
    cout << "Banyak Simpul : "; cin >> n;
	for(int i; i<n; i++){
		CreateSimpul(p);
    	insertBST(root, p);
	}
	notasiKurung(root);
	do{
		cout <<endl;
		cout << "======MENU======" <<endl;
		cout << "1. PreOrder" <<endl;
		cout << "2. InOrder" <<endl;
		cout << "3. PostOrder" <<endl;
		cout << "4. Exit" <<endl;
		cout << "================";
		cout << "\nPilih : "; cin >> pil;
		switch (pil){
			case 1 :
			system("cls");
			cout << "=====PREORDER=====" <<endl;
			preOrder(root);
			break;
			case 2 :
			system("cls");
			cout << "=====INORDER=====" <<endl;
			inOrder(root);
			break;
			case 3 :
			system("cls");
			cout << "=====POSTORDER=====" <<endl;
			postOrder(root);
			break;
			case 4 :
			cout << "\n^^Terima Kasih Telah Menggunakan Program Ini^^";
			break;
			default :
			cout << "\n^^ANGKA YANG ANDA INPUT SALAH^^" <<endl;
            cout << "^^Tekan <Enter> Untuk Mengulang^^";
            getch();
			break;
		}
	}while(pil!=4);
}
