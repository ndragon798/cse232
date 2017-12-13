//Nathan Easton
//014
//lab01
// 09/08/17
#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    long days; 
    long sdist=39.33;
    double speedkms=14.24,speedmis=8.85;
    //make speed in miles per day and kilometers per day;
    double speedkmd=speedkms*86400,speedmid=speedmis*86400;
    //
    cout << fixed << setprecision(2);
    // Your code here
    //cout << "Input an int: ";
    cin >> days;
    //,make dist in au;
    double aus= (days*speedmid)/92955800;
    //make dist in kilos 
    double kmd= (days*speedkmd) +(39.33*149598000);
    //output both dist in kilometers and miles;
    cout << (days*speedkmd) +(39.33*149598000) << endl;
    cout << (days*speedmid)+ (39.33*92955800) <<endl;
    //output round trip radio waves
    cout << (kmd*1000*2/299792458)/3600;
    //cout <<aus;
    return 0;
}
