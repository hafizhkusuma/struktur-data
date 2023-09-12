#include <iostream>
#include <string>
using namespace std;

// Mendefinisikan sebuah struct bernama 'Mahasiswa'
struct Mahasiswa {
    string nama;
    string nrp;
    int umur;
    double tinggi;
    double berat;
    string kota;
    string kecamatan;
    string kelurahan;
    int rw;
    int rt;
};

int main() {
    const int MAX_MAHASISWA = 100; // Ukuran maksimum array mahasiswa
    Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa;

    cout << "Masukkan jumlah mahasiswa (tidak lebih dari " << MAX_MAHASISWA << "): ";
    cin >> jumlahMahasiswa;
    cin.ignore();

    if (jumlahMahasiswa > MAX_MAHASISWA) {
        cout << "Jumlah mahasiswa melebihi kapasitas maksimum.\n";
        return 1;
    }

    // Mengisi data dalam array 'mahasiswa' dengan input dari pengguna
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        Mahasiswa m;

        cout << "\nMasukkan Data Mahasiswa ke-" << (i + 1) << ":\n";
        cout << "Nama: ";
        getline(cin, m.nama);

        cout << "NRP: ";
        getline(cin, m.nrp);

        cout << "Umur: ";
        cin >> m.umur;

        cout << "Tinggi (cm): ";
        cin >> m.tinggi;

        cout << "Berat (kg): ";
        cin >> m.berat;

        cin.ignore();

        cout << "Kota: ";
        getline(cin, m.kota);

        cout << "Kecamatan: ";
        getline(cin, m.kecamatan);

        cout << "Kelurahan: ";
        getline(cin, m.kelurahan);

        cout << "RW: ";
        cin >> m.rw;

        cout << "RT: ";
        cin >> m.rt;

        cin.ignore();

        mahasiswa[i] = m;
    }

    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Tambah Data Baru\n";
        cout << "3. Hapus Data\n";
        cout << "4. Ubah Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                cout << "\nData Mahasiswa:\n";
                for (int i = 0; i < jumlahMahasiswa; ++i) {
                    cout << "Mahasiswa ke-" << (i + 1) << ":\n";
                    cout << "Nama: " << mahasiswa[i].nama << endl;
                    cout << "NRP: " << mahasiswa[i].nrp << endl;
                    cout << "Umur: " << mahasiswa[i].umur << " tahun" << endl;
                    cout << "Tinggi: " << mahasiswa[i].tinggi << " cm" << endl;
                    cout << "Berat: " << mahasiswa[i].berat << " kg" << endl;
                    cout << "Kota: " << mahasiswa[i].kota << endl;
                    cout << "Kecamatan: " << mahasiswa[i].kecamatan << endl;
                    cout << "Kelurahan: " << mahasiswa[i].kelurahan << endl;
                    cout << "RW: " << mahasiswa[i].rw << endl;
                    cout << "RT: " << mahasiswa[i].rt << ":\n" << endl;
                }
                break;
            }

            case 2: {
                if (jumlahMahasiswa < MAX_MAHASISWA) {
                    Mahasiswa m;

                    cout << "\nMasukkan Data Mahasiswa Baru:\n";
                    cout << "Nama: ";
                    getline(cin, m.nama);

                    cout << "NRP: ";
                    getline(cin, m.nrp);

                    cout << "Umur: ";
                    cin >> m.umur;

                    cout << "Tinggi (cm): ";
                    cin >> m.tinggi;

                    cout << "Berat (kg): ";
                    cin >> m.berat;

                    cin.ignore();

                    cout << "Kota: ";
                    getline(cin, m.kota);

                    cout << "Kecamatan: ";
                    getline(cin, m.kecamatan);

                    cout << "Kelurahan: ";
                    getline(cin, m.kelurahan);

                    cout << "RW: ";
                    cin >> m.rw;

                    cout << "RT: ";
                    cin >> m.rt;

                    cin.ignore();

                    mahasiswa[jumlahMahasiswa] = m;
                    ++jumlahMahasiswa;
                    cout << "Data mahasiswa berhasil ditambahkan.\n";
                } else {
                    cout << "Kapasitas maksimum mahasiswa telah tercapai.\n";
                }
                break;
            }

            case 3: {
                if (jumlahMahasiswa > 0) {
                    int indeks;
                    cout << "Masukkan indeks data yang ingin dihapus: ";
                    cin >> indeks;

                    if (indeks >= 0 && indeks < jumlahMahasiswa) {
                        for (int i = indeks; i < jumlahMahasiswa - 1; ++i) {
                            mahasiswa[i] = mahasiswa[i + 1];
                        }
                        --jumlahMahasiswa;
                        cout << "Data mahasiswa berhasil dihapus.\n";
                    } else {
                        cout << "Indeks tidak valid.\n";
                    }
                } else {
                    cout << "Data mahasiswa kosong.\n";
                }
                break;
            }

            case 4: {
                if (jumlahMahasiswa > 0) {
                    int indeks;
                    cout << "Masukkan indeks data yang ingin diubah: ";
                    cin >> indeks;

                    if (indeks >= 0 && indeks < jumlahMahasiswa) {
                        cout << "\nUbah Data Mahasiswa ke-" << (indeks + 1) << ":\n";
                        cout << "Nama: ";
                        cin.ignore();
                        getline(cin, mahasiswa[indeks].nama);

                        cout << "NRP: ";
                        getline(cin, mahasiswa[indeks].nrp);

                        cout << "Umur: ";
                        cin >> mahasiswa[indeks].umur;

                        cout << "Tinggi (cm): ";
                        cin >> mahasiswa[indeks].tinggi;

                        cout << "Berat (kg): ";
                        cin >> mahasiswa[indeks].berat;

                        cin.ignore();

                        cout << "Kota: ";
                        getline(cin, mahasiswa[indeks].kota);

                        cout << "Kecamatan: ";
                        getline(cin, mahasiswa[indeks].kecamatan);

                        cout << "Kelurahan: ";
                        getline(cin, mahasiswa[indeks].kelurahan);

                        cout << "RW: ";
                        cin >> mahasiswa[indeks].rw;

                        cout << "RT: ";
                        cin >> mahasiswa[indeks].rt;

                        cin.ignore();

                        cout << "Data mahasiswa berhasil diubah.\n";
                    } else {
                        cout << "Indeks tidak valid.\n";
                    }
                } else {
                    cout << "Data mahasiswa kosong.\n";
                }
                break;
            }

            case 5:
                cout << "Terima kasih! Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
