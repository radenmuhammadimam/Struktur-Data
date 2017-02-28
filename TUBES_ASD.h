#ifndef TUBES_ASD_H_INCLUDED
#define TUBES_ASD_H_INCLUDED
#define Nil NULL
#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define next_buku(p) (p)->next_buku
#define next_pinjam(p) (p)->next_pinjam
#define first(l) ((l).first)
#define last(l) ((l).last)
#include <iostream>

using namespace std;

typedef struct buku infotypeb;
struct buku {
    string nmbuku;
    string pengarang;
    string jumhal;
    string kategori;
    string kdbuku;
    int jumbuk;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct elmlistbuku *adr_buku;
struct elmlistbuku
{
    infotypeb info;
    adr_buku next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct list_buku
{
    adr_buku first;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct pinjam infotype_pinjam;
struct pinjam {
	int tanggal;
	int bulan;
	int tahun;
	string pk_pinjam;

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct elmlistpinjam *adr_pinjam;
struct elmlistpinjam
{
	infotype_pinjam info;
	adr_pinjam next;
	adr_buku next_buku;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct list_pinjam
{
	adr_pinjam first;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct pelanggan infotype_pelanggan;
struct pelanggan
{
	string nama;
	string no_tlp;
	string id_pel;
    string email;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct elmlistpelanggan *adr_pelanggan;
struct elmlistpelanggan
{
	infotype_pelanggan info;
	adr_pelanggan next;
	adr_pelanggan prev;
	adr_pinjam next_pinjam;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct list_pelanggan
{
	adr_pelanggan first;
	adr_pelanggan last;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

buku creatbuku(string nmbuku, string pengarang, string jumhal, string kategori,string kdbuku, int jumbuk);
pinjam createpinjam(int tanggal, int bulan, int tahun, string pk_pinjam);
pelanggan createpelanggan(string nama, string no_tlp, string id_pel, string email);

void creatlistbuku(list_buku &l);
void creatlistpinjam(list_pinjam &l);
void creatlistpelanggan(list_pelanggan &l);

adr_buku alokasibuku (infotypeb x);
adr_pinjam alokasipinjam (infotype_pinjam x);
adr_pelanggan alokasipelanggan (infotype_pelanggan x);

void dealokasibuku(adr_buku &p);
void dealokasipinjam(adr_pinjam &p);
void dealokasipelanggan(adr_pelanggan &p);

void insertFirstbuku(list_buku &l, adr_buku p);
void insertFirstpinjam(list_pinjam &l, adr_pinjam p);
void insertLastpinjam(list_pinjam &l, adr_pinjam p, adr_pelanggan q);
void insertFirstpelanggan(list_pelanggan &l, adr_pelanggan p);

void deletebuku(list_buku &l, adr_buku &p);
void deleteFirstpinjam (list_pinjam &l, adr_pinjam &p);
void deletepelanggan (list_pelanggan &l, adr_pelanggan &p);
void deleteLastpinjam(list_buku &l,adr_pinjam &p);
void deleteAfterpinjam(list_pinjam &l, adr_pinjam &p,adr_pinjam prec);

void addbuku(list_pinjam l, list_buku l1,adr_pinjam &p);
void addpinjam(list_pelanggan l3, list_pinjam l2, list_buku l1);

adr_buku find_buku (list_buku l,string x);
adr_pinjam find_pinjam(list_pinjam l,list_pelanggan l1, adr_buku b, adr_pelanggan b1);
adr_pelanggan find_pelanggan(list_pelanggan l,string x);

void printinfo (list_buku l);
void printinfo_pinjam (list_pinjam l, adr_pelanggan p1);
void printinfo_pelanggan (list_pelanggan l, list_pinjam l2);

void hitung_denda(int db, int mb, int yb, list_pinjam &l, adr_pinjam p);
void balikin(list_pelanggan l3, list_buku l1, list_pinjam l2);

void update_pelanggan(list_pelanggan &l3);
void update_buku(list_buku &l2);

#endif // TUBES_ASD_H_INCLUDED
