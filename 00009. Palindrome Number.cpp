char str[1024];
int reverse(int x) {
    int ans = 1,star = 0,tmp = 0;
    int len;
    sprintf(str,"%d",x);
    len = (int)strlen(str);
    if(str[0] == '-'){
        star = 1;
        ans = -1;
    }
    for(int i = len-1,j;i>=star;i--){
        j = str[i]-'0';
        tmp = tmp*10+j;
        if(j != tmp%10) return 0;
    }
    return tmp*ans;
}

bool isPalindrome(int x) {
    if(x < 0) return false;
    int tmp = reverse(x);
    return tmp == x;
}

