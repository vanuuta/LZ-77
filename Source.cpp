//#pragma warning(suppress : 6387)
#include<string>
#include <cstring>
#include <iostream>
#include<algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

string s = "На_мирный_шум_дубов,_на_тишину_полей,_на_праздность_вольную,_подругу_размышленья.IПеред_опасностью_позорно-малодушны,_и_перед_властию_-_презренные_рабы.";
//string s = "Везде_передо_мной_подвижные_картины:_здесь_вижу_двух_озер_лазурные_равнины.IНа_севере_диком_стоит_одиноко_на_голой_вершине_сосна.";
string str;

// прототипы
int length(int match, char* c);
char* binary(int num);
char* mon(int num);
char* bin(int num);
char* unar(int num);
bool is_equal(char* c, char* arr, int len);
int len_bin(int num);
bool is_here(char c);
int match_index(char* c);
int getHead(char* str);
int last_seen(char* arr, int len);
void print(char* c);
int length_dec(int num);

int len_bin(int num) {
	int i = 0;
	while (num) {
		num /= 2;
		i++;
	}
	return i;
}

char* binary(int num) {
	static char binary[50]; int count = 0;
	do {
		if (num % 2 == 0)
			binary[count++] = '0';
		else
			binary[count++] = '1';
		num /= 2;
	} while (num);
	binary[count++] = '\0';

	static char bin[50];

	int k = 0;
	for (int i = strlen(binary); i > 0; i--) {
		bin[k++] = binary[i - 1];
	}
	bin[k++] = '\0';
	/*for (int i = 0; i < strlen(bin); i++) {
		cout << bin[i];
	}*/
	return bin;
}

char* bin(int num) {
	char* temp = binary(num);
	int i = 0;
	char* ptr = temp + 1;
	while (ptr[i] != '\0') {
		//cout << ptr[i];
		i++;
	}
	ptr[i++] = '\0';
	return ptr;
}

char* unar(int num) {
	char* temp = new char[num+2];
	for (int i = 0; i < num ; i++) {
		temp[i] = '1';
	}
	temp[num] = '0';
	temp[num+1] = '\0';
	/*for (int i = 0; i < num + 1; i++) {
		cout << temp[i] << " ";
	}*/
	return temp;
}

char* mon(int num) {
	char* temp = bin(num);
	int size_bin = 0;
	while (temp[size_bin] != '\0') {
		//cout << temp[i];
		size_bin++;
	}
	int x = size_bin + 1;
	char* ptr = unar(x);
	int size_unar = 0;
	while (ptr[size_unar] != '\0') {
		//cout << ptr[i];
		size_unar++;
	}
	int size_mon = size_bin + size_unar;
	char* mon = new char[size_mon + 1];
	int i = 0;
	for (i; i < size_unar; i++) {
		mon[i] = ptr[i];
	}
	i = 0;
	for (size_unar; size_unar < size_mon; size_unar++) {
		mon[size_unar] = temp[i];
		i++;
	}
	mon[size_unar++] = '\0';
	i = 0;
	/*while (mon[i] != '\0') {
		cout << mon[i];
		i++;
	}*/
	return mon;
}

bool is_here(char c) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == c)
			return true;
	}
	return false;
}

int length(int match, char* c) {
	int length = 1;
	while ((s[++match] == *(++c)) && (*(c + 1) != '\0')) {
		length++;
	}
	return length;
}

