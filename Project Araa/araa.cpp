#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char unameLogin[20], passLogin[20];


struct akun_pembeli {
    char name[50];
    char uname[50];
    char email[50];
    char no_hp[50];
    char pass[50];
};

struct akun_penjual {
    char nik[50];
    char name[50];
    char uname[50];
    char email[50];
    char no_hp[50];
    char nama_bank[50];
    char no_rek[50];
    char pass[50];
};

struct StackAP{
    struct akun_pembeli data[MAX];
    int top;
};

// struct StackAJ{
//     struct akun_penjual data[MAX];
//     int top;
// };

void initAP(struct StackAP *sAP);
int isFullAP(struct StackAP *sAP);
int isEmptyAP(struct StackAP *sAP);
struct akun_pembeli popAP(struct StackAP *sAP);
void pushAP(struct StackAP *sAP, struct akun_pembeli ap);
void saveAP(struct StackAP *sAP);
// void initAJ(struct StackAJ *s);
// int isFullAJ(struct StackAJ *s);
// int isEmptyAJ(struct StackAJ *s);
// void pushAJ(struct StackAJ *s, struct akun_penjual aj);
// void saveAJ(struct StackAJ *s);

int main(){
    int pilihan;
    char cnfrm_pass[50];
    struct StackAP sAP;
    // struct StackAJ sAJ;
    initAP(&sAP);
    // initAJ(&sAJ);
    struct akun_pembeli ap;
    // struct akun_penjual aj;
    system("cls");
    printf("\n\t---- Masuk Sebagai ----\n");
    printf("1. Pembeli \n");
    printf("2. Penjual \n");
    printf("3. Exit \n\n");
    printf("Pilihan: ");
    scanf("%d",&pilihan);
    switch(pilihan){
        case 1 :
            saveAP(&sAP); // Bikin Akun Pembeli
            // loginAP();
            break;

        case 2 :
            // saveAJ(&sAJ); // Bikin Akun Penjual
            break;

        case 3:
            printf("Keluar. . .\n");
            break;

        default :
            printf("PILIHAN TIDAK ADA !!! \n");
            getchar(); 
            break;
    }
}

void initAP(struct StackAP *sAP){
    sAP->top = -1;
}

int isFullAP(struct StackAP *sAP){
    if(sAP->top == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmptyAP(struct StackAP *sAP){
    if(sAP->top == -1){
        return 1;
    }else{
        return 0;
    }
}

 // Bikin Akun Pembeli
void pushAP(struct StackAP *sAP, struct akun_pembeli ap){
    if(!isFullAP(sAP)){
        sAP->top++;
        sAP->data[sAP->top] = ap;
    }else{
        printf("\nStack penuh, data gagal ditambahkan\n");
    }
}

struct akun_pembeli popAP(struct StackAP *sAP){
    struct akun_pembeli ap;
    if(!isEmptyAP(sAP)){
        ap = sAP->data[sAP->top];
        sAP->top--;
    }else{
        printf("\nStack kosong, tidak ada data yang dihapus\n");
    }
    return ap;
}

void cekPassAP(char cnfrm_pass[50], struct akun_pembeli *ap){
    printf ("Password: "); scanf ("%s", ap->pass); getchar();
    printf ("Confirm Password: "); scanf ("%s", cnfrm_pass); getchar();
    if (strcmp(ap->pass, cnfrm_pass) == 0){
        
    } else {
        printf("\nPassword Tidak Sama\n");
        printf("\nMasukkan Ulang Password\n\n");
        cekPassAP(cnfrm_pass, ap);
    }
}

void saveAP(struct StackAP *sAP){
    struct akun_pembeli ap;
    char cnfrm_pass[50];
    printf ("Nama    : "); scanf (" %[^\n]", ap.name); getchar();
    printf ("Username: "); scanf ("%[^\n]", ap.uname); getchar();
    printf ("Email   : "); scanf ("%[^\n]", ap.email); getchar();
    printf ("No HP   : "); scanf ("%[^\n]", ap.no_hp); getchar();
    cekPassAP(cnfrm_pass, &ap);
    pushAP(sAP, ap);
    printf("\nAkun Berhasil Dibuat\n");
}

void loginAP(struct akun_pembeli* ap) {
    printf("\n\t---- Login Pembeli ----\n\n");
    printf("Username: "); scanf("%s", unameLogin);
    printf("Password: "); scanf("%s", passLogin);

    bool isFound = false;
    while (!ap->akun_pembeli.empty()) {
        Akun akun = ap->akun_pembeli.top();
        ap->akun_pembeli.pop();

        if (akun.uname == unameLogin && akun.pass == passLogin) {
            isFound = true;
            break;
        }
    }

    if (isFound) {
        printf("\n\nLogin Berhasil!\n\n");
        // masuk marketplace
    } else {
        printf("\n\nUsername dan Password Tidak Ditemukan\n\n");
        loginAP(ap);
    }
}




// Bikin Akun Penjual
// void pushAJ(struct Stack *s, struct akun_penjual aj){
//     if(!isFull(s)){
//         s->top++;
//         s->data[s->top] = aj;
//     }else{
//         printf("\nStack penuh, data gagal ditambahkan\n");
//     }
// }

// void cekPassAJ(char cnfrm_pass[50], struct akun_penjual *aj){
//     printf ("Password: "); scanf ("%s", aj->pass); getchar();
//     printf ("Confirm Password: "); scanf ("%s", cnfrm_pass); getchar();
//     if (strcmp(aj->pass, cnfrm_pass) == 0)
//     {
        
//     } else {
//         printf("\nPassword Tidak Sama\n");
//         printf("\nMasukkan Ulang Password\n\n");
//         cekPassAP(cnfrm_pass, aj);
//     }
// }

// void saveAJ(struct Stack *s){
//     struct akun_penjual aj;
//     char cnfrm_pass[50];
//     printf ("NIK        : "); scanf (" %[^\n]", aj.nik); getchar();
//     printf ("Nama       : "); scanf (" %[^\n]", aj.name); getchar();
//     printf ("Username   : "); scanf ("%[^\n]", aj.uname); getchar();
//     printf ("Email      : "); scanf ("%[^\n]", aj.email); getchar();
//     printf ("No HP      : "); scanf ("%[^\n]", aj.no_hp); getchar();
//     printf ("Nama Bank  : "); scanf ("%[^\n]", aj.nama_bank); getchar();
//     printf ("No Rekening: "); scanf ("%[^\n]", aj.no_rek); getchar();
//     cekPassAP(cnfrm_pass, &aj);
//     pushAJ(s, aj);
//     printf("\nAkun Berhasil Dibuat\n");
// }