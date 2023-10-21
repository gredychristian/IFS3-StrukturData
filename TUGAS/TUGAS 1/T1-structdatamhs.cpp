#include <iostream>
#include <cstring>
using namespace std;

//GREDY CHRISTIAN HENDRAWAN PUTRA
//22081010195
//STRUKTUR DATA E081
//TUGAS 1

// DEKLARASI ISI STRUCT MAHASISWA
struct Mahasiswa
{
    char nama[50];
    char npm[12];
    char ipk[5];
};

// TEMPLATE MENU
void listMenu()
{
    cout << "|          MAIN  MENU          |" << endl;
    cout << "|==============================|" << endl << endl;
    cout << "1. Masukkan data mahasiswa" << endl;
    cout << "2. Perbarui data mahasiswa" << endl;
    cout << "3. Tampilkan data mahasiswa" << endl;
    cout << "4. Hapus data mahasiswa" << endl;
    cout << "5. Tambahkan data mahasiswa baru" << endl;
    cout << "6. Keluar" << endl;
    cout << "PILIH MENU (1-6) -> ";
}

// MENU 1 INPUT DATA
void inputMhs(struct Mahasiswa mahasiswa[], int &jumlahmhs, int &cekdata)
{
    if (!cekdata)
    {
        cout << "Jumlah mahasiswa yang akan didata -> ";
        cin >> jumlahmhs;
        cin.ignore(); // Membersihkan newline di buffer
        int i;
        for (i = 0; i < jumlahmhs; i++)
        {
            int s = i + 1;
            cout << "Masukkan biodata mahasiswa ke-" << s << endl;
            cout << "Nama\t: ";
            //cin.ignore(); // Membersihkan newline di buffer
            cin.getline(mahasiswa[i].nama, sizeof(mahasiswa[i].nama));
            cout << "NPM\t: ";
            cin.getline(mahasiswa[i].npm, sizeof(mahasiswa[i].npm)); // Menggunakan getline() untuk NPM
            cout << "IPK\t: ";
            cin.getline(mahasiswa[i].ipk, sizeof(mahasiswa[i].ipk));
        }

        cout << endl << "Data yang telah dimasukkan ->" << endl;
        for (i = 0; i < jumlahmhs; i++)
        {
            int s = i + 1;
            cout << "Data biodata mahasiswa ke-" << s << endl;
            cout << "Nama\t: " << mahasiswa[i].nama << endl;
            cout << "NPM\t: " << mahasiswa[i].npm << endl;
            cout << "IPK\t: " << mahasiswa[i].ipk << endl << endl;
        }
        cekdata = 1;
    }
    else
    {
        cout << "Data mahasiswa sudah ada." << endl << endl;
    }
}

// MENU 2 UPDATE DATA
void updateMhs(struct Mahasiswa mahasiswa[], int jumlahmhs, int cekdata)
{
    int i;
    cout << "Pilih mahasiswa yang akan diperbarui (1-" << jumlahmhs << ") -> ";
    cin >> i;
    if (i >= 1 && i <= jumlahmhs)
    {
        int s = i - 1;
        cout << "Masukkan data baru untuk mahasiswa ke-" << i << endl;
        cin.ignore(); // Membersihkan newline di buffer
        cout << "Nama\t: ";
        cin.getline(mahasiswa[s].nama, sizeof(mahasiswa[s].nama));
        cout << "NPM\t: ";
        cin.getline(mahasiswa[s].npm, sizeof(mahasiswa[s].npm)); // Menggunakan getline() untuk NPM
        cout << "IPK\t: ";
        cin.getline(mahasiswa[s].ipk, sizeof(mahasiswa[s].ipk));
        cout << "Data mahasiswa ke-" << i << " berhasil diperbarui." << endl << endl;
    }
    else
    {
        cout << "Nomor mahasiswa tidak valid." << endl << endl;
    }
}

// MENU 3 DISPLAY DATA
void displayMhs(struct Mahasiswa mahasiswa[], int jumlahmhs, int cekdata)
{
    if (cekdata)
    {
        int i;
        for (i = 0; i < jumlahmhs; i++)
        {
            int s = i + 1;
            cout << "Data biodata mahasiswa ke-" << s << endl;
            cout << "Nama\t: " << mahasiswa[i].nama << endl;
            cout << "NPM\t: " << mahasiswa[i].npm << endl;
            cout << "IPK\t: " << mahasiswa[i].ipk << endl << endl;
        }
    }
    else
    {
        cout << "Data mahasiswa tidak ada." << endl << endl;
    }
}

