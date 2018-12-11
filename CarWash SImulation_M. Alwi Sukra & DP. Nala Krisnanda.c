#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct antre{
	char nama[10];
	int tipe;
	int umur;
	struct antre *next;
}*startSatu = NULL, *startDua = NULL, *startTiga = NULL, *startEmpat = NULL, *startLima = NULL;

void tampilkan();
void menu(int *pm);
void menuTerpilih(int mt,int *exit);
void continuesButton();
int cekNama(char alias[], int *flag);
int tipeCuci();
void countAntre();
void countUmur();
void enqueue(char alias[],int tipe);
int pilih();
void enq(struct antre *make, struct antre *temp, int choice);
void notif(char alias[], int tipe);
void simulasiWaktu();
void checkUmurStart();
void dequeue(int pilih);
void tambahPendapatan(int pilih);
void keluarin(int flag,char alias[]);
int out(char alias[], struct antre* temp);
void tampilanAwal();
void judul();
void petunjuk();
int isEmpty();

int jumlahAntre[5];
int jumlahUmurAscending[5];
int jumlahUmur[5];
int age[3] = {20,30,40};
int harga[3] ={40000,50000,60000};
int clock = 10;
int antrean;
int jumlah_pendapatan;
int jumlah_waktu;

int main(){
	int pilih_menu,exit;
	
	tampilanAwal();

	do{
		system("cls");
		judul();
		tampilkan();
		menu(&pilih_menu);
		menuTerpilih(pilih_menu,&exit);
	}while(exit != 1);

	return 0;
}

void tampilkan(){
	struct antre *temp1,*temp2,*temp3,*temp4,*temp5;

	printf("\nTempat Cuci 1 ");
	if(startSatu == NULL){
		printf("( Kosong )");
	}else{
		temp1 = startSatu;
		printf("( %s, waktu sisa : %d menit) ",temp1->nama,temp1->umur);
		temp1 = temp1->next;
		while(temp1 != NULL){
			printf("<-- %s ",temp1->nama);
			temp1 = temp1->next;
		}		
	}
	
	printf("\nTempat Cuci 2 ");
	if(startDua == NULL){
		printf("( Kosong )");
	}else{
		temp2 = startDua;
		printf("( %s, waktu sisa : %d menit) ",temp2->nama,temp2->umur);
		temp2 = temp2->next;
		while(temp2 != NULL){
			printf("<-- %s ",temp2->nama);
			temp2 = temp2->next;
		}		
	}
	
	printf("\nTempat Cuci 3 ");
	if(startTiga == NULL){
		printf("( Kosong )");
	}else{
		temp3 = startTiga;
		printf("( %s, waktu sisa : %d menit) ",temp3->nama,temp3->umur);
		temp3 = temp3->next;
		while(temp3 != NULL){
			printf("<-- %s ",temp3->nama);
			temp3 = temp3->next;
		}		
	}
	
	printf("\nTempat Cuci 4 ");
	if(startEmpat == NULL){
		printf("( Kosong )");
	}else{
		temp4 = startEmpat;
		printf("( %s, waktu sisa : %d menit) ",temp4->nama,temp4->umur);
		temp4 = temp4->next;
		while(temp4 != NULL){
			printf("<-- %s ",temp4->nama);
			temp4 = temp4->next;
		}		
	}
	
	printf("\nTempat Cuci 5 ");
	if(startLima == NULL){
		printf("( Kosong )");
	}else{
		temp5 = startLima;
		printf("( %s, waktu sisa : %d menit) ",temp5->nama,temp5->umur);
		temp5 = temp5->next;
		while(temp5 != NULL){
			printf("<-- %s ",temp5->nama);
			temp5 = temp5->next;
		}		
	}
	printf("\nPendapatan hari ini : Rp.%d",jumlah_pendapatan);
}

void menu(int *pm){
	printf("\n\nMenu :\n");
	printf("1. Tambah Mobil Untuk Dicuci\n");
	printf("2. Keluarkan Mobil Dari Antrian\n");
	printf("3. simulasi waktu ( %d menit)\n",clock);
	printf("4. Petunjuk\n");
	printf("5. Selesai\n");
	do{
		printf("pilihan : ");scanf("%d",pm);
		if(*pm<1 || *pm>5){
			printf("pilihan diantara 1 - 5, silahkan isi lagi.\n");
		}
	}while(*pm<1 || *pm>5);
	
}

