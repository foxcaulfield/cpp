/* https://github.com/foxcaulfield/cpp */

#include <cmath>
#include <format>
#include <iostream>
#include <string>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::string;
using std::tuple;

const int range_limit = 999;

tuple<int, int> euclidean_divide(int a, int b) {
    if (a >= 0) {
        return {a / b, a % b};
    } else {
        a = std::abs(a);
        if (b > 0) {
            return {-((a + b) / b), b - (a % b)};
        } else {
            b = std::abs(b);
            return {(a + b) / b, b - (a % b)};
        }
    }
}

void print_table_row(int a, int b) {
    auto [eucl_q, eucl_r] = euclidean_divide(a, b);
    string row_str = format("|{:>5}{:>5}|{:>15}{:>15}|{:>15}{:>15}|", a, b,
                            eucl_q, eucl_r, a / b, a % b);
    cout << row_str << endl;
}

void print_table_filler_line(int len = 74) {
    cout << format("{:->{}}", "", len) << endl;
}

bool in_range(int low, int high, int i) {
    return low <= i && i <= high;
}

int main() {
    int orig_a = 0;
    int orig_b = 0;

    const string header1 =
        format("|{2:>10}|{0:^30}|{1:^30}|", "Euclidean definition",
               "C++ (truncated) definition", "");
    const string header2 = format("|{2:>10}|{0:^30}|{1:^30}|",
                                  "(with a positive remainder)", "", "");
    const string header3 =
        format("|{0:>5}{1:>5}|{2:>15}{3:>15}|{2:>15}{3:>15}|", "a", "b",
               "a/b (q)", "a%b (r)");

    while (true) {
        while (true) {
            cout << format(
                "Enter a dividend absolute value (a) from range [{},{}]: ",
                0, range_limit);
            cin >> orig_a;
            if (in_range(0, range_limit, orig_a)) {
                break;
            } else {
                cout << "Wrong value!" << endl;
            }
        }

        while (true) {
            cout << format(
                "Enter a divisor absolute value (b) from range [{},{}]: ", 1,
                range_limit);
            cin >> orig_b;
            if (in_range(1, range_limit, orig_b)) {
                break;
            } else {
                cout << "Wrong value!" << endl;
            }
        }

        print_table_filler_line();
        cout << header1 << endl;
        cout << header2 << endl;
        cout << header3 << endl;

        print_table_filler_line();
        print_table_row(orig_a, orig_b);
        print_table_row(orig_a, -orig_b);
        print_table_row(-orig_a, orig_b);
        print_table_row(-orig_a, -orig_b);

        print_table_filler_line();

        string tmp_answer = "n";

        cout << "Try again? [y/n]: ";

        cin >> tmp_answer;

        if (tmp_answer != "y") {
            break;
        }
    }

    return 0;
}