// MENU 4 DELETE DATA
void deleteMhs(struct Mahasiswa mahasiswa[], int &jumlahmhs, int &cekdata)
{
    if (cekdata)
    {
        int i;
        cout << "Pilih data yang ingin dihapus (1-" << jumlahmhs << ") -> ";
        cin >> i;
        if (i >= 1 && i <= jumlahmhs)
        {
            // Menggeser data mahasiswa setelah yang dihapus
            for (int j = i - 1; j < jumlahmhs - 1; j++)
            {
                strcpy_s(mahasiswa[j].nama, sizeof(mahasiswa[j].nama), mahasiswa[j + 1].nama);
                strcpy_s(mahasiswa[j].npm, sizeof(mahasiswa[j].npm), mahasiswa[j + 1].npm);
                strcpy_s(mahasiswa[j].ipk, sizeof(mahasiswa[j].ipk), mahasiswa[j + 1].ipk);
            }
            jumlahmhs--;
            cout << "Data mahasiswa ke-" << i << " berhasil dihapus." << endl << endl;
        }
        else
        {
            cout << "Nomor mahasiswa tidak valid." << endl << endl;
        }
    }
    else
    {
        cout << "Data mahasiswa tidak ada." << endl << endl;
    }
}

// MENU 5 ADD NEW DATA
void addMhs(struct Mahasiswa mahasiswa[], int &jumlahmhs, int &cekdata)
{
    if (cekdata)
    {
        if (jumlahmhs < 5)
        {
            cout << "Masukkan biodata mahasiswa baru" << endl;
            int s = jumlahmhs;
            cout << "Nama\t: ";
            cin.ignore(); // Membersihkan newline di buffer
            cin.getline(mahasiswa[s].nama, sizeof(mahasiswa[s].nama));
            cout << "NPM\t: ";
            cin.getline(mahasiswa[s].npm, sizeof(mahasiswa[s].npm));
            cout << "IPK\t: ";
            cin.getline(mahasiswa[s].ipk, sizeof(mahasiswa[s].ipk));

            jumlahmhs++;
            cout << "Data mahasiswa baru berhasil ditambahkan." << endl << endl;
        }
        else
        {
            cout << "Jumlah mahasiswa sudah mencapai batas maksimum (5)." << endl << endl;
        }
    }
    else
    {
        cout << "Data mahasiswa tidak ada." << endl << endl;
    }
}

// FUNGSI UTAMA
int main()
{
    int pilihanmenu;
    int jumlahmhs;
    struct Mahasiswa mahasiswa[5];
    int exit = 0;
    int cekdata = 0;
    cout << "|==============================|" << endl;
    cout << "|     DATA POKOK MAHASISWA     |" << endl;
    cout << "|    FAKULTAS ILMU KOMPUTER    |" << endl;
    cout << "|    UPN VETERAN JAWA TIMUR    |" << endl;
    cout << "|==============================|" << endl;
    while (!exit)
    {
        listMenu();
        cin >> pilihanmenu;
        cout << endl;
        cin.ignore(); // Membersihkan newline di buffer

        switch (pilihanmenu)
        {
            case 1:
                inputMhs(mahasiswa, jumlahmhs, cekdata);
                break;
            case 2:
                updateMhs(mahasiswa, jumlahmhs, cekdata);
                break;
            case 3:
                displayMhs(mahasiswa, jumlahmhs, cekdata);
                break;
            case 4:
                deleteMhs(mahasiswa, jumlahmhs, cekdata);
                break;
            case 5:
                addMhs(mahasiswa, jumlahmhs, cekdata);
                break;
            case 6:
                system("cls");
                cout << "|==============================|" << endl;
                cout << "|     DATA POKOK MAHASISWA     |" << endl;
                cout << "|    FAKULTAS ILMU KOMPUTER    |" << endl;
                cout << "|    UPN VETERAN JAWA TIMUR    |" << endl;
                cout << "|==============================|" << endl;
                cout << "|             DONE             |" << endl;
                cout << "|==============================|";
                exit = 1;
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi." << endl;
        }
    }
    return 0;
}
