#include "Cjt_autors.hh"

using namespace std;

int main() {
    Cjt_autors cjt_autors;
    string s;
    while (getline(cin, s) && s != "sortir"){
        if (s.size() != 0)
            cjt_autors.comanda(s);
    }
    cout << s << endl;
    return 0;
}
