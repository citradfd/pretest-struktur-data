#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// struct pegawai
struct Pegawai {
    string NIP;
    string nama;
    string alamat;
    string golongan;
    float gaji;
    Pegawai* next;
    Pegawai* prev;
};

// fungsi untuk menentukan golongan berdasarkan gaji
string tentukanGolongan(float gaji) {
    if (gaji <= 1000000) {
        return "1A";
    } else if (gaji <= 2000000) {
        return "1B";
    } else if (gaji <= 3000000) {
        return "2A";
    } else if (gaji <= 4000000) {
        return "2B";
    } else if (gaji <= 5000000) {
        return "3A";
    } else if (gaji <= 6000000) {
        return "3B";
    } else if (gaji <= 7000000) {
        return "4A";
    } else {
        return "4B";
    }
}

// fungsi untuk menambah data pegawai dari depan
void tambahDepan(Pegawai*& head, Pegawai*& tail) {
    Pegawai* pegawaiBaru = new Pegawai;
    cout << "Masukkan NIP: ";
    cin >> pegawaiBaru->NIP;
    cout << "Masukkan nama: ";
    cin >> pegawaiBaru->nama;
    cout << "Masukkan alamat: ";
    cin >> pegawaiBaru->alamat;
    cout << "Masukkan gaji: ";
    cin >> pegawaiBaru->gaji;
    pegawaiBaru->golongan = tentukanGolongan(pegawaiBaru->gaji);
    pegawaiBaru->prev = NULL;
    pegawaiBaru->next = head;
    if (head != NULL) {
        head->prev = pegawaiBaru;
    } else {
        tail = pegawaiBaru;
    }
    head = pegawaiBaru;
    cout << "Data berhasil ditambahkan!\n";
}

// fungsi untuk menambah data pegawai dari belakang
void tambahBelakang(Pegawai*& head, Pegawai*& tail) {
    Pegawai* pegawaiBaru = new Pegawai;
    cout << "Masukkan NIP: ";
    cin >> pegawaiBaru->NIP;
    cout << "Masukkan nama: ";
    cin >> pegawaiBaru->nama;
    cout << "Masukkan alamat: ";
    cin >> pegawaiBaru->alamat;
    cout << "Masukkan gaji: ";
    cin >> pegawaiBaru->gaji;
    pegawaiBaru->golongan = tentukanGolongan(pegawaiBaru->gaji);
    pegawaiBaru->next = NULL;
    pegawaiBaru->prev = tail;
    if (tail != NULL) {
        tail->next = pegawaiBaru;
    } else {
        head = pegawaiBaru;
    }
    tail = pegawaiBaru;
    cout << "Data berhasil ditambahkan!\n";
}

// fungsi untuk menambah data pegawai setelah key
void tambahSetelah(Pegawai*& head, Pegawai*& tail) {
    string key;
    cout << "Masukkan NIP key: ";
    cin >> key;
        Pegawai* current = head;
    while (current != NULL) {
        if (current->NIP == key) {
            Pegawai* pegawaiBaru = new Pegawai;
            cout << "Masukkan NIP: ";
            cin >> pegawaiBaru->NIP;
            cout << "Masukkan nama: ";
            cin >> pegawaiBaru->nama;
            cout << "Masukkan alamat: ";
            cin >> pegawaiBaru->alamat;
            cout << "Masukkan gaji: ";
            cin >> pegawaiBaru->gaji;
            pegawaiBaru->golongan = tentukanGolongan(pegawaiBaru->gaji);
            pegawaiBaru->prev = current;
            pegawaiBaru->next = current->next;
            if (current->next != NULL) {
                current->next->prev = pegawaiBaru;
            } else {
                tail = pegawaiBaru;
            }
            current->next = pegawaiBaru;
            cout << "Data berhasil ditambahkan!\n";
            return;
        }
        current = current->next;
    }
    cout << "Key tidak ditemukan.\n";
}

// fungsi untuk menampilkan seluruh data pegawai
void tampilkanData(Pegawai* head) {
    if (head == NULL) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    Pegawai* current = head;
    cout << "Data Pegawai:\n";
    while (current != NULL) {
        cout << "NIP: " << current->NIP << endl;
        cout << "Nama: " << current->nama << endl;
        cout << "Alamat: " << current->alamat << endl;
        cout << "Golongan: " << current->golongan << endl;
        cout << "Gaji: " << fixed << setprecision(2) << current->gaji << endl;
        cout << "-------------------------\n";
        current = current->next;
    }
}

