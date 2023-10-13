int p[100005], rk[100005];
int find(int n){
	if(p[n] == n)return n;
	return find(p[n]);
}
void union_set(int x, int y){
	int rx = find(x);
	int ry = find(y);
	if(rx != ry){
		if(rk[rx] > rk[ry]){
			p[ry] = rx;
		}
		else if(rk[ry] > rk[rx]){
			p[rx] = ry;
		}
		else {
			p[rx] = ry;
			rk[ry] += 1;
		}
	}
}
