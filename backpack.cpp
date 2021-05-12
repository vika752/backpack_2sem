
#include <iostream>
using namespace std;

void sort(int* p_ves, int* p_zn, int n){ //сортировка, к-я будет уч знач из p ves и p zn
	int t;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(p_zn[j]/p_ves[j] <= p_zn[j+1]/p_ves[j+1]){
				t = p_ves[j];
				p_ves[j] = p_ves[j + 1];
				p_ves[j + 1] = t;
				t = p_zn[j];
				p_zn[j] = p_zn[j + 1];
				p_zn[j + 1] = t;
			}
		}
	}
}
//p_ves - список, сод вес n эл-в, 
//p_zn - список, содержащий значение n эл-в, n - сколько предметов
int backpack_f(int* p_ves, int* p_zn, int n, int U) { // U - макс вес, что можно упаковать
	sort(p_ves, p_zn, n);
	int W = 0; //переменная W подсчитывает значение объектов
	int shtuk = 0; //переменная, к-я будет хранить в и-й итерации, сколько штук можно упаковать
	for(int i = 0; i < n; i++){
//подсчитаем, сколько штук можно упаковать
		shtuk = U / p_ves[i];//ум зн-е, сколько еще можно упаковать 
		W += shtuk * p_zn[i];//ув стоимость рюкзака
	}
	return W;
}
//В кач рез-та дается общ стоимость предметов рюкзаков
int main () {
	int n;
	int U;
	cin >> n >> U;
	int* p_zn = new int[n];
	for(int i = 0; i < n; i++)
		cin >> p_zn[i];
	int* p_ves = new int[n];
	for(int i = 0; i < n; i++)
		cin >> p_ves[i];
	cout << backpack_f(p_ves, p_zn, n, U);
	cout << endl;
	delete[] p_ves, p_zn;
	system("pause");
	return 0;
}