void menuTerpilih(int mt, int *exit){
	char alias[15];int dec, tipe, temp_waktu,flag,pil;
	switch(mt){
		case 1:
			do{
				printf("\nmasukkan nama (sebagai identitas dari mobil) :");scanf("%s",&alias);
				dec = cekNama(alias,&flag);
				if(dec != 0){
					printf("ada nama pemilik mobil yang sama. silahkan isi dengan nama yang berbeda.\n");
				}
			}while(dec != 0);
			tipe = tipeCuci();
			if(tipe == 4){break;}
			enqueue(alias, tipe);
			notif(alias, tipe);
			continuesButton();
			*exit = 0;
			break;
		case 2:
			pil = isEmpty();
			if(pil == 0){
				printf("tidak ada mobil.");
				continuesButton();
				break;
			}
			do{
				flag = 0;
				printf("\nmasukkan nama pemilik mobil yang mobilnya ingin dikeluarkan (jika tidak jadi isi 0) : ");scanf("%s",&alias);
				if(alias[0]=='0'){
					break;
				}
				dec = cekNama(alias,&flag);
				if(dec == 0){
					printf("tidak ada mobil dengan nama pemilik tersebut. silahkan isi dengan nama yang berbeda.\n");
				}
			}while(dec == 0);
			keluarin(flag,alias);
			*exit = 0;
			break;
		case 3:
			simulasiWaktu();
			*exit = 0;
			break;
		case 4:
			petunjuk();
			*exit = 0;
			continuesButton();
			break;
		case 5:
			pil = isEmpty();
			if(pil != 0){
				printf("masih ada mobil yang sedang dicuci. tidak bisa keluar dari program.\n");
				continuesButton();
				*exit = 0;
				break;	
			}
			*exit = 1;
			system("cls");
			printf("Hari ini, dengan total waktu kerja %d menit, didapat penghasilan sebesar Rp.%d\n",jumlah_waktu,jumlah_pendapatan);
			printf("THANK YOU!!!\n\n");
			judul();	
			break;
	}
}

void continuesButton(){
	printf("\nTekan apapun untuk melanjutkan!");
	getch();
}

int cekNama(char alias[], int *flag){
	struct antre *temp1,*temp2,*temp3,*temp4,*temp5;
	temp1 = startSatu;
	temp2 = startDua;
	temp3 = startTiga;
	temp4 = startEmpat;
	temp5 = startLima;
	
	int check = 0;

	if(temp1 != NULL){
		while(temp1 != NULL){
			if(strcmp(alias,temp1->nama) == 0){
				check++;
				*flag = 1;	
			}
			temp1 = temp1->next;
		}	
	}
	if(temp2 != NULL){
		while(temp2 != NULL){
			if(strcmp(alias,temp2->nama) == 0){
				check++;
				*flag = 2;
			}
			temp2 = temp2->next;
		}	
	}
	if(temp3 != NULL){
		while(temp3 != NULL){
			if(strcmp(alias,temp3->nama) == 0){
				check++;
				*flag = 3;	
			}
			temp3 = temp3->next;
		}	
	}
	if(temp4 != NULL){
		while(temp4 != NULL){
			if(strcmp(alias,temp4->nama) == 0){
				check++;
				*flag = 4;	
			}
			temp4 = temp4->next;
		}	
	}
	if(temp5 != NULL){
		while(temp5 != NULL){
			if(strcmp(alias,temp5->nama) == 0){
				check++;
				*flag = 5;	
			}
			temp5 = temp5->next;
		}	
	}
	return check;
}

int tipeCuci(){
	int ch;
	printf("\nNo.\t| Tipe\t\t\t\t| Lama Pengerjaan\t| harga\n");
	printf("1.\t| Standard\t\t\t| %d menit\t\t| Rp.%d\n",age[0],harga[0]);
	printf("2.\t| Standard + Kolong\t\t| %d menit\t\t| Rp.%d\n",age[1],harga[1]);
	printf("3.\t| Standard + Kolong + Mesin\t| %d menit\t\t| Rp.%d\n",age[2],harga[2]);
	printf("4. Tidak Jadi\n");
	do{
		printf("Pilihan : ");scanf("%d",&ch);
		if(ch<1 || ch>4){
			printf("pilihan diantara 1 - 4, silahkan isi lagi.\n");
		}
	}while(ch<1 || ch>4);
	return ch;
}

void countAntre(){
	
	int count;
	struct antre *temp1,*temp2,*temp3,*temp4,*temp5;
	temp1 = startSatu;
	temp2 = startDua;
	temp3 = startTiga;
	temp4 = startEmpat;
	temp5 = startLima;
	
	count = 0;
	while(temp1 != NULL){
		temp1 = temp1->next;
		count++;
	}
	jumlahAntre[0] = count;
	
	count = 0;
	while(temp2 != NULL){
		
		temp2 = temp2->next;
		count++;
		
	}
	jumlahAntre[1] = count;
	
	count = 0;
	while(temp3 != NULL){
		temp3 = temp3->next;
		count++;
	}
	jumlahAntre[2] = count;
	
	count = 0;
	while(temp4 != NULL){
		temp4 = temp4->next;
		count++;
	}
	jumlahAntre[3] = count;
	
	count = 0;
	while(temp5 != NULL){
		temp5 = temp5->next;
		count++;
	}
	jumlahAntre[4] = count;
}

