#include <stdio.h>
#include <stdlib.h>

float ukuran_layar, berat, kecepatan_processor;
float layar_kecil, layar_sedang,layar_besar;
float berat_ringan, berat_sedang, berat_Berat;
float processor_rendah, processor_sedang, processor_tinggi;

float rul1, rul2, rul3, rul4, rul5, rul6, rul7, rul8;
float z1, z2, z3, z4a, z4b, z5a, z5b, z6, z7, z8;

void uprocessor_rendah(){
if (kecepatan_processor <= 1000){processor_rendah = 1;}
else if (kecepatan_processor < 1700 && kecepatan_processor > 1000) {processor_rendah = (1700 -kecepatan_processor)/700;}
else if (kecepatan_processor <= 1700)  {processor_rendah= 0;}
}

void uprocessor_sedang(){
if (kecepatan_processor<= 1600 || kecepatan_processor >= 2000 ) {processor_sedang = 0;}
else if (kecepatan_processor> 1600 && kecepatan_processor< 1800){ processor_sedang = (kecepatan_processor- 1600) / 200;}
else if (kecepatan_processor = 1800) {processor_sedang = 1;}
else if (kecepatan_processor> 1800 && kecepatan_processor < 2000){ processor_sedang = (2000 - kecepatan_processor) / 200;}
}

void uprocessor_tinggi(){
if (kecepatan_processor <= 5000){processor_tinggi = 1;}
else if (kecepatan_processor < 1900 && kecepatan_processor > 5000) {processor_tinggi = (kecepatan_processor - 1900)/700;}
else if (kecepatan_processor <= 1900)  {processor_tinggi= 0;}
}

void ulayar_kecil(){
if (ukuran_layar <= 11 ) {layar_kecil = 1;}
else if (ukuran_layar> 11 && ukuran_layar< 14){ layar_kecil = (14 - ukuran_layar) / 3;}
else if (ukuran_layar>= 14) {layar_kecil = 0;}
}

void ulayar_sedang(){
if (ukuran_layar<= 11 || ukuran_layar >= 17 ) {layar_sedang = 0;}
else if (ukuran_layar> 11 && ukuran_layar< 14){ layar_sedang = (ukuran_layar- 11) / 3;}
else if (ukuran_layar = 14) {layar_sedang = 1;}
else if (ukuran_layar> 14 && ukuran_layar < 17){ layar_sedang = (17 - ukuran_layar) / 3;}
}

void ulayar_besar(){
if (ukuran_layar <= 14 ) {layar_besar = 0;}
else if (ukuran_layar> 14 && ukuran_layar< 17){layar_besar = (ukuran_layar- 14) / 3;}
else if (ukuran_layar>= 17) {layar_besar = 1;}
}

void uberat_ringan(){
if (berat <= 1800 ) {berat_ringan = 1;}
else if (berat > 1800 && berat < 2200){ berat_ringan = (2200 - berat) / 400;}
else if (berat >= 2200) {berat_ringan = 0;}
}

void uberat_sedang(){
if (berat <= 1800 || berat >= 2600 ) {berat_sedang = 0;}
else if (berat > 1800 && berat < 2200){ berat_sedang = (berat - 1800) / 400;}
else if (berat > 2200 && berat < 2600){ berat_sedang = (2600 - berat) / 400;}
else if (berat = 2200) {berat_sedang = 1;}
}

void uberat_Berat(){
if (berat <= 2200 ) {berat_Berat = 0;}
else if (berat > 2200 && berat < 2600){ berat_Berat = (berat - 2200) / 400;}
else if (berat >= 2600) {berat_Berat = 1;}
}

void fuzzyfikasi(){
ulayar_kecil();
ulayar_sedang();
ulayar_besar();
uberat_ringan();
uberat_sedang();
uberat_Berat();
uprocessor_rendah();
uprocessor_sedang();
uprocessor_tinggi();
}

float min (float a, float b, float c){
if (a < b && a<c){
    return a;
}
else if (b < a && b < c){
    return b;
}

else {
    return c;
}
}

