#pragma once
#include <iostream>
#include <vector>
#define ALPHABET_SIZE 26
using namespace std;
const int NMAX = 10000;

class Bohr {
    struct vertex {
        int nextVertex[ALPHABET_SIZE], patNum, suffLink, autoMove[ALPHABET_SIZE], par, suffFlink;
        bool flag;
        char symb;
        vertex(int p, char c) {
            memset(nextVertex, 255, sizeof(nextVertex));
            memset(autoMove, 255, sizeof(autoMove));
            flag = false;
            suffLink = -1;
            par = p;
            symb = c;
            suffFlink = -1;
        }
    };
    vector<vertex> bohr;
    vector<string> pattern;
public:
    Bohr() {
        bohr.push_back(vertex(0, '$'));
    }
    void add(const string& s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i] - 'a';
            if (bohr[num].nextVertex[ch] == -1) {
                bohr.push_back(vertex(num, ch));
                bohr[num].nextVertex[ch] = bohr.size() - 1;
            }
            num = bohr[num].nextVertex[ch];
        }
        bohr[num].flag = true;
        pattern.push_back(s);
        bohr[num].patNum = pattern.size() - 1;
    }
    bool find(const string& s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i] - 'a';
            if (bohr[num].nextVertex[ch] == -1) {
                return false;
            }
            num = bohr[num].nextVertex[ch];
        }
        return true;
    }
    int get_suff_link(int v) {
        if (bohr[v].suffLink == -1)
            if (v == 0 || bohr[v].par == 0)
                bohr[v].suffLink = 0;
            else
                bohr[v].suffLink = get_auto_move(get_suff_link(bohr[v].par), bohr[v].symb);
        return bohr[v].suffLink;
    }
    int get_auto_move(int v, char ch) {
        if (bohr[v].autoMove[ch] == -1)
            if (bohr[v].nextVertex[ch] != -1)
                bohr[v].autoMove[ch] = bohr[v].nextVertex[ch];
            else
                if (v == 0)
                    bohr[v].autoMove[ch] = 0;
                else
                    bohr[v].autoMove[ch] = get_auto_move(get_suff_link(v), ch);
        return bohr[v].autoMove[ch];
    }
    int get_suff_flink(int v) {
        if (bohr[v].suffFlink == -1) {
            int u = get_suff_link(v);
            if (u == 0)
                bohr[v].suffFlink = 0;
            else
                bohr[v].suffFlink = (bohr[u].flag) ? u : get_suff_flink(u);
        }
        return bohr[v].suffFlink;
    }
    void check(int v, int i) {
        for (int u = v; u != 0; u = get_suff_flink(u)) {
            if (bohr[u].flag)
                cout << i - pattern[bohr[u].patNum].length() + 1 << " " << pattern[bohr[u].patNum] << endl;
        }
    }
    void find_all_pos(const string& s) {
        int u = 0;
        for (int i = 0; i < s.length(); i++) {
            u = get_auto_move(u, s[i] - 'a');
            check(u, i + 1);
        }
    }

};