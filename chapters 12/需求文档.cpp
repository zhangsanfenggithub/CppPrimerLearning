#include<iostream>
����
	�����ļ����ܼ�ס���ʵĳ��ֵ����������ֵĴ���
	���
		--��ȡ���ʳ��ֵ��к�
		--�к�����
		--�ܹ���ӡ�����к��ı�
	
	
	--vector<string> ��ȡ�ı���ÿ����Ϊһ��Ԫ�أ���Ҫ��ӡʱѰ���к�
	--set�����кţ���֤���ظ�������
	--map�����ʺ��кŹ�������
	
	�����ļ���TextQuery
	��ѯ�����QueryResult
	
	
�����ǰ����ʹ������˼��������Ҫ�Ĳ���

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);//���ļ������ʼ��
	string s;
	while(1){
		cout << "enter word to look for or enter q to quit" << endl;
		if(!(cin >> s) && s == "q") break;
		print(cout, tq.query(s));//��������Լ�tq����Ҫ�Ĳ�ѯ���� 
	} 
 } 
