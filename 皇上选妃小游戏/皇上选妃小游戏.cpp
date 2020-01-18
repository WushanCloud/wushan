// 皇上选妃小游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "皇上选妃小游戏.h"


int main()
{
	string wushan_emperor_name;
	string wushan_emperor_time;
	int count = 0;//目前妃子总个数 
    cout << "请输入皇帝的名讳："<<endl;
	cin >> wushan_emperor_name;
	cout << "请输入皇帝年号：" << endl;
	cin >> wushan_emperor_time;
	//开始游戏
	cout << wushan_emperor_time << "元年" << wushan_emperor_name << "登基称帝" << endl;
	//后宫初始化
	emperor_harem_initialize(&count);
	system("cls");
	//emperor_harem[0].wushan_concubine_class = "淑仪";
	while (true)
	{
		PlaySound(TEXT("D:\\Git\\wushan\\皇上选妃小游戏\\gamemusic\\背景音乐.wav"),
			NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		int select = 0;
		cout << wushan_emperor_time;
			data_read();
			cout << wushan_emperor_name << "登基第" << dates[3] << "天"<<endl;
		menu();
		cout << "请陛下选择今天的行程：";
		cin >> select;
		if(select >= 1 || select <= 5)
		switch (select)
		{
		case 1://陛下钦点选妃
			data_count();
			increaseConcubine(&count);
			break;
		case 2://陛下宠幸妃子
			data_count();
			modificationConcubine();
			break;
		case 3://将妃子打入冷宫
			data_count();
			deleteConcubine();
			break;
		case 4://陛下选择妃子谈心
			data_count();
			seekConcubine();
			break;
		case 5://输出后宫状态
			emperor_harem_print(count);
			break;
		default:
			break;
		}
		else
		{
			cout << "后宫处理乃皇家大事，请谨慎选择" << endl;
		}
		system("cls");
	}
    return 0;
}

bool emperor_harem_initialize(int *count)
{
	int& pos = *count;
	for (size_t i = 0; i < N && i < sizeof(concubine_name)/sizeof(concubine_name[0]); i++)
	{
		emperor_harem[i].wushan_concubine_name = concubine_name[i];
		emperor_harem[i].wushan_concubine_class = concubine_class[0];
		emperor_harem[i].wushan_concubine_favorability = 100;
		emperor_harem[i].wushan_concubine_active = true;
		pos++;
	}
	return true;
}

void data_count()//时间计数器
{
	dates[2]++;
	dates[3]++;
	int month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (dates[2] / month[dates[1]] == 1)
	{
		dates[2] = 1;
		dates[1]++;
		if (dates[1] / 12 == 1)
		{
			dates[1] = 1;
			dates[0]++;
		}
	}
}

void data_read()//读取游戏时间
{
	string year[] = { "0","元", "二", "三", "四", "五", "六", "七", "八", "九", "十" ,
		"十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十" };
	string month[] = { "0","元", "二", "三", "四", "五", "六", "七", "八", "九", "十" ,"十一","十二" };
	string day[] = { "0","一", "二", "三", "四", "五", "六", "七", "八", "九", "十" ,
		"十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十" ,
		"二十一","二十二", "二十三", "二十四", "二十五", "二十六", "二十七", "二十八", "二十九", "三十" ,"三十一" };
	cout << year[dates[0]] << "年" << month[dates[1]] << "月" << day[dates[2]] << "日" << endl;
}

void menu()
{
	cout << "******************************\n";
	cout << "1. 陛下钦点选妃\n";
	cout << "2. 陛下宠幸妃子\n";
	cout << "3. 将妃子打入冷宫\n";
	cout << "4. 陛下选择妃子谈心\n";
	cout << "5. 输出后宫状态\n";
	cout << "******************************" << endl;
}

bool increaseConcubine(int* count)
{
	PlaySound(TEXT("D:\\Git\\wushan\\皇上选妃小游戏\\gamemusic\\选妃.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	int& pos = *count;
	/*if (pos >= N)
	{
		cout << "后宫妃子已满，请陛下爱惜枕边人！" << endl;
	}*/
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
	PlaySound(TEXT("D:\\Git\\wushan\\皇上选妃小游戏\\gamemusic\\翻牌.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	string concubine_newname;
	cout << "请输入妃子姓名" << endl;
	cin >> concubine_newname;
	int pos = 0;//记录了被选者的位置
	int temp = 0;//记录是否找到
	for (int i = 0; i < N; i++)
	{
		if(emperor_harem[i].wushan_concubine_active == true)
		if (concubine_newname.compare(emperor_harem[i].wushan_concubine_name) == 0)
		{
			cout << "春宵一刻值千金！"<< endl;
			emperor_harem[i].wushan_concubine_favorability += 10;
			temp = 1;
			if (emperor_harem[i].wushan_concubine_class.compare(concubine_class[sizeof(concubine_class)/sizeof(concubine_class[0])-1]) == 0)
			{
				;
			}
			else for (size_t j = 0; j < sizeof(concubine_class)/sizeof(concubine_class[0]); j++)
			{
				if (emperor_harem[i].wushan_concubine_class.compare(concubine_class[j]) == 0)
				{
					emperor_harem[i].wushan_concubine_class = concubine_class[++j];
					break;
				}
			}
		}
	}
	if (temp == 0)
	{
		cout << "后宫中没有此妃子！" << endl;
		return false;
	}
	for (int i = 0; i < N ; i++)
	{
		if (emperor_harem[i].wushan_concubine_active == true && i != pos)
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
	}
	return true;
}

bool deleteConcubine()
{
	PlaySound(TEXT("D:\\Git\\wushan\\皇上选妃小游戏\\gamemusic\\冷宫.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	string concubine_delname;
	cout << "请输入妃子姓名" << endl;
	cin >> concubine_delname;
	for (int i = 0; i < N && emperor_harem[i].wushan_concubine_active == true; i++)
	{
		if (concubine_delname.compare(emperor_harem[i].wushan_concubine_name) == 0)
		{
			emperor_harem[i].wushan_concubine_active = false;
		}
	}
	return true;
}

bool seekConcubine()
{
	PlaySound(TEXT("D:\\Git\\wushan\\皇上选妃小游戏\\gamemusic\\一笑倾城.wav"),
		NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	string concubine_seekname;
	cout << "请输入妃子姓名" << endl;
	cin >> concubine_seekname;
	for (int i = 0; i < N && emperor_harem[i].wushan_concubine_active == true; i++)
	{
		if (concubine_seekname.compare(emperor_harem[i].wushan_concubine_name) == 0)
		{
			emperor_harem[i].wushan_concubine_favorability += 10;
		}
	}
	return true;
}

void emperor_harem_print(int count)
{
	cout << "******************************\n";
	cout << "姓名\t级别\t好感度" << endl;
	for (int i = 0; i < count ;  i++)
	{
		if (emperor_harem[i].wushan_concubine_active == true)
		{
			cout << emperor_harem[i].wushan_concubine_name << "\t";
			cout << emperor_harem[i].wushan_concubine_class << "\t";
			cout << emperor_harem[i].wushan_concubine_favorability << "\t";
			cout << emperor_harem[i].wushan_concubine_active << "\t";
			cout << endl;
		}
	}
	cout << "后宫佳丽总人数："<<count<< "\n";
	cout << "******************************\n" << endl;
	system("pause");
}
