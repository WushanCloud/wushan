// 皇上选妃小游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "皇上选妃小游戏.h"


int main()
{
	string wushan_emperor_name;
	string wushan_emperor_time;
	int count = 0;//目前有效妃子个数 
    cout << "请输入皇帝的名讳："<<endl;
	cin >> wushan_emperor_name;
	cout << "请输入皇帝年号：" << endl;
	cin >> wushan_emperor_time;
	//开始游戏
	cout << wushan_emperor_time << " 元年 " << wushan_emperor_name << " 登基称帝" << endl;
	//后宫初始化
	//emperor_harem_initialize();
	while (true)
	{
		int select = 0;
		menu();
		cin >> select;
		if(select > 5 || select < 1)
		{
			cout << "后宫处理乃皇家大事，请谨慎选择" << endl;
			continue;
		}
		switch (select)
		{
		case 1:
			increaseConcubine(&count);
			break;
		case 2:
			modificationConcubine();
			break;
		case 3:
			deleteConcubine();
			break;
		case 4:
			seekConcubine();
			break;
		case 5:
			emperor_harem_print(count);
			break;
		default:
			break;
		}
	}
    return 0;
}

bool emperor_harem_initialize()
{
	;

	return true;
}

void menu()
{
	cout << "1. 陛下钦点选妃\n";
	cout << "2. 陛下宠幸妃子\n";
	cout << "3. 将妃子打入冷宫\n";
	cout << "4. 陛下选择妃子谈心\n";
	cout << "5. 输出后宫状态" << endl;
}

bool increaseConcubine(int* count)
{
	int& pos = *count;
	if (pos >= N)
	{
		cout << "后宫妃子已满，请陛下爱惜枕边人！" << endl;
	}
	cout << "请输入妃子姓名" << endl;
	cin >> emperor_harem[pos].wushan_concubine_name;
	emperor_harem[pos].wushan_concubine_class = concubine_class[0];
	emperor_harem[pos].wushan_concubine_favorability = 100;
	emperor_harem[pos].wushan_concubine_active = true;
	pos++;
	return true;
}

bool modificationConcubine()
{
	string concubine_name;
	cout << "请输入妃子姓名" << endl;
	cin >> concubine_name;
	size_t j = 0;
	for (int i = 0; i <= N && emperor_harem[i].wushan_concubine_active == true; i++)
	{
		if (concubine_name.compare(emperor_harem[i].wushan_concubine_name) == 0)
		{
			cout << "春宵一刻值千金！"<< endl;
			if (emperor_harem[i].wushan_concubine_class.compare(concubine_class[concubine_class->size()]) == 0)
			{
				break;
			}
			else for (j = 0; j < concubine_class->size(); j++)
			{
				if (emperor_harem[i].wushan_concubine_class.compare(concubine_class[j]) == 0)
				{
					emperor_harem[i].wushan_concubine_favorability += 20;
					emperor_harem[i].wushan_concubine_class = concubine_class[++j];
				}
					
			}
		}
	}
	for (int i = 0; i <= N && emperor_harem[i].wushan_concubine_active == true && i != j; i++)
	{
		emperor_harem[i].wushan_concubine_favorability -= 10;
		if (emperor_harem[i].wushan_concubine_favorability < 0)
		{
			cout << emperor_harem[i].wushan_concubine_name
				<< "由于长期未得召见，心生暗恨，最终火烧后宫，后宫从此不复存在!\n"
				<< "游戏结束\n" << endl;
			exit(0);
		}
	}
	return true;
}

bool deleteConcubine()
{
	string concubine_name;
	cout << "请输入妃子姓名" << endl;
	cin >> concubine_name;
	for (int i = 0; i <= N && emperor_harem[i].wushan_concubine_active == true; i++)
	{
		if (concubine_name.compare(emperor_harem[i].wushan_concubine_name) == 0)
		{
			emperor_harem[i].wushan_concubine_active = false;
		}
	}
	return true;
}

bool seekConcubine()
{
	string concubine_name;
	cout << "请输入妃子姓名" << endl;
	cin >> concubine_name;
	for (int i = 0; i <= N && emperor_harem[i].wushan_concubine_active == true; i++)
	{
		if (concubine_name.compare(emperor_harem[i].wushan_concubine_name) == 0)
		{
			emperor_harem[i].wushan_concubine_favorability += 10;
		}
	}
	return true;
}

void emperor_harem_print(int count)
{
	cout << "**********************************\n";
	cout << "姓名\t级别\t好感度" << endl;
	for (int i = 0; i < count && emperor_harem[i].wushan_concubine_active == true;  i++)
	{
		cout << emperor_harem[i].wushan_concubine_name << "\t";
		cout << emperor_harem[i].wushan_concubine_class << "\t";
		cout << emperor_harem[i].wushan_concubine_favorability<< "\t";
		cout << endl;
	}
	cout << "后宫佳丽总人数："<<count<< "\n";
	cout << "**********************************\n" << endl;
}
