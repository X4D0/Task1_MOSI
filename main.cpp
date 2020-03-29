#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <vector>
#define phi 3.14159265
#include "gnuplot.h"

using namespace std;

int main()
{

    /* Fungsi Menghitung waktu saat menyentuh Tanah */
    /* Perhitungan Numerik */
    int pilihan;
    cout << "Menu" << endl;
    cout << "1. Dengan Mengabaikan Hambatan Udara" << endl;
    cout << "2. Dengan Mempertimbangkan Hambatan Udara" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;

        if (pilihan == 1)
    {
        double kecepatan;
        double sudut;
        double deltat;
        double g = 9.8;

        /* Array untuk nilai x dan y */
        vector<double> NumerikX;
        vector<double> NumerikY;
        vector<double> AnalitikX;
        vector<double> AnalitikY;

        /* Posisi Awal Numerik */
        double posisiXnumerik = 0;
        double posisiYnumerik = 0;
        NumerikX.push_back(posisiXnumerik);
        NumerikY.push_back(posisiYnumerik);

        /* Posisi Awal Analitik */
        double posisiXanalitik = 0;
        double posisiYanalitik = 0;
        AnalitikX.push_back(posisiXanalitik);
        AnalitikY.push_back(posisiYanalitik);

        /* Input Kecepatan, Sudut, dan Dt yang diketahui */
        cout<<"Kecepatan (m/s) : ";
        cin>>kecepatan;
        cout<<"Sudut : ";
        cin>>sudut;
        cout<<"Delta t : ";
        cin>>deltat;

        double waktu = (2*kecepatan*(sin(sudut*phi/180))/g); /* Fungsi mencari Waktu Total*/
        double hMax = ((pow(kecepatan,2))*(pow(sin(sudut*phi/180),2))/(2*g)); /* Fungsi mencari Tinggi Maksimum */
        double jarak = (kecepatan*(cos(sudut*phi/180))*waktu); /* Fungsi mencari Jarak Maksimum*/

        g = g*-1;

        /* Mencari Kecepatan */
        double kecepatanXnumerik = (kecepatan*(cos(sudut*phi/180)));
        double kecepatanYnumerik = (kecepatan*(sin(sudut*phi/180)));
        double kecepatanXanalitik = (kecepatan*(cos(sudut*phi/180)));
        double kecepatanYanalitik = (kecepatan*(sin(sudut*phi/180)));

        /* Sebagai Keperluan Visualisasi maka dibuat file .dat*/
        ofstream numerik;
        numerik.open("D:/PROGRAMMING/MOSI/numerik.dat");
        ofstream analitik;
        analitik.open("D:/PROGRAMMING/MOSI/analitik.dat");

        cout<<"\nPerhitungan Numerik : "<<endl;
        for(double t=0; t<(waktu+deltat); t+=deltat)
        {
            kecepatanYnumerik = (kecepatanYnumerik+(g*deltat));
            posisiXnumerik = (posisiXnumerik+(kecepatanXnumerik*deltat));
            posisiYnumerik = (posisiYnumerik+(kecepatanYnumerik*deltat));
            numerik << posisiXnumerik << " " << posisiYnumerik <<endl;
            cout<<"X("<<t<<") : "<<posisiXnumerik<<endl;
            cout<<"Y("<<t<<") : "<<posisiYnumerik<<endl;
            NumerikX.push_back(posisiXnumerik);
            NumerikY.push_back(posisiYnumerik);
            if (posisiYnumerik<0)
            {
                cout<<"Waktu menyentuh tanah (Numerik) : "<<t<<endl;
                break;
            }
        }

        /* Perhitungan Analitik */
        cout<<"\nPerhitungan Analitik : "<<endl;
        for(double t=0; t<(waktu+deltat); t+=deltat)
        {
            posisiXanalitik = (kecepatanXanalitik*t);
            AnalitikX.push_back(posisiXanalitik);
            posisiYanalitik = ((kecepatanYanalitik*t)+(g*(pow(t,2))*0.5));
            AnalitikY.push_back(posisiYanalitik);
            analitik << posisiXanalitik << " " << posisiYanalitik <<endl;
            cout<<"X("<<t<<") : "<<posisiXanalitik<<endl;
            cout<<"Y("<<t<<") : "<<posisiYanalitik<<endl;
            if (posisiYanalitik<0)
            {
                cout<<"Waktu menyentuh tanah (Analitik) : "<<t<<endl;
                break;
            }
        }

        cout<<"\nWaktu Total : "<<waktu<<endl;
        cout<<"Jarak Maksimum : "<<jarak<<endl;
        cout<<"Tinggi Maksimum : "<<hMax<<endl;

        /* Menutup file numerik.dat dan analitik.dat */
        numerik.close();
        analitik.close();

        /* Visualisasi menggunakan Gnuplot */
        GnuplotPipe gp;
        gp.sendLine("set xlabel 'X'");
        gp.sendLine("set ylabel 'Y'");
        gp.sendLine("cd 'D:/PROGRAMMING/MOSI");
        gp.sendLine("plot 'analitik.dat' using 1:2 w l lt rgb 'red' title 'Analitik', \
                'numerik.dat' using 1:2 w l lt rgb 'blue' title 'Numerik'");


    }else if (pilihan == 2){
        double kecepatan;
        double sudut;
        double deltat;
        double g = 9.8;

        /* Array untuk nilai x dan y */
        vector<double> NumerikX;
        vector<double> NumerikY;
        vector<double> AnalitikX;
        vector<double> AnalitikY;

        /* Posisi Awal Numerik */
        double posisiXnumerik = 0;
        double posisiYnumerik = 0;
        NumerikX.push_back(posisiXnumerik);
        NumerikY.push_back(posisiYnumerik);

        /* Posisi Awal Analitik */
        double posisiXanalitik = 0;
        double posisiYanalitik = 0;
        AnalitikX.push_back(posisiXanalitik);
        AnalitikY.push_back(posisiYanalitik);

        /* Input Kecepatan, Sudut, dan Dt yang diketahui */
        cout<<"Kecepatan (m/s) : ";
        cin>>kecepatan;
        cout<<"Sudut : ";
        cin>>sudut;
        cout<<"Delta t : ";
        cin>>deltat;

        double waktu = (2*kecepatan*(sin(sudut*phi/180))/g); /* Fungsi mencari Waktu Total*/
        double hMax = ((pow(kecepatan,2))*(pow(sin(sudut*phi/180),2))/(2*g)); /* Fungsi mencari Tinggi Maksimum */
        double jarak = (kecepatan*(cos(sudut*phi/180))*waktu); /* Fungsi mencari Jarak Maksimum*/

        g = g*-1;

        /* Mencari Kecepatan */
        double kecepatanXnumerik = (kecepatan*(cos(sudut*phi/180)));
        double kecepatanYnumerik = (kecepatan*(sin(sudut*phi/180)));

        double D,massa;
        cout << "Masukkan Nilai D : ";
        cin >> D;
        cout << "Masukkan Massa Benda : ";
        cin >> massa;
        double ax = -((D/massa)*kecepatan*kecepatanXnumerik);
        double ay = -g-((D/massa)*kecepatan*kecepatanYnumerik);


        double kecepatanXanalitik = (1/2*ax*waktu*waktu)+(kecepatan*waktu)+posisiXanalitik;
        double kecepatanYanalitik = (1/2*ay*waktu*waktu)+(kecepatan*waktu)+posisiYanalitik;


        /* Sebagai Keperluan Visualisasi maka dibuat file .dat*/
        ofstream numerik;
        numerik.open("D:/PROGRAMMING/MOSI/numerik.dat");
        ofstream analitik;
        analitik.open("D:/PROGRAMMING/MOSI/analitik.dat");

        cout<<"\nPerhitungan Numerik : "<<endl;
        for(double t=0; t<(waktu+deltat); t+=deltat)
        {
            kecepatanYnumerik = (kecepatanYnumerik+(ay*deltat));
            posisiXnumerik = (posisiXnumerik+(kecepatanXnumerik*deltat));
            posisiYnumerik = (posisiYnumerik+(kecepatanYnumerik*deltat));
            numerik << posisiXnumerik << " " << posisiYnumerik <<endl;
            cout<<"X("<<t<<") : "<<posisiXnumerik<<endl;
            cout<<"Y("<<t<<") : "<<posisiYnumerik<<endl;
            NumerikX.push_back(posisiXnumerik);
            NumerikY.push_back(posisiYnumerik);
            if (posisiYnumerik<0)
            {
                cout<<"Waktu menyentuh tanah (Numerik) : "<<t<<endl;
                break;
            }
        }

        /* Perhitungan Analitik */
        cout<<"\nPerhitungan Analitik : "<<endl;
        for(double t=0; t<(waktu+deltat); t+=deltat)
        {
            posisiXanalitik = (kecepatanXanalitik*t);
            AnalitikX.push_back(posisiXanalitik);
            posisiYanalitik = ((kecepatanYanalitik*t)+(ay*(pow(t,2))*0.5));
            AnalitikY.push_back(posisiYanalitik);
            analitik << posisiXanalitik << " " << posisiYanalitik <<endl;
            cout<<"X("<<t<<") : "<<posisiXanalitik<<endl;
            cout<<"Y("<<t<<") : "<<posisiYanalitik<<endl;
            if (posisiYanalitik<0)
            {
                cout<<"Waktu menyentuh tanah (Analitik) : "<<t<<endl;
                break;
            }
        }

        cout<<"\nWaktu Total : "<<waktu<<endl;
        cout<<"Jarak Maksimum : "<<jarak<<endl;
        cout<<"Tinggi Maksimum : "<<hMax<<endl;

        /* Menutup file numerik.dat dan analitik.dat */
        numerik.close();
        analitik.close();

        /* Visualisasi menggunakan Gnuplot */
        GnuplotPipe gp;
        gp.sendLine("set xlabel 'X'");
        gp.sendLine("set ylabel 'Y'");
        gp.sendLine("cd 'D:/PROGRAMMING/MOSI");
        gp.sendLine("plot 'analitik.dat' using 1:2 w l lt rgb 'red' title 'Analitik', \
                'numerik.dat' using 1:2 w l lt rgb 'blue' title 'Numerik'");
    }


}
