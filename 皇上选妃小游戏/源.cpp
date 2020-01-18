//#define _CRT_SECURE_NO_WARNINGS
////#include <iostream>
////#include <vector>
////#include <iomanip>
////#include <cstdio>
////#include<algorithm>//包含算法的头文件
////using namespace std;
//////后宫翻牌
/////*游戏规则：皇上每天只能有一次操作，
////
////1->选妃  2->宠幸
////3->打入冷宫 4->查找爱妃
////选妃和宠幸其他妃嫔的好感度会-10，被宠幸的+10，被选的为初始值100
////被打入冷宫的爱妃被删除，其他妃嫔好感度+10->查找不变
////如果在10天之内有三个以及以上的妃嫔的好感值<60,则后宫暴乱
////*/
////typedef struct fanpai
////{
////    int mysize = 0;
////    int capacity = 5;
////    string arr_name[5][2] = { {"马文洁","贵人"},{"文文","嫔妃"},{"小马","贵妃"},{"阿洁","皇贵妃"},{"小洁洁","皇后"} };
////    string arr_dengji[5]{ "1","2", "3", "4", "5" };
////    int zhi[5] = { 100,100,100,100,100 };
////}pfanpai;
////
////
////string dengji[5] = { "贵人","嫔妃","贵妃","皇贵妃","皇后" };
////
////void fun(pfanpai* fanpai)
////{
////    fanpai->arr_name[0][0] = "肖邦";
////    fanpai->arr_name[0][1] = "皇贵妃";
////    fanpai->arr_dengji[0] = "皇后";
////}
////void print(pfanpai fanpai)
////{
////    cout << fanpai.arr_name[0][0] << "\t";
////    cout << fanpai.arr_name[0][1] << "\t";
////    cout << fanpai.arr_dengji[0] << "\t"<<endl;
////}
////int main()
////{
////    pfanpai fanpai;
////    for (int i = 0; i < fanpai.capacity; i++)
////    {
////        cout << fanpai.arr_name[i][0] << "\t";
////        cout << fanpai.arr_name[i][1] << "\t";
////        cout << fanpai.arr_dengji[i] << "\t";
////        cout << fanpai.zhi[i] << "\t" << endl;
////    }
////    cout << fanpai.capacity << "\t";
////    cout << fanpai.mysize << "\t" << endl;
////
////    fanpai.arr_name[0][0] = "肖战";
////    fanpai.arr_name[0][1] = "贵妃";
////    fanpai.arr_dengji[0] = "贵人";
////    cout << fanpai.arr_name[0][0] << "\t";
////    cout << fanpai.arr_name[0][1] << "\t";
////    cout << fanpai.arr_dengji[0] << "\t" << endl;
////    fun(&fanpai);
////    cout << fanpai.arr_name[0][0] << "\t";
////    cout << fanpai.arr_name[0][1] << "\t";
////    cout << fanpai.arr_dengji[0] << "\t"<<endl;
////    print(fanpai);
////    return 0;
////}
////void chushihua(pfanpai fanpai)
////{
////    fanpai->arr[0][0] = "肖战" ;
////    fanpai->arr[0][1] = "贵人" ;
////    fanpai->zhi[0] = 100;
////}
//////选妃
////void addfei(pfanpai fanpai)
////{
////
////    fanpai->mysize++;
////    if (fanpai->mysize == fanpai->capacity)
////    {
////        fanpai->capacity = fanpai->capacity * 2;
////    }
////    string name;
////    printf("要选的名讳:"); cin >> name;
////    fanpai->arr[0][0] = name;
////    cout << fanpai->arr[0][0]<< endl;
////    fanpai->arr[(fanpai->mysize) - 1][1] = dengji[0];
////    fanpai->zhi[(fanpai->mysize) - 1] = 100;
////    for (int i = 0; i < ((fanpai->mysize) - 1); i++)
////    {
////        fanpai->zhi[i] = fanpai->zhi[i] - 10;
////    }
////}
////
//////要宠幸的妃子，好感值+10，上升等级
////void chong(pfanpai fanpai)
////{
////    string name;
////    printf("陛下，今晚临幸哪位妃子呀：");
////    cin >> name;
////    for (int i = 0; i < fanpai->mysize; i++)
////    {
////        if (name.compare(fanpai->arr[i][0]) == 0)
////        {
////            fanpai->zhi[i] += 10;
////            for (int j = 0; j < 4; j++)
////            {
////                if (dengji[j].compare(fanpai->arr[i][1]) == 0)
////                {
////                    fanpai->arr[i][1] = dengji[j + 1];
////                    cout << "恭喜" << fanpai->arr[i][1] << "娘娘升为" << dengji[j + 1] << "其他娘娘好感度-10" << endl;
////
////                }
////            }
////
////
////        }
////        fanpai->zhi[i] -= 10;
////    }
////    printf("陛下，没有这位妃子，您是不是记错了\n");
////}
////void my_delete(int i, pfanpai fanpai)
////{
////    for (int j = i; j < fanpai->mysize - 1; j++)
////    {
////        fanpai->arr[j][0] = fanpai->arr[j + 1][0];
////        fanpai->arr[j][1] = fanpai->arr[j + 1][1];
////        fanpai->zhi[j] = fanpai->zhi[j + 1];
////    }
////    fanpai->mysize--;
////
////}
////void leng(pfanpai fanpai)
////{
////    string name;
////    printf("请输入要打入冷宫的妃子：");
////    cin >> name;
////    int i = 0;
////    for (; i < fanpai->mysize; i++)
////    {
////        if (name.compare(fanpai->arr[i][0]) == 0)
////        {
////            my_delete(i, fanpai);
////
////        }
////        printf("人情冷暖，所有娘娘好感度+10\n");
////        fanpai->zhi[i] += 10;
////    }
////    if (i == fanpai->mysize)
////    {
////        printf("虚惊一场，查无此人\n");
////    }
////
////}
//////删除妃子信息
////
////void cha(pfanpai fanpai)
////{
////    string name;
////    cout << "您要哪位爱妃:";
////    cin >> name;
////
////    for (int i = 0; i < fanpai->mysize; i++)
////    {
////        if ((name.compare(fanpai->arr[i][0]) == 0))
////        {
////            cout << name << "的好感度+10" << endl;
////            fanpai->zhi[i] += 10;
////            return;
////        }
////
////
////    }
////    printf("陛下，没有这位爱妃\n");
////
////
////}
////int sactury(pfanpai fanpai)
////{
////    int count = 0;
////    for (int i = 0; i < fanpai->mysize; i++)
////    {
////        if (fanpai->zhi[i] < 60)
////        {
////            count++;
////        }
////    }
////    if (count >= 3)
////        return 0;
////    else
////        return 1;
////
////}
////
////void print(pfanpai fanpai)
////{
////    // denji(fanpai);
////    printf("姓名     等级      好感度\n");
////    printf("----------------------\n");
////    for (int i = 0; i < fanpai->mysize; i++)
////    {
////        for (int j = 0; j < 2; j++)
////        {
////            cout << fanpai->arr[i][j] << "  ";
////        }
////        printf("%d\n", fanpai->zhi[i]);
////
////    }
////    printf("\n");
////}
////int main()
////{
////    pfanpai fanpai = (pfanpai)malloc(sizeof(pfanpai));
////    fanpai->capacity = 5;
////    fanpai->mysize = 0;
////    fanpai->arr[0][0] = "肖战";
////    fanpai->arr[0][1] = "贵人";
////    fanpai->zhi[0] = 100;
////    //chushihua(fanpai);
////    print(fanpai);
////    int day = 1; int choose = 0;
////    while (day <= 10)
////    {
////        //sactury();//判断后宫是否暴乱
////        cout << "第" << day << "天" << endl;
////        printf("1-> 皇帝下旨选妃    (增加)\n");
////        printf("2-> 翻牌宠幸        (修改状态)\n");
////        printf("3-> 打入冷宫        (删除)\n");
////        printf("4-> 朕的爱妃哪去了  (查找)\n");
////        printf("请陛下选择：");
////        scanf("%d", &choose);
////        if (choose == 1)
////        {
////            cout << "惊风玉露一相逢，便胜却人间无数\n";
////            addfei(fanpai);
////            print(fanpai);
////        }
////        else if (choose == 2)
////        {
////            cout << "云想衣裳花想容，春风拂槛露华浓\n";
////            chong(fanpai);
////            print(fanpai);
////        }
////        else if (choose == 3)
////        {
////            cout << "只见新人笑，哪闻旧人哭 \n";
////            leng(fanpai);
////            print(fanpai);
////        }
////        else if (choose == 4)
////        {
////            cha(fanpai);
////            print(fanpai);
////        }
////        else
////        {
////            cout << "还请陛下重新选择\n";
////        }
////
////        if (sactury(fanpai) == 0)
////        {
////            cout << "皇帝执政" << day << "天，卒死" << endl;
////            break;
////        }
////        day++;
////    }
////    if (day == 11)
////    {
////        cout << "陛下英明\n";
////    }
////
////}
//
//
//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <cstdio>
//#include<algorithm>//包含算法的头文件
//using namespace std;
////后宫翻牌
///*游戏规则：皇上每天只能有一次操作，
//
//1.选妃  2.宠幸
//3.打入冷宫 4.查找爱妃
//选妃和宠幸其他妃嫔的好感度会-10，被宠幸的+10，被选的为初始值100
//被打入冷宫的爱妃被删除，其他妃嫔好感度+10.查找不变
//如果在10天之内有三个以及以上的妃嫔的好感值<60,则后宫暴乱
//*/
//typedef struct fanpai
//{
//    int mysize;
//    int capacity;
//    string arr[5][2];
//    int zhi[5];
//}pfanpai;
//string dengji[5] = { "贵人","嫔妃","贵妃","皇贵妃","皇后" };
//
////选妃
//
//void addfei(pfanpai* fanpai)
//{
//
//    fanpai->mysize++;
//    if (fanpai->mysize == fanpai->capacity)
//    {
//        fanpai->capacity = fanpai->capacity * 2;
//    }
//    string name;
//    printf("要选的名讳:"); cin >> name;
//    fanpai->arr[(fanpai->mysize) - 1][0] = name;
//    fanpai->arr[(fanpai->mysize) - 1][1] = "贵人";
//    fanpai->zhi[(fanpai->mysize) - 1] = 100;
//    for (int i = 0; i < ((fanpai->mysize) - 1); i++)
//    {
//        fanpai->zhi[i] = fanpai->zhi[i] - 10;
//    }
//}
//
////要宠幸的妃子，好感值+10，上升等级
//void chong(pfanpai* fanpai)
//{
//    string name;
//    printf("陛下，今晚临幸哪位妃子呀：");
//    cin >> name;
//    int i = 0;
//    for (; i < fanpai->mysize; i++)
//    {
//        if (name.compare(fanpai->arr[i][0]) == 0)
//        {
//            fanpai->zhi[i] += 10;
//            for (int j = 0; j < 4; j++)
//            {
//                if (dengji[j].compare(fanpai->arr[i][1]) == 0)
//                {
//                    fanpai->arr[i][1] = dengji[j + 1];
//                    cout << "恭喜" << fanpai->arr[i][0] << "娘娘升为" << fanpai->arr[i][1] << "其他娘娘好感度-10" << endl;
//                }
//            }
//        }
//        else fanpai->zhi[i] -= 10;
//    }
//    if (i > fanpai->mysize)
//        printf("陛下，没有这位妃子，您是不是记错了\n");
//}
//void my_delete(int i, pfanpai* fanpai)
//{
//    for (int j = i; j < fanpai->mysize - 1; j++)
//    {
//        fanpai->arr[j][0] = fanpai->arr[j + 1][0];
//        fanpai->arr[j][1] = fanpai->arr[j + 1][1];
//        fanpai->zhi[j] = fanpai->zhi[j + 1];
//    }
//    fanpai->mysize--;
//
//}
//void leng(pfanpai* fanpai)
//{
//    string name;
//    printf("请输入要打入冷宫的妃子：");
//    cin >> name;
//    int i = 0;
//    for (; i < fanpai->mysize; i++)
//    {
//        if (name.compare(fanpai->arr[i][0]) == 0)
//        {
//            printf("人情冷暖，所有娘娘好感度+10\n");
//            my_delete(i, fanpai);
//
//        }
//
//        fanpai->zhi[i] += 10;
//    }
//    if (i == fanpai->mysize)
//    {
//        printf("虚惊一场，查无此人\n");
//    }
//
//}
////删除妃子信息
//
//void cha(pfanpai* fanpai)
//{
//    string name;
//    cout << "您要哪位爱妃:";
//    cin >> name;
//
//    for (int i = 0; i < fanpai->mysize; i++)
//    {
//        if ((name.compare(fanpai->arr[i][0]) == 0))
//        {
//            cout << name << "的好感度+10" << endl;
//            fanpai->zhi[i] += 10;
//            return;
//        }
//
//
//    }
//    printf("陛下，没有这位爱妃\n");
//
//
//}
//int sactury(pfanpai fanpai)
//{
//    int count = 0;
//    for (int i = 0; i < fanpai.mysize; i++)
//    {
//        if (fanpai.zhi[i] < 60)
//        {
//            count++;
//        }
//    }
//    if (count >= 3)
//        return 0;
//    else
//        return 1;
//
//}
//
//void print(pfanpai fanpai)
//{
//    //  denji(fanpai);
//    printf("姓名     等级      好感度\n");
//    printf("----------------------\n");
//    for (int i = 0; i < fanpai.mysize; i++)
//    {
//        for (int j = 0; j < 2; j++)
//        {
//            cout << fanpai.arr[i][j] << "    ";
//        }
//        printf("%d\n", fanpai.zhi[i]);
//
//    }
//    printf("\n");
//}
//int main()
//
//{
//    pfanpai fanpai;
//    fanpai.capacity = 5;
//    fanpai.mysize = 2;
//    fanpai.arr[0][0] = "肖战";
//    fanpai.arr[0][1] = "贵妃";
//    fanpai.zhi[0] = 100;
//    fanpai.arr[1][0] = "王一博";
//    fanpai.arr[1][1] = "贵妃";
//    fanpai.zhi[1] = 100;
//    int day = 1; int choose = 0;
//    while (day <= 10)
//    {
//        //sactury();//判断后宫是否暴乱
//        cout << "第" << day << "天" << endl;
//        printf("1.  皇帝下旨选妃    (增加)\n");
//        printf("2.  翻牌宠幸        (修改状态)\n");
//        printf("3.  打入冷宫        (删除)\n");
//        printf("4.  朕的爱妃哪去了  (查找)\n");
//        printf("5.  打印 (查找)\n");
//        printf("请陛下选择：");
//        scanf("%d", &choose);
//        if (choose == 1)
//        {
//            cout << "惊风玉露一相逢，便胜却人间无数\n";
//            addfei(&fanpai);
//            print(fanpai);
//        }
//        else if (choose == 2)
//        {
//            cout << "云想衣裳花想容，春风拂槛露华浓\n";
//            chong(&fanpai);
//            print(fanpai);
//        }
//        else if (choose == 3)
//        {
//            cout << "只见新人笑，哪闻旧人哭 \n";
//            leng(&fanpai);
//            print(fanpai);
//        }
//        else if (choose == 4)
//        {
//            cha(&fanpai);
//            print(fanpai);
//        }
//        else if (choose == 5)
//        {
//            print(fanpai);
//        }
//        else
//        {
//            cout << "还请陛下重新选择\n";
//        }
//
//
//        if (sactury(fanpai) == 0)
//        {
//            cout << "皇帝执政" << day << "天，卒死" << endl;
//            break;
//        }
//        else
//            day++;
//    }
//    if (day == 11)
//    {
//        cout << "陛下英明\n";
//    }
//
//
//}
