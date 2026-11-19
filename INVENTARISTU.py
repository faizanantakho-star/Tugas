stok_proyektor = 4
stok_spidol = 15
stok_kabel_hdmi = 6
pak_kertas_hvs = 10
lembar_per_pak = 500

jumlah_dipinjam = 0
jumlah_dikembalikan = 0
pinjaman_berhasil = False
tarif_denda_per_hari = 5000

print("--- SISTEM INVENTARIS BARANG TU ---\n")

total_lembar_kertas = pak_kertas_hvs * lembar_per_pak

print("--- DAFTAR STOK BARANG TU ---")
print(f"1. Proyektor (Stok: {stok_proyektor} unit)")
print(f"2. Spidol (Stok: {stok_spidol} unit)")
print(f"3. Kabel HDMI (Stok: {stok_kabel_hdmi} unit)")
print(f"4. Kertas HVS (Stok: {pak_kertas_hvs} pak)\n")

# Process peminjaman
pilihan_barang = int(input("Barang apa yang ingin dipinjam? (Masukkan nomor 1-4): "))

if pilihan_barang == 1:
    jumlah_dipinjam = int(input("Berapa banyak Proyektor yang ingin dipinjam? "))
    if jumlah_dipinjam > stok_proyektor or jumlah_dipinjam < 1:
        print("Error: Jumlah pinjam tidak valid atau melebihi stok!\n")
    else:
        stok_proyektor -= jumlah_dipinjam
        pinjaman_berhasil = True
        print(f"Berhasil! Sisa stok Proyektor sekarang: {stok_proyektor} unit\n")

elif pilihan_barang == 2:
    jumlah_dipinjam = int(input("Berapa banyak Spidol yang ingin dipinjam? "))
    if jumlah_dipinjam > stok_spidol or jumlah_dipinjam < 1:
        print("Error: Jumlah pinjam tidak valid atau melebihi stok!\n")
    else:
        stok_spidol -= jumlah_dipinjam
        pinjaman_berhasil = True
        print(f"Berhasil! Sisa stok Spidol sekarang: {stok_spidol} unit\n")

elif pilihan_barang == 3:
    jumlah_dipinjam = int(input("Berapa banyak Kabel HDMI yang ingin dipinjam? "))
    if jumlah_dipinjam > stok_kabel_hdmi or jumlah_dipinjam < 1:
        print("Error: Jumlah pinjam tidak valid atau melebihi stok!\n")
    else:
        stok_kabel_hdmi -= jumlah_dipinjam
        pinjaman_berhasil = True
        print(f"Berhasil! Sisa stok Kabel HDMI sekarang: {stok_kabel_hdmi} unit\n")

elif pilihan_barang == 4:
    jumlah_dipinjam = int(input("Berapa pak Kertas HVS yang ingin diambil? "))
    if jumlah_dipinjam > pak_kertas_hvs or jumlah_dipinjam < 1:
        print("Error: Jumlah pinjam tidak valid atau melebihi stok!\n")
    else:
        pak_kertas_hvs -= jumlah_dipinjam
        pinjaman_berhasil = True
        total_lembar_kertas = pak_kertas_hvs * lembar_per_pak
        print(f"Berhasil! Sisa Kertas HVS: {pak_kertas_hvs} pak ({total_lembar_kertas} lembar)\n")

else:
    print("Error: Pilihan barang tidak ada dalam menu!\n")

# Proses pengembalian barang
if pinjaman_berhasil:
    print("--- PENGEMBALIAN BARANG ---")
    jumlah_dikembalikan = int(input("Berapa banyak barang yang ingin dikembalikan? "))
    
    if jumlah_dikembalikan > jumlah_dipinjam or jumlah_dikembalikan < 1:
        print("Error: Jumlah pengembalian tidak valid (melebihi jumlah yang dipinjam)!")
    else:
        if pilihan_barang == 1:
            stok_proyektor += jumlah_dikembalikan
            print(f"Stok Proyektor berhasil ditambahkan. Total stok sekarang: {stok_proyektor} unit")
            print("Barang dikembalikan ke: Laci/Rak Khusus Proyektor\n")
        elif pilihan_barang == 2:
            stok_spidol += jumlah_dikembalikan
            print(f"Stok Spidol berhasil ditambahkan. Total stok sekarang: {stok_spidol} unit")
            print("Barang dikembalikan ke: Laci/Rak Khusus Spidol\n")
        elif pilihan_barang == 3:
            stok_kabel_hdmi += jumlah_dikembalikan
            print(f"Stok Kabel HDMI berhasil ditambahkan. Total stok sekarang: {stok_kabel_hdmi} unit")
            print("Barang dikembalikan ke: Laci/Rak Khusus Kabel HDMI\n")
        elif pilihan_barang == 4:
            pak_kertas_hvs += jumlah_dikembalikan
            total_lembar_kertas = pak_kertas_hvs * lembar_per_pak
            print(f"Stok Kertas HVS berhasil ditambahkan. Total stok sekarang: {pak_kertas_hvs} pak ({total_lembar_kertas} lembar)")
            print("Barang dikembalikan ke: Laci/Rak Khusus Kertas HVS\n")
        
        hari_terlambat = int(input("Masukkan keterlambatan pengembalian (hari): "))
        total_denda = hari_terlambat * tarif_denda_per_hari
        print(f"Total denda keterlambatan: Rp {total_denda}")