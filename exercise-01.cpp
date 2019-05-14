/*
	Nama 	  : Muhamad Fahrul Azimi
	NPM		  : 140810180027
	Deskripsi : Program ini dibuat untuk queue array
	Tanggal	  : 14 Mei 2019
*/

// nama file : exercise-01.cpp
#include<iostream>
using namespace std;

const int maxElemen = 255;

struct Queue{
	char isi[maxElemen];
	int head;
	int tail;
};
Queue q;

void createQueue (Queue& q){
	q.head = 0;
	q.tail = -1;
}

void createElement(char& elemen){
    cout << "Input Angka : "; cin >> elemen;
}

void insertQueue (Queue& q, char elemen){
	if (q.tail==maxElemen-1){
		cout << "Antrian sudah penuh" <<endl;
	}
	else{
		q.tail=q.tail + 1;
		q.isi[q.tail] = elemen;
	}
}

void deleteQueue (Queue& q, char& elemenHapus){
	if(q.head>q.tail){
		cout << "Antrian kosong" <<endl;
	}
	else{
		elemenHapus = q.isi[q.head];
		for (int i=0; i<q.tail; i++){
			q.isi[i]=q.isi[i+1];
		}
		q.tail=q.tail-1;
	}
}

void reverseQueue (Queue q){
	for (int i=q.tail; i>=0; i--){
		cout << q.isi[i] << " ";
	}
}

void traversal (Queue q){
	if(q.head == -1){
		cout<<"Queue Kosong"<<endl;
	}
	else{
	for (int i=q.head; i<=q.tail; i++){
		cout << q.isi[i] << " ";
		}
	}
}

int main(){
	char a,ambil;
	int n;
	createQueue(q);
	cout << "Banyak element : "; cin >> n;
    for (int i=0;i<n;i++){
        createElement(a);
        insertQueue(q,a);
    }
    cout <<endl;
    cout << "Input  : " <<endl;
	traversal(q);
	cout <<endl;
	for(int i=0;i<n;i++){
		deleteQueue(q,ambil);
		cout << ambil << " ";
	}
}
