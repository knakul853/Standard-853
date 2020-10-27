vector<int>Robin_Karp(const string &pat, const string& text){

/*
Time : O(len1 + len2)
space : O(len2)
 p: is prime which is suitable for the lowercase char. u can use other prime as well.
 more about hashing : https://cp-algorithms.com/string/string-hashing.html
*/


    int P = 31;
    int len1 = pat.size();
    int len2 = text.size();

    vector<int> prime_pow(max(len1, len2) + 1);
    prime_pow[0] = 1;

    for (int i = 1; i < sz(prime_pow); i++){
        prime_pow[i] = (prime_pow[i - 1] * P) % mod;
    }

    int h_pat = 0;
    vector<int> h_text(len2+1, 0);

    // hash value for the text;
    for (int i = 1; i <= len2; i++)
    {
        h_text[i] = (h_text[i - 1] + (text[i - 1] - 'a' + 1) * prime_pow[i - 1]) % mod;
    }
    
    //hash value for the pattern.
    for (int i = 0; i < len1; i++){
        h_pat = (h_pat + (pat[i] - 'a' + 1) * prime_pow[i]) % mod;
    }

    vector<int> occ;

    for (int i = 0; i + len1-1 < len2; i++){
      
      int cur_text = (h_text[i+len1] - h_text[i] + mod)%mod;
      if(cur_text == (h_pat * prime_pow[i])%mod){

          occ.pb(i+1);
      }
    }
    return occ;
}
