/*
	Nama 	  : Muhamad Fahrul Azimi
	NPM		  : 140810180027
	Deskripsi : Program ini dibuat untuk queue linkedlist
	Tanggal	  : 14 Mei 2019
*/

// nama file : exercise-02.cpp
#include <iostream>
using namespace std;

struct Element{
	char info;
	Element* next;
};

typedef Element* pointer;
typedef pointer List;

struct Queue{
	List Head;
	List Tail;
};
Queue Q;

void createList(Queue& Q){
	Q.Head=NULL;
	Q.Tail=NULL;
}

void createElement(pointer& pBaru){
	pBaru=new Element;
	cout << "Masukkan satu huruf : "; cin >> pBaru->info;
	pBaru->next=NULL;
}

void cetak(Queue Q){
	pointer pBantu=Q.Head;
    if(Q.Head == NULL && Q.Tail == NULL){
        cout << "\n\t***Data masih kosong***" << endl;
    }else{
        while(pBantu != NULL){
            cout << pBantu->info;
            pBantu=pBantu->next;
            cout << " ";
        }
    }
}

void insertQueue( Queue& Q, pointer pBaru){
    if (Q.Head==NULL && Q.Tail==NULL) { // kosong
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else { // ada isi
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(Queue& Q, pointer& pHapus){
    cout<<"Delete Queue"<<endl;
    if (Q.Head==NULL && Q.Tail==NULL) { //kasus kosong
        pHapus=NULL;
        cout<<"List Queue kosong "<<endl;
    }
    else if (Q.Head->next==NULL) { // kasus isi 1 elemen
        pHapus=Q.Head;
        Q.Head=NULL;
        Q.Tail=NULL;
    }
    else { // kasus > 1 elemen
        pHapus=Q.Head;
        Q.Head=Q.Head->next;
        pHapus->next=NULL;
    }
}

int main(){
    pointer p;
    List a;
    int n;

    createList(Q);
    cout<<"Masukkan Banyak elemen : ";cin >> n;
    for(int i = 0; i < n; i++)
    {
        createElement(p);
        insertQueue(Q,p);
    }
    cetak(Q);
}

