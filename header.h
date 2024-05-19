#include <iostream>
#include <string>

#define MAKSIMAL_PERTEMUAN 14
using namespace std;
typedef struct Mahasiswa {
    string nama;
    int kehadiran[MAKSIMAL_PERTEMUAN];
    Mahasiswa* berikut;
} Mahasiswa;

void inisialisasiMahasiswa(Mahasiswa* mahasiswa, string& nama);
void tambahKehadiran(Mahasiswa* mahasiswa, int pertemuan);
void cetakMahasiswa(Mahasiswa* mahasiswa);

Mahasiswa* tambahMahasiswa(Mahasiswa* head, string& nama);
void tambahKehadiranMahasiswa(Mahasiswa* head, string& nama, int pertemuan);
void cetakSemuaMahasiswa(Mahasiswa* head);
void hapusSemuaMahasiswa(Mahasiswa* head);
