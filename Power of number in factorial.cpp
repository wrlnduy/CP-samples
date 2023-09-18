int fact_pow(int f, int p){
    int cnt = 0;
    while(f){
        f/=p;
        cnt += f;
    }
    return cnt;
}
