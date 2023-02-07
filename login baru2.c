#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

static int i=0;
struct {
	char name[30],pass[30];
}w[99];
int n;
void login(void);
void reg(void);

void daftar(){
	system("@cls||clear");
	printf("=================================================\n");
	printf("\t\tKelompok 2\n");
	printf("\t     Anggota Kelompok :\n");
	printf("    Albertus Bima Krisnawan (672020095)\n");
	printf("Mikha Kurnia Anggi Purbaningtyas (672020109)\n");
	printf("=================================================\n");
	system("pause");
  	system("@cls||clear");
	XY:	
		printf("=================================\n");
		printf("SILAHKAN PILIH MENU YANG TERSEDIA\n");
		printf("\t1. LOGIN\n");
		printf("\t2. DAFTAR\n");
		printf("=================================\n");
		printf("PILIHAN KAMU: ");
		scanf("%d",&n);
		switch(n){
    		case 1: system("@cls||clear");
    	    	login();
    	    	break;
    		case 2: system("@cls||clear");
     	   		reg();
        		break;
  	  		default: printf("MENU TIDAK DITEMUKAN!!!");
  	  			system("pause");
      		  	main();
      	 	goto XY;
 		}
}
void reg(){
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("login.txt","w");
    printf("DAFTARKAN AKUNMU SEKARANG");
    printf("\n======================");

    for(i=0;i<100;i++){
      	printf("\nMASUKKAN USERNAME: ");               
      	scanf("%s",checker);
        while(!feof(fp)){
        	fread(&w[i],sizeof(w[i]),1,fp);
          	if(strcmp(checker,w[i].name)==0){
            	printf("USERNAME TELAH TERPAKAI");
            	system("@cls||clear");
            	reg();
            }
        	else{
           	 	strcpy(w[i].name,checker);
           		break;
       		}
        }
   		printf("MASUKKAN PASSWORD: ");
      	while((c=getch())!=13){
          	w[i].pass[z++]=c;
          	printf("%c",'*');
        }
      	fwrite(&w[i],sizeof(w[i]),1,fp);
      	fclose(fp);
        system("@cls||clear");
		printf("=============================\n");
        printf("AKUN KAMU SUDAH TEREGRISTRASI\n");
    	printf("=============================\n");
        printf("MAU COBA AKUN KAMU UNTUK LOGIN?\n");
        printf("TEKAN 1 UNTUK COBA AKUN\nTEKAN 2 UNTUK LANGSUNG KE MENU UTAMA\n");
        printf("PILIHAN KAMU : ");
        scanf("%d",&n);
       	switch(n){
            case 1: system("@cls||clear");
                login();
                break;
            case 2: system("@cls||clear");
                printf("TERIMA KASIH TELAH MENDAFTAR!!");
                break;
        	}break;
    }getch();
}

void login(){
    FILE *fp;
    char c,name[30],pass[30]; int z=0;
    int checku,checkp;
    fp=fopen("login.txt","r");
	printf("========================================\n");
    printf("SILAHKAN MASUKKAN USERNAME DAN PASSWORD:\n");
    printf("========================================\n");
    for(i=0;i<1000;i++){
    	printf("\nMASUKKAN USERNAME: ");
        scanf("%s",name);
        printf("MASUKKAN PASSWORD: ");
        while((c=getch())!=13){
          	pass[z++]=c;
          	printf("%c",'*');
        }
        pass[z]='\0';
      	while(!feof(fp)){
        	fread(&w[i],sizeof(w[i]),1,fp);
          	checku=strcmp(name,w[i].name);
          	checkp=strcmp(pass,w[i].pass);
          	if(checku==0&&checkp==0){
            	system("@cls||clear");
            	animasijadi();
            	break;
          	}
        	else if(checku==0&&checkp!=0){
            	printf("\nGAGAL MASUK!!\n");
            	login();
          	}
        	else if(checku!=0){
            	printf("\nUSERNAME DAN PASSWORD KAMU TIDAK TERDAFTAR!!!\n");
            	if(getch()==13)
            	system("@cls||clear");
            	reg();
          	}
        }
        break;
    }
      getch();
}

//ANIMASI

