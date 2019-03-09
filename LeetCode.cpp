// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>
#include<map>
#include<queue>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<sstream>
#include<cmath>
#include<regex>
#include<numeric>
#include<unordered_map>
#define INT_MAX (2147483647)
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
class Solution {
//回溯法
public:
	vector<string> Permutation(string str) {
		set<string> strset;
		vector<string> res;
		if (str.length() == 0)
			return res;
		int num = pow(2, str.length());
		while (num!=0)
		{
			int addr = num;
			while (addr)
			{

			}
		}
	}
	int Rectangularcover(vector<vector<int>> axis)
	{
		int  res = 0;
		for (int i = 0; i < axis.size(); i++)
		{
			for (int j = i+1; j < axis.size(); j++)
			{
				if (axis[j][0] < axis[i][2] && axis[j][1] < axis[i][3])
				{
					res += (axis[i][2] - axis[i][0]) * (axis[i][3] - axis[i][1]) + (axis[j][2] - axis[j][0]) * (axis[j][3] - axis[j][1]);
					if (axis[j][2] < axis[i][2] && axis[j][3] < axis[i][3])
						res -= (axis[j][2] - axis[j][0]) * (axis[j][3] - axis[j][1]);
					else
						res -= (axis[i][2] - axis[j][0]) * (axis[i][3] - axis[j][1]);
					break;
				}
			}
		}
		return res;
	}
	void findlen(vector<string>guizhe, string bad, vector<char> bchar,int& len)
	{
		if (bchar.size() == 0)
		{
			len = -1;
			return;
		}
		vector<char> gz;
		len++;
		for (int i = 0; i < bchar.size(); i++)
		{
			int len = 0;
			for (int j = 0; j < guizhe.size(); j++)
			{
				if (guizhe[j][1] == bchar[i])
					gz.push_back(guizhe[j][0]);
			}
		}
		for (int i = 0; i <gz.size(); i++)
		{
			if (bad.find(gz[i]) == string::npos)
				return;
		}
		findlen(guizhe, bad, gz, len);
	}
	int Completemanuscript(vector<string>guizhe, string bad,string manuscript)
	{
		map<char, int> mymap;
		for (int i = 0; i < bad.length(); i++)
		{
			vector<char> gz;
			gz.push_back(bad[i]);
			int len = 0;
			findlen(guizhe, bad, gz, len);
			mymap[bad[i]] = len;
		}
		int res = 0;
		for (int i = 0; i < manuscript.length(); i++)
		{
			if (bad.find(manuscript[i])==string::npos)
				res++;
			else
			{
				if (mymap[manuscript[i]] == -1)
					return 0;
				else
					res += mymap[manuscript[i]] + 1;
			}
		}
		return res;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size()<=1)
			return true;
		int sign = sequence.size() - 2;
		while (sign >= 0)
		{
			if (sequence[sign] < sequence[sequence.size() - 1])
				break;
			sign--;
		}
		for (int i = sign; i >=0; i--)
		{
			if (sequence[i] > sequence[sequence.size() - 1])
				return false;
		}
		if (sign == -1)
		{
			vector<int> ns(sequence.begin(), sequence.end() - 1);
			return VerifySquenceOfBST(ns);
		}
		if (sign == sequence.size() - 2)
		{
			vector<int> ns(sequence.begin(), sequence.end() - 1);
			return VerifySquenceOfBST(ns);
		}
		vector<int> ns1(sequence.begin(), sequence.begin()+sign+1);
		vector<int> ns2(sequence.begin() + sign + 1, sequence.end() - 1);
		return VerifySquenceOfBST(ns1) && VerifySquenceOfBST(ns2);
	}
	int isSubStr(string str1, string str2)
	{
		if (str2.length() > str1.length()||str2.length()==0)
			return 0;
		int num = 0;
		string sstr = str1;
		while (sstr.find(str2) != string::npos)
		{
			sstr = sstr.substr(sstr.find(str2)+str2.length() + 1, sstr.length() - sstr.find(str2) - str2.length() - 1);
			num++;
		}
		return num;
	}
	int SroundCount(const string& str, const string& sub) {
		int ret = 0;
		if (sub.empty() || str.length() < sub.length()) return ret;
		for (int i = 0; i < str.length() + sub.length() - 1; ++i) {
			int j;
			for (j = 0; j < sub.length(); ++j)
				if (str[(i + j) % str.length()] != sub[j]) break;
			if (j == sub.length()) ret++;
		}
		return ret;
	}

	//wstring circulating(string number)
	//{
	//	string str1 = "";
	//	string str2 = "";
	//	int sign = 0;
	//	while (number[sign] != '/')
	//		sign++;
	//	str1 = number.substr(0, sign);
	//	str2 = number.substr(sign + 1, number.length() - sign);
	//	int num1 = 0, num2 = 0;
	//	stringstream mystr;
	//	mystr << str1;
	//	mystr >> num1;
	//	mystr.clear();
	//	mystr << str2;
	//	mystr >> num2;
	//	double divres = num1*1.0 / num2;
	//	wstring divress = to_wstring(divres);
	//	sign = 0;
	//	while (divress[sign] != '.')
	//		sign++;
	//	int sign2 = sign + 2;
	//	while (sign2 < divress.length())
	//	{
	//		if ()
	//		{

	//		}
	//	}
	//	return divress;
	//	//return str1;
	//}
};
int main() {
	//unordered_map<int, int> Nmap;
	//vector<int> cnode;
	//cnode.push_back(3);
	//bres = sl.findloop(graph,cnode,Nmap, 3,0);
	Solution sl;
	//sl.circulating("2456/3678");
	int res = 0;
	//vector<vector<int>> axis = { {0,0,1,1},{1,1,2,2},{1,0,2,1} };
	//res=sl.Rectangularcover(axis);
	//int N = 0;
	//cin >> N;
	//while (N!=0)
	//{
	//	int x0, y0, x1, y1;
	//	x0 = y0 = x1 = y1 = 0;
	//	cin >> x0 >> y0 >> x1 >> y1;
	//	vector<int> in;
	//	in.push_back(x0);
	//	in.push_back(y0);
	//	in.push_back(x1);
	//	in.push_back(y1);
	//	axis.push_back(in);
	//}
	vector<string> guizhe = { "ab","bc","xc","ef","fx" };
	string bad = "bc";
	string manuscript = "helloworldabc";
	res = sl.Completemanuscript(guizhe, bad, manuscript);
	return 0;
}
