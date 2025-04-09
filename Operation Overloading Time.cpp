#include <iostream>
using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Clock(int hours, int minutes , int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void setTime(int hours, int minutes, int seconds) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void getTime(int& hours, int& minutes, int& seconds) {
        hours = this->hours;
        minutes = this->minutes;
        seconds = this->seconds;
    }

    Clock& operator ++ () {
        ++seconds;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
        return *this;
    }

    bool operator == (const Clock & x) {
        if (this->seconds == x.seconds) {
            if (this->minutes == x.minutes) {
                if (this->hours == x.hours) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator <= (const Clock & x) {
        if (this->seconds <= x.seconds) {
            if (this->minutes <= x.minutes) {
                if (this->hours <= x.hours) {
                    return true;
                }
            }
        }
        return false;
    }

    friend istream& operator >> (istream& in, Clock& t) {
        char c;
        in >> t.hours >> c >> t.minutes >> c >> t.seconds;
        return in;
    }

    friend ostream& operator << (ostream& out, Clock& t) {
        out << t.hours << ":" << t.minutes << ":" << t.seconds;
        return out;
    }

};


int main() {

    Clock c1 (23,59,58);
    Clock c2 (12,0,0);

    cout << "initial c1: "<< c1 << endl;
    cout << "initial c2: "<< c2 << endl;
    ++c1;
    cout << "artirilmis c1: "<< c1 << endl;
    ++c1;
    cout << "artirilmis c1(2nd time): "<< c1 << endl;

    if(c1==c2)
        cout<<"c1 and c2 are equal"<<endl;
    else
        cout<<"c1 and c2 are not equal"<<endl;

    cout << "time entered: " << c2 << endl;
    c1.setTime(17,58,23);
    cout << "c1:" << c1 << endl;
    int h,m,s;
    c1.getTime(h,m,s);
    cout <<"hours:"<<h<<" minutes:"<<m<<" second:"<<s<<endl;
    return 0;
}
