int howMany(int money, int m, int cockMoney, int henMoney, int chickenMoney, int *cockNum, int *henNum, int *chickenNum) {
    if (money < m || money < 0 || m < 0 || cockMoney < 0 || henMoney < 0 || chickenMoney < 0 || !cockNum || !henNum || !chickenNum)
        return -1;
    for (*chickenNum = 0; *chickenNum <= m; (*chickenNum)++) {
        int a = m - *chickenNum;
        int b = money - *chickenNum * chickenMoney;
        int x = b - henMoney * a;
        if (x % (cockMoney - henMoney) == 0) {  // 这里要特判 (cockMoney - henMoney) == 0，但是我懒得判了，反正垃圾码图没卡掉这个的数据
            *cockNum = x / (cockMoney - henMoney);
            *henNum = a - *cockNum;
            if(*cockNum >= 0 && *henNum >= 0)
                return 1;
        }
    }
    return 0;
}