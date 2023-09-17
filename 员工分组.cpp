#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
#include<algorithm>
using namespace std;

class Worker
{
public:
	string m_name;
	int m_salary;
};

void CreateWorker(vector<Worker>& v)
{
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "员工";
		worker.m_name += nameseed[i];
		worker.m_salary = rand() % 10001 + 10000;
		v.push_back(worker);
	}
}
void SetGroup(vector<Worker>& v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depid = rand() % 3;
		m.insert(make_pair(depid, *it));
	}
}
void ShowWorkerByGroup(multimap<int, Worker>&m)
{
	cout << "策划部门（0）的员工信息如下：" << endl;
	multimap<int, Worker>::iterator pos = m.find(0);
	int num = m.count(0);
	int i = 0;
	for (; pos != m.end() && i < num; i++, pos++)
	{
		cout << "姓名：" << pos->second.m_name << " 薪水：" << pos->second.m_salary << endl;
	}
	cout << "销售部门（1）的员工信息如下：" << endl;
	i = 0;
	pos = m.find(1);
	num = m.count(1);
	for (; pos != m.end() && i < num; i++, pos++)
	{
		cout << "姓名：" << pos->second.m_name << " 薪水：" << pos->second.m_salary << endl;
	}
	cout << "技术部门（2）的员工信息如下：" << endl;
	i = 0;
	pos = m.find(2);
	num = m.count(2);
	for (; pos != m.end() && i < num; i++, pos++)
	{
		cout << "姓名：" << pos->second.m_name << " 薪水：" << pos->second.m_salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker>worker;
	CreateWorker(worker);
	multimap<int, Worker>groups;
	SetGroup(worker, groups);
	ShowWorkerByGroup(groups);
	system("pause");
	return 0;
}
