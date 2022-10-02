//dp[i][j] = min of dp[i - 1][k] + C[k][j] forall k < j,
//and optk[i][j] <= optk[i][j+1]
//optk is optimial k that gives you answer.
// compute dp_cur[l], ... dp_cur[r] (inclusive)
// C(a,c) + C(b,d) <= C(a,d) + C(b,c) for all a<=b<=c<=d
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};
    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
    }
    dp_cur[mid] = best.first;
    int opt = best.second;
    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}
// notebook-generator ./ --author "CatsOnTrees" --initials UTP --size 11 --columns 3 --paper a4paper
