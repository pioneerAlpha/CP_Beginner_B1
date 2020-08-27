/// palindromic tree
int nxt[N][26], sfx[N], len[N];
void init(int n){
    memset(nxt[n],-1,sizeof nxt[n]);
}
int palindromic_tree(char s[]){
    int cur = 0, tot = 2;
    len[0] = -1;
    len[1] = sfx[1] = sfx[0] = 0;
    init(0);
    init(1);
    for(int i = 0; s[i]!='\0'; i++){
        while(cur!=0 && s[i-1-len[cur]]!=s[i]) cur = sfx[cur];
        if(nxt[cur][s[i]-'a']!=-1){
            cur = nxt[cur][s[i]-'a'];
            continue;
        }
        init(tot);
        len[tot] = len[cur] + 2;
        nxt[cur][s[i]-'a'] = tot;
        cur = sfx[cur];
        while(s[i-1-len[cur]]!=s[i]) cur = sfx[cur];
        if(len[tot]!=1) sfx[tot] = nxt[cur][s[i]-'a'];
        else sfx[tot] = 1;
        cur = tot++;
    }
    return tot;
}
