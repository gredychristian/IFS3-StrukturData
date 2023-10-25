#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string nama;
    char jenisKelamin;
    Mahasiswa* next;

    Mahasiswa(string _nama, char _jenisKelamin) {
        nama = _nama;
        jenisKelamin = _jenisKelamin;
        next = nullptr;
    }
};

// Kelas yang merepresentasikan lingkaran mahasiswa
class LingkaranMahasiswa {
private:
    Mahasiswa* head;
    Mahasiswa* tail;

public:
    LingkaranMahasiswa() {
        head = nullptr;
        tail = nullptr;
    }

    // Menambahkan mahasiswa ke lingkaran
    void tambahMahasiswa() {
        string nama;
        char jenisKelamin;

        cout << "Masukkan nama mahasiswa: ";
        cin >> nama;
        cout << "Masukkan jenis kelamin (L/P): ";
        cin >> jenisKelamin;

        Mahasiswa* newMahasiswa = new Mahasiswa(nama, jenisKelamin);

        if (!head) {
            head = newMahasiswa;
            tail = newMahasiswa;
            newMahasiswa->next = head;
        } else {
            tail->next = newMahasiswa;
            tail = newMahasiswa;
            newMahasiswa->next = head;
        }
        cout << "Mahasiswa " << nama << " ditambahkan ke dalam lingkaran." << endl;
    }

    void tambahMahasiswaDiTengah(const string& nama, char jenisKelamin) {
        Mahasiswa* newMahasiswa = new Mahasiswa(nama, jenisKelamin);

        if (!head) {
            head = newMahasiswa;
            tail = newMahasiswa;
            newMahasiswa->next = head;
        } else {
            int posisi;
            cout << "Data dimasukkan pada urutan ke ";
            cin >> posisi;

            if (posisi < 1) {
                newMahasiswa->next = head;
                head = newMahasiswa;
                tail->next = head;
                posisi = 1;
            } else {
                Mahasiswa* current = head;
                int counter = 1;

                while (current->next != head && counter < posisi - 1) {
                    current = current->next;
                    counter++;
                }

                newMahasiswa->next = current->next;
                current->next = newMahasiswa;

                if (posisi > counter) {
                    tail = newMahasiswa;
                }
            }
        }

        cout << "Berhasil\n";
    }

    // Menghapus mahasiswa dari lingkaran
    void hapusMahasiswa() {
        if (!head) {
            cout << "Lingkaran kosong." << endl;
            return;
        }

        string nama;
        cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
        cin >> nama;

        Mahasiswa* current = head;
        Mahasiswa* prev = nullptr;

        do {
            if (current->nama == nama) {
                if (current == head) {
                    head = head->next;
                    tail->next = head;
                } else if (current == tail) {
                    tail = prev;
                    tail->next = head;
                } else {
                    prev->next = current->next;
                }

                delete current;
                cout << nama << " telah keluar dari lingkaran." << endl;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != head);

        cout << nama << " tidak ditemukan dalam lingkaran." << endl;
    }

    // Pisahkan mahasiswa berdasarkan jenis kelamin
    void pisahkanJenisKelamin() {
        if (!head) {
            cout << "Lingkaran kosong." << endl;
            return;
        }

        Mahasiswa* current = head;
        do {
            if (current->jenisKelamin == 'P') {
                cout << current->nama << " adalah mahasiswi." << endl;
            } else {
                cout << current->nama << " adalah mahasiswa." << endl;
            }
            current = current->next;
        } while (current != head);
    }

    // Menampilkan daftar mahasiswa dalam lingkaran
    void tampilkanMahasiswa() {
        if (!head) {
            cout << "Lingkaran kosong." << endl;
            return;
        }

        Mahasiswa* current = head;
        cout << "Daftar Mahasiswa dalam Lingkaran [kiri = lebih dulu diinput]\n";
        do {
            cout << current->nama << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Memindah urutan bernyanyi
    void pindahUrutanBernyanyi() {
        if (!head) {
            cout << "Lingkaran kosong." << endl;
            return;
        }

        head = head->next; // Pindahkan kepala ke mahasiswa berikutnya
        tampilkanMahasiswa();
    }

    // Tambahkan fungsi baru ke dalam kelas LingkaranMahasiswa
    void tampilkanMahasiswaBerdasarkanJenisKelamin(char jenisKelamin) {
        if (!head) {
            cout << "Lingkaran kosong." << endl;
            return;
        }

        Mahasiswa* current = head;
        cout << "Daftar Mahasiswa ";
        if (jenisKelamin == 'L') {
            cout << "Laki-Laki";
        } else if (jenisKelamin == 'P') {
            cout << "Perempuan";
        }
        cout << ": ";

        do {
            if (current->jenisKelamin == jenisKelamin) {
                cout << current->nama << " ";
            }
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    // Mengambil mahasiswa yang sedang bernyanyi
    string mahasiswaSedangBernyanyi() {
        string alp;
        if (!head) {
            return "Lingkaran kosong.";
        }

        return head->nama;
        cout << "Yang sedang bernyanyi adalah " << head -> nama;
        cout << "Lanjut";
        cin >> alp;
        cout << endl;
    }
};

int main() {
    LingkaranMahasiswa lingkaran;
    int pilihan;
    system("cls");

    do {
        cout << "|===============================|" << endl;
        cout << "|    CAMPING DI GUNUNG ANYAR    |" << endl;
        cout << "|===============================|" << endl;
        cout << endl;
        cout << "1. Tambah Mahasiswa di Depan" << endl;
        cout << "2. Tambah Mahasiswa di Tengah" << endl;
        cout << "3. Hapus Mahasiswa Berdasarkan Nama" << endl << endl;
        cout << "4. Tampilkan Data Berdasarkan Kelamin" << endl;
        cout << "5. Tampilkan Seluruh Isi List" << endl << endl;
        cout << "6. Rolling Urutan Bernyanyi" << endl;
        cout << "7. Mahasiswa yang Sedang Bernyanyi" << endl << endl;
        cout << "8. Cetak Mahasiswa Laki-Laki" << endl;
        cout << "9. Cetak Mahasiswa Perempuan" << endl;
        cout << "0. Keluar" << endl << endl;
        cout << "Pilih Menu ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                lingkaran.tambahMahasiswa();
                break;
            case 2:
                {
                    string nama;
                    char jenisKelamin;

                    cout << "Masukkan nama mahasiswa: ";
                    cin >> nama;
                    cout << "Masukkan jenis kelamin (L/P): ";
                    cin >> jenisKelamin;

                    lingkaran.tambahMahasiswaDiTengah(nama, jenisKelamin);
                }
                break;

            case 3:
                lingkaran.hapusMahasiswa();
                break;
            case 4:
                lingkaran.pisahkanJenisKelamin();
                break;
            case 5:
                lingkaran.tampilkanMahasiswa();
                break;
            case 6:
                lingkaran.pindahUrutanBernyanyi();
                break;
            case 7:
                cout << "Sedang bernyanyi: " << lingkaran.mahasiswaSedangBernyanyi() << endl;
                break;
            case 8:
                lingkaran.tampilkanMahasiswaBerdasarkanJenisKelamin('L');
                break;
            case 9:
                lingkaran.tampilkanMahasiswaBerdasarkanJenisKelamin('P');
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:;
        }
    } while (pilihan != 0);

    return 0;
}