// kecepatan animasi
void tunggu( unsigned int a){
    unsigned int b;
    unsigned int c;

    for(b = 500; b < a ; b++ ){
        for(c = 500; c < b ; c++ ){}
    }
}
// karakter animasi
const char animasi[] =
    " __    __      __      ___\n\
| |   | |     /  \\     | |  \n\
| |   | |    / /\\ \\    | | \n\
| |===| |   / /__\\ \\   | |  \n\
| |   | |  / ______ \\  | |  \n\
|_|   |_| /_/      \\_\\ |_|    \n\
";
int animasijadi(){

    int spasiatas;
    const int sometunggu = 7000;
    int spasibawah;

    //spasiatas= animasi bisa mulai dari bawah
    for (spasiatas = 0; spasiatas < 50; spasiatas++)
    {
        printf("\n");
    }

	//fputs = 
	//stdout = 
    fputs(animasi,stdout);

    for (spasibawah = 0; spasibawah < 50; spasibawah++)
    {
        // agar nyambung ke kecepatan animasi
        tunggu(sometunggu);
        
        // agar animasi naik
        printf("\n");
    }
    system("cls");
    menu1();
    return 0;
}

char file_name[] = "stok_barang.txt";
char delim[] = ";";
char data_barang[200][4][200];
int jml_data_barang = 0;

char *substring(char *string, int position, int length) {
   	char *pointer;
   	int c;
 
   	pointer = malloc(length+1);
   
   	if (pointer == NULL) {
      	printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
   	}
 
   	for (c = 0 ; c < length ; c++) {
      	*(pointer+c) = *(string+position-1);      
      	string++;  
   	}
 
   	*(pointer+c) = '\0';
 
   	return pointer;
}

void getData() {
	FILE *fp = fopen(file_name, "r");
    char line[200];
	
	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;  
	   
	if (fp == NULL) {
		printf("Gagal membuka file %s", file_name);
		exit(EXIT_FAILURE);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		int j = 0;
			while (token != NULL) {
				strcpy(data_barang[i][j], token);
				token = strtok(NULL, delim);
				j++;
			}
			
			i++;
			jml_data_barang++;
		}
	}
	fclose(fp);
}

void viewData() {
    getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf("Menu Lihat Data Barang\n");
   	printf("============================================\n");
    if (jml_data_barang > 0) {
        printf("Kode\tNama Barang\tHarga\tStok\n");
   		printf("============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][1]);
			
			if (strlen(nama_brg) > 15) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 15));
		   		
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][1], "\t");
			}
			
			int kode_brg = atoi(data_barang[i][0]);
            int harga_brg = atoi(data_barang[i][2]);
            int stok_brg = atoi(data_barang[i][3]);
            

            printf("%d\t%s\t%d\t%d \n",kode_brg,nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }
    printf("============================================\n");
    system("pause");
    menu_utama();
}

	/*Fungsi ini berguna untuk menambahkan data (string) ke file tujuan.
	fopen adalah fungsi untuk membuka file dan melakukan aksi (baca / edit / tambah).*/
bool addToFile(char inputan[]) {
	FILE *fp = fopen(file_name,"a+");
	if (fp == NULL) {
		return false;
	} else {
		fputs(inputan, fp);
	}
	fclose(fp);
	return true;
}

