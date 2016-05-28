#include "Text.hh"

bool Text::avalua_frase_expressio(string expressio, string frase) {
    int n = expressio.size();
    if (expressio[0] == '{') {
        int i = 1;
        string paraules;
        while (expressio[i] != '}') {
            paraules.push_back(expressio[i]);
            i++;
        }
        string paraula = "";
        int m = paraules.size();
        int j = 0;
        bool compleix = true;
        while (j < m) {
            if (paraules[j] != 32)
                paraula += paraules[j];
            else {
                if (not Text::conte_paraula(frase, paraula))
                    compleix = false;
                paraula = "";
            }
            j++;
        }
        compleix = compleix and Text::conte_paraula(frase, paraula);
        return compleix;

    }
    else if (expressio[0] == '(') {
        int parenthesis_counter = 1;
        int i = 1;
        char op;
        int pos_op = -1;
        while (parenthesis_counter != 0) {
            if (expressio[i] == '(')
                parenthesis_counter++;
            else if (expressio[i] == ')')
                 parenthesis_counter--;
            else if (expressio[i] == '&' and parenthesis_counter == 1) {
                pos_op = i;
                op = '&';
            }
            else if (expressio[i] == '|' and parenthesis_counter == 1) {
                pos_op = i;
                op = '|';
            }
            ++i;
        }
        string expressio_esquerra, expressio_dreta;
        for (int j = 1; j <= (pos_op -2) ; j++)
            expressio_esquerra.push_back(expressio[j]);
        for (int j = pos_op+2; j < i ; j++)
            expressio_dreta.push_back(expressio[j]);
        bool be = avalua_frase_expressio(expressio_esquerra,frase);
        if (not be and op == '&')
            return false;
        else if (be and op == '|')
            return true;
        else if ((not be and op == '|') or (be and op == '&'))
            return avalua_frase_expressio(expressio_dreta,frase);
    }
}