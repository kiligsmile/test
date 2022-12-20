#include<iostream>
#include<stack>
using namespace std;

// ע�� ������������Ackermann���Ƿ�ԭʼ�ݹ麯�������� ���Ƕ���(4,3)������Ѵ�ò���׼ȷ���� 

int Ak(int m, int n){
	// cout << "m=" << m << ", n=" << n << endl;
	if(m == 0){
		// cout << "m = 0, ����n+1=" << (n+1) << endl;
		return n + 1;	
	}
	else if(n == 0){
		// cout << "m !=0, n = 0, ����Ak(" << (m-1) << ", 1)" << endl;
		return Ak(m-1, 1);
	}else{
		// cout << "m != 0, n != 0, ����Ak(" << (m-1) << ", Ak(" << m << ", " << (n-1) << ")" << endl;
		return Ak(m-1, Ak(m, n-1));
	}
}

// �ǵݹ� 
int Ak2(int m, int n){
	 stack<int> s;
	 s.push(m);
	 s.push(n);
	 while(!s.empty()){
	 	n = s.top();  // ע��ȡ�õ�һ��ֵΪn 
	 	s.pop();
	 	if(!s.empty()){
	 		m = s.top();
	 		s.pop();
		 }
	 	else{
	 		return n;
		 }
		 if(m==0){
		 	s.push(n+1);
		 }else if(n == 0){
		 	s.push(m-1);
		 	s.push(1);
		 }else{
		 	s.push(m-1);
		 	s.push(m);
		 	s.push(n-1);
		 }
	 }
}

int main(){
	cout << "�ݹ����Ľ��Ϊ��" << endl;
	int m, n;
	cout << "������m(<4)" << endl;
	cin >> m;
	cout << "������m(<3)" << endl;
	cin >> n;
	cout << "�ݹ����Ľ��Ϊ��" << endl;
	int res = Ak(m, n);
	cout << res << endl;
	cout << "�ǵݹ����Ľ��Ϊ��" << endl;
	int res2 = Ak2(m, n);
	cout << res2 << endl;
	return 0;
} 
