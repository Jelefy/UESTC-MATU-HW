struct cyclic_list{
    int id;
    cyclic_list *nxt;
    cyclic_list(int id, cyclic_list *nxt = 0) : id(id), nxt(nxt){}
    bool delete_nxt(){
        if(nxt == this)
            return false;
        cyclic_list *tmp = nxt->nxt;
        delete nxt;
        nxt = tmp;
        return true;
    }
};
int *solve(int n, int m, int k){
    int *res = new int[n - k];
    cyclic_list *lst = new cyclic_list(n);
    lst->nxt = lst;
    for (int i = n - 1; i > 0; i--)
        lst->nxt = new cyclic_list(i, lst->nxt);
    for (int i = 0; i < n - k; i++){
        for (int j = 1; j < m; j++)
            lst = lst->nxt;
        res[i] = lst->nxt->id;
        lst->delete_nxt();
    }
    while(lst->delete_nxt());
    delete lst;
    return res;
}