vector<int> prefix_function(string&s){
        
        int n = s.size();
        vector<int>phi(n);
        
        for(int i=1; i<n; i++){
            
            int j = phi[i-1];
            
            while(j>0 && s[i] != s[j] ){
                j = phi[j-1];
            }
            
            if(s[i] == s[j]){
                j++;
            }
            
            phi[i] = j;
        }
        
        return phi;
    }
