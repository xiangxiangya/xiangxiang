
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;


#if 0
//��vector�г��ýӿڵĲ���
int main()
{
	/*vector<int> v(4, 100);
	auto it = v.begin();
	for (it; it != v.end(); it++)
	{
		cout << *it;
	}*/

	/*vector<int> v = { 1, 2, 3, 4, 5 };
	int a = 0;
	cout << a + v.back() << endl;*/
	//int arr[] = { 6, 7, 8, 9 };
	//vector<int> v = { 1, 2, 3, 4, 5 };
	////v.assign(3, 5);
	//
	//for (auto e : v)
	//{
	//	cout << e;
	//}


	vector<int>v(5, 100);
	
	v.insert(v.begin()+1, 5);

	auto it = v.begin() + 1;
	cout << *it;
	system("pause");
	return 0;
}
#endif


//��̬��ά����Ĵ���
//int main()
//{
//	vector<vector<int>> v;//������һ���������еĶ�λ����
//	v.resize(3);
//	for (int i = 0; i < v.size(); i++)
//	{
//		v[i].resize(4);
//	}
//	v.assign({});
//	system("pause");
//	return 0;
//}



//ģ��ʵ��vector


//class mine
//{
//public:
//	class vector
//	{
//	private:
//		T *star;
//		T* end;
//		T* endofstorge;
//	};
//};
//int main()
//{
//	system("pause");
//	return 0;
//}


//������һ��ֻ���ڶ��ϴ����������
//���˼·�������캯���Ϳ��������Ȩ�޸���˽��


void test()
{
	int a = 10;
}
int main()
{
	test();
	return 0;
}
