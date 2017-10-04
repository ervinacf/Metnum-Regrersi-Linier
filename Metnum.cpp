#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include<conio.h>
#include <stdlib.h>
#include <Windows.h>
#include<iomanip>

using namespace std;
void head(){  
printf("\n =============================");
printf("\n METODE NUMERIK");
printf("\n =============================");
printf("\n Ervina Chintia");
printf("\n Ari Alfarizi");
printf("\n =============================\n");

}

void RegresiLinier(int n);
int main() {
	 char pil,plh;
 int n;
 system("cls");
 head();
 cout <<"\n Masukkan Jumlah Data yang akan diinputkan : ";cin>>n;
 cout<<"\n [ 1 ] Metode Regresi Linier\n"
 "\n Silahkan Pilih Metode Yang digunakan : "; cin>>pil;
  switch(pil){
    case '1':
     system("cls");
     RegresiLinier(n);
     break;
 }
     system("pause");
 return 0;
}

void RegresiLinier(int q){
 system("cls");
 long jumx=0,jumy=0,jumxy=0,jumxx=0,xy=0,xx=0,X,Y;
 int n=q, i, ulang;
 long ratx,raty,a,b;
 float x[100],y[100];
 float data, totalX, totalY, totalXY, totalXkuadrat, kuadrattotalX;

 //algortma
 cout<<"\n -------------";
 cout<<"\n Input Data";
 cout<<"\n -------------";
 for (int h=1;h<=n;h++){
  cout<<"\nNilai x"<<h<<" = ";cin>>x[h];
 }cout<<"\n\n -------------";
 for(int k=1;k<=n;k++){
  cout<<"\nNilai y"<<k<<" = ";cin>>y[k];
 }
 system("cls");
 cout<<"\n ===================================================================";
 cout<<"\n | Data ke  |   X   |      Y      |       XY      |       X^2      |";
 cout<<"\n ===================================================================\n";
 for(int i=1;i<=n;i++){
  jumx=jumx+x[i];
  jumy=jumy+y[i];
  xy=(x[i]*y[i]);
  xx=(x[i]*x[i]);
  jumxy=jumxy+xy;
  jumxx=jumxx+xx;
 cout<<"  "<<setiosflags(ios::left)<<setw(13)<<i;
 cout<<setiosflags(ios::left)<<setw(11)<<x[i];
 cout<<setiosflags(ios::left)<<setw(16)<<y[i];
 cout<<setiosflags(ios::left)<<setw(16)<<xy;
 cout<<setiosflags(ios::left)<<setw(11)<<xx;
 cout<<"\n\n";
 }
 cout<<" -------------------------------------------------------------------\n";
 cout<<"  "<<setiosflags(ios::left)<<setw(13)<<"JUMLAH";
 cout<<setiosflags(ios::left)<<setw(11)<<jumx;
 cout<<setiosflags(ios::left)<<setw(16)<<jumy;
 cout<<setiosflags(ios::left)<<setw(16)<<jumxy;
 cout<<setiosflags(ios::left)<<setw(11)<<jumxx;
 cout<<"\n ===================================================================";
 ratx=jumx/n;
 raty=jumy/n;
 b=((jumxy*n)-(jumx*jumy))/((jumxx*n)-(jumx*jumx));
 a=raty-(b*ratx);
 cout<<"\n Nilai Rata - Rata x = "<<ratx;
 cout<<"\n Nilai Rata -  Rata y = "<<raty;
 cout<<"\n Nilai b = "<<b;
 cout<<"\n Nilai a = "<<a;
  cout << "\n \nProgram menghitung nilai regresi dengan format Y=mx+c" ;
 cout << endl ;
 
 do
 {
    totalX=0, totalY=0, totalXY=0, totalXkuadrat=0;
    cout << endl << endl ;
 cout << "Masukkan banyak data yang ingin Anda di imput : " ;
 cin >> data ;
 cout << endl ;
 
 //input data
 for (i=0 ; i<data ; i++)
  {
   cout << "Masukkan nilai X-" << i+1 << " : " ;
   cin >> x[i];
   cout << "Masukkan nilai Y-" << i+1 << " : " ;
   cin >> y[i];
   cout << endl;
  }
 
 cout << endl;
 
 // menghitung nilai b
  
  //menghitung nilai jumlah nilai XY
  for (i=0 ; i<data ; i++){
  	totalXY=totalXY+(x[i]*y[i]);
  }
  	 
  

  
  //menghitung nilai jumlah X dan jumlah Y
  for (i=0 ; i<data ; i++)
   {
    totalX=totalX+x[i];
    totalY=totalY+y[i];
   }
  
  //menghitung total X kuadrat
  for (i=0 ; i<data ; i++){
   totalXkuadrat=totalXkuadrat+(x[i]*x[i]);
  }
  
  

  // menghitung kuadrat total X
  for (i=0 ; i<data ; i++){
  	 kuadrattotalX=totalX*totalX;
  }

  
  //menghitung nilai b
  float b=((data*totalXY)-(totalX*totalY)) / ((data*totalXkuadrat)-(kuadrattotalX));
  

 //menghitung nilai a
  
  float a=((totalXkuadrat*totalY)-(totalX*totalXY)) / ((data*totalXkuadrat)-(kuadrattotalX));
   
 // menampilkan hasil persamaan regresi


 //menghitung error
 int i, nmax;
 float pre[nmax+1], error[nmax+1];
 float sigmaerror, err;
   for (i=1; i<=n;i++){
   	error[i]=y[i]-pre[i];
   	if (error[i]<0){
          error[i]=pre[i]-y[i];
	  }
          sigmaerror=sigmaerror + error[i];
   }
       	 //menghitung error
   			err=sigmaerror/n;
  
   
   //tampil error tiap prediksi
    printf ("\n================================================");
   printf ("\n========= SELISIH WAKTU (ERROR) ===============\n");
   for (i=1; i<=n;i++){
    	printf ("\nSelisih Waktu jika f(x)=%.2f yaitu %.2f \n", pre[i], error[i]);
}
   //tampil nilai error keseluruhan
   printf ("\n=========================");
  // printf ("\nNilai Sigma error = %f \n ", sigmaerror);
   printf ("\n====== ERROR ======\n");
   printf ("\nMaka nilai error sebesar %.2f \n ", err);
getch();

    // fungsi mengulang program
    cout << "Ingin mengulang (Y/T) ?" ;
    ulang=getch();
    } while (ulang=='Y' || ulang=='y');
    
} 




