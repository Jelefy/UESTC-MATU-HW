int find(int n){
    if(n >= 1000)
        return 0;
    int res = 0;
    for (int i = 100; i <= n; i++){
        int tmp = i, cubsum = 0;
        while(tmp){
            int dig = tmp % 10;
            cubsum += dig * dig * dig;
            tmp /= 10;
        }
        if(cubsum == i)
            res++;
    }
    return res;
}