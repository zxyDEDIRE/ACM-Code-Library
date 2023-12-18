#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
namespace NFA {
int cnt, S, T;
int G[N][26];
set<int> eps[N];
void clear() {
    for (int i = 1; i <= cnt; ++i) {
        fill(G[i], G[i] + 26, 0);
        eps[i].clear();
    }

    cnt = S = T = 0;
}

int newNode() {
    return ++cnt;
}

void addEdge(int u, int v, char c) {
    if (c == 0)
        eps[u].insert(v);
    else
        G[u][c - 'a'] = v;
}
} // namespace NFA

namespace DFA {
int cnt, S = 1;
set<int> T;
int G[N][26];
map<set<int>, int> ID;
set<int> ST[N];
set<int> vis;

void clear() {
    for (int i = 1; i <= cnt; ++i) {
        fill(G[i], G[i] + 26, 0);
        ST[i].clear();
    }

    T.clear();
    ID.clear();
    cnt = 0, S = 1;
}

int idof(const set<int> &s) {
    if (s.empty())
        return 0;

    if (ID.count(s))
        return ID[s];

    return ST[++cnt] = s, ID[s] = cnt;
}

void getToSet(set<int> &to, int u, char c) {
    vis.insert(u);

    if (NFA::G[u][c - 'a'])
        to.insert(NFA::G[u][c - 'a']);

    for (auto v : NFA::eps[u])
        if (!vis.count(v))
            getToSet(to, v, c);
}

bool checkFinal(int u) {
    vis.insert(u);

    if (u == NFA::T)
        return true;

    for (auto v : NFA::eps[u])
        if (!vis.count(v) && checkFinal(v)) {
            return true;
        }

    return false;
}

void build() {
    queue<int> Q;
    Q.push(idof({NFA::S}));

    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();

        for (char c = 'a'; c <= 'z'; ++c) {
            set<int> to;

            for (auto u : ST[p]) {
                vis.clear();
                getToSet(to, u, c);
            }

            if (!to.empty() && !ID.count(to)) {
                Q.push(idof(to));
            }

            G[p][c - 'a'] = idof(to);
        }

        for (auto u : ST[p]) {
            vis.clear();

            if (checkFinal(u)) {
                T.insert(p);
            }
        }
    }
}

bool run(const string &s) {
    int p = 1;

    for (auto c : s) {
        p = G[p][c - 'a'];
    }

    return T.count(p);
}
} // namespace DFA

