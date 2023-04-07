void mobiphin(int n) {
    vector<int> phi(n + 1);
    vector<int> mu(n + 1);
    for (int i = 0; i <= n; i++){
     phi[i] = i; mu[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
     if (phi[i] == i) {
         for (int j = i; j <= n; j += i)
          phi[j] -= phi[j] / i;
          if((j/i)%i == 0) mu[j] = 0;
          mu[j] = -mu[j];
         }
    }}