void tambahData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("Menu Tambah Data Barang\n");
   	printf("============================================\n");
   	
   	char nama[100], harga[50], stok[50], hasil[200], kode[50];
   	
	printf("Masukkan Nama Barang : ");
   	gets(nama);
   	if (strlen(nama) > 15) {
   		strcpy(nama, substring(nama, 1, 15));
	}
	
	printf("Masukkan Kode Barang : ");
   	gets(kode);
   	int kodee = atoi(kode);
   	if (kodee <= 0) kodee=0;
   	
   	printf("Masukkan Harga Barang : ");
   	gets(harga);
   	int hargaa = atoi(harga);
   	if (hargaa < 1000) hargaa = 1000;
   	else if (hargaa > 9999999) hargaa = 9999999;
   	
   	printf("Masukkan Stok Barang : ");
   	gets(stok);
   	int stokk = atoi(stok);
   	if (stokk < 1) stokk = 1;
   	else if (stokk > 10000) stokk = 10000;
   	
   	printf("============================================\n");
	snprintf(hasil, sizeof hasil, "%d;%s;%d;%d", kodee, nama, hargaa, stokk);
	if (jml_data_barang > 0) {
		FILE *fp = fopen(file_name, "r");
	    char line[200];
		   
		if (fp == NULL) {
			printf("Gagal membuka file %s", file_name);
			exit(EXIT_FAILURE);
		} else {
			bool ada = false, ada2 = false;
			int i = 0, j = 0, k = 0;
			char tampung[100][200];
			while (fgets(line, sizeof(line), fp) != NULL) {
				char *token = strtok(line, delim);
	    		j = 0;
				ada = false;
				while (token != NULL) {
					if (j == 0) {
						if (strcmp(data_barang[i][1],nama) == 0) {
							ada = true;
							ada2 = true; //memastikan jika ketemu
						}
					}
					token = strtok(NULL, delim);
				}
				
				if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s", data_barang[i][0], data_barang[i][1], data_barang[i][2], data_barang[i][3]);
					k++;
				}
				
				i++;
			}
			
			fclose(fp);
			
			if (ada2) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}	
				}
			}
			addToFile(hasil);
			printf("Sukses tambah barang\n");
		}
   	}
	printf("============================================\n");
	system("pause");
    menu_utama();
}

void hapusData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("Menu Hapus Data Barang\n");
   	printf("============================================\n");
   	char nama[100];
   	printf("Masukkan Nama Barang : ");
   	gets(nama);
	if (jml_data_barang > 0) {
		FILE *fp = fopen(file_name, "r");
	    char line[200];
		   
		if (fp == NULL) {
			printf("Gagal membuka file %s", file_name);
			exit(EXIT_FAILURE);
		} else {
			bool ada = false, ada2 = false;
			int i = 0, j = 0, k = 0;
			char tampung[100][200];
			while (fgets(line, sizeof(line), fp) != NULL) {
				char *token = strtok(line, delim);
	    		j = 0;
				ada = false;
				while (token != NULL) {
					if (j == 0) {
						if (strcmp(data_barang[i][1],nama) == 0) {
							ada = true;
							ada2 = true; //memastikan jika ketemu
						}
					}
					token = strtok(NULL, delim);
				}
				
				if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s", data_barang[i][0], data_barang[i][1], data_barang[i][2], data_barang[i][3]);
					k++;
				}
				
				i++;
			}
			
			fclose(fp);
			
			printf("============================================\n");
			if (ada2) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}	
				}
				printf("Sukses hapus (%s) dari data barang!\n",nama);
			} else {
				printf("Nama barang (%s) tidak ditemukan!\n",nama);
			}
		}
   	} else {
   		printf("============================================\n");
   		printf("Tidak ada data barang!\n");
    }
    
    printf("============================================\n");
    system("pause");
    menu_utama();
}

