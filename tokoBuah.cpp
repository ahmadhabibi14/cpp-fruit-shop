#include <iostream>
using namespace std;

struct InfoUser {
   string   uname;
   string   pass;
};

struct {
   string   barang;
} BarangDiBeli[5];

bool login() {
   cout << "+ ======================================= + \n";
   cout << "|                 LOGIN                   | \n";
   cout << "+ ======================================= + \n";
   bool u, p;
   InfoUser user;
   inputUsername:
      cout << "Masukkan username : "; cin >> user.uname;
      if (user.uname != "habibi") {
         cout << "Username salah !! \n";
         goto inputUsername;
      } else {
         u = true;
      }
   inputPassword:
      cout << "Masukkan password : "; cin >> user.pass;
      if (user.pass != "hbb") {
         cout << "Password salah !! \n";
         goto inputPassword;
      } else {
         p = true;
      }
   return true;
}

void menuBuah() {
   cout << "+ ======================================= + \n";
   cout << "|          TOKO BUAH HAABIBICH            | \n";
   cout << "+ ======================================= + \n";
   cout << "|  Silahkan pilih Buah untuk dibeli...    | \n";
   cout << "|  [1] Apel          |           Rp.7000  | \n";
   cout << "|  [2] Jeruk         |           Rp.3000  | \n";
   cout << "|  [3] Pepaya        |          Rp.10000  | \n";
   cout << "|  [4] Stroberi      |           Rp.2000  | \n";
   cout << "|  [5] Mangga        |           Rp.4000  | \n";
   cout << "+ ======================================= + \n";
   cout << "|  Maksimal belanja : 5 buah              | \n";
   cout << "+ ======================================= + \n";
}

void berhasilBeli() {
   cout << "+ ======================================= + \n";
   cout << "|  Buah berhasil dibeli                   | \n";
   cout << "+ ======================================= + \n";
}

void beliBuah() {
   // BarangDiBeli buah;
   int max = 6, top = 0;
   // string keranjangBuah[max];
   int totalHarga = 0;
   string beliLagi;
   int kode;
   int nominalBayar;

   do {
      system("clear");
      menuBuah();
      if (top == max - 1) {
         beliLagi == "t";
         system("clear");
         cout << "+ ======================================= + \n";
         cout << "|  Keranjang Penuh !!!                    | \n";
         cout << "+ ======================================= + \n";
      } else {
         inputBuah:
            cout << "> "; cin >> kode;
            if (kode == 1) {
               BarangDiBeli[top].barang = "Apel";
               totalHarga += 7000;
               top++;
            } else if (kode == 2) {
               BarangDiBeli[top].barang = "Jeruk";
               totalHarga += 3000;
               top++;
            } else if (kode == 3) {
              BarangDiBeli[top].barang = "Pepaya";
              totalHarga += 10000;
              top++;
            } else if (kode == 4) {
              BarangDiBeli[top].barang = "Stroberi";
              totalHarga += 2000;
              top++;
            } else if (kode == 5) {
              BarangDiBeli[top].barang = "Mangga";
              totalHarga += 4000;
              top++;
            } else {
               cout << "salahketik" << endl;
               goto inputBuah;
            }
      }
      cout << "Isi Keranjang : " <<endl;
      for (int a = 0; a < top; a++) {
         cout << a + 1 << ". " << BarangDiBeli[a].barang << endl;
      }
      cout << BarangDiBeli[top].barang << endl;
      cout << totalHarga << endl;
      cout << "Beli buah lagi (y = ya, t/random = tidak): ";
      cin >> beliLagi;
   } while (beliLagi == "y" || beliLagi == "Y");

   system("clear");
   cout << "+ ======================================= + \n";
   cout << "  Total Harga : " << totalHarga << "\n";
   cout << "+ ======================================= + \n";

   bayar:
   cout << "Masukkan nominal pembayaran : "; cin >> nominalBayar;
   if (nominalBayar < totalHarga) {
      cout << "Uang anda tidak cukup !!" << endl;
      goto bayar;
   } else if (nominalBayar > totalHarga) {
      system("clear");
      berhasilBeli();
      cout << "Kembalian : " << nominalBayar - totalHarga << endl;
   } else {
      system("clear");
      berhasilBeli();
      cout << "Uang pas !!" << endl;
   }
}

int main() {
   if (login() == true) {
      system("clear");
      beliBuah();
   }
   return 0;
}
