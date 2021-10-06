#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 3

typedef struct orang
{
    long int NIK;
    char nama[20];
    int umur;
}DATA;

void menu(int *pilih){
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
    scanf("%d", pilih);
}

void enqueue(DATA antrian[], int *head, int *tail){
    if(((*tail) + 1) % MAXSIZE == *head){
        printf("\t:: Antrian penuh\n");
    }else{
        (*tail) = ((*tail) + 1) % MAXSIZE;
        printf("\t:: Ketik Data Baru :\n");
        printf("\t:: Ketik NIK : ");
        scanf("%ld", &antrian[*tail].NIK);
        printf("\t:: Ketik nama : ");
        scanf("%*c%[^\n]s", &antrian[*tail].nama);
        printf("\t:: Ketik umur : ");
        scanf("%d", &antrian[*tail].umur);

        if((*head) == -1)
            (*head) = *tail;
        
        printf("\t:: Data berhasil ditambahkan\n");
    }
}

void dequeue(int *head, int *tail){
    if(*head == -1){
        printf("\t:: Antrian kosong\n");
    }else{
        if(*head == *tail){
            *head = *tail = -1;
        }else{
            (*head) = ((*head) + 1) % MAXSIZE;
        }
        printf("\t:: Data berhasil diproses\n");
       
    }
}

void lihatAntrian(DATA antrian[], int temp, int tail){
    if(tail == -1){
        printf("\t:: Antrian kosong\n");
    }else{
        printf("\t++==================++======================++======++\n"
               "\t::        NIK       ::         NAMA         :: UMUR ::\n"
               "\t++==================++======================++======++\n");
        printf("\t:: %-16ld :: %-20s :: %-4d ::\n", antrian[temp].NIK, antrian[temp].nama, antrian[temp].umur);

        while(temp != tail){
            temp = (temp + 1) % MAXSIZE;
            printf("\t:: %-16ld :: %-20s :: %-4d ::\n", antrian[temp].NIK, antrian[temp].nama, antrian[temp].umur);
        }
        printf("\t++==================++======================++======++\n");
    }
}

void kosongkanAntrian(int *head, int *tail){
    *head = *tail = -1;
    printf("\t:: Antrian berhasil dikosongkan\n");
}

int main (){
    int pilih, head = -1, tail = -1;
    DATA antrianVaksin[MAXSIZE];
    char ulang;

    do{
        system("cls");
        menu(&pilih);
        if(pilih == 1){
            enqueue(antrianVaksin, &head, &tail);
        }else if(pilih == 2){
            dequeue(&head, &tail);
        }else if(pilih == 3){
            lihatAntrian(antrianVaksin, head, tail);
        }else if(pilih == 4){
            kosongkanAntrian(&head, &tail);
        }else if(pilih == 5){
            break;
        }else{
            printf("\t:: Pilihan menu tidak tersedia\n");
        }

        label_cek_ulang :
        fflush(stdin);

        printf("\t:: Apakah ingin mengulang menu (y/n)? : ");
        scanf("%c", &ulang);

        if(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
            printf("\t:: Input salah\n");
            goto label_cek_ulang;
        }

    }while(ulang == 'y' || ulang == 'Y');
    printf("\t:: Akhir dari program\n");
    return 0;
}