void transaksi () {
	getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf("Menu Lihat Data Barang\n");
   	printf("============================================\n");
    if (jml_data_barang > 0) {
        printf("Kode\tNama Barang\tHarga\tStok\n");
   		printf("============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][1]);
			
			if (strlen(nama_brg) > 15) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 15));
		   		
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][1], "\t");
			}
			
			int kode_brg = atoi(data_barang[i][0]);
            int harga_brg = atoi(data_barang[i][2]);
            int stok_brg = atoi(data_barang[i][3]);
            

            printf("%d\t%s\t%d\t%d \n",kode_brg,nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }

    int jml_barang, l, jumlah[100],harga, total[100], total_seluruh=0, bayar, kembalian, kekurangan;
	int kode[100], jum, q[100];
	char kod[100];
    
    
	scanf("%c");
	printf("============================================\n");
   	printf("\t  TOKO SPAREPART BAHAGIA\n");
   		time_t t = time(NULL);
  		struct tm tm = *localtime(&t);
  		printf("\t     Waktu Pembelian\n");
  		printf("\t\t%d-%02d-%02d \n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
		printf("\t\t%02d:%02d:%02d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);
			FILE *tr = fopen("struk.txt","a+");
			fprintf(tr,"=============================================\n");
			fprintf(tr,"%d-%02d-%02d(%02d:%02d:%02d)\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec);
			fclose(tr);
	printf("============================================\n");
	printf("Kasir\t\t\t\t: Junet\n");
   	printf("============================================\n");
   	printf("Banyak Jenis Barang yang Dibeli : ");
   	scanf("%d", &jml_barang);
   	printf("============================================\n");
   	
   	for(l=0; l<jml_barang; l++){
    	printf("Masukkan Kode Barang\t\t: ");
    	scanf(" %[^\n]%*c", &kod);
    		FILE *a = fopen("struk.txt","a+");
			fprintf(tr,"\n\t*Kode Barang\t    \t  : %s\n", kod);
			fclose(a);
   		printf("Jumlah Barang yang Dibeli\t: ");
   	 	scanf(" %d", &jum);	
    	printf("============================================\n");
   		if (jml_data_barang > 0) {
			FILE *fp = fopen(file_name, "r");
	   		char line[200];
		   
			if (fp == NULL) {
				printf("Gagal membuka file %s", file_name);
				exit(EXIT_FAILURE);
			}else {
				bool ada = false, ada2 = false;
				int i = 0, j = 0, k = 0, a = 0;
				char tampung[100][200], hasil[100][200];
				while (fgets(line, sizeof(line), fp) != NULL) {
					char *token = strtok(line, delim);
	    			j = 0;
					ada = false;
					while (token != NULL) {
							if (strcmp(data_barang[i][0],kod) == 0) {
								ada = true;
								ada2 = true;
								
							}
						token = strtok(NULL, delim);
					}
					if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s", data_barang[i][0], data_barang[i][1], data_barang[i][2], data_barang[i][3]);
					k++;
				}
					
					if(ada) {
						int stok = atoi(data_barang[i][3]);
						if(jum>stok){
							printf("\n\t   Jumlah Stok Hanya %d\n",stok);
							printf("     Membeli Makimal Stok yang Tersedia\n");
							printf("\n============================================\n");
							int harga = atoi(data_barang[i][2])*stok;
							printf("\n%s\t\t\t: ", data_barang[i][1]);
							printf("%d\n", harga);
/**/						snprintf(hasil[a], sizeof hasil[a], "%s;%s;%s;%d", data_barang[i][0],  data_barang[i][1],  data_barang[i][2], stok - atoi(data_barang[i][3]));
							a++;
				fclose(fp);
								FILE *b = fopen("struk.txt","a+");
								fprintf(tr,"\t   *Jumlah Barang\t  : %d\n", stok);
								fclose(b);
				FILE *fp = fopen(file_name, "r");
							total_seluruh += harga;
							printf("\n============================================\n");
						}else if(jum<=stok && jum>0){
							int harga = atoi(data_barang[i][2])*jum;
							printf("\n%s\t\t\t: ", data_barang[i][1]);
							printf("%d\n", harga);
/**/						snprintf(hasil[a], sizeof hasil[a], "%s;%s;%s;%d", data_barang[i][0],  data_barang[i][1],  data_barang[i][2], stok-jum);
							a++;
							printf("\n============================================\n");
				fclose(fp);
								FILE *b = fopen("struk.txt","a+");
								fprintf(tr,"\t   *Jumlah Barang\t  : %d\n", jum);
								fclose(b);
				FILE *fp = fopen(file_name, "r");
							total_seluruh += harga;		
						}	
					}
					
					if (ada==false) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s", data_barang[i][0], data_barang[i][1], data_barang[i][2], data_barang[i][3]);
					k++;
					}
					i++;
				}
				fclose(fp);
				
				if (ada2==true) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}	
				}
				
				}
				if (a>0){
					for(i=0; i<a; i++){
						addToFile(hasil[i]);
					}
				}
				
			}
   		}
   	}
		printf("\n\tTotal Harga = \t%d\n\n", total_seluruh);
			FILE *c = fopen("struk.txt","a+");
			fprintf(tr,"\n\t\t*Harga      \t  : %d\n", total_seluruh);
			fclose(c);
		printf("============================================\n");
		printf("Masukkan Jumlah Pembayaran\t: ");
		scanf("%d", &bayar);
			FILE *d = fopen("struk.txt","a+");
			fprintf(tr,"\t\t*Bayar      \t  : %d\n", bayar);
			fclose(d);
		kembalian = bayar - total_seluruh;
		if(bayar > total_seluruh){
			printf("Kembalian \t\t\t: %d\n", kembalian);
				FILE *e = fopen("struk.txt","a+");
				fprintf(tr,"\t\t*Kembalian  \t  : %d\n", kembalian);
				fclose(e);
		}else if(bayar == total_seluruh){
			printf("Uang Pas\n");
			printf("Terima Kasih");
				FILE *f = fopen("struk.txt","a+");
				fprintf(tr,"\t\t*Kekurangan \t  : 0\n");
				fclose(f);
		}else{
			kekurangan = -1*kembalian;
			printf("Kekurangan\t\t\t: %d\n",kekurangan);
				FILE *g = fopen("struk.txt","a+");
				fprintf(tr,"\t\t*Kekurangan \t  : %d\n", kekurangan);
				fclose(g);
			printf("Ingin Bayar Kekurangan?\n");
			printf("Ketik 1 untuk Bayar\n");
			printf("Ketik 2 untuk NGUTANG\n");
			printf("Jawaban Kamu \t\t\t: ");
			int jawab; 	
			scanf("%d", &jawab);
			
			int a1 = 1;
			int b1 = 2;
			int bayar1;
			if(jawab == a1){
				printf("Bayar Kekurangan\t\t: ");
				scanf("%d", &bayar1);
					FILE *h = fopen("struk.txt","a+");
					fprintf(tr,"\t\t-Bayar Kekurangan : %d\n", bayar1);
					fclose(h);
				int kembalian2;
				kembalian2 = bayar1 - kekurangan;
				printf("Kembalian\t\t\t: %d\n", kembalian2);
					FILE *i = fopen("struk.txt","a+");
					fprintf(tr,"\t\t-Kembalian\t  : %d\n", kembalian2);
					fclose(i);
			}else if(jawab == b1){
				printf("SORRY YE... DISINI GABISA NGUTANG!!\n");
				printf("Bayar Kekurangan\t\t: ");
				scanf("%d", &bayar1);
					FILE *h = fopen("struk.txt","a+");
					fprintf(tr,"\t\t-Bayar Kekurangan : %d\n", bayar1);
					fclose(h);
				int kembalian2;
				kembalian2 = bayar1 - kekurangan;
				printf("Kembalian\t\t\t: %d\n", kembalian2);
					FILE *i = fopen("struk.txt","a+");
					fprintf(tr,"\t\t-Kembalian\t  : %d\n", kembalian2);
					fclose(i);	
			}else{
				printf("TIDAK ADA PILIHAN!!!\n");
			}
		}system("pause");
	menu_utama();
}

