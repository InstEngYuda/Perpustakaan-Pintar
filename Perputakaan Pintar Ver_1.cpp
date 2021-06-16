#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

struct bukumasuk
{
    string judul;
    int kodebuku;
    char nomorloker[5];
}inputbuku[100];
struct mencaribuku
{
    string judul;
}caribuku;
struct masukadmin
{
    string admin;
    string pass;
}loginadmin;
struct peminjamanbuku
{
    string kelas;
    string judul;
    string nama;
    int kodebuku;
    int tanggalpinjam;
    int tanggalkembali;
}peminjaman[100];

int b = -1;
int a = -1;
char yn;
stringstream ss;
void bukuyangmasuk()
{
            cout<<"\n"<<endl;
            cout<<"\t\t----------Input Buku----------"<<endl;
            cout<<endl;
            b++;
            cout<<"Masukan Data Buku Ke "<<b+1<<endl;
            cout<<"Masukan Judul Buku            : ";
            getline(cin, inputbuku[b].judul);
            ss.clear();
            cout<<"Masukan Kode Buku             : ";
            cin>>inputbuku[b].kodebuku;
            cout<<"Masukan Nomor Loker           : ";
            cin>>inputbuku[b].nomorloker;
            cin.get();
            cout<<endl;
}
void databasebukuperputakaan()
{
            cout<<"\n"<<endl;
            cout<<"\t\t----------Daftar Buku Yang Tersedia----------"<<endl;
            cout<<endl;
            cout<<"--------------------------------------------------"<<endl;
            cout<<"NO  Kode Buku        Judul Buku        Nomor Loker"<<endl;
            cout<<"--------------------------------------------------"<<endl;
            for(int c = 0; c<= b; c++)
            {
                cout<<c+1<<setw(6)<<inputbuku[c].kodebuku<<setw(24)<<inputbuku[c].judul<<setw(10)<<inputbuku[c].nomorloker<<endl;
            }
            cout<<endl;
}
void mencaribukuperpustakaan()
{
            cout<<"\n"<<endl;
            cout<<"\t\t----------Pencarian Loker Buku----------"<<endl;
            cout<<endl;
            cout<<"Masukan Judul Buku Yang Dicari: ";
            getline(cin,caribuku.judul);
            ss.clear();
            cout<<endl;
            for(int c = 0; c<=b; c++)
            {
                if(caribuku.judul == inputbuku[c].judul)
                {
                    cout<<"Buku       : "<< inputbuku[c].judul <<endl;
                    cout<<"Ada Diloker: "<< inputbuku[c].nomorloker <<endl;
                }
            }
            cout<<endl;
}
void transaksipeminjaman()
{
            cout<<"\n"<<endl;
            cout<<"\t\t----------Peminjaman Buku----------"<<endl;
            cout<<endl;
            a++;
            cout<<"Nama Peminjam                 : ";
            getline(cin, peminjaman[a].nama);
            cout<<"Kelas                         : ";
            getline(cin, peminjaman[a].kelas);
            cout<<"Judul Buku                    : ";
            getline(cin, peminjaman[a].judul);
            cout<<"Kode Buku                     : ";
            cin>>peminjaman[a].kodebuku;
            cout<<"Tanggal Pinjam                : ";
            cin>>peminjaman[a].tanggalpinjam;
            cout<<"Tanggal Kembali               : ";
            cin>>peminjaman[a].tanggalkembali;
            cout<<endl;
}
void laporanpeminjaman()
{
            cout<<"\n"<<endl;
            cout<<"\t\t----------Laporan Peminjaman Buku Perpustakaan----------"<<endl;
            cout<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            cout<<"No Nama         Kelas           Judul         Kode     Tanggal Pinjam      Tanggal Kembali"<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            for(int c = 0; c<=a; c++)
            {
                cout<<c+1<<setw(6)<<peminjaman[c].nama<<setw(19)<<peminjaman[c].kelas<<setw(16)<<peminjaman[c].judul<<setw(7)<<peminjaman[c].kodebuku<<setw(8)<<peminjaman[c].tanggalpinjam<<setw(20)<<peminjaman[c].tanggalkembali<<endl;
            }
            cout<<endl;
}
void cetaklaporan()
{
           ofstream laporan;
           laporan.open("Laporan Peminjaman");
           laporan<<"\n"<<endl;
            laporan<<"\t\t----------Laporan Peminjaman Buku Perpustakaan----------"<<endl;
            laporan<<endl;
            laporan<<"------------------------------------------------------------------------------------------"<<endl;
            laporan<<"No Nama         Kelas           Judul         Kode     Tanggal Pinjam      Tanggal Kembali"<<endl;
            laporan<<"------------------------------------------------------------------------------------------"<<endl;
            for(int c = 0; c<=a; c++)
            {
                laporan<<c+1<<setw(6)<<peminjaman[c].nama<<setw(19)<<peminjaman[c].kelas<<setw(16)<<peminjaman[c].judul<<setw(7)<<peminjaman[c].kodebuku<<setw(8)<<peminjaman[c].tanggalpinjam<<setw(20)<<peminjaman[c].tanggalkembali<<endl;
            }
            laporan.close();
            cout<<"Data Peminjaman Berhasil Dicetak"<<endl;
}
int main()
{
    int b = -1;
    int a = -1;
    int pilihanmenu;
    char yn;
    stringstream ss;
    admin:
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\tPerpustakaan Pintar \n\n";
    cout << "\t\t\t  Username : ";
    getline(cin, loginadmin.admin);
    ss.clear();
    cout << "\t\t\t  Password : ";
    getline(cin, loginadmin.pass);
    ss.clear();
    cout<<endl;
    if(loginadmin.admin == "admin" && loginadmin.pass == "1" )
    {
        cout<< "\n\n Login Berhasil \n" <<endl;
        system("pause");
        system("cls");
        goto menuawal;
	}
	else{
		cout<<" Password Anda Salah \n";
   	    system("pause");
   	    system("cls");
	 	goto admin;
	}
    menuawal:
    cout<<"\n\n\n\n\n\n"<<endl;
    cout<<"\t\t\tPerpustakaan Sederhana"<<endl;
    cout<<endl;
    cout<<"\t\t\t1. Input Buku"<<endl;
    cout<<"\t\t\t2. Daftar Buku Diperpustakaan"<<endl;
    cout<<"\t\t\t3. Mencari Buku"<<endl;
    cout<<"\t\t\t4. Peminjaman Buku"<<endl;
    cout<<"\t\t\t5. Laporan Peminjaman Buku"<<endl;
    cout<<"\t\t\t6. Cetak Laporan Peminjaman"<<endl;
    cout<<"\t\t\t7. Logout"<<endl;
    cout<<endl;
    cout<<"\t\t\tMasukan Pilihan Menu: ";
    cin>>pilihanmenu;
    cin.get();
    switch(pilihanmenu)
    {
    case 1:
        {
            case1:
            system("cls");
            bukuyangmasuk();
            cout<<"Data Telah Tersimpan!"<<endl;
            cout<<endl;
            cout<<"Ingin Menambah Data Lagi?(y/n): ";
            cin>>yn;
            cin.get();
            if(yn == 'y')
            {
                goto case1;
            }
            else{
                system("cls");
                goto menuawal;
            }
            break;
        }
    case 2:
        {
            system("cls");
            databasebukuperputakaan();
            cout<<"Kembali Menu Awal Ketik (y): ";
            cin>>yn;
            if(yn == 'y')
            {
                system("cls");
                goto menuawal;
            }
            break;

        }
    case 3:
        {
            case3:
            system("cls");
            mencaribukuperpustakaan();
            cout<<"Kembali Menu Awal Ketik (y): ";
            cin>>yn;
            if(yn == 'y')
            {
                system("cls");
                goto menuawal;
            }
            break;
        }
    case 4:
        {
            case4:
            system("cls");
            transaksipeminjaman();
            cout<<"Ingin Menambah Data Lagi?(y/n): ";
            cin>>yn;
            cin.get();
            if(yn == 'y')
            {
                goto case4;
            }
            else{
                system("cls");
                goto menuawal;
            }
        }
    case 5:
        {
            system("cls");
            laporanpeminjaman();
            cout<<"Kembali Menu Awal Ketik (y): ";
            cin>>yn;
            if(yn == 'y')
            {
                system("cls");
                goto menuawal;
            }
            break;
        }
    case 6:
        {
            system("cls");
            cetaklaporan();
            cout<<"Kembali Menu Awal Ketik (y): ";
            cin>>yn;
            if(yn == 'y')
            {
                system("cls");
                goto menuawal;
            }
            getch();
            break;
        }
    case 7:
        {
            cout<<"-- Anda Telah Logout -- \n";
            system("pause");
            system("cls");
            goto admin;
            break;
        }
    default:
        {
            system("cls");
            goto menuawal;
        }
    }
    cin.get();
    return 0;
}
