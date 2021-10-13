// BİSECTİON METHOD KULLANILARAK VERİLEN BİR FONKSİYONUN KÖKÜNÜ BULABİLİRİZ. AŞAĞIDAKİ KOD VERİLEN FONKSİYONUN KÖKLERİNİ BULMAYA YARAR.
// BURADA DEĞİŞEBİLECEK ŞEYLER 1- FONKSİYONUN KENDİSİ 2-VERİLEN BAŞLANGIÇ NOKTALARI
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double root_bisection(double(*)(double),double,double,double, int&);  //Bisection Metod için yazıldı

double fzero(double);

int main()
{
    double a,b,root,eps;
    int flag;
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(5); // noktadan sonra kaç basamak yazılacağını söylüyor. örnek 0.12345

    a=0;       // Sol tarafta bulunan son nokta Başlangıç noktası Sorularda burası değişebilir.
    b=0.11;    // Sağ tarafta bulunan son nokta  Başlangıç noktası Sorularda burası değişebilir.
    eps=1.0e-6;       // Kaç anlamlı sayıya kadar olacağını belirten kısım(belirsizlik töleransı)

    root = root_bisection(fzero,a,b,eps,flag);

    if (flag== 0 ) cout << "Bisection Method ile bulunan bir kök yoktur."<< endl;
    else
    {
        cout << "Kaçıncı İterasyon  " << "Bulunan Kök" << endl;  
        cout << setw(9) << flag << setw(19) << root << endl;  } //Hizalama parametreleri 9.basamak 19.basamak gibi düşünülebilir.

    system("Dur");
    return 0;


}

double fzero(double x) {       // Problemde verilen fonksiyonu tanımlıyoruz.
    double y;
    y = pow(x,3.) - 0.165*pow(x,2.) + 3.933*pow(10.,-4);          // problemde verilen fonksiyon. Bu fonksiyon değişebilir.
    return y;

}

double root_bisection(double(*f)(double), double a , double b, double eps, int& flag){
    double xl,x0,xu;
    int i, iter=1000;   // max iterasyon sayısı


    if(f(a)*f(b) > 0.0) //Bisection için 1.Koşul
    {flag = 0;
    return 0.0;}

    i = 0;
    xl = a;
    xu = b;

    while (fabs(xu-xl)>= eps) {  //Bisection için 2.koşul
        i = i+1;
        x0 = (xu + xl)/2.0;
        if((f(xl)*f(x0)) <= 0.0) //Bisection için 3.koşul
            xu = x0;
            else
            xl = x0;
        if(i>=iter) break;

    }

    flag = i;
    return x0;


}