void logout(){
	system("cls");
	printf("=======================================================\n");
	printf("TERIMA KASIH TELAH BERBELANJA DI TOKO SPAREPART BAHAGIA\n");	
	printf("=======================================================\n");
	system("pause");
	exit(0);
}



void menu(int pil) {
	if (pil == 1) viewData();
	else if (pil == 2) tambahData();
	else if (pil == 3) hapusData();
	else if (pil == 4) transaksi();
	else if (pil == 5) logout();
}

void menu_utama() {
	int pilihan = 0;
	while (pilihan == 0) {
		system("@cls||clear");
		printf("============================================\n");
		printf("\t\tMENU UTAMA\n");
		printf("============================================\n");
		printf("\t    1. Lihat Data Barang\n");
		printf("\t   2. Tambah Data Barang\n");
		printf("\t   3. Hapus Data Barang\n");
		printf("\t        4. Transaksi\n");
		printf("\t         5. Logout\n");
		printf("\t          6. Exit\n");
		printf("\t       Pilih Menu : ");
		scanf("%d",&pilihan);
		if (pilihan <= 0 || pilihan > 6) {
			pilihan = 0;
			system("@cls||clear");
			printf("Pilihan Menu Salah!");
			system("pause");
		}
	}
	
		if (pilihan == 6) exit(EXIT_SUCCESS);
		else menu(pilihan);
}

int menu1(){
	getData();
	menu_utama();
	return 0;
}


int main(){
	daftar();
	return 0;
}

