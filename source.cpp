#include "header.h"


void inisialisasiMahasiswa(Mahasiswa* mahasiswa, string& nama) {
    mahasiswa->nama = nama;
    mahasiswa->berikut = nullptr;
    for (int i = 0; i < MAKSIMAL_PERTEMUAN; ++i) {
        mahasiswa->kehadiran[i] = 0;
    }
}

void tambahKehadiran(Mahasiswa* mahasiswa, int pertemuan) {
    if (pertemuan >= 1 && pertemuan <= MAKSIMAL_PERTEMUAN) {
        mahasiswa->kehadiran[pertemuan - 1]++;
    }
}

void cetakMahasiswa(Mahasiswa* mahasiswa) {
    std::cout << "Nama: " << mahasiswa->nama << "\nKehadiran: ";
    for (int i = 0; i < MAKSIMAL_PERTEMUAN; ++i) {
        std::cout << mahasiswa->kehadiran[i] << " ";
    }
    cout << endl;
}

Mahasiswa* tambahMahasiswa(Mahasiswa* head, string& nama) {
    Mahasiswa* mahasiswaBaru = new Mahasiswa;
    inisialisasiMahasiswa(mahasiswaBaru, nama);
    mahasiswaBaru->berikut = head;
    return mahasiswaBaru;
}

void tambahKehadiranMahasiswa(Mahasiswa* head, string& nama, int pertemuan) {
    Mahasiswa* saatIni = head;
    while (saatIni != nullptr) {
        if (saatIni->nama == nama) {
            tambahKehadiran(saatIni, pertemuan);
            return;
        }
        saatIni = saatIni->berikut;
    }
    cout << "Mahasiswa tidak ditemukan!" << endl;
}

void cetakSemuaMahasiswa(Mahasiswa* head) {
    Mahasiswa* saatIni = head;
    while (saatIni != nullptr) {
        cetakMahasiswa(saatIni);
        saatIni = saatIni->berikut;
    }
}

void hapusSemuaMahasiswa(Mahasiswa* head) {
    Mahasiswa* saatIni = head;
    while (saatIni != nullptr) {
        Mahasiswa* mahasiswaBerikutnya = saatIni->berikut;
        delete saatIni;
        saatIni = mahasiswaBerikutnya;
    }
}
