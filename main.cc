#include "Cjt_autors.hh"

using namespace std;

int main() {
    Cjt_autors cjt_autors;
    string s;
    while (getline(cin, s) && s != "sortir"){
        if(s[0] != '\n' and s[0] != '\r' and s.size() != 0){
            cjt_autors.comanda(s);
            cout << endl;
        }
    }
    cout << "sortir" << endl;
    return 0;
}
