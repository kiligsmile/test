#include<iostream>
#include<stack>
using namespace std;

// 注意 阿克曼函数（Ackermann）是非原始递归函数的例子 仅是对于(4,3)的输出已大得不能准确计算 

int Ak(int m, int n){
	// cout << "m=" << m << ", n=" << n << endl;
	if(m == 0){
		// cout << "m = 0, 返回n+1=" << (n+1) << endl;
		return n + 1;	
	}
	else if(n == 0){
		// cout << "m !=0, n = 0, 返回Ak(" << (m-1) << ", 1)" << endl;
		return Ak(m-1, 1);
	}else{
		// cout << "m != 0, n != 0, 返回Ak(" << (m-1) << ", Ak(" << m << ", " << (n-1) << ")" << endl;
		return Ak(m-1, Ak(m, n-1));
	}
}

// 非递归 
int Ak2(int m, int n){
	 stack<int> s;
	 s.push(m);
	 s.push(n);
	 while(!s.empty()){
	 	n = s.top();  // 注意取得第一个值为n 
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
	cout << "递归求解的结果为：" << endl;
	int m, n;
	cout << "请输入m(<4)" << endl;
	cin >> m;
	cout << "请输入m(<3)" << endl;
	cin >> n;
	cout << "递归求解的结果为：" << endl;
	int res = Ak(m, n);
	cout << res << endl;
	cout << "非递归求解的结果为：" << endl;
	int res2 = Ak2(m, n);
	cout << res2 << endl;
	return 0;
} 
