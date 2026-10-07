#include <iostream>
#include <string>
using namespace std;

// Class dasar
class Kendaraan {
public:
    string jenis;
    int lamaParkir;

    void inputKendaraan() {
        cout << "Masukkan jenis kendaraan (Mobil/Motor): ";
        cin >> jenis;
        cout << "Masukkan lama parkir (jam): ";
        cin >> lamaParkir;
    }
};

// Class turunan pertama (multilevel)
class Parkir : public Kendaraan {
protected:
    int tarifMobil;
    int tarifMotor;

public:
    Parkir(int tarifMobil, int tarifMotor) {
        this->tarifMobil = tarifMobil;
        this->tarifMotor = tarifMotor;
    }

    int hitungBayar() {
        if (jenis == "Mobil") {
            return lamaParkir * tarifMobil;
        } else if (jenis == "Motor") {
            return lamaParkir * tarifMotor;
        } else {
            return 0;
        }
    }
};

// Class tambahan untuk multiple inheritance
class Diskon {
public:
    int hitungDiskon(int total) {
        if (total >= 20000) {
            return total * 0.1; // diskon 10% jika total >= 20 ribu
        }
        return 0;
    }
};

// Class turunan kedua (multilevel + multiple)
class Pembayaran : public Parkir, public Diskon {
public:
    Pembayaran(int tarifMobil, int tarifMotor) : Parkir(tarifMobil, tarifMotor) {}

    void prosesBayar(int uangBayar) {
        int total = hitungBayar();
        int potongan = hitungDiskon(total);
        int totalBayar = total - potongan;

        cout << "Nominal yang harus dibayar : Rp " << total << endl;
        if (potongan > 0) {
            cout << "Diskon diberikan           : Rp " << potongan << endl;
        }
        cout << "Total setelah diskon       : Rp " << totalBayar << endl;
        cout << "Uang Dibayar               : Rp " << uangBayar << endl;

        if (uangBayar < totalBayar) {
            cout << "Maaf, uang anda kurang Rp " << totalBayar - uangBayar << endl;
        } else {
            cout << "Kembalian                  : Rp " << uangBayar - totalBayar << endl;
            cout << "Transaksi berhasil. Terima kasih!\n";
        }
    }
};

int main() {
    Pembayaran bayar(5000, 2000); // tarif mobil & motor
    int uangBayar;

    cout << "=== Sistem Pembayaran Parkir (Multilevel + Multiple Inheritance) ===\n";
    bayar.inputKendaraan();

    cout << "Masukkan Uang Bayar: Rp ";
    cin >> uangBayar;

    bayar.prosesBayar(uangBayar);

    return 0;
}