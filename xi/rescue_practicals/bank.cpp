#include <iostream>
#include <iomanip>
using namespace std;

class Account {
    private :
        long long balance;
        short cents;
        void credit(long amount, short change) {
            balance += amount + (cents + change) / 100;
            cents = (cents + change) % 100;
        }
        void debit(long amount, short change) {
            balance -= amount + (change - cents) / 100;
            cents = (cents - change + 100) % 100;
        }
    public :
        static const float intrest_rate = 0.12;
        float giveIntrestAmount() {
            return (balance * intrest_rate + (cents * intrest_rate) / 100 + (int)(cents * intrest_rate) % 100);
        }
        void applyIntrest() {
            balance += balance * intrest_rate + (cents * intrest_rate) / 100;
            cents += (int)(cents * intrest_rate) % 100; 
        }
        float readBalance() {
            return (balance + (float)cents / 100);
        }
        bool canWithdraw(long amount, short change) {
            return (balance + float(cents) / 100) > (amount + float(change) / 100);
        }
        bool transact(Account b, long amount, short change, bool give_money) {
            if (give_money) 
                if (canWithdraw(amount, change)) {
                    b.credit(amount, change);
                    debit(amount, change);
                    return true;
                }
            else 
                if (b.canWithdraw(amount, change)) {
                    credit(amount, change);
                    b.debit(amount, change);
                    return true;
                }
            return false;
        }
        void makeNew(long initial_deposit, short initial_change) {
            balance = initial_deposit + initial_change / 100;
            cents = initial_change % 100;
        }
};

int main() {
    int y;
    float money;
    Account acc;
    cout << "Provide Initial deposit : "; cin >> money;
    acc.makeNew(long(money), int(money*100)%100);
    cout << "Provide no. of years of investment : "; cin >> y;
    cout << "Years" << setw(5) << ' ' << "   " << setw(15) << "Initial Balance" << "  " << setw(15) << "Year's Interest" << "  " << setw(15) << "Final Balance" << endl;
    for (int i = 0; i <= y; ++i) {
        cout << "Year " << setw(5) << (i+1) << " : " << setw(15) << fixed << acc.readBalance() << "  " << setw(15) << fixed << acc.giveIntrestAmount();
        acc.applyIntrest();
        cout << "  " << setw(15) << fixed << acc.readBalance() << endl;
    }
    while (getchar() != '\n');
    getchar();
}
