#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>



typedef enum //Bilet Türü
{
    Ogrenci,
    Normal
}eBiletTuru;
typedef struct //Matine
{
    bool koltuklar[50];
    eBiletTuru biletTuru[50];
    char FilmAdi[100];
    int SatilanBiletSayisi;
}Matine;
typedef struct // Salon
{
    char SalonAdi[100];
    Matine MatineNo[5];
}Salonlar;

typedef struct//Sinema
{
    int HasilatBilgisi;
    Salonlar Salon[3];
}Sinema;
    bool SifreKontrol(char kAdi[10],char parola[10]);
    int BiletSat(Salonlar *salon,eBiletTuru bltTuru, int matineNo);
    void BiletSatis(Sinema *sin);
    void KoltuklariBosalt(Sinema *sin);
    void DetayliBiletYazdir(Sinema *sin);
    bool KoltukKontrol(Salonlar *salon,int biletSayisi,int matineNo);
    void CokluSatis(Salonlar *salon, int BiletSayisiOgrenci,int BiletSayisiTam,int matineNo);
    char *Decript(char text[]);
    char *Encript(char text[]);
    void KoltuklariListele(Sinema *sin);
int main()
{
    int kalanDenemeSayisi=3; //Yanlış Girilebilecek Login Sayısı
    char kAdi[10];
    char parola[10];
    bool kontrol=false;
    Sinema Pollywood;
    strcpy(Pollywood.Salon[0].SalonAdi,"Salon 1");
    strcpy(Pollywood.Salon[1].SalonAdi,"Salon 2");
    strcpy(Pollywood.Salon[2].SalonAdi,"Salon 3");
    strcpy(Pollywood.Salon[0].MatineNo[0].FilmAdi,"Salon 1 Matine 1");
    strcpy(Pollywood.Salon[0].MatineNo[1].FilmAdi,"Salon 1 Matine 2");
    strcpy(Pollywood.Salon[0].MatineNo[2].FilmAdi,"Salon 1 Matine 3");
    strcpy(Pollywood.Salon[0].MatineNo[3].FilmAdi,"Salon 1 Matine 4");
    strcpy(Pollywood.Salon[0].MatineNo[4].FilmAdi,"Salon 1 Matine 5");

    strcpy(Pollywood.Salon[1].MatineNo[0].FilmAdi,"Salon 2 Matine 1");
    strcpy(Pollywood.Salon[1].MatineNo[1].FilmAdi,"Salon 2 Matine 2");
    strcpy(Pollywood.Salon[1].MatineNo[2].FilmAdi,"Salon 2 Matine 3");
    strcpy(Pollywood.Salon[1].MatineNo[3].FilmAdi,"Salon 2 Matine 4");
    strcpy(Pollywood.Salon[1].MatineNo[4].FilmAdi,"Salon 2 Matine 5");

    strcpy(Pollywood.Salon[2].MatineNo[0].FilmAdi,"Salon 3 Matine 1");
    strcpy(Pollywood.Salon[2].MatineNo[1].FilmAdi,"Salon 3 Matine 2");
    strcpy(Pollywood.Salon[2].MatineNo[2].FilmAdi,"Salon 3 Matine 3");
    strcpy(Pollywood.Salon[2].MatineNo[3].FilmAdi,"Salon 3 Matine 4");
    strcpy(Pollywood.Salon[2].MatineNo[4].FilmAdi,"Salon 3 Matine 5");
    KoltuklariBosalt(&Pollywood);
    printf("\tGIRIS\t\n");
    do
    {
        if (kalanDenemeSayisi==0)
        {
            printf("3 defa yanlis girdiginiz icin uygulama sonlandi");
            return 0;
        }
        printf("Kullanici Adi: ");
        gets(kAdi);
        printf("Parola: ");
        gets(parola);
        kontrol = SifreKontrol(kAdi,parola);
        if (kontrol == false)
        {
            kalanDenemeSayisi -=1;
            printf("\nKalan Hak Sayisi: %d\n\n",kalanDenemeSayisi);
        }

    }while(kontrol != true);
    printf("Giris Basarili!\n");
    system("CLS");
    printf("Hos geldiniz\n\n");

    bool secimYapildi=false;
    int secim = 0;
    do
    {
        printf("\tMENU\t\n");
        printf("1.Bilet Satis\n");
        printf("2.Hasilat Bilgisi\n");
        printf("3.Toplam Satilan Bilet Sayisi\n");
        printf("4.Kullanici Ekle\n");
        printf("5.Cikis\n");
        printf("6.Satilan Koltuklari Listele\n");
        printf("Secim: ");
        scanf("%d",&secim);

        switch(secim)
        {
            case 1:
                {
                    BiletSatis(&Pollywood);
                    break;
                }
            case 2:
                {
                    HasilatHesapla(&Pollywood);
                    printf("\nMenuye donmek icin herhangi bir tusa basin...");
                    getch();
                    break;
                }
            case 3:
                {
                    DetayliBiletYazdir(&Pollywood);
                    break;
                }
            case 4:
                {
                    KullaniciEkle();
                    printf("\nMenuye donmek icin herhangi bir tusa basin...");
                    getch();
                    break;
                }
            case 5:
                {
                    printf("\nGule Gule\n");
                    exit(0);
                }
            case 6:
                {
                    KoltuklariListele(&Pollywood);
                    printf("\nMenuye donmek icin herhangi bir tusa basin...");
                    getch();
                    break;
                }
            default:
                {
                   printf("\n");
                   printf("Hatali Secim.\n");
                   printf("\nMenuye donmek icin herhangi bir tusa basin...");
                   getch();
                }
        }
        system("CLS");

    }while(1==1);
    return 0;
}
void KoltuklariListele(Sinema *sin)
{
    int i,j,k;
    for(i=0;i<3;i++)
    {
        printf("Salon Adi: %s\n",sin->Salon[i].SalonAdi);
        for(j=0;j<5;j++)
        {
            printf("Matine Adi: %s\n",sin->Salon[i].MatineNo[j].FilmAdi);
            for(k=0;k<50;k++)
            {
                if(sin->Salon[i].MatineNo[j].koltuklar[k]==true)
                    printf("%d.Koltuk: Dolu\n",(k+1));
                else
                    break;
            }
        }
    }
}
void KoltuklariBosalt(Sinema *sin)
{

    int i,j,k;
    for (i=0;i<3;i++)
    {
        sin->HasilatBilgisi=0;

       for(j=0;j<5;j++)
        {
            sin->Salon[i].MatineNo[j].SatilanBiletSayisi=0;
            for(k=0;k<50;k++)
            {
                sin->Salon[i].MatineNo[j].biletTuru[k] = 1;
                sin->Salon[i].MatineNo[j].koltuklar[k] = false;
            }
        }
    }

}
void BiletSatis(Sinema *sin)
{
    int salonNo=0;
    int matineNo=0;
    int ogrenciBilet=0;
    int tamBilet=0;

    printf("\n\tBilet Satis\t\n");
    int dongu_degiskeni1=0;
    for (dongu_degiskeni1=0;dongu_degiskeni1<3;dongu_degiskeni1++)//Salon Listeleme
        printf("%d.Salon : %s\n",(dongu_degiskeni1+1),sin->Salon[dongu_degiskeni1].SalonAdi);
    printf("Salon No: ");
    scanf("%d",&salonNo);
    if (salonNo<1 && salonNo>3)
    {
        printf("Hata!Lütfen salon numarasını 1-3 arasında seciniz\n");
        return;
    }
    for (dongu_degiskeni1=0;dongu_degiskeni1<5;dongu_degiskeni1++)//Matine Listeleme
        printf("%d.Matine No: %s\n",(dongu_degiskeni1+1),sin->Salon[salonNo-1].MatineNo[dongu_degiskeni1].FilmAdi);
    printf("Matine No: ");
    scanf("%d",&matineNo);
    if (matineNo<1 && matineNo>5)
    {
        printf("Hata!Lütfen matine numarasını 1-5 arasında seciniz\n");
        return;
    }
    printf("Ogrenci Bilet Sayisi: ");
    scanf("%d",&ogrenciBilet);
    printf("Tam Bilet Sayisi: ");
    scanf("%d",&tamBilet);
    CokluSatis(&sin->Salon[salonNo-1],ogrenciBilet,tamBilet,matineNo-1);
    printf("\nMenuye donmek icin herhangi bir tusa basin...\n");
    getch();
}
void DetayliBiletYazdir(Sinema *sin)
{
    int i,j,toplamBiletSayisi=0;
    for (i = 0;i<3;i++)
    {
        printf("%s\n",sin->Salon[i].SalonAdi);
        for(j=0;j<5;j++)
        {
            printf("%d.Matine\nFilm Adi: %s\nSatilanBiletSayisi: %d\n",(j+1),sin->Salon[i].MatineNo[j].FilmAdi,sin->Salon[i].MatineNo[j].SatilanBiletSayisi);
            toplamBiletSayisi += sin->Salon[i].MatineNo[j].SatilanBiletSayisi;
        }
        printf("\n");
    }
    printf("\n\Satilan Toplam Bilet Sayisi = %d\n",toplamBiletSayisi);
    printf("\nMenuye donmek icin herhangi bir tusa basin...");
    getch();
}
void KullaniciEkle()
{
    FILE *fp;
    char kAd1[10];
    char parola1[10];
    char *kAd2;
    char *parola2;
    char kontrol[1];
    bool kontrolYazilabilir=true;
    printf("\n\tKullanici Ekle\t\n");
    printf("Kullanici Adi: ");
    scanf(" %s",kAd1);
    printf("Parola: ");
    scanf(" %s",parola1);
    printf("Kaydetmek istediginize emin misiniz?(E/H): ");
    scanf(" %s",&kontrol);
    int sonuc = strcmp(kontrol,"E");
    printf("sonuc : %d",sonuc);
    if ( sonuc == 0)
    {
        //Dosyada Aynı isimden olup olmadığını kontrol etme
        if ((fp=fopen("sifre.txt","r")) == NULL)
        {
            printf("Dosya açma hatasi!");
            exit(1);
        }
        while( !feof(fp) )
        {
            char tempkAd[10],tempParola[10];
            fscanf(fp,"%s - %s",tempkAd,tempParola);
            kAd2 = Decript(tempkAd); //Decripted password
            parola2 = Decript(tempParola); //Decripted password
            int kAdiSonuc = strcmp(kAd1,kAd2);
            if (kAdiSonuc == 0)
            {
                kontrolYazilabilir=false;
                break;
            }
        }
        fclose(fp);
        if(kontrolYazilabilir)
            printf("\nYazilabilir.\n");
        else
            printf("\nYazdirilamaz\n");
        if (kontrolYazilabilir == true)
        {
            if ((fp=fopen("sifre.txt","a")) == NULL)
            {
                printf("Dosya açma hatasi!\n");
                exit(1);
            }
            char *sifreliKad=Decript(kAd1);
            char *sifreliParola=Decript(parola1);
            printf("\nSifreli Kullanici adi: %s\n",sifreliKad);
            printf("\nSifreli Parola: %s\n",sifreliParola);
            int sonuc = fprintf(fp,"\n%s - %s",sifreliKad,sifreliParola);
            if (sonuc ==-1)
                printf("Yazma Hatasi\n");
            else
                printf("Yazma Basarili");
            fclose(fp);
        }
    }else
    {
        printf("Yeni Kullanici Eklenmedi.");
        return;
    }

}

