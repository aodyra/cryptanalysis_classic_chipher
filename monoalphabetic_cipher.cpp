#include <bits/stdc++.h>

using namespace std;

int* hitungFrekuensiHuruf(string s);
map<string, int> hitungFrekuensiBigram(string s);
map<string, int> hitungFrekuensiTrigram(string s);
/* bool compValue(pair<string, int> a, pair<string, int> b); */
bool compValue(const pair<string, int> &a, const pair<string, int> &b);
vector<pair<string, int> > sortedValue(map<string, int> mb);

int main(){
    string namafile;
    cout << "Masukan nama file: ";
    cin >> namafile;
    ifstream fileinput(namafile.c_str());
    string isifile = "";
    getline(fileinput, isifile);
    fileinput.close();
    ofstream fileoutput("out1.txt");
    /* cout << isifile.size() << endl; */
    int * arr = hitungFrekuensiHuruf(isifile);
    for(int i = 0; i < 26; ++i){
        fileoutput << char(i+97) << " " << arr[i] << endl;
    }
    fileoutput.close();
    fileoutput.open("out3.txt");
    map<string, int> mb = hitungFrekuensiTrigram(isifile);
    vector<pair<string, int> > vb = sortedValue(mb);
    for(int i = 0; i < vb.size(); ++i){
        fileoutput << vb[i].first << " " << vb[i].second << endl;
    }
    fileoutput.close();
    fileoutput.open("out2.txt");
    mb = hitungFrekuensiBigram(isifile);
    vb = sortedValue(mb);
    for(int i = 0; i < vb.size(); ++i){
        fileoutput << vb[i].first << " " << vb[i].second << endl;
    }
    fileoutput.close();

    return 0;
}

int* hitungFrekuensiHuruf(string s){
    int* arrTotalHuruf = (int *)malloc(sizeof(int) * 26);
    for(int i = 0; i < 26; ++i){
        arrTotalHuruf[i] = 0;
    }
    for(int i = 0; i < s.size(); ++i){
        arrTotalHuruf[s[i]-97]++;
    }
    return arrTotalHuruf;
}

bool compValue(const pair<string, int> &a, const pair<string, int> &b){
    return a.second > b.second;
}

vector<pair<string, int> > sortedValue(map<string, int> mb){
    vector<pair<string, int> > vb;
    copy(mb.begin(), mb.end(), back_inserter(vb));
    sort(vb.begin(), vb.end(), compValue);
    return vb;
}

map<string, int> hitungFrekuensiBigram(string s){
    map<string, int> mb;
    string key = "";
    for(int i = 0; i < s.size()-1; ++i){
        key += s[i];
        key += s[i+1];
        mb[key] = mb[key]+1;
        key = "";
    }
    return mb; 
}

map<string, int> hitungFrekuensiTrigram(string s){
    map<string, int> mt;
    string key = "";
    for(int i = 0; i < s.size()-2; ++i){
        key += s[i];
        key += s[i+1];
        key += s[i+2];
        mt[key] = mt[key]+1;
        key = "";
    }
    return mt;
}
