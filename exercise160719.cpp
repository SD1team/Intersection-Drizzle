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
	cout<<"[크기가 다른 두 난수집합의 교집합 구하기]"<<endl;
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

	//1~100만까지 입력된 numpoolv 생성, 랜덤 셔플, va, vb 크기만큼 입력
	//cout<<"\n*난수 생성 중입니다…"<<endl;

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

	//numpoolv 메모리 해제
	vector<int> ().swap(numpoolv);


	//A.txt, B.txt찍기
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

	//교집합 찾기
	//cout<<"*교집합을 찾는 중입니다…"<<endl;
	int shorter = (alength<blength)?alength:blength;
	vector<int> vInter(shorter);
	vector<int>::iterator itInter;

	sort(va.begin(),va.end());
	sort(vb.begin(),vb.end());

	itInter=set_intersection(va.begin(), va.end(), vb.begin(), vb.end(), vInter.begin());
	vInter.resize(itInter-vInter.begin());
	sort(vInter.begin(),vInter.end());

	//va, vb 메모리 해제
	vector<int> ().swap(va);
	vector<int> ().swap(vb);

	//R.txt찍기
	fileop.open("R.txt");

	for(vector<int>::iterator itprint=vInter.begin(); itprint!=vInter.end();++itprint)
	{
		fileop<<*itprint<<endl;
	}
	fileop.close();

	//vInter 메모리 해제
	vector<int> ().swap(vInter);

	//end = clock();
	cout<<"*Complete!"<<endl;
	//cout<<"[소요시간 : "<<(float)(end-start)/CLOCKS_PER_SEC<<"초]"<<endl;
	system("pause");
}

