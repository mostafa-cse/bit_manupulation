1.Rest ans of the problems :
int count(int n, vector<int> a, int x) {
	int msb = __lg(x), ans = n, temp = 0, vis[n] = {0};
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && ((x >> i) & 1) && !((a[j] >> i) & 1) )temp++, vis[j] = 1;
			if (!((a[j] >> i) & 1) && !vis[j])cnt++;
		}

		if (!((x >> i) & 1))ans = min(ans, temp + cnt);
	}
	return ans;
}

2.rest of ans the problem

int count(int N, int A[], int X) 
    {   
        // code here
        int prefix=0,ans=N;
        for(int i=30;i>=0;i--){
            if(((X>>i)&1)!=0){
                prefix^=(1l<<i);
                continue;
            }
            int ct=0;
            long p=prefix^(1l<<i);
            for(int j=0;j<N;j++){
                if((A[j]&p)==p)
                    ct++;
            }
            ans=Math.min(ans,N-ct);
        }
        return ans;
    }      
