#include <iostream>
using namespace std;

template <typename _T>
class node {
public:
    _T x;
    node *pre, *nxt;
    _T get_value() { return x; }
    void set_value(_T a) {
        x = a;
        pre = NULL;
        nxt = NULL;
    }
    void insert(node *a) {
        if (pre != NULL) {
            (*pre).nxt = a;
            (*a).pre = pre;
        }
        pre = a;
        (*a).nxt = this;
    }
    node *get_next() { return nxt; }
    node *get_pre() { return pre; }
};

void test1() {
    node<int> *ptr;
    node<int> node1, node2, node3;
    node1.set_value(1);
    node2.set_value(2);
    node3.set_value(3);
    node3.insert(&node2);
    node2.insert(&node1);

    for (ptr = &node1;; ptr = ptr->get_next()) {
        cout << ptr->get_value() << " ";
        if (ptr->get_next() == NULL)
            break;
    }
}

void test2() {
    node<float> *ptr;
    node<float> node1, node2, node3;
    node1.set_value(1.1);
    node2.set_value(2.2);
    node3.set_value(3.3);
    node3.insert(&node2);
    node2.insert(&node1);

    for (ptr = &node1;; ptr = ptr->get_next()) {
        cout << ptr->get_value() << " ";
        if (ptr->get_next() == NULL)
            break;
    }
}

void test3() {
    node<char> *ptr;
    node<char> node1, node2, node3;
    node1.set_value('a');
    node2.set_value('b');
    node3.set_value('c');
    node3.insert(&node2);
    node2.insert(&node1);

    for (ptr = &node1;; ptr = ptr->get_next()) {
        cout << ptr->get_value() << " ";
        if (ptr->get_next() == NULL)
            break;
    }
}

int main() {
    int type;
    cin >> type;

    switch (type) {
    case 1:
        test1();
        break;

    case 2:
        test2();
        break;

    case 3:
        test3();
        break;
    }
    return 0;
}
