#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	cout<<"[ũ�Ⱑ �ٸ� �� ���������� ������ ���ϱ�]"<<endl;
	cout<<"[n(A)=100,000, n(B)=1000, Sort R in ascending order]"<<endl;
	//	clock_t start, end;
	//	start = clock();

	int alength=100000;
	int blength=1000;
	int range=1000000;
	ofstream fileop;
	vector<int> va;
	vector<int> vb;
	int *vp;
	srand((unsigned int)time(NULL));
	vector<int> numpoolv(range);

	//1~100������ �Էµ� numpoolv ����, ���� ����, va, vb ũ�⸸ŭ �Է�
	//cout<<"\n*���� ���� ���Դϴ١�"<<endl;

	for(int i=0;i<range;++i)
	{
		numpoolv[i]=i+1;
	}

	vp=&numpoolv[0];
	random_shuffle(numpoolv.begin(), numpoolv.end());

	for(int i=0;i<alength;++i)
	{
		va.push_back(*vp);
		++vp;
	}

	vp=&numpoolv[0];
	random_shuffle(numpoolv.begin(), numpoolv.end());

	for(int i=0;i<blength;++i)
	{
		vb.push_back(*vp);
		++vp;	
	}

	//numpoolv �޸� ����
	vector<int> ().swap(numpoolv);


	//A.txt, B.txt���
	fileop.open("A.txt");

	for(int i=0;i<alength;++i)
	{
		fileop<<va[i]<<endl;
	}
	fileop.close();

	fileop.open("B.txt");

	for(int i=0;i<blength;++i)
	{
		fileop<<vb[i]<<endl;
	}
	fileop.close();

	//������ ã��
	//cout<<"*�������� ã�� ���Դϴ١�"<<endl;
	int shorter = (alength<blength)?alength:blength;
	vector<int> vInter(shorter);
	vector<int>::iterator itInter;

	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());

	itInter=set_intersection(va.begin(), va.end(), vb.begin(), vb.end(), vInter.begin());
	vInter.resize(itInter-vInter.begin());
	sort(vInter.begin(),vInter.end());

	//va, vb �޸� ����
	vector<int> ().swap(va);
	vector<int> ().swap(vb);

	//R.txt���
	fileop.open("R.txt");

	for(vector<int>::iterator itprint=vInter.begin(); itprint!=vInter.end();++itprint)
	{
		fileop<<*itprint<<endl;
	}
	fileop.close();

	//vInter �޸� ����
	vector<int> ().swap(vInter);

	//end = clock();
	cout<<"*Complete!"<<endl;
	//cout<<"[�ҿ�ð� : "<<(float)(end-start)/CLOCKS_PER_SEC<<"��]"<<endl;
	system("pause");
}

