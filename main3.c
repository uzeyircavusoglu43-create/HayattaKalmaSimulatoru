#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    char Komut;
    int Saglik, Enerji, Yemek, Siginak, sayac;
    sayac = 0;
    Saglik = 100;
    Enerji = 100;
    Yemek = 0;
    Siginak = 0;

    do {
        // KOMUT MENÜSÜ
        printf("\n--- Komutlar ---\n");
        printf("A => Avlan\n");
        printf("S => Siginak ara\n");
        printf("R => Dinlen\n");
        printf("E => Envanter\n");
        printf("F => Tehlike dalgasi\n");
        printf("P => Sifreli gecis\n");
        printf("X => Cikis\n");
        printf("----------------\n");
        printf("Komutlar Buyuk Harflerle Girilmeli. Caps Lockun Acik Oldugundan Emin Ol\n");
        printf("Komut Gir: ");
        scanf(" %c", &Komut);

        switch (Komut) {

            case 'A':  // Avlan
                printf("Avlaniyorsun..\n");	
                Enerji -= 10;
                sayac++;
                printf("Kalan Enerji: %d\n",Enerji);
                if (sayac % 3 == 0) {
                    Yemek++;
                    printf("Yemek Buldun! (Yemek: %d)\n", Yemek);
                } else {
                    if (sayac % 5 == 0) {
                        Saglik -= 10;
                        printf("Yaralandin! (Saglik= %d)\n", Saglik);
                    } else {
                        printf("Hicbir sey bulamadin.\n");
                    }
                }

                // Ölüm Kontrol
                if (Saglik <= 0) {
                    printf("Oyuncu Saglik nedeniyle hayatta kalamadi! Oyun bitti.\n");
                    Komut = 'X';
                }
                if (Enerji <= 0) {
                    printf("Oyuncu Enerji bitimi nedeniyle hayatta kalamadi! Oyun bitti.\n");
                    Komut = 'X';
                }
                break;

            case 'S': // Sığınak Bul
                printf("Siginak Araniyor..\n");
                if (Enerji >= 35) {
                    printf("Siginak Buldun!\n");
                    Siginak = 1;
                } else {
                    printf("Siginak bulunmadi! Enerjin Dusuk oldugu icin Yeteri kadar arayamadin!\n");
                }
                break;

            case 'R': // Dinlen
                printf("Dinleniyorsun..\n");
                Enerji += 10;
                Saglik += 10;
                if (Enerji > 100) Enerji = 100;
                if (Saglik > 100) Saglik = 100;
                printf("Enerji ve Saglik artti!. (Enerji= %d, Saglik= %d)\n", Enerji, Saglik);
                break;

            case 'E': // Envanter
                printf("---Envanter---\n");
                printf("Saglik= %d\n", Saglik);
                printf("Enerji= %d\n", Enerji);
                printf("Yemek= %d\n", Yemek);
                if (Siginak == 1) {
                    printf("Siginak Durumu: Var\n");
                } else {
                    printf("Siginak Durumu: Yok\n");
                }

                // Yemek kullanma
                if (Yemek > 0) {
                    char kullan;
                    printf("Yemek Kullanmak Ister misin? Kullan= Y / Kullanma= N: ");
                    scanf(" %c", &kullan);

                    if (kullan == 'y' || kullan == 'Y') {
                        Yemek--;
                        Saglik += 10;
                        Enerji += 10;
                        if (Saglik > 100) Saglik = 100;
                        if (Enerji > 100) Enerji = 100;
                        printf("Yemek kullanildi! Saglik= %d, Enerji= %d, Kalan Yemek= %d\n", Saglik, Enerji, Yemek);
                    }
                }
                break;

            case 'F': // Tehlike dalgası
                printf("Tehlike dalgasi Basliyor!\n");
                for (int i = 1; i <= 3; i++) {
                    Saglik -= 10;
                    Enerji -= 10;
                    printf("%d.dalga=> Saglik= %d Enerji= %d\n", i, Saglik, Enerji);

                    // Ölüm Kontrol
                    if (Saglik <= 0 || Enerji <= 0) {
                        printf("Oyuncu Tehlike Dalgasi Sirasinda Hayatta Kalamadi! Oyun Bitti.\n");
                        Komut = 'X';
                        break;
                    }
                }
                printf("Tehlike Dalgasi Sona Erdi.\n");
                break;

            case 'P': { // Şifreli geçiş
                int Sifre = 7;
                int giris;
                printf("Sifre: x^2 - 8x + 7 = 0 Denkleminin Koklerinden 1 tanesi\n");

                do {
                    printf("Kapidan Gecmek Icin Sifre Gir: ");
                    scanf("%d", &giris);
                } while (giris != Sifre);

                printf("Kapidan Basariyla Gectin!\n");
                break;
            }

            case 'X':
                printf("Oyundan Cikis Yapiliyor..\n");
                break;

            default:
                printf("Gecersiz Komut\n");
        }

    } while (Komut != 'X');



	return 0;
}