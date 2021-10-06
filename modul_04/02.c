#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3

typedef struct orang{
    long int NIK;
    char nama[20];
    int umur;
}DATA;

void menu (int *pilih_menu){
    printf("\t++====================================++\n"
           "\t:: Program Antrian Vaksinasi COVID-19 ::\n"
           "\t++====================================++\n"
           "\t:: 1. Tambah antrian                  ::\n"
           "\t:: 2. Proses antrian                  ::\n"
           "\t:: 3. Lihat antrian                   ::\n"
           "\t:: 4. Kosongkan antrian               ::\n"
           "\t:: 5. Keluar                          ::\n"
           "\t++====================================++\n"
           "\t:: Ketik pilihan : ");
    scanf("%d", pilih_menu);
}

void tambahAntrian(DATA func_antrian[], int *head, int *tail){
    if(((*tail) + 1) % MAXSIZE == *head){
        printf("\t:: Antrian penuh\n");
    }else{  
        *tail = (*tail + 1) % MAXSIZE;
        printf("\t:: Ketik NIK\t: ");
        scanf("%ld", &func_antrian[*tail].NIK);
        printf("\t:: Ketik nama\t: ");
        scanf("%*c%[^\n]s", &func_antrian[*tail].nama);
        printf("\t:: Ketik umur\t: ");
        scanf("%d", &func_antrian[*tail].umur);
        if(*head == -1)
            *head = *tail;
        printf("\t:: Antrian berhasil ditambah\n");
    }
}

void prosesAntrian(int *head, int *tail){
    if(*head == -1)
        printf("\t:: Antrian kosong\n");
    else{
        if(*head == *tail)
            *head = *tail = -1;
        else
            *head = (*head + 1) % MAXSIZE;
        printf("\t:: Antrian berhasil di proses\n");
    }
}

void lihatAntrian(DATA func_antrian[], int temp, int tail){
    if(temp == -1){
        printf("\t:: Antrian kosong\n");
    }else{
        printf("\t++==================++======================++======++\n"
               "\t::        NIK       ::          NAMA        :: UMUR ::\n"
               "\t++==================++======================++======++\n");
        printf("\t:: %-16ld :: %-20s :: %-4d ::\n", func_antrian[temp].NIK, func_antrian[temp].nama, func_antrian[temp].umur);
        
        while(temp != tail){
            temp = (temp + 1) % MAXSIZE;
            printf("\t:: %-16ld :: %-20s :: %-4d ::\n", func_antrian[temp].NIK, func_antrian[temp].nama, func_antrian[temp].umur);
        }

        printf("\t++==================++======================++======++\n");
    }
}

void clearAntrian(int *head, int *tail){
    *head = *tail = -1;
    printf("\t:: Antrian berhasil dikosongkan\n");
}

int main (){
    DATA antrian[MAXSIZE];
    char ulang;
    int pilih, head = -1, tail = -1;
    do{
        system("cls");
        menu(&pilih);
        if(pilih == 1){
            tambahAntrian(antrian, &head, &tail);
        }else if(pilih == 2){
            prosesAntrian(&head, &tail);
        }else if(pilih == 3){
            lihatAntrian(antrian, head, tail);
        }else if(pilih == 4){
            clearAntrian(&head, &tail);
        }else if(pilih == 5){
            break;
        }else{
            printf("\t:: Menu tidak tersedia\n");
        }

        label_cek_ulang :

        fflush(stdin);
        printf("\t:: Apakah ingin mengulang? (y/n) : ");
        scanf("%c", &ulang);
    
        if(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
            printf("\t:: Input salah\n");
            goto label_cek_ulang;
        }
    }while(ulang == 'y' || ulang == 'Y');
    printf("\t:: Akhir dari program\n");
    return 0;
}