void rule (){
fuzzyfikasi();
//If ukuran_layar kecil , berat ringan, dan kecepatan processor rendah then harga murah
rul1 = min (layar_kecil, berat_ringan, processor_rendah);
z1 = 10 - (6*rul1);
//If ukuran_layar kecil,  berat sedang, dan kecepatan processor sedang then harga murah
rul2 = min (layar_kecil, berat_sedang, processor_sedang);
z2 = 10 - (6*rul2);
//If ukuran_layar sedang, berat sedang, dan kecepatan processor rendah  then  harga murah
rul3 = min(layar_sedang, berat_sedang,processor_rendah);
z3 = 10 - (6*rul3);
//If ukuran_layar sedang, berat sedang, dan kecepatan processor sedang then harga sedang
rul4 = min(layar_sedang, berat_ringan, processor_sedang);
z4a = (6*rul4)+4;
z4b = 15-(5*rul4);
//If ukuran_layar sedang,  berat ringan, dan kecepatan procesoor sedang then harga sedang
rul5 = min(layar_sedang, berat_ringan, processor_sedang);
z5a = (6*rul5) + 4;
z5b = 15 - (5*rul5);
//If ukuran_layar besar, beratnya berat, dan kecepatan processor tinggi  then harga mahal
rul6 = min(layar_besar, berat_Berat, processor_tinggi);
z6 = (5*rul6) + 10;
//If ukuran_layar sedang, berat ringan, dan kecepatan processor tinggi then harga mahal
rul7 = min(layar_sedang, berat_ringan, processor_tinggi);
z7 = (5*rul7) +10;
//If ukuran_layar sedang, beratnya sedang, dan kecepatan processor tinggi berat then harga  mahal
rul8 = min(layar_besar, berat_sedang,processor_tinggi);
z8 = (5*rul8) + 10;
}
float defuzyfikasi(){
rule();

float A = ((rul1 *z1) + (rul2 *z2) + (rul3 *z3) + (rul4 *z4a)+(rul4*z4b) + (rul5 *z5a) + (rul5 *z5b) + (rul6 *z6)+ (rul7 *z7)+ (rul8 *z8));
float B = rul1+rul2+rul3+rul4+rul5+rul6+rul7+rul8;
printf("\nA :%f", A);
printf("\nB :%f", B);
return A/B;
}
int main()
{
    printf("Masukan ukuran_layar dari laptop (Inci):");
    scanf("%f", &ukuran_layar);
    printf("Masukan Jumlah berat (Gram):");
    scanf("%f", &berat);
    printf("Masukan kecepatan processor (MHz)  :");
    scanf("%f", &kecepatan_processor);
    printf("\n\n");
    rule();
    printf("----Hasil Perhitungan Fuzzyfikasi----\n");
    printf("Anggota ukuran_layarSepi : ");
    printf("%f\n", layar_kecil);
    printf("Anggota ukuran_layarsedang : ");
    printf("%f\n", layar_sedang);
    printf("Anggota ukuran_layarramai : ");
    printf("%f\n",layar_besar);
    printf("Anggota berat Sedikit : ");
    printf("%f\n", berat_ringan);
    printf("Anggota berat Setengah : ");
    printf("%f\n", berat_sedang);
    printf("Anggota berat banyak : ");
    printf("%f\n", berat_Berat);
    printf("\n\n");
    printf("----Hasil Perhitungan Min Rule----\n");
    printf("rul1 :%f", rul1);
    printf("\nrul2 :%f", rul2);
    printf("\nrul3 :%f", rul3);
    printf("\nrul4 :%f", rul4);
    printf("\nrul5 :%f", rul5);
    printf("\nrul6 :%f", rul6);
    printf("\nrul7 :%f", rul7);
    printf("\nrul8 :%f", rul8);
    printf("\n\n");
    printf("----Hasil Perhitungan Output rule----\n");
    printf("z1 :%f", z1);
    printf("\nz2 :%f", z2);
    printf("\nz3 :%f", z3);
    printf("\nz4a :%f", z4a);
    printf("\n z4b: %f", z4b);
    printf("\nz5a :%f", z5a);
    printf("\nz5b :%f", z5b);
    printf("\nz6 :%f", z6);
    printf("\nz7 :%f", z7);
    printf("\nz8 :%f", z8);
    printf("\n\n");

    printf("----Hasil Keputusan sistem untuk harga laptop ----\n");
    printf("\nHarga Laptop :%f juta", defuzyfikasi());
    printf("\n\n");
    printf("-------Selesai------\n");
    return 0;
}

