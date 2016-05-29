#include "Text.hh"

Text::Text(){
    num_paraules = 0;
}
void Text::afegeix_contingut() {
    string word;
    int i = 0;
    while(cin >> word && word[0] != '*'){
        num_paraules++;
        if (linies.size() == 0)
            linies.push_back("");
        if (linies[i].size() != 0)
            linies[i] += " " + word;
        else
            linies[i] += word;
        char last_char = word[word.size()-1];
        if (last_char == '.' || last_char == '?' || last_char == '!'){
            linies.push_back("");
            i++;
        }
        if ( !((last_char >= '0' and last_char <= '9') or (last_char >= 'a' and last_char <= 'z') or (last_char >= 'A' and last_char <= 'Z')))
            word.pop_back();
        int n = frequencies.size();
        int j = 0;
        bool found = false;
        while (not found and j < n) {
            if (frequencies[j].paraula == word)
                found = true;
            else
                j++;
        }
        if (found)
            frequencies[j].freq++;
        else {
            frequencia f;
            f.paraula = word;
            f.freq = 1;
            frequencies.push_back(f);
        }
    }
    if (linies.size() != 0 && linies[linies.size()-1].size() == 0)
        linies.pop_back();
    ordenar_frequencies(frequencies);
}
bool Text::avalua_frase_expressio(string expressio, string frase) {
   if (expressio[0] == '{') {
        istringstream iss (expressio);
        string s;
		bool end = false;
		bool infrase = true;
		while (not end and iss >> s) {
			if (s[0] == '{') s = s.substr(1);
			if (s[s.length()-1] == '}') {
				s.erase(s.length()-1);
				end = true;
			}
			//cout << "Paraula s: " << s << endl;
			if (infrase) {
				bool found = false;
				istringstream frasestream(frase);
				string a;
				while(not found and frasestream >> a) {
                    deformatword(a);
					if (a == s) found = true;
				}
				infrase = found;
				//if (found) cout << s << " trobada." << endl;
				//else cout << s << " no trobada." << endl;
			}
		}
		if (infrase) {
            //cout << "Expressio " << exp << " trobada." << endl;
            return true;
        }
		else {
            //cout << "Expressio " << exp << " no trobada." << endl;
            return false;
        }
	} else if (expressio[0] == '('){
        char c = expressio[1]; //pot ser ( o {
        int counter = 1;
        int i=2;
        char ci;
        if (c == '(') ci = ')';
        else if (c == '{') ci = '}';
        else cout << "error expected (, { got " << c << endl;
        while(counter != 0 and i < expressio.length()){
            if (expressio[i] == c) counter++;
            else if (expressio[i] == ci) counter--;
            i++;
        }
        if(i == expressio.length()) {
            //cout << "error, end of string" << endl;
            return false;
        }
        // i es el tanco subexpressio +1
        string expesquerra = expressio.substr(1, i-1);
        //cout << "ANALITZANT EXP ESQ: " << expesquerra << endl;

        char op = expressio[i+1];
        c = expressio[i+3]; //pot ser ( o {
        counter = 1;
        int in = i+3;
        i= i+4;
        if (c == '(') ci = ')';
        else if (c == '{') ci = '}';
        else cout << "error expected (, { got " << c << endl;
        while(counter != 0 and i < expressio.length()){
            if (expressio[i] == c) counter++;
            else if (expressio[i] == ci) counter--;
            i++;
        }
        if(i == expressio.length()) {cout << "error, end of string" << endl; return false;}
        string expdreta = expressio.substr(in, i-in);
        //cout << "ANALITZANT EXP DRE: " << expdreta << endl;
        if (op == '&') return avalua_frase_expressio(expesquerra, frase) and avalua_frase_expressio(expdreta, frase);
        else if (op == '|') return avalua_frase_expressio(expesquerra, frase) or avalua_frase_expressio(expdreta, frase);
    }
	return false;

   /* if (expressio[0] == '{') {
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
    //else if (expressio[0] == '(') {
    else {
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
        //else if ((not be and op == '|') or (be and op == '&'))
        else
            return avalua_frase_expressio(expressio_dreta,frase);
    }
    */
}
bool Text::comp(const frequencia& a, const frequencia& b) {
	if (a.freq != b.freq)
		return a.freq > b.freq;
    else if (a.paraula.size() != b.paraula.size())
            return a.paraula.size() < b.paraula.size();
    else
        return a.paraula < b.paraula;
}
int Text::comptar_linies() {
	return linies.size();
}
int Text::comptar_paraules() {
	return num_paraules;
}
bool Text::conte_paraula(string text, string paraula){
    stringstream ss;
    ss << text;
    string word;
    while (ss >> word){
        char last = word[word.size() - 1];
        if (! ( (last >= 'a' and last <= 'z') or (last >= 'A' and last <= 'Z') or (last >= '0' and last <= '9') )) //Checks if last char is not a letter or a number
            word.erase(word.size() - 1, 1);
        if (paraula == word)
            return true;
    }
    return false;
}
void Text::escriure(){
    for (int i = 0; i < linies.size(); i++){
        cout << i + 1 << " " << linies[i] << endl;
    }
}
bool Text::existeix_paraula(string paraula){
    for (int i = 0; i < linies.size(); i++){
        if (Text::conte_paraula(linies[i], paraula))
            return true;
    }
    return false;
}
vector<string> Text::frases_x_fins_y(int x, int y) {
	vector<string> frases;
	for (int i = x-1; i <= y-1; i++)
		frases.push_back(linies[i]);
	return frases;
}
void Text::imprimeix_frases_paraules(vector<string> &paraules){
	int n = linies.size();
	stringstream ss;
	for (int i = 0; i < n; i++) {
		int m = paraules.size();
		ss.str("");
		ss.clear();
		ss << linies[i];
        string word;
        int aux = 0;
        while (ss >> word and aux != m){
            char last = word[word.size() - 1];
            if (! ( (last >= 'a' and last <= 'z') or (last >= 'A' and last <= 'Z') or (last >= '0' and last <= '9') )) //Checks if last char is not a letter or a number
                word.erase(word.size() - 1, 1);
            if (paraules[aux] == word)
                aux++;
            else
                aux = 0;
        }
		if (aux == m)
            cout << i+1 << " " << linies[i] << endl;

	}
}
void Text::imprimeix_linies(int primera_linia, int ultima_linia){
	for (int i = primera_linia-1; i <= ultima_linia-1; i++)
		cout << i+1 << " " << linies[i] << endl;
}
void Text::imprimeix_nombre_frases(){
    cout << linies.size();
}
void Text::imprimeix_nombre_paraules() {
   cout << num_paraules;
}
void Text::imprimeix_taula_frequencies() {
	int n = frequencies.size();
	for (int i = 0; i < n; i++)
		cout << frequencies[i].paraula << " " << frequencies[i].freq << endl;
}
void Text::ordenar_frequencies(vector<frequencia>& freqs) {
    sort(freqs.begin(), freqs.end(), comp);
    while (freqs[freqs.size() - 1].freq == 0)
        freqs.pop_back();
}
void Text::substituir(string paraula_a_substituir, string paraula_que_substitueix) {
    int p1_pos = -1;
    int p2_pos = -1;
    for (int i = 0; i < frequencies.size() and (p1_pos == -1 or p2_pos == -1); i++){
        if (frequencies[i].paraula == paraula_a_substituir)
            p1_pos = i;
        if (frequencies[i].paraula == paraula_que_substitueix)
            p2_pos = i;
    }

    if (p1_pos != -1 and p1_pos != p2_pos){
        int n = linies.size();
        for (int i = 0; i < n; i++) {
            int pos = linies[i].find(paraula_a_substituir);
            while (pos != -1){
                linies[i].replace(pos, paraula_a_substituir.length(), paraula_que_substitueix);
                pos = linies[i].find(paraula_a_substituir);
            }
        }
        if (p2_pos != -1){
            frequencies[p2_pos].freq += frequencies[p1_pos].freq;
            frequencies[p1_pos].freq = 0;
        }
        else{
            frequencies[p1_pos].paraula = paraula_que_substitueix;
        }
        ordenar_frequencies(frequencies);
    }

}
Text::~Text() {

}
