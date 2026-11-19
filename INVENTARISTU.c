
#include <stdio.h>

int main() {
    int stokProyektor = 4;
    int stokSpidol = 15;
    int stokKabelHDMI = 6;
    int pakKertasHVS = 10;
    int lembarPerPak = 500;

    int pilihanBarang;
    int jumlahDipinjam = 0;
    int jumlahDikembalikan = 0;

    int hariTerlambat;
    int tarifDendaPerHari = 5000;

    printf("=== SISTEM INVENTARIS BARANG TU ===\n\n");

    int totalLembarKertas = pakKertasHVS * lembarPerPak;

    printf("--- DAFTAR STOK BARANG TU ---\n");
    printf("1. Proyektor   (Stok: %d unit)\n", stokProyektor);
    printf("2. Spidol      (Stok: %d unit)\n", stokSpidol);
    printf("3. Kabel HDMI  (Stok: %d unit)\n", stokKabelHDMI);
    printf("4. Kertas HVS  (Stok: %d pak)\n\n", pakKertasHVS);

    printf("Barang apa yang ingin dipinjam? (Masukkan nomor 1-4): ");
    scanf("%d", &pilihanBarang);

    if (pilihanBarang == 1) {
        printf("Berapa banyak Proyektor yang ingin dipinjam? ");
        scanf("%d", &jumlahDipinjam);
        if (jumlahDipinjam > stokProyektor || jumlahDipinjam < 1) {
            printf("Error: Jumlah pinjam tidak valid atau melebihi stok!\n\n");
        } else {
            stokProyektor = stokProyektor - jumlahDipinjam;
            printf("Berhasil! Sisa stok Proyektor sekarang: %d unit\n\n", stokProyektor);
        }
    } else if (pilihanBarang == 2) {
        printf("Berapa banyak Spidol yang ingin dipinjam? ");
        scanf("%d", &jumlahDipinjam);
        if (jumlahDipinjam > stokSpidol || jumlahDipinjam < 1) {
            printf("Error: Jumlah pinjam tidak valid atau melebihi stok!\n\n");
        } else {
            stokSpidol = stokSpidol - jumlahDipinjam;
            printf("Berhasil! Sisa stok Spidol sekarang: %d unit\n\n", stokSpidol);
        }
    } else if (pilihanBarang == 3) {
        printf("Berapa banyak Kabel HDMI yang ingin dipinjam? ");
        scanf("%d", &jumlahDipinjam);
        if (jumlahDipinjam > stokKabelHDMI || jumlahDipinjam < 1) {
            printf("Error: Jumlah pinjam tidak valid atau melebihi stok!\n\n");
        } else {
            stokKabelHDMI = stokKabelHDMI - jumlahDipinjam;
            printf("Berhasil! Sisa stok Kabel HDMI sekarang: %d unit\n\n", stokKabelHDMI);
        }
    } else if (pilihanBarang == 4) {
        printf("Berapa pak Kertas HVS yang ingin diambil? ");
        scanf("%d", &jumlahDipinjam);
        if (jumlahDipinjam > pakKertasHVS || jumlahDipinjam < 1) {
            printf("Error: Jumlah pinjam tidak valid atau melebihi stok!\n\n");
        } else {
            pakKertasHVS = pakKertasHVS - jumlahDipinjam;
            totalLembarKertas = pakKertasHVS * lembarPerPak;
            printf("Berhasil! Sisa Kertas HVS: %d pak (%d lembar)\n\n", pakKertasHVS, totalLembarKertas);
        }
    } else {
        printf("Error: Pilihan barang tidak ada dalam menu!\n\n");
    }

    if (pilihanBarang >= 1 && pilihanBarang <= 4 && jumlahDipinjam > 0) {
        printf("--- PENGEMBALIAN BARANG ---\n");
        printf("Berapa banyak barang yang ingin dikembalikan? ");
        scanf("%d", &jumlahDikembalikan);

        if (jumlahDikembalikan > jumlahDipinjam || jumlahDikembalikan < 1) {
            printf("Error: Jumlah pengembalian tidak valid (melebihi jumlah yang dipinjam)!\n");
        } else {
            if (pilihanBarang == 1) {
                stokProyektor = stokProyektor + jumlahDikembalikan;
                printf("Stok Proyektor berhasil ditambahkan. Total stok sekarang: %d unit\n", stokProyektor);
                printf("Barang dikembalikan ke: Laci/Rak Khusus Proyektor\n\n");
            } else if (pilihanBarang == 2) {
                stokSpidol = stokSpidol + jumlahDikembalikan;
                printf("Stok Spidol berhasil ditambahkan. Total stok sekarang: %d unit\n", stokSpidol);
                printf("Barang dikembalikan ke: Laci/Rak Khusus Spidol\n\n");
            } else if (pilihanBarang == 3) {
                stokKabelHDMI = stokKabelHDMI + jumlahDikembalikan;
                printf("Stok Kabel HDMI berhasil ditambahkan. Total stok sekarang: %d unit\n", stokKabelHDMI);
                printf("Barang dikembalikan ke: Laci/Rak Khusus Kabel HDMI\n\n");
            } else if (pilihanBarang == 4) {
                pakKertasHVS = pakKertasHVS + jumlahDikembalikan;
                totalLembarKertas = pakKertasHVS * lembarPerPak;
                printf("Stok Kertas HVS berhasil ditambahkan. Total stok sekarang: %d pak (%d lembar)\n", pakKertasHVS, totalLembarKertas);
                printf("Barang dikembalikan ke: Laci/Rak Khusus Kertas HVS\n\n");
            }

            printf("Masukkan keterlambatan pengembalian (hari): ");
            scanf("%d", &hariTerlambat);

            int totalDenda = hariTerlambat * tarifDendaPerHari;
            printf("Total denda keterlambatan: Rp %d\n", totalDenda);
        }
    }

    return 0;
}