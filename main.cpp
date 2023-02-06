#include <iostream>
#include <set>
#include <cctype>
#include <vector>

using namespace std;

int sum_of_cifres(const int& i) {
    int result = 0;
    int number = i;
    while (number > 0) {
        result += number % 10;
        number /= 10;
    }
    return result;
}

string tosixth(const int& i) {
    if (i == 0) return "0";
    string result;
    int it = i;
    while (it > 0) {
        int ost = it - (it / 16) * 16;
        if (ost >= 10) {
            if (ost == 10) result += 'A';
            if (ost == 11) result += 'B';
            if (ost == 12) result += 'C';
            if (ost == 13) result += 'D';
            if (ost == 14) result += 'E';
            if (ost == 15) result += 'F';
        }
        else {
            result += to_string(ost);
        }
        it /= 16;
    }
    string result2;
    for (int i = result.size() - 1; i >= 0; i--) {
        result2 += result[i];
    }
    return result2;
}

int get_number(const char& c) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (unsigned int i = 0; i < alphabet.size(); i++) {
        if (alphabet[i] == c) return i + 1;
    }
    return 0;
}

string get_last_three(const string& s) {
    if (s.size() < 3) {
        if (s.size() == 0) return "000";
        if (s.size() == 1) return "00" + s;
        if (s.size() == 2) return "0" + s;
    } else {
        return s.substr(s.size() - 3, 3);
    }
    return "";
}

int main() {
    int N;
    cin >> N;
    vector<string> result;
    for (int j = 0; j < N; j++) {
        int cifre;
        {
            bool is_first = true;
            set<char> letters;
            int dels = 0;
            while (dels < 3) {
                char c;
                cin >> c;
                if (is_first) {
                    is_first = false;
                    //cout << "get_number(tolower(" << c << ")) = " << get_number(tolower(c)) << endl;
                    cifre = get_number(tolower(c)) * 256;
                }
                if (c == ',') {
                    dels++;
                    continue;
                }
                letters.insert(c);
            }
            cifre += letters.size();
        }

        {
            int day, month, year;
            char del, del2;
            cin >> day >> del >> month >> del2 >> year;
            cifre += (sum_of_cifres(day) + sum_of_cifres(month)) * 64;
        }

        result.push_back(get_last_three(tosixth(cifre)));
    }

    for (string s : result) {
        cout << s << " ";
    }

    return 0;
}