namespace Parser {

struct Exp {
    virtual pair<int, int> build() = 0;
    virtual string tostr() = 0;
    virtual ~Exp() {};
};

Exp *exp;

void clear() {
    delete exp;
}

struct Char : Exp {
    char c;
    Char(char c) : c(c) {}
    pair<int, int> build() {
        int s = NFA::newNode();
        int t = NFA::newNode();
        NFA::addEdge(s, t, c);
        NFA::S = s, NFA::T = t;
        return {s, t};
    }
    string tostr() {
        return "Char(" + string{c} + ")";
    }
    ~Char() {}
};

struct Concat : Exp {
    Exp *e1, *e2;
    Concat(Exp *e1, Exp *e2) : e1(e1), e2(e2) {}
    pair<int, int> build() {
        auto [s1, t1] = e1->build();
        auto [s2, t2] = e2->build();
        NFA::addEdge(t1, s2, 0);
        NFA::S = s1, NFA::T = t2;
        return {s1, t2};
    }
    string tostr() {
        return "Concat(" + e1->tostr() + ", " + e2->tostr() + ")";
    }
    ~Concat() {
        delete e1;
        delete e2;
    }
};

struct Or : Exp {
    Exp *e1, *e2;
    Or(Exp *e1, Exp *e2) : e1(e1), e2(e2) {}
    pair<int, int> build() {
        auto [s1, t1] = e1->build();
        auto [s2, t2] = e2->build();
        int s = NFA::newNode();
        int t = NFA::newNode();
        NFA::addEdge(s, s1, 0);
        NFA::addEdge(s, s2, 0);
        NFA::addEdge(t1, t, 0);
        NFA::addEdge(t2, t, 0);
        NFA::S = s, NFA::T = t;
        return {s, t};
    }
    string tostr() {
        return "Or(" + e1->tostr() + ", " + e2->tostr() + ")";
    }
    ~Or() {
        delete e1;
        delete e2;
    }
};

struct Closure : Exp {
    Exp *e;
    Closure(Exp *e) : e(e) {}
    pair<int, int> build() {
        auto [s, t] = e->build();
        int s0 = NFA::newNode();
        int t0 = NFA::newNode();
        NFA::addEdge(s0, s, 0);
        NFA::addEdge(t, t0, 0);
        NFA::addEdge(t, s, 0);
        NFA::addEdge(s0, t0, 0);
        NFA::S = s0, NFA::T = t0;
        return {s0, t0};
    }
    string tostr() {
        return "Closure(" + e->tostr() + ")";
    }
    ~Closure() {
        delete e;
    }
};

struct P_Closure : Exp {
    Exp *e;
    P_Closure(Exp *e) : e(e) {}
    pair<int, int> build() {
        auto [s, t] = e->build();
        int s0 = NFA::newNode();
        int t0 = NFA::newNode();
        NFA::addEdge(s0, s, 0);
        NFA::addEdge(t, t0, 0);
        NFA::addEdge(t, s, 0);
        NFA::S = s0, NFA::T = t0;
        return {s0, t0};
    }
    string tostr() {
        return "P_Closure(" + e->tostr() + ")";
    }
    ~P_Closure() {
        delete e;
    }
};

stack<char> stkOp;
stack<Exp *> stkExp;
void cal() {
    char op = stkOp.top();

    if (op == '#') {
        Exp *e2 = stkExp.top();
        stkExp.pop();
        Exp *e1 = stkExp.top();
        stkExp.pop();
        stkExp.push(new Concat(e1, e2));
    } else if (op == '|') {
        Exp *e2 = stkExp.top();
        stkExp.pop();
        Exp *e1 = stkExp.top();
        stkExp.pop();
        stkExp.push(new Or(e1, e2));
    } else if (op == '*') {
        Exp *e = stkExp.top();
        stkExp.pop();
        stkExp.push(new Closure(e));
    } else if (op == '+') {
        Exp *e = stkExp.top();
        stkExp.pop();
        stkExp.push(new P_Closure(e));
    }

    stkOp.pop();
}
string preprocess(const string &ptn) {
    string newptn;

    for (int i = 0; i < (int)ptn.size(); i++) {
        if (i > 0 && (ptn[i] >= 'a' && ptn[i] <= 'z' || ptn[i] == '(') && ptn[i - 1] != '(' && ptn[i - 1] != '|') {
            newptn.push_back('#');
        }

        newptn.push_back(ptn[i]);
    }

    return newptn;
}
Exp *parse(const string &ptn) {
    string newptn = preprocess(ptn);

    for (char c : newptn) {
        if (c == '(') {
            stkOp.push(c);
        } else if (c == ')') {
            while (!stkOp.empty() && stkOp.top() != '(')
                cal();

            stkOp.pop();
        } else if (c == '*' || c == '+') {
            stkOp.push(c);
            cal();
        } else if (c == '|') {
            while (!stkOp.empty() && stkOp.top() != '(')
                cal();

            stkOp.push(c);
        } else if (c == '#') {
            while (!stkOp.empty() && stkOp.top() != '(' && stkOp.top() != '|')
                cal();

            stkOp.push(c);
        } else if (c >= 'a' && c <= 'z') {
            stkExp.push(new Char(c));
        }
    }

    while (!stkOp.empty())
        cal();

    return exp = stkExp.top();
}
} // namespace Parser

void clearAll() {
    Parser::clear();
    NFA::clear();
    DFA::clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string p, s;

    while (cin >> p >> s) {
        clearAll();
        Parser::parse(p)->build();
        DFA::build();
        cout << (DFA::run(s) ? "Yes" : "No") << '\n';
    }

    return 0;
}