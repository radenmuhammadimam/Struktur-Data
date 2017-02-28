#include <iostream>
#include "TUBES_ASD.h"
#include "stdlib.h"

using namespace std;

buku creatbuku(string nmbuku, string pengarang, string jumhal, string kategori,
               string kdbuku, int jumbuk)
{
    buku b;
    b.nmbuku=nmbuku;
    b.pengarang=pengarang;
    b.jumhal=jumhal;
    b.kategori=kategori;
    b.kdbuku=kdbuku;
    b.jumbuk=jumbuk;
    return b;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

pinjam createpinjam(int tanggal, int bulan, int tahun)
{
    pinjam x;
    x.tanggal=tanggal;
    x.bulan=bulan;
    x.tahun=tahun;
    return x;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

pelanggan createpelanggan(string nama, string no_tlp, string id_pel, string email)
{
    pelanggan x;
    x.nama = nama;
    x.no_tlp = no_tlp;
    x.id_pel = id_pel;
    x.email = email;
    return x;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void creatlistbuku(list_buku &l)
{
    first(l) = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void creatlistpelanggan(list_pelanggan &l)
{
    first(l) = NULL;
    last(l) = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void creatlistpinjam(list_pinjam &l)
{
    first(l) = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adr_buku alokasibuku(infotypeb x)
{
    adr_buku p = new elmlistbuku;
    info(p) = x;
    next(p) = NULL;
    return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adr_pinjam alokasipinjam (infotype_pinjam x)
{
    adr_pinjam p = new elmlistpinjam;
    info(p) = x;
    next(p) = NULL;
    next_buku(p) = NULL;
    return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adr_pelanggan alokasipelanggan (infotype_pelanggan x)
{
    adr_pelanggan p = new elmlistpelanggan;
    info(p) = x;
    next(p) = NULL;
    next_pinjam(p) = NULL;
    prev(p) = NULL;

    return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dealokasibuku(adr_buku &p)
{
    delete p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dealokasipinjam(adr_pinjam &p)
{
    delete p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dealokasipelanggan(adr_pelanggan &p)
{
    delete p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void insertFirstbuku(list_buku &l, adr_buku p)
{
    if (first(l) == NULL)
    {
        first(l) = p;
    } else {
    next(p) = first(l);
    first(l) = p;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void insertFirstpelanggan(list_pelanggan &l, adr_pelanggan p)
{
    if (first(l) == NULL)
    {
        first(l) = p;
        last(l) = p;
    }
    else {
            next(p) = first(l);
            prev(first(l)) = p;
            first(l) = p;

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deleteFirstpinjam (list_pinjam &l, adr_pinjam &p)
{
	if(first(l) == NULL)
    {
        cout<<"List Kosong"<<endl;
    } else {
    p = first(l);
    first(l) = next(p);
    next(p) = NULL;
    dealokasipinjam(p);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deletebuku(list_buku &l, adr_buku &p)
{
    if (first(l)==NULL){
        cout<<"List Kosong"<<endl;
    } else {
        adr_buku q;
        adr_buku cekfirst=first(l);
        if ((cekfirst==p)&&(next(p)==NULL)){
            first(l)=NULL;
            dealokasibuku(p);

        } else if ((cekfirst==p)&&(next(p)!=NULL)){
            q = next(p);
            first(l) = q;
            next(p) = NULL;
            dealokasibuku(p);

        } else if ((p!=first(l))&&(next(p)==NULL)){
            q = first(l);
            while((next(q)!=NULL)&&(next(q)!=p)){
                q = next(q);
            }
            next(q) = NULL;
            dealokasibuku(p);
        } else if ((p!=first(l))&&(next(p)!=NULL)){
            q = first(l);
            while((next(q)!=NULL)&&(next(q)!=p)){
                q = next(q);
            }
            next(q) = next(p);
            next(p) = NULL;
            dealokasibuku(p);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deletepelanggan(list_pelanggan &l, adr_pelanggan &p)
{
    if (first(l)==NULL){
        cout<<"List Kosong"<<endl;
    } else {
        adr_pelanggan q;
        if ((p == first(l))&&(next(p) == NULL)){
            first(l) = NULL;
            next_pinjam(p) = NULL;
            prev(p) = NULL;
            next(p) = NULL;
            dealokasipelanggan(p);
        } else if ((p == first(l))&&(next(p) != NULL)){
            q = next(p);
            next_pinjam(p) = NULL;
            first(l) = q;
            prev(q) = NULL;
            prev(p) = NULL;
            next(p) = NULL;
            dealokasipelanggan(p);
        } else if (p == last(l)){
            q = prev(p);
            next_pinjam(p) = NULL;
            next(q) = NULL;
            prev(p) = NULL;
            dealokasipelanggan(p);
        } else if ((p != first(l))&&(p != last(l))&&(next(p)!=NULL)){
            q = prev(p);
            next_pinjam(p) = NULL;
            next(q) = next(p);
            prev(p) = NULL;
            next(p) = NULL;
            dealokasipelanggan(p);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deleteLastbuku(list_buku &l, adr_buku &p)
{
    if (first(l) == NULL)
    {
        cout<<"List Kosong"<<endl;
    } else {
    adr_buku q;
    p=first(l);
    while(next(p) != NULL){
        q = p;
        p = next(p);
    }
    next(q) = NULL;
    dealokasibuku(p);
    }
    cout<<"List Sudah Terhapus"<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printinfo (list_buku l)
{
    adr_buku p = first(l);
    if (first(l) != NULL){
        while(p != NULL){
            cout<<"Judul Buku                : "<<info(p).nmbuku<<endl;
            cout<<"Pengarang Buku            : "<<info(p).pengarang<<endl;
            cout<<"Jumlah Halaman            : "<<info(p).jumhal<<endl;
            cout<<"Kategori Buku             : "<<info(p).kategori<<endl;
            cout<<"Kode Buku                 : "<<info(p).kdbuku<<endl;
            cout<<"Jumlah Buku Yang Tersedia : "<<info(p).jumbuk<<endl;
            cout<<" "<<endl;
            p=next(p);
    }
    } else {
    cout<<"List Kosong"<<endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printinfo_pinjam (list_pinjam l, adr_pelanggan p1)
{
    adr_pinjam p = next_pinjam(p1);
    if (p != NULL){
    while (p != NULL){
        cout<<info(p).tanggal<<"/"<<info(p).bulan<<"/"<<info(p).tahun<<endl;
        adr_buku q;
        q = next_buku(p);
        cout<<"Judul Buku                 : "<<info(q).nmbuku<<endl;
        cout<<"Pengarang Buku             : "<<info(q).pengarang<<endl;
        cout<<"Jumlah Halaman             : "<<info(q).jumhal<<endl;
        cout<<"Kategori Buku              : "<<info(q).kategori<<endl;
        cout<<"Kode Buku                  : "<<info(q).kdbuku<<endl;
        cout<<"Jumlah Buku Yang Tersedia  : "<<info(q).jumbuk<<endl;
        cout<<" "<<endl;
        p = next(p);
    }
    } else {
        cout<<"Tidak Ada Buku Yang Di Pinjam"<<endl;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printinfo_pelanggan (list_pelanggan l, list_pinjam l2)
{
    adr_pelanggan p;
    adr_pinjam q;
    string x;
    if (first(l) != NULL){
            cout<<" Masukkan ID Pelanggan : "<<endl;
            cin>>x;
            cout<<"======INFO======="<<endl;
            p = find_pelanggan(l,x);
            if (p != NULL){
            cout<<"Nama          : "<<info(p).nama<<endl;
            cout<<"Nomor Telepon : "<<info(p).no_tlp<<endl;
            cout<<"ID Pelanggan  : "<<info(p).id_pel<<endl;
            cout<<"Email         : "<<info(p).email<<endl;
            cout<<" "<<endl;
            q = next_pinjam(p);
            if (q != NULL){
            while (q != NULL)
            {
                cout<<info(q).tanggal<<"/"<<info(q).bulan<<"/"<<info(q).tahun<<endl;
                adr_buku r;
                r = next_buku(q);
                cout<<"Judul Buku     : "<<info(r).nmbuku<<endl;
                cout<<"Pengarang Buku : "<<info(r).pengarang<<endl;
                cout<<"Jumlah Halaman : "<<info(r).jumhal<<endl;
                cout<<"Kategori Buku  : "<<info(r).kategori<<endl;
                cout<<"Kode Buku      : "<<info(r).kdbuku<<endl;
                cout<<" "<<endl;
                q=next(q);
            }
            } else {
                cout<<"Tidak Ada Buku Yang Di Pinjam"<<endl;
            }

       } else {
       cout<<"Pelanggan Belum Ada"<<endl;
       }
  } else {
    cout<<"List Kosong"<<endl;
  }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adr_buku find_buku (list_buku l, string x)
{
    adr_buku p;
    p = first(l);
    while (p != NULL) {
        if (info(p).kdbuku == x){
            return p;
        } else {
        p=next(p);
        }
    } return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adr_pinjam find_pinjam(list_pinjam l,list_pelanggan l1,adr_buku b, adr_pelanggan b1)
{
    adr_pinjam p = NULL;
    p = next_pinjam(b1);
    if (next_pinjam(b1) != NULL){
        while (next(p) != NULL&&next_buku(p)!=b) {
            p = next(p);
            }
        if (next_buku(p) == b&&next_pinjam(b1)!=NULL)
        {
            return p;
        }
        else if (next_buku(p) != b&&next(p) == NULL){
            return NULL;
        }
    }
    else
        {
            return NULL;
        }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

adr_pelanggan find_pelanggan(list_pelanggan l,string x)
{
    adr_pelanggan p;
    if (first(l) == NULL) {
        return NULL;
    } else {
    p=first(l);
    while ((next(p) != NULL)&&(info(p).id_pel!=x)) {
            p = next(p);
    }
        if (info(p).id_pel == x){
            return p;
        } else if (info(p).id_pel != x && next(p)==NULL) {
          return NULL;
        }

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addbuku(list_pinjam l, list_buku l1, adr_pinjam &p, adr_buku p1)
{
    p = first(l);
    adr_buku q;
    string x;
    if (next_buku(p) == NULL)
    {
        cout<<"Masukkan Kode Buku Yang Ingin Di Pinjam : ";
        cin>>x;
        q = find_buku(l1,x);
        if (q == NULL)
        {
            cout<<"Tidak Ada Buku"<<endl;
            system("Pause");
            system("clr");
        }
        else
            {
                next_buku(p)=q;
                cout<<"Buku Ada"<<endl;
                cout<<"------Proses Pinjam Selesai-------"<<endl;
                cout<<"---------Selamat Membaca----------"<<endl;
            }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void addpinjam(list_pelanggan l3, list_pinjam l2, list_buku l1)
{
    pinjam y;
    adr_pelanggan p;
    adr_pinjam q;
    adr_buku r;
    string a;
    int tanggal,bulan,tahun;
    cout<<"Masukkan ID Pelanggan : "<<endl;
    cin>>a;
    p = find_pelanggan(l3,a);
    if (p == NULL){
        cout<<"ID Tidak Ada"<<endl;
    }
    else
        {
            cout<<"Tanggal : "<<endl;
            cin>>tanggal;
            cout<<"Bulan   : "<<endl;
            cin>>bulan;
            cout<<"Tahun   : "<<endl;
            cin>>tahun;
            y = createpinjam(tanggal,bulan,tahun);
            q = alokasipinjam(y);
            string kode;
            cout<<"Masukkan Kode Buku Yang Ingin Di Pinjam : ";
            cin>>kode;
            r = find_buku(l1,kode);
        if (r == NULL)
        {
            cout<<"Tidak Ada Buku"<<endl;
            dealokasipinjam(q);
        }
        else if (info(r).jumbuk == 0){
            cout<<"Buku Sedang Terpinjam Semua"<<endl;
        }
        else
            {
                if (next_pinjam(p) == NULL) {
                next_pinjam(p) = q;
                first(l2) = q;
            }
        else
            {
                adr_pinjam z = next_pinjam(p);
                next(q) = z;
                next_pinjam(p) = q;
                first(l2) = q;
            }
            info(r).jumbuk = info(r).jumbuk-1;
            next_buku(q) = r;
            cout<<"Buku Ada"<<endl;
            cout<<"------Proses Pinjam Selesai-------"<<endl;
            cout<<"---------Selamat Membaca----------"<<endl;
            cout<<" "<<endl;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hitung_denda(int db, int mb, int yb, list_pinjam &l, adr_pinjam p)
{
int d,y,m,hitung;
d = info(p).tanggal;
m = info(p).bulan;
y = info(p).tahun;

if (db<d) {
    if (m==2){
            if (y%4==0) {
                d=(29-d)+db;
            } else {
                d=(28-d)+db;
            }

    } else if (m%2==0) {
    d=(30*(mb-m)-d)+db;
    } else if (m%2==1) {
    d=(31*(mb-m)-d)+db;
    }
} else if ((db>=d)&&(mb==m)){
    d=db-d;
} else if ((db>=d)&&(mb!=m)){
    if (m==2){
            if (y%4==0) {
                d=(29-d)+db;
            } else {
                d=(28-d+db);
            }

    } else if (m%2==0) {
    d=(30*(mb-m)-d)+db;
    } else if (m%2==1) {
    d=(31*(mb-m)-d)+db;
    }
}
cout<<"Jumlah Hari Peminjaman : "<<d<<" Hari"<<endl;
if (d>=21){
    hitung=10000+((d-20)*1000);
} else {
    hitung=10000;
}
cout<<"Total Biaya : "<<hitung<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void balikin(list_pelanggan l3, list_buku l1, list_pinjam l2)
{
    string x,y;
                int d,m,t;
                adr_pelanggan p;
                adr_buku r;
                cout<<"Masukkan ID Pelanggan : ";
                cin>>x;
                cout<<" "<<endl;
                p = find_pelanggan(l3,x);
                if (p == NULL){
                    cout<<"Tidak Ada ID Tersebut"<<endl;
                } else {
                    adr_pinjam q=next_pinjam(p);
                    cout<<"Masukkan Kode Buku Yang Ingin Di Kembalikan : ";
                    cin>>y;
                    cout<<" "<<endl;
                    r = find_buku(l1,y);
                    if (r == NULL){
                        cout<<"Tidak Ada Kode Dengan ID Tersebut"<<endl;
                    } else {
                       adr_pinjam s=find_pinjam(l2,l3,r,p);

                       if (s == NULL)
                       {
                           cout<<"Buku Tersebut Tidak Sedang Dipinjam Oleh Anda"<<endl;
                       } else {
                            cout<<info(p).nama<<endl;
                            cout<<"---------------------"<<endl;
                            cout<<info(r).nmbuku<<"/"<<info(r).kdbuku<<endl;
                            cout<<"---------------------"<<endl;
                            cout<<info(s).tanggal<<"/"<<info(s).bulan<<endl;
                            info(r).jumbuk=info(r).jumbuk+1;
                            cout<<"---------------------"<<endl;
                            cout<<"Masukkan Tanggal Pengembalian"<<endl;
                            cout<<"Tanggal : ";
                            cin>>d;
                            cout<<"Bulan   : ";
                            cin>>m;
                            cout<<"Tahun   : ";
                            cin>>t;
                            hitung_denda(d,m,t,l2,s);
                        if ((next(s) == NULL)&&(next_pinjam(p) == s)){
                            next_buku(s) = NULL;
                            next_pinjam(p) = NULL;
                            dealokasipinjam(s);
                        } else if (next(s) != NULL && (next_pinjam(p)==s))
                        {
                            next_pinjam(p) = next(s);
                            next_buku(s) = NULL;
                            next(s) = NULL;
                            dealokasipinjam(s);
                        } else if ((next_pinjam(p) != s)&&(next(s) == NULL)){
                            adr_pinjam caris = next_pinjam(p);
                            while((next(caris) != NULL)&&(next(caris) != s))
                            {
                                caris = next(caris);
                            }
                            next(caris) = NULL;
                            next_buku(s) = NULL;
                            dealokasipinjam(s);
                        } else if ((next_pinjam(p)!=s)&&(next(s)!=NULL)){
                            adr_pinjam caris=next_pinjam(p);
                            while ((next(caris)!=NULL)&&(next(caris)!=s)) {
                                caris=next(caris);
                            }
                            next(caris)=next(s);
                            next_buku(s)=NULL;
                            next(s)=NULL;
                            dealokasipinjam(s);
                        }
                        }
                    }

                }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_pelanggan(list_pelanggan &l3)
{
    string x,nama,no_tlp,id_pel,email;
    cout<<"----UPDATE DATA----"<<endl;
    cout<<"Masukkan ID Pelanggan Anda : ";
    cin>>x;
    adr_pelanggan p=find_pelanggan(l3,x);
    cout<<"Nama          : "<<info(p).nama<<" ";
    cout<<"Nomor Telepon : "<<info(p).no_tlp<<" ";
    cout<<"ID Pelanggan  : "<<info(p).id_pel<<" ";
    cout<<"Email         : "<<info(p).email<<" ";
    cout<<"------------------"<<endl;
    getline(cin, info(p).nama);
    cout<<"Nama          : ";
    getline(cin, info(p).nama);
    cout<<"Nomor Telepon : ";
    cin>>info(p).no_tlp;
    cout<<"ID Pelanggan  : ";
    cin>>info(p).id_pel;
    cout<<"Email         : ";
    cin>>info(p).email;
    system("cls");
    cout<<"----Sudah Terupdate----"<<endl;
    cout<<"Nama          : "<<info(p).nama<<" ";
    cout<<"Nomor Telepon : "<<info(p).no_tlp<<" ";
    cout<<"ID Pelanggan  : "<<info(p).id_pel<<" ";
    cout<<"Email         : "<<info(p).email<<" ";
    system("Pause");
    system("cls");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void update_buku(list_buku &l2)
{
  string x,nmbuku,pengarang,jumhal,kategori,kdbuku;
    cout<<"----UPDATE DATA----"<<endl;
    cout<<"Masukkan Kode Buku : ";
    cin>>x;
    adr_buku p=find_buku(l2,x);
    cout<<"Nama           : "<<info(p).nmbuku;
    cout<<" "<<endl;
    cout<<"Pengarang      : "<<info(p).pengarang;
    cout<<" "<<endl;
    cout<<"Jumlah Halaman : "<<info(p).jumhal;
    cout<<" "<<endl;
    cout<<"Kategori       : "<<info(p).kategori;
    cout<<" "<<endl;
    cout<<"Kode Buku      : "<<info(p).kdbuku;
    cout<<" "<<endl;
    cout<<"Jumlah Buku    : "<<info(p).jumbuk;
    cout<<" "<<endl;
    cout<<"------------------"<<endl;
    cout<<"Update Pada Kode Buku "<<info(p).kdbuku;
    cout<<" "<<endl;
    getline(cin, info(p).nmbuku);
    cout<<"Judul Buku     : "<<endl;
    getline(cin, info(p).nmbuku);
    cout<<"Pengarang      : "<<endl;
    getline(cin, info(p).pengarang);
    cout<<"Jumlah Halaman : "<<endl;
    getline(cin, info(p).jumhal);
    cout<<"Kategori       : "<<endl;
    getline(cin, info(p).kategori);
    cout<<"Jumlah Buku    : "<<endl;
    cin>>info(p).jumbuk;
    system("cls");
    cout<<"----Sudah Terupdate----"<<endl;
    cout<<"Judul          : "<<info(p).nmbuku<<endl;
    cout<<"Pengarang      : "<<info(p).pengarang<<endl;
    cout<<"Jumlah Halaman : "<<info(p).jumhal<<endl;
    cout<<"Kategori       : "<<info(p).kategori<<endl;
    cout<<"Kode Buku      : "<<info(p).kdbuku<<endl;
    system("Pause");
    system("cls");
}