int match_index(char* c) {
	//cout << "---------------------------------------------------" << temp << endl;
	int index[20] = {-1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int len[20] = { -1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	//int* index = NULL; int* len = NULL;
	int* prr = index;
	int* l = len;
	int i = 0;
	while (&s[i] != c) {
		//cout << i << " ";
		if (s[i] == *c) {
			*prr++ = i;
			*l++ = length(i, c);	
		}
		i++;
	} 
	int max = 0;
	for (int i = 0; i < 20; i++) {
		if (len[i] > max) {
			max = index[i];
		}
	}
	
	return max;
}

int getHead(char* str) {
	for (int i = 0; i < s.size(); i++) {
		if (&s[i] == str)
			return i;
	}
	return 0;
}

int last_seen(char* arr,int len) {
	
	int i = 0;
	int flag = 0; int index = 0;
	while (&s[i] != &arr[0] ) {
		if (s[i] == *arr) {
			if (is_equal(&s[i], arr, len)) 
				index=i;
		}
			
		
		i++;
	}
	return index;
	
	
}

bool is_equal(char* c, char* arr, int len) {
	bool flag = false;
	for (int i = 0; i < len; i++) {
		if (c[i] == arr[i])
			flag = true;
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

void print(char* c) {
	int i = 0;
	while (c[i] != '\0') {
		cout << c[i];
		i++;
	}
}

int length_dec(int num) {
	int i = 0;
	while (num) {
		num /= 10;
		i++;
	}
	return i;
}


#define DEBUG
int main() {

	setlocale(LC_ALL, "Rus");

#ifdef DEBUG

	//153
	cout << setiosflags(ios::left);
	char* ptr = &s[0];
	s[s.length()] = '\0';
	int flag = 0; int z = 0; int final_cost = 0;
	int i = 0; int global = 0;
	cout << setw(5) << "i" << setw(5) << "Флаг" << "\t" << "Словарь" << "\t\t" << "d" << "\t\t" << "l" << "\t" << "Код" << "\t\t" << "Затраты в битах" << endl;


	while (*ptr != s[s.length()]) {
		if (!is_here(*ptr)) {
			flag = 0;
			str += *ptr;
			cout << setw(5) << i + 1 << setw(5) << flag << "\t" << *ptr << "\t\t" << "-" << "\t\t" << "0" << "\t" << "0";
			char* bin = binary(static_cast<unsigned int> (static_cast<unsigned char> (*ptr)));
			print(bin);
			int k = 0;
			while (bin[k] != '\0') {
				k++;
			}
			if (k + 1 >= 8) cout << "\t"; else cout << "\t\t";
			cout << k + 1 << endl;
			final_cost += k + 1;
			global++;
			ptr++;
		}
		else {
			flag = 1;
			cout << setw(5) << i + 1 << setw(5) << flag << "\t";
			int len = length(match_index(ptr), ptr);
			char* arr;
			arr = new char[len];
			arr = ptr;
			int t = global;
			for (int i = 0; i < len; i++) {
				arr[i] = *ptr;
				cout << arr[i];
				global++;
				ptr++;
			}
			for (int i = 0; i < s.size(); i++) {
				if (&s[i] == &arr[0])
					z = i;
			}
			
			if (len > 8) cout << "\t";
			else cout << "\t\t";
			cout <<  t - last_seen(arr, len) - 1;
			cout << "(" << z << ")"; 
			if (length_dec(t - last_seen(arr, len) - 1) + length_dec(z) + 2 >= 8) 	cout << "\t"; else cout << "\t\t";
			cout  << len << "\t" << "1";
			int lg = ceil(log(z) / log(2));							//Количество разрядов
			int len_binary = len_bin(t - last_seen(arr, len) - 1);  //длина двоичного кода числа d
			char* b = binary(t - last_seen(arr, len) - 1);			//двоичный код числа d
			char res[50];
			int k = 0;
			if (len_binary <= lg) {
				for (int i = 0; i < lg-len_binary; i++) {
					res[k++] = '0';
				}
				for (int i = 0; i < len_binary; i++) {
					res[k++] = b[i];
				}
			}
			char* mono = mon(len);
			int mono_index = 0;
			while (mono[mono_index] != '\0') {
				res[k++] = mono[mono_index];
				mono_index++;
			}
			res[k++] = '\0';
			print(res);
			k = 0;
			while (res[k] != '\0') {
				k++;
			}
			if (k + 1 >= 8) cout << "\t"; else cout << "\t\t";
			cout << k + 1 << endl;
			final_cost += k + 1;
		}
		i++; 
	}
	cout << endl << "l(x) = " << final_cost << endl;
#else
	
	//char* arr = &s[35];
	//cout << arr[0] << arr[1] << endl;
	//cout << arr[4] << endl;
	//cout << arr << endl << s << endl;

	/*cout << match_index(arr) << endl << endl;
	cout << length(match_index(arr), arr) << endl;*/
	//cout << len_bin(456);
	//cout << last_seen(arr, 2);
	/*cout << getHead(arr) << endl;
	cout << last_seen(arr, 2) << endl << getHead(arr) - last_seen(arr, 2) - 1 << endl << s;
	*/
    char* m=mon(237);
	int i = 0;
	while (m[i] != '\0') {
		cout << m[i];
		i++;
	}

	//cout << getHead(arr);
	//cout << s.length();
	

#endif
	return 0;
}