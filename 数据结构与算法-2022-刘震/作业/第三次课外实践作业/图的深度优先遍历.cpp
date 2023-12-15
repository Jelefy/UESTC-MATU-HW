#include <cstdio>
using namespace std;
const int N = 3000;

bool w[N][N], visA[N], visB[N];

struct linkedlist{
    struct node{
        int val;
        node *nxt;
        node(int val, node *nxt) : val(val), nxt(nxt){}
    } *head, *tail;
    linkedlist() : head(0), tail(0){}
    void push_back(int val){
        if(tail){
            tail->nxt = new node(val, 0);
            tail = tail->nxt;
        }
        else
            head = tail = new node(val, 0);
    }
    ~linkedlist(){
        while(head){
            node *tmp = head->nxt;
            delete head;
            head = tmp;
        }
    }
} g[N];

void dfsA(int n, int u, int *&p){
    if(visA[u])
        return;
    visA[u] = true;
    *(p++) = u;
    for (int v = 1; v <= n; v++)
        if(w[u][v])
            dfsA(n, v, p);
}

void solveA(int n, int m, int e[][2], int out[]){
    for (int i = 0; i < m; i++)
        w[e[i][0]][e[i][1]] = w[e[i][1]][e[i][0]] = 1;
    dfsA(n, 0, out);
}

void dfsB(int n, int u, int *&p){
    if(visB[u])
        return;
    visB[u] = true;
    *(p++) = u;
    for (linkedlist::node *it = g[u].head; it; it = it->nxt)
        dfsB(n, it->val, p);
}

void solveB(int n, int m, int e[][2], int out[]){
    for (int i = 0; i < m; i++){
        g[e[i][0]].push_back(e[i][1]);
        g[e[i][1]].push_back(e[i][0]);
    }
    dfsB(n, 0, out);
}