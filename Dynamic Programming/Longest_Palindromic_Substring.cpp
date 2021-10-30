string longestPalindrome(string s) {

    // Manachers algorithm 
    
    // we will be solving using o(n sq.)
    int maxlength=0;
    int length=1;
    int lans;
    int rans;
    int elength=0;
    for(int i=0;i<s.size();i++)
    {
        int l=i-1;
        int r=i+1;
        int el=i;
        int er=i+1;
        while(el>=0 && er<s.size() && s[el]==s[er])
        {
            elength+=2;
            el--;
            er++;
        }
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            length+=2;
            l--;
            r++;
        }
        if(length>maxlength)
        {
            lans=l+1;
            rans=r-1;
            maxlength=length;
        }
        if(elength>maxlength)
        {
            lans=el+1;
            rans=er-1;
            maxlength=elength;
        }
        elength=0;
        length=1;
    }
    string ans="";
    for(int i=lans;i<=rans;i++)
    {
        ans+=s[i];
    }
   return ans;
}
};