bool SifreKontrol(char kAdi[10],char parola[10])
{
    FILE *fp;
    bool kontrol = false;
    if ((fp=fopen("sifre.txt","r")) == NULL)
    {
        printf("Dosya açma hatasi!");
        exit(1);
    }
    char kAd1[10];
    char parola1[10];
    char *kAd2;
    char *parola2;
    while( !feof(fp) )
    {
      fscanf(fp,"%s - %s\n",kAd1,parola1);
      kAd2 = Decript(kAd1); //Decripted password
      parola2 = Decript(parola1); //Decripted password
      int kAdiSonuc = strcmp(kAdi,kAd2);
      int parolaSonuc = strcmp(parola,parola2);
      if (kAdiSonuc == 0 && parolaSonuc == 0)
        {
            kontrol=true;
            break;
        }
    }
    fclose(fp);
    return kontrol;
}
    int BiletSat(Salonlar *salon,eBiletTuru bltTuru, int matineNo)
    {
        if (salon->MatineNo[matineNo].SatilanBiletSayisi == 50)
            return;
        int sBiletSayisi = salon->MatineNo[matineNo].SatilanBiletSayisi;
        salon->MatineNo[matineNo].koltuklar[sBiletSayisi] = true;
        salon->MatineNo[matineNo].biletTuru[sBiletSayisi] = bltTuru;
        salon->MatineNo[matineNo].SatilanBiletSayisi++;
        if (bltTuru == 0)
            return 20;
        else
            return 30;
    }

    int HasilatHesapla(Sinema *sin)
    {
        int i = 0;
        int k = 0;
        int j = 0;
        int hasilatSalon=0;
        int hasilatToplam=0;
        FILE *fp;
        if ((fp=fopen("hasilat.txt","w+")) == NULL)
        {
            printf("Dosya açma hatasi!");
            exit(1);
        }
        fprintf(fp,"\tHASILAT BILGISI\n");
        for (i=0;i<3;i++)
        {
            hasilatSalon=0;
            for (j = 0;j<5;j++)
            {
                for (k = 0;k<50;k++)
                {
                    if (sin->Salon[i].MatineNo[j].koltuklar[k] != true)
                        break;
                    if(sin->Salon[i].MatineNo[j].biletTuru[k] == 0) //ogrenci
                        hasilatSalon+=20;
                    else
                        hasilatSalon+=30;
                }
            }
            printf("%d Nolu salonun hasilati = %d\n",(i+1),hasilatSalon);
            fprintf(fp,"%d Nolu salonun hasilati = %d\n",(i+1),hasilatSalon);

            hasilatToplam+=hasilatSalon;
        }
        sin->HasilatBilgisi = hasilatToplam;
        printf("Sinemanin toplam hasilati = %d\n",hasilatToplam);
        fprintf(fp,"Sinemanin toplam hasilati = %d\n",hasilatToplam);
        fclose(fp);
        printf("\Hasilat bilgisi dosyaya yazildi.");
        return hasilatToplam;
    }
    bool KoltukKontrol(Salonlar *salon,int biletSayisi,int matineNo)
    {
        if ((50 - salon->MatineNo[matineNo].SatilanBiletSayisi) >= biletSayisi)
            return true;
        else
            return false;
    }
    void CokluSatis(Salonlar *salon, int BiletSayisiOgrenci,int BiletSayisiTam,int matineNo)
    {
        int i;
        int ToplamUcret=0;
        int temp =0;
        bool satilabilir = false;
        if (KoltukKontrol(salon,BiletSayisiOgrenci+BiletSayisiTam,matineNo) == true )
            satilabilir = true;
        if (satilabilir == true){
            for (i=0;i<BiletSayisiOgrenci;i++)
            {
                temp = BiletSat(salon,0,matineNo);
                if(temp !=-1)
                    ToplamUcret += temp;
            }
            for (i=0;i<BiletSayisiTam;i++)
            {
                temp = BiletSat(salon,1,matineNo);
                if(temp !=-1)
                    ToplamUcret += temp;
            }
            printf("Toplam ucret = %d\n",ToplamUcret);
        }else
         printf("Yeterli koltuk olmadýðýndan satmýyoruz.1!!!");
    }

    char *Encript(char text[])
    {
        int i;
        int boyut=sizeof(text);
        for (i =0;i<boyut;i++)
            text[i] = (char)((int)text[i] + 3);
        return text;
    }
    char *Decript(char text[])
    {
        int i = 0;
        int boyut = sizeof(text);
        for (i=0;i<boyut;i++)
            text[i] = (char)((int)text[i] - 3);
        return text;
    }
