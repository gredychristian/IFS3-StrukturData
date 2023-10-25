#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definisi struktur data mahasiswa
struct Mahasiswa {
    string nama;
    char jenisKelamin;
    Mahasiswa* next;
};

// Fungsi untuk menambahkan mahasiswa ke dalam lingkaran
void tambahMahasiswa(Mahasiswa*& head, string nama, char jenisKelamin) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->jenisKelamin = jenisKelamin;
    newMahasiswa->next = nullptr;

    if (!head) {
        head = newMahasiswa;
        newMahasiswa->next = newMahasiswa;
    } else {
        Mahasiswa* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newMahasiswa;
        newMahasiswa->next = head;
    }
}

// Fungsi untuk menyisipkan mahasiswa ke dalam lingkaran pada posisi tertentu
void sisipkanMahasiswa(Mahasiswa*& head, string nama, char jenisKelamin, int posisi) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->jenisKelamin = jenisKelamin;

    if (!head) {
        head = newMahasiswa;
        newMahasiswa->next = newMahasiswa;
    } else {
        if (posisi == 1) {
            Mahasiswa* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newMahasiswa;
            newMahasiswa->next = head;
            head = newMahasiswa;
        } else {
            int counter = 1;
            Mahasiswa* temp = head;
            while (counter < posisi - 1 && temp->next != head) {
                temp = temp->next;
                counter++;
            }
            newMahasiswa->next = temp->next;
            temp->next = newMahasiswa;
        }
    }
}

// Fungsi untuk menghapus mahasiswa dari lingkaran
void hapusMahasiswa(Mahasiswa*& head, string nama) {
    if (head == nullptr) {
        return;
    }

    Mahasiswa* current = head;
    Mahasiswa* previous = nullptr;

    while (current->next != head) {
        if (current->nama == nama) {
            if (current == head) {
                Mahasiswa* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
                delete current;
                return;
            } else {
                previous->next = current->next;
                delete current;
                return;
            }
        }

        previous = current;
        current = current->next;
    }

    // Check if the last node is the one to be deleted
    if (current->nama == nama) {
        if (current == head) {
            head = nullptr;
        } else {
            previous->next = head;
        }
        delete current;
    }
}

// Fungsi untuk majukan urutan bernyanyi
Mahasiswa* lanjutkanBernyanyi(Mahasiswa* current) {
    return current->next;
}

// Fungsi untuk menampilkan mahasiswa yang sedang bernyanyi
void tampilkanMahasiswaYangBernyanyi(Mahasiswa* current) {
    cout << "Mahasiswa yang sedang bernyanyi: " << current->nama << " (Jenis Kelamin: " << current->jenisKelamin << ")" << endl;
}

// Fungsi untuk menampilkan linked list mahasiswa
void tampilkanLinkedList(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "Lingkaran mahasiswa kosong." << endl;
        return;
    }

    Mahasiswa* current = head;
    do {
        cout << "Mahasiswa: " << current->nama << " (Jenis Kelamin: " << current->jenisKelamin << ")" << endl;
        current = current->next;
    } while (current != head);
}

int main() {
    Mahasiswa* lingkaranHead = nullptr;
    Mahasiswa* mahasiswaYangSedangBernyanyi = nullptr;
    vector<Mahasiswa> dataMahasiswa;

    int pilihan;
    string nama;
    char jenisKelamin;

    do {
        cout << "|=========================|" << endl;
        cout << "| CAMPING DI GUNUNG ANYAR |" << endl;
        cout << "|=========================|" << endl;

        cout << "Menu:" << endl;
        cout << "1. Tambah Mahasiswa ke Lingkaran" << endl;
        cout << "2. Sisipkan Mahasiswa ke Tengah Linked List" << endl;
        cout << "3. Hapus Mahasiswa dari Lingkaran" << endl;
        cout << "4. Majukan Urutan Bernyanyi" << endl;
        cout << "5. Tampilkan Mahasiswa yang Sedang Bernyanyi" << endl;
        cout << "6. Tampilkan Linked List Mahasiswa" << endl;
        cout << "7. Tampilkan Data Mahasiswa" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan jenis kelamin (L/P): ";
                cin >> jenisKelamin;
                tambahMahasiswa(lingkaranHead, nama, jenisKelamin);
                if (!mahasiswaYangSedangBernyanyi) {
                    mahasiswaYangSedangBernyanyi = lingkaranHead;
                }
                dataMahasiswa.push_back({nama, jenisKelamin});
                break;
            case 2:
                cout << "Masukkan nama mahasiswa: ";
                cin >> nama;
                cout << "Masukkan jenis kelamin (L/P): ";
                cin >> jenisKelamin;
                int posisi;
                cout << "Masukkan posisi (nomer berapa) untuk menyisipkan: ";
                cin >> posisi;
                sisipkanMahasiswa(lingkaranHead, nama, jenisKelamin, posisi);
                dataMahasiswa.push_back({nama, jenisKelamin});
                break;
            case 3:
                cout << "Masukkan nama mahasiswa yang akan dihapus: ";
                cin >> nama;
                hapusMahasiswa(lingkaranHead, nama);
                if (lingkaranHead) {
                    mahasiswaYangSedangBernyanyi = lingkaranHead;
                } else {
                    mahasiswaYangSedangBernyanyi = nullptr;
                }
                dataMahasiswa.erase(
                    remove_if(dataMahasiswa.begin(), dataMahasiswa.end(),
                              [nama](const Mahasiswa& mhs) { return mhs.nama == nama; }),
                    dataMahasiswa.end());
                break;
            case 4:
                if (mahasiswaYangSedangBernyanyi) {
                    mahasiswaYangSedangBernyanyi = lanjutkanBernyanyi(mahasiswaYangSedangBernyanyi);
                }
                break;
            case 5:
                if (mahasiswaYangSedangBernyanyi) {
                    tampilkanMahasiswaYangBernyanyi(mahasiswaYangSedangBernyanyi);
                } else {
                    cout << "Tidak ada mahasiswa yang sedang bernyanyi." << endl;
                }
                break;
            case 6:
                tampilkanLinkedList(lingkaranHead);
                break;
            case 7:
                if (dataMahasiswa.empty()) {
                    cout << "Belum ada data mahasiswa." << endl;
                } else {
                    cout << "Data Mahasiswa:" << endl;
                    for (const Mahasiswa& mhs : dataMahasiswa) {
                        cout << "Nama: " << mhs.nama << " Jenis Kelamin: " << mhs.jenisKelamin << endl;
                    }
                }
                break;
            case 8:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 8);

    while (lingkaranHead != nullptr) {
        Mahasiswa* temp = lingkaranHead;
        lingkaranHead = lingkaranHead->next;
        delete temp;
    }

    return 0;
}
