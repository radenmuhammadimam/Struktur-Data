#include <iostream>
#include "TUBES_ASD.h"
#include "stdlib.h"
#include <string>
using namespace std;

int main()
{
    int pilihan;
    list_buku l1;
    list_pinjam l2;
    list_pelanggan l3;
    creatlistbuku(l1);
    creatlistpinjam(l2);
    creatlistpelanggan(l3);

    do {
    cout<<endl;
    cout << "=====PERPUSTAKAAN=====" << endl;
    cout<<" 1.  Print Buku "<<endl;
    cout<<" 2.  Input Buku "<<endl;
    cout<<" 3.  Delete Buku "<<endl;
    cout<<" 4.  Cari Buku "<<endl;
    cout<<" 5.  Daftar Anggota "<<endl;
    cout<<" 6.  Cek Anggota "<<endl;
    cout<<" 7.  Delete Anggota "<<endl;
    cout<<" 8.  Pinjam Buku "<<endl;
    cout<<" 9.  Pengembalian Buku "<<endl;
    cout<<" 10. Update Data Anggota "<<endl;
    cout<<" 11. Update Data Buku "<<endl;
    cout<<" 0.  Exit"<<endl;
    cin>>pilihan;
    switch(pilihan)
    {
        case 1:
            cout<<"---BUKU---"<<endl;
            printinfo(l1);
        break;

        case 2:
            {
            buku x;
            adr_buku p;
            string nmbuku;
            string pengarang;
            string jumhal;
            string kategori;
            string kdbuku;
            int jumbuk;
            system("cls");
            getline(cin, nmbuku);
            cout<<"Judul Buku     : "<<endl;
            getline(cin, nmbuku);
            cout<<"Pengarang Buku : "<<endl;
            getline(cin, pengarang);
            cout<<"Jumlah Halaman : "<<endl;
            getline(cin, jumhal);
            cout<<"Kategori Buku  : "<<endl;
            getline(cin, kategori);
            cout<<"Kode Buku      : "<<endl;
            getline(cin, kdbuku);
            cout<<"Jumlah Buku Yang Tersedia    : "<<endl;
            cin>>jumbuk;
            adr_buku cekbuku=find_buku(l1,kdbuku);
            if (cekbuku!=NULL)
            {
                cout<<"Buku Sudah Ada"<<endl;
                system("Pause");
                system("cls");
                x=creatbuku(nmbuku,pengarang,jumhal,kategori,kdbuku,jumbuk);
                p=alokasibuku(x);
                delete p;
            } else {
            x=creatbuku(nmbuku,pengarang,jumhal,kategori,kdbuku,jumbuk);
            p=alokasibuku(x);
            insertFirstbuku(l1,p);
            system("cls");
            }
        break;
            }
        case 3:
            {
            adr_buku p;
            string x;
            cout<<"Masukkan Kode Buku Yang Ingin Di Hapus : "<<endl;
            cin>>x;
            p=find_buku(l1,x);
            if(p==NULL){
                cout<<"Kode Buku Tersebut Tidak Ada"<<endl;
            } else {
            deletebuku(l1,p);
            }
        break;
            }

        case 4:
            {
            string x;
            cout<<"---PENCARIAN BUKU---"<<endl;
            cout<<"Masukkan Kode Buku : ";
            cin>>x;
            adr_buku p = find_buku(l1,x);
            if (p==NULL){
                cout<<"Tidak Ada Data Yang Di Temukan"<<endl;
            } else {
                cout<<"Judul     : "<<info(p).nmbuku<<endl;
                cout<<"Kode Buku : "<<info(p).kdbuku<<endl;
                cout<<"Pengarang : "<<info(p).pengarang<<endl;
                cout<<"Sisa Buku : "<<info(p).jumbuk<<endl;
            };
        break;
            }
                    case 5:
            {
                string nama,no_tlp,id_pel,email;
                adr_pelanggan p;
                pelanggan x;
                cout<<"----PENDAFTARAN ANGGOTA----"<<endl;
                getline(cin, nama);
                cout<<"Nama               : "<<endl;
                getline(cin, nama);
                cout<<"Nomor Telepon      : "<<endl;
                cin>>no_tlp;
                cout<<"ID Pelanggan Baru  : "<<endl;
                cin>>id_pel;
                cout<<"Email              : "<<endl;
                cin>>email;
                p=find_pelanggan(l3,id_pel);
                if (p==NULL) {
                    x=createpelanggan(nama,no_tlp,id_pel,email);
                    p=alokasipelanggan(x);
                    insertFirstpelanggan(l3,p);
                    cout<<"Selamat "<<nama<<"! Anda Sudah Terdaftar Jadi Anggota."<<endl;
                } else {
                cout<<"ID Sudah Terdaftar, Silahkan Coba Mendaftar Lagi."<<endl;
                }
                break;
            }
        case 6:
            {
                cout<<"----PELANGGAN-----"<<endl;
                printinfo_pelanggan(l3,l2);
                system("Pause");
                system("cls");
                break;
            }
        case 7:
            {
            string x;
            cout<<"--- DELETE ANGGOTA ---"<<endl;
            cout<<"Masukkan ID Anggota : ";
            cin>> x;
            cout<<endl;
            adr_pelanggan p=find_pelanggan(l3,x);
            if (p==NULL){
                cout<<"ID Tidak Ada"<<endl;

            } else {
            if (next_pinjam(p)!=NULL) {
                cout<<"Anda Sedang Meminjam Buku"<<endl;
                printinfo_pinjam(l2,p);
                cout<<"Silahkan Kemabalikan Buku Terlebih Dahulu"<<endl;
                system("Pause");
                system("cls");
            } else {
            deletepelanggan(l3,p);
            }
            }

            break;
            }
        case 8:
            {
                addpinjam(l3,l2,l1);
                break;
            }
        case 9:
            {
                cout<<"----PENGEMBALIAN BUKU----"<<endl;
                balikin(l3,l1,l2);
                break;
            }
        case 10:
            {
                update_pelanggan(l3);
                break;
            }
        case 11:
            {
                update_buku(l1);
                break;
            }
    }
    } while (pilihan != 0);
    return 0;
}