void countUmur(){
	struct antre *temp1,*temp2,*temp3,*temp4,*temp5;
	temp1 = startSatu;
	temp2 = startDua;
	temp3 = startTiga;
	temp4 = startEmpat;
	temp5 = startLima;
	
	jumlahUmur[0] = 0;jumlahUmur[1] = 0;jumlahUmur[2] = 0;jumlahUmur[3] = 0;jumlahUmur[4] = 0;
	
	if(startSatu == NULL){
		jumlahUmur[0] = 0;
	}else{
		while(temp1!=NULL){
			jumlahUmur[0] += temp1->umur;
			temp1 = temp1->next;
		}	
	}
	if(startDua == NULL){
		jumlahUmur[1] = 0;
	}else{
		while(temp2!=NULL){
			jumlahUmur[1] += temp2->umur;
			temp2 = temp2->next;
		}
	}
	if(startTiga == NULL){
		jumlahUmur[2] = 0;
	}else{
		while(temp3!=NULL){
			jumlahUmur[2] += temp3->umur;
			temp3 = temp3->next;
		}
	}
	if(startEmpat == NULL){
		jumlahUmur[3] = 0;
	}
	else{
		while(temp4!=NULL){
			jumlahUmur[3] += temp4->umur;
			temp4 = temp4->next;
		}
	}
	if(startLima == NULL){
		jumlahUmur[4] = 0;
	}else{
		while(temp5!=NULL){
			jumlahUmur[4] += temp5->umur;
			temp5 = temp5->next;
		}
	}
}

void enqueue(char alias[], int tipe){
	int choice;
	
	struct antre *make, *temp;
	make = (struct antre*)malloc(sizeof(struct antre));
	
	if(make == NULL){
		printf("\nerror, tidak tersedia memori\n");
	}else{
		strcpy(make->nama,alias);
		make->next = NULL;
		switch(tipe){
			case 1:
				make->tipe = 1;
				make->umur = age[0];
				break;
			case 2:
				make->tipe = 2;
				make->umur = age[1];
				break;
			case 3:
				make->tipe = 3;
				make->umur = age[2];	
		}
	}
	
	countUmur();
	choice = pilih();
	switch(choice){
		case 0:
			temp = startSatu;
			enq(make,temp,choice);
			break;
		case 1:
			temp = startDua;
			enq(make,temp,choice);
			break;
		case 2:
			temp = startTiga;
			enq(make,temp,choice);
			break;
		case 3:
			temp = startEmpat;
			enq(make,temp,choice);
			break;
		case 4:
			temp = startLima;
			enq(make,temp,choice);
			break;
	}
}

int pilih(){
	int c, d, swap;
	jumlahUmurAscending[0] = jumlahUmur[0];
	jumlahUmurAscending[1] = jumlahUmur[1];
	jumlahUmurAscending[2] = jumlahUmur[2];
	jumlahUmurAscending[3] = jumlahUmur[3];
	jumlahUmurAscending[4] = jumlahUmur[4];
	
	for (c = 0 ; c < 4; c++){
    	for (d = 0 ; d < 4 - c ; d++){
      		if (jumlahUmurAscending[d] > jumlahUmurAscending[d+1]){
        		swap = jumlahUmurAscending[d];
        		jumlahUmurAscending[d] = jumlahUmurAscending[d+1];
        		jumlahUmurAscending[d+1] = swap;
      		}
    	}
	}
	for (c = 0; c < 5; c++){
    	if (jumlahUmur[c] == jumlahUmurAscending[0]){
        	break;
    	}
	}
	antrean = c;
  	return c;
}

void enq(struct antre *make, struct antre *temp, int choice){
	
	if(temp == NULL){
		switch(choice){
		case 0:
			startSatu = make;
			break;
		case 1:
			startDua = make;
			break;
		case 2:
			startTiga = make;
			break;
		case 3:
			startEmpat = make;
			break;
		case 4:
			startLima = make;
			break; 
		}
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		make->next = NULL;
		temp->next = make;		
	}	
}			

void simulasiWaktu(){
	if(startSatu != NULL){
		startSatu->umur -= clock;
	}
	if(startDua != NULL){
		startDua->umur -= clock;
	}
	if(startTiga != NULL){
		startTiga->umur -= clock;
	}
	if(startEmpat != NULL){
		startEmpat->umur -= clock;
	}
	if(startLima != NULL){
		startLima->umur -= clock;
	}
	checkUmurStart();
}

