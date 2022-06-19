// doesn't return -1, always >= 0
int lsb(int x){
    int re = 0;
    while((x&1)==0){
        re++;
        x>>=1;
    }
    return re;
}