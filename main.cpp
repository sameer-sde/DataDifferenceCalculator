#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int daysInMonth(int m, int y) {
        switch(m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(y) ? 29 : 28;
            default: return 0;
        }
    }

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValid() {
        if(year < 1 || month < 1 || month > 12) return false;
        if(day < 1 || day > daysInMonth(month, year)) return false;
        return true;
    }

    long julianDay() {
        int Y = year;
        int M = month;
        int D = day;

        if(M <= 2) {
            Y -= 1;
            M += 12;
        }

        int A = Y / 100;
        int B = 2 - A + (A / 4);

        return long(365.25 * (Y + 4716)) + long(30.6001 * (M + 1)) + D + B - 1524;
    }

    string toString() {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

void computeDifference(Date d1, Date d2, ofstream &outfile) {
    long jd1 = d1.julianDay();
    long jd2 = d2.julianDay();
    long totalDays = abs(jd1 - jd2);

    int years = totalDays / 365;
    int months = (totalDays % 365) / 30;
    int days = (totalDays % 365) % 30;

    cout << "\nBetween " << d1.toString() << " and " << d2.toString() << ":\n";
    cout << "Total days: " << totalDays << endl;
    cout << "Approximate difference: " << years << " year(s), " 
         << months << " month(s), " << days << " day(s)\n";

    if(outfile.is_open()) {
        outfile << d1.toString() << " - " << d2.toString() 
                << " = " << totalDays << " days (" 
                << years << "y " << months << "m " << days << "d)" << endl;
    }
}

void viewSavedResults() {
    ifstream infile("DateDifferences.txt");
    if(!infile) {
        cout << "No saved results found.\n";
        return;
    }
    string line;
    cout << "\n=== Saved Date Differences ===\n";
    while(getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();
}

int main() {
    char choice;
    do {
        cout << "\n=== Data Difference Calculator ===\n";
        cout << "1. Compute new date difference\n";
        cout << "2. View saved results\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                int d1, m1, y1, d2, m2, y2;
                cout << "Enter first date (DD MM YYYY): ";
                cin >> d1 >> m1 >> y1;
                Date date1(d1, m1, y1);
                if(!date1.isValid()) {
                    cout << "Invalid first date!\n";
                    break;
                }

                cout << "Enter second date (DD MM YYYY): ";
                cin >> d2 >> m2 >> y2;
                Date date2(d2, m2, y2);
                if(!date2.isValid()) {
                    cout << "Invalid second date!\n";
                    break;
                }

                ofstream outfile("DateDifferences.txt", ios::app);
                computeDifference(date1, date2, outfile);
                outfile.close();
                break;
            }
            case '2':
                viewSavedResults();
                break;
            case '3':
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != '3');

    return 0;
}
