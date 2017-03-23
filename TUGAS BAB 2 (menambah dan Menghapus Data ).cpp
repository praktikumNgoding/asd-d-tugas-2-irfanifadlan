#include <iostream>
#include <cstdlib>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head;

int cek();
void masuk_depan(int dtbaru);
void hapus_depan();
void masuk_belakang(int dtbaru);
void hapus_belakang();
void tampil_data();
int main(){
	
	char hasil;
	int p;
	do{
	int dtbaru;
	cout << "MENU : \n";
	cout<<"1. Tambah data depan"<<endl;
	cout<<"2. Hapus data depan"<<endl;
	cout<<"3. Tambah data belakang"<<endl;
	cout<<"4. Hapus data belakang"<<endl;
	cout<<"5. Tapilkan data"<<endl;
	cout<<"99. Keluar dari program"<<endl;
		cout<<"Masukkan pilihan anda = ";
		cin>>p;
		cout<<endl;
	switch (p){
		case 1 :
			masuk_depan(dtbaru);
		break;
		case 2 :
			hapus_depan(); 
		break;	
		case 3 :
			masuk_belakang(dtbaru); 
		break;
		case 4 :
			hapus_belakang(); 
		break;
		case 5 :
			tampil_data(); 
		break;
		default :
		cout<<"Perintah tidak dikenali, silahkan ulangi \n\n";
		break;	
	}
	}
	while (p!=99);
	cout<<"\tProgram Dihentikan";
}
void masuk_depan(int dtbaru){
	cout<<"Data = ";
	cin>>dtbaru;
	node *baru;
	baru = new node;
	baru->data = dtbaru;
	baru->next = NULL;
	if(cek()==1){
		head = baru;
		head->next = NULL;
	}
	else{
		baru->next = head;
		head = baru;
	}
	cout<<"\nData dimasukkan\n";
}
void hapus_depan(){
	node *hapus;
	int y;
	if(cek()==0){
		if(head->next != NULL){
			hapus=head;
			y=hapus->data;
			head = head->next;
			delete hapus;
		}
		else{
			y= head->data;
			head=NULL;
		}
		cout <<y<< "Data terhapus\n";
	}
	else cout<<"Data masih kosong\n";
}

void masuk_belakang (int dtbaru){
	cout<<"Data = ";
	cin>>dtbaru;
	node *baru, *bantu;
	baru = new node;
	baru -> data = dtbaru;
	baru -> next = NULL;
	if (cek() == 1){
		head = baru;
		head -> next = NULL;
	}else{
		bantu = head;
		while (bantu->next != NULL){
			bantu=bantu->next;
		}
		bantu -> next = baru;
	}
	cout <<"Data telah masuk\n";
}
void hapus_belakang(){
	node *hapus,*bantu;
	int d;
	if (cek () == 0){
		if (head->next != NULL ){
			bantu = head;
			while (bantu->next->next != NULL){
				bantu = bantu ->next;
			}
			hapus = bantu->next;
			d = hapus -> data;
			bantu->next = NULL;
			delete hapus;
		}
		else{
			d = head -> data;
			head = NULL;
		}
		cout<<"Data terhapus\n";
	} 
	else cout<<"Data masih kosong\n";
}
void tampil_data(){
	node *bantu;
	bantu = head;
	if(cek() == 0){
		cout<<"\nData =\n";
		while(bantu !=NULL){
			cout<<"\t"<<bantu->data<<" ";
			bantu=bantu->next;
		}
		cout<<endl;
	} 
	else cout<<"Data masih kosong\n";
}
int cek(){
	if (head==NULL){
	return 1;
	}
	else {
	return 0;
	}
}