void notif(char alias[], int tipe){
	int temp_waktu;
	printf("\nmobil %s berhasil ditambahkan, perkiraan lama waktu hingga selesai adalah",alias);
	switch(tipe){
		case 1:
			temp_waktu = age[0];break;
		case 2:
			temp_waktu = age[1];break;
		case 3:
			temp_waktu = age[2];break;	
		}
	switch(antrean){
		case 0:
			printf(" %d menit.\n",jumlahUmur[0]+temp_waktu);break;
		case 1:
			printf(" %d menit.\n",jumlahUmur[1]+temp_waktu);break;
		case 2:
			printf(" %d menit.\n",jumlahUmur[2]+temp_waktu);break;
		case 3:
			printf(" %d menit.\n",jumlahUmur[3]+temp_waktu);break;
		case 4:
			printf(" %d menit.\n",jumlahUmur[4]+temp_waktu);break;
		}
}

void checkUmurStart(){
	if(startSatu != NULL){
		if(startSatu->umur == 0){
			dequeue(0);
		}
	}
	if(startDua != NULL){
		if(startDua->umur == 0){
			dequeue(1);
		}
	}
	if(startTiga != NULL){
		if(startTiga->umur == 0){
			dequeue(2);
		}
	}
	if(startEmpat != NULL){
		if(startEmpat->umur == 0){
			dequeue(3);
		}
	}
	if(startLima != NULL){
		if(startLima->umur == 0){
			dequeue(4);
		}
	}
}

void dequeue(int pilih){
	struct antre *temp;
	switch(pilih){
		case 0:
			tambahPendapatan(startSatu->tipe);
			temp = startSatu;
			startSatu = startSatu->next;
			free(temp);
			break;
		case 1:
			tambahPendapatan(startDua->tipe);
			temp = startDua;
			startDua = startDua->next;
			free(temp);
			break;
		case 2:
			tambahPendapatan(startTiga->tipe);
			temp = startTiga;
			startTiga = startTiga->next;
			free(temp);
			break;
		case 3:
			tambahPendapatan(startEmpat->tipe);
			temp = startEmpat;
			startEmpat = startEmpat->next;
			free(temp);
			break;
		case 4:
			tambahPendapatan(startLima->tipe);
			temp = startLima;
			startLima = startLima->next;
			free(temp);
			break;
	}
}

void tambahPendapatan(int pilih){
	switch(pilih){
		case 1:
			jumlah_pendapatan += harga[0];break;
			jumlah_waktu += age[0];
		case 2:
			jumlah_pendapatan += harga[1];break;
			jumlah_waktu += age[1];
		case 3:
			jumlah_pendapatan += harga[2];break;
			jumlah_waktu += age[2];
	}
}

void keluarin(int flag, char alias[]){
	struct antre *temp1,*temp2,*temp3,*temp4,*temp5; 
	temp1 = startSatu;
	temp2 = startDua;
	temp3 = startTiga;
	temp4 = startEmpat;
	temp5 = startLima;
	
	switch(flag){
		case 1:
			out(alias,temp1);
			break;
		case 2:
			out(alias,temp2);
			break;
		case 3:
			out(alias,temp3);
			break;
		case 4:
			out(alias,temp4);
			break;
		case 5:
			out(alias,temp5);
			break;	
	}
	continuesButton();	
}

int out(char alias[], struct antre* temp){
	struct antre *freed;
	if(strcmp(alias,temp->nama) == 0){
		printf("\nmobil yang sedang dalam pencucian tidak bisa dikeluarkan, silahkan menunggu sebentar.\n");
	}else{
		while(strcmp(alias,temp->next->nama)!=0){
			temp = temp->next;
		}
		freed = temp->next;
		temp->next = temp->next->next;
		free(freed);
	}
}

void tampilanAwal(){
	judul();
	petunjuk();
	continuesButton();
	system("cls");
}

void judul(){
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("**** CARWASH SIMULATION ****\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void petunjuk(){
	printf("\nPetunjuk Penggunaan Program : \n");
	printf("-> Akan ditampilkan selalu tabel yang berisi list mobil masing masing tempat cuci\n");
	printf("-> Untuk menambah mobil yang ingin dicuci pilih 1 pada menu\n");
	printf("-> Untuk mengeluarkan mobil dari antrian pilih 2 pada menu\n");
	printf("-> Untuk menjalankan simulasi selama 10 menit pilih 3 pada menu\n");
	printf("-> Untuk melihat petunjuk pilih 4 pada menu\n");
	printf("-> Untuk keluar dari program pilih 5 pada menu\n");
	}
	
int isEmpty(){
	int check;
	if(startSatu != NULL){
			check++;	
	}
	if(startDua != NULL){
			check++;
	}
	if(startTiga != NULL){
			check++;
	}
	if(startEmpat != NULL){
			check++;
	}
	if(startLima != NULL){
			check++;
	}
	return check;
}

