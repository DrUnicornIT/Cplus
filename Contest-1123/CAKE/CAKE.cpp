#include <bits/stdc++.h>

using namespace std;

struct Tnode {
	int x, y;
	int id;
}Triangle[500010];

int cnt;
int n, Q;
int Ans[100010];

bool cmpX (Tnode a, Tnode b) {
	if(a.x == b.x) {
		return a.id > b.id;
	}
	return a.x < b.x;
}
bool cmpY (Tnode a, Tnode b) {
	if(a.y == b.y) {
		return a.id > b.id;
	}
	return a.y < b.y;
}
int Edge[100010];

int main() {

	cin >> n;
 	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= 3; j ++) {
			int x, y;
			cin >> x >> y;
			Triangle[++cnt].x = x;
			Triangle[cnt].y = y;
			Triangle[cnt].id = i;
		}
	}
	cin >> Q;
	for(int i = 1; i <= Q; i ++) {
		char x, y;
		cin >> x >> y;
		int val; 
		cin >> val;
		if(x == 'x') {
			Triangle[++cnt].x = val;
			Triangle[cnt].y = 0;
			Triangle[cnt].id = -i;
		} else {
			Triangle[++cnt].x = 0;
			Triangle[cnt].y = val;
			Triangle[cnt].id = -i;
		}
	}	
	sort(Triangle + 1, Triangle + 1 + cnt, cmpX);

	int Cur = 0;
	int Inc = 0;
	for(int i = 1; i <= cnt; i ++) {
		int ID = Triangle[i].id;
		if(ID > 0) {
			Edge[ID] ++;
			if(Edge[ID] == 1) Inc ++;
			if(Edge[ID] == 3) {
				Cur --;
				Inc --;
			}
		} else {
			if(Triangle[i].x) {
				Ans[-Triangle[i].id] = Cur;
			}
		}
		if(Triangle[i].x != Triangle[i+1].x) Cur = Inc;
	}
	sort(Triangle + 1, Triangle + 1 + cnt, cmpY);
	Cur = 0;
	Inc = 0;
	memset(Edge, 0, sizeof Edge);
	for(int i = 1; i <= cnt; i ++) {
		int ID = Triangle[i].id;
		if(Triangle[i].id > 0) {
			Edge[ID] ++;
			if(Edge[ID] == 1) Inc ++;
			if(Edge[ID] == 3) {
				Cur --;
				Inc --;
			}
		} else {
			if(Triangle[i].y) {
				Ans[-Triangle[i].id] = Cur;
			}
		}
		if(Triangle[i].y != Triangle[i+1].y) Cur = Inc;
	}
	for(int i = 1; i <= Q; i ++) {
		cout << Ans[i] << '\n';
	}
}