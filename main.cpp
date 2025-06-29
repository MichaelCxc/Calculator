#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;


vector<string> parser(string input) {
    vector<string> res;
    istringstream iss(input);
    string token;
    while (iss >> token) {
        res.push_back(token);
        //cout<< res.back() << endl;
    }
    return res;
}

int main() {
    string input;
    cout << "Please enter the expression(use space to separate the operator and number): "<<endl;
    getline(cin, input);
    //cout << input << endl;
    vector<string> res = parser(input);

    string op = "";
    int number = -1;
    for (string token : res) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (op != "") {
                cerr << "Operator already exists" << endl;
            }
            op = token;
            continue;
        }
        try {
            int tmp = stoi(token);
            if (number == -1) {
                number = tmp;
                continue;
            }
            if (op != "") {
                if (op == "+") {
                    number += tmp;
                }else if (op == "-") {
                    number -= tmp;
                }else if (op == "*") {
                    number *= tmp;
                }else if (op == "/"){
                    number /= tmp;
                }
                op = "";
            }
        }catch (const exception& e) {
            cerr << e.what() << endl;
        }

    }

    cout << number << endl;

    cout << "test whether cmake debug would be ignored";
}