// fungsi untuk menampilkan gaji tertinggi pegawai
void tampilkanGajiTertinggi(Pegawai* head) {
    if (head == NULL) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    float maxGaji = head->gaji;
    Pegawai* current = head->next;
    while (current != NULL) {
        if (current->gaji > maxGaji) {
            maxGaji = current->gaji;
        }
        current = current->next;
    }
    cout << "Gaji tertinggi: " << fixed << setprecision(2) << maxGaji << endl;
}

// fungsi untuk menampilkan rata-rata gaji pegawai
void tampilkanRataRataGaji(Pegawai* head) {
    if (head == NULL) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    float totalGaji = 0;
    int count = 0;
    Pegawai* current = head;
    while (current != NULL) {
        totalGaji += current->gaji;
        count++;
        current = current->next;
    }
    float rataRata = totalGaji / count;
    cout << "Rata-rata gaji: " << fixed << setprecision(2) << rataRata << endl;
}

// fungsi untuk menghapus data pegawai dari depan
void hapusDepan(Pegawai*& head, Pegawai*& tail) {
    if (head == NULL) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    Pegawai* hapus = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }
    delete hapus;
    cout << "Data pegawai berhasil dihapus dari depan.\n";
}

// fungsi untuk menghapus data pegawai dari belakang
void hapusBelakang(Pegawai*& head, Pegawai*& tail) {
    if (tail == NULL) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    Pegawai* hapus = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    delete hapus;
    cout << "Data pegawai berhasil dihapus dari belakang.\n";
}

// fungsi untuk menghapus data pegawai berdasarkan NIP yang diinput oleh user
void hapusDataNIP(Pegawai*& head, Pegawai*& tail, string NIP) {
    if (head == NULL) {
        cout << "Data pegawai kosong.\n";
        return;
    }
    Pegawai* current = head;
    while (current != NULL) {
        if (current->NIP == NIP) {
            if (current == head) {
                hapusDepan(head, tail);
            } else if (current == tail) {
                hapusBelakang(head, tail);
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                cout << "Data pegawai dengan NIP " << NIP << " berhasil dihapus.\n";
            }
            return;
        }
        current = current->next;
    }
    cout << "Data pegawai dengan NIP " << NIP << " tidak ditemukan.\n";
}

int main() {
    Pegawai* head = NULL;
    Pegawai* tail = NULL;
    int pilihan;
    string key, NIP;

    do {
        cout << "\n=== PROGRAM MANAJEMEN PEGAWAI ===\n";
        cout << "1. Tambah Data Pegawai dari Depan\n";
        cout << "2. Tambah Data Pegawai dari Belakang\n";
        cout << "3. Tambah Data Pegawai Setelah Key\n";
        cout << "4. Tampilkan Seluruh Data Pegawai\n";
        cout << "5. Tampilkan Gaji Tertinggi Pegawai\n";
        cout << "6. Tampilkan Rata-rata Gaji Pegawai\n";
        cout << "7. Hapus Data Pegawai dari Depan\n";
        cout << "8. Hapus Data Pegawai dari Belakang\n";
        cout << "9. Hapus Data Pegawai dengan NIP\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDepan(head, tail);
                break;
            case 2:
                tambahBelakang(head, tail);
                break;
            case 3:
                tambahSetelah(head, tail);
                break;
            case 4:
                                tampilkanData(head);
                break;
            case 5:
                tampilkanGajiTertinggi(head);
                break;
            case 6:
                tampilkanRataRataGaji(head);
                break;
            case 7:
                hapusDepan(head, tail);
                break;
            case 8:
                hapusBelakang(head, tail);
                break;
            case 9:
                cout << "Masukkan NIP yang ingin dihapus: ";
                cin >> NIP;
                hapusDataNIP(head, tail, NIP);
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    // dealokasi semua node pada linked list
    Pegawai* current = head;
    while (current != NULL) {
        Pegawai* hapus = current;
        current = current->next;
        delete hapus;
    }

    return 0;
}