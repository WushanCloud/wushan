//#define _CRT_SECURE_NO_WARNINGS
////#include <iostream>
////#include <vector>
////#include <iomanip>
////#include <cstdio>
////#include<algorithm>//�����㷨��ͷ�ļ�
////using namespace std;
//////�󹬷���
/////*��Ϸ���򣺻���ÿ��ֻ����һ�β�����
////
////1->ѡ��  2->����
////3->�����乬 4->���Ұ���
////ѡ���ͳ����������ɵĺøжȻ�-10�������ҵ�+10����ѡ��Ϊ��ʼֵ100
////�������乬�İ�����ɾ�����������ɺøж�+10->���Ҳ���
////�����10��֮���������Լ����ϵ����ɵĺø�ֵ<60,��󹬱���
////*/
////typedef struct fanpai
////{
////    int mysize = 0;
////    int capacity = 5;
////    string arr_name[5][2] = { {"���Ľ�","����"},{"����","����"},{"С��","����"},{"����","�ʹ���"},{"С���","�ʺ�"} };
////    string arr_dengji[5]{ "1","2", "3", "4", "5" };
////    int zhi[5] = { 100,100,100,100,100 };
////}pfanpai;
////
////
////string dengji[5] = { "����","����","����","�ʹ���","�ʺ�" };
////
////void fun(pfanpai* fanpai)
////{
////    fanpai->arr_name[0][0] = "Ф��";
////    fanpai->arr_name[0][1] = "�ʹ���";
////    fanpai->arr_dengji[0] = "�ʺ�";
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
////    fanpai.arr_name[0][0] = "Фս";
////    fanpai.arr_name[0][1] = "����";
////    fanpai.arr_dengji[0] = "����";
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
////    fanpai->arr[0][0] = "Фս" ;
////    fanpai->arr[0][1] = "����" ;
////    fanpai->zhi[0] = 100;
////}
//////ѡ��
////void addfei(pfanpai fanpai)
////{
////
////    fanpai->mysize++;
////    if (fanpai->mysize == fanpai->capacity)
////    {
////        fanpai->capacity = fanpai->capacity * 2;
////    }
////    string name;
////    printf("Ҫѡ������:"); cin >> name;
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
//////Ҫ���ҵ����ӣ��ø�ֵ+10�������ȼ�
////void chong(pfanpai fanpai)
////{
////    string name;
////    printf("���£�����������λ����ѽ��");
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
////                    cout << "��ϲ" << fanpai->arr[i][1] << "������Ϊ" << dengji[j + 1] << "��������øж�-10" << endl;
////
////                }
////            }
////
////
////        }
////        fanpai->zhi[i] -= 10;
////    }
////    printf("���£�û����λ���ӣ����ǲ��ǼǴ���\n");
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
////    printf("������Ҫ�����乬�����ӣ�");
////    cin >> name;
////    int i = 0;
////    for (; i < fanpai->mysize; i++)
////    {
////        if (name.compare(fanpai->arr[i][0]) == 0)
////        {
////            my_delete(i, fanpai);
////
////        }
////        printf("������ů����������øж�+10\n");
////        fanpai->zhi[i] += 10;
////    }
////    if (i == fanpai->mysize)
////    {
////        printf("�龪һ�������޴���\n");
////    }
////
////}
//////ɾ��������Ϣ
////
////void cha(pfanpai fanpai)
////{
////    string name;
////    cout << "��Ҫ��λ����:";
////    cin >> name;
////
////    for (int i = 0; i < fanpai->mysize; i++)
////    {
////        if ((name.compare(fanpai->arr[i][0]) == 0))
////        {
////            cout << name << "�ĺøж�+10" << endl;
////            fanpai->zhi[i] += 10;
////            return;
////        }
////
////
////    }
////    printf("���£�û����λ����\n");
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
////    printf("����     �ȼ�      �øж�\n");
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
////    fanpai->arr[0][0] = "Фս";
////    fanpai->arr[0][1] = "����";
////    fanpai->zhi[0] = 100;
////    //chushihua(fanpai);
////    print(fanpai);
////    int day = 1; int choose = 0;
////    while (day <= 10)
////    {
////        //sactury();//�жϺ��Ƿ���
////        cout << "��" << day << "��" << endl;
////        printf("1-> �ʵ���ּѡ��    (����)\n");
////        printf("2-> ���Ƴ���        (�޸�״̬)\n");
////        printf("3-> �����乬        (ɾ��)\n");
////        printf("4-> �޵İ�����ȥ��  (����)\n");
////        printf("�����ѡ��");
////        scanf("%d", &choose);
////        if (choose == 1)
////        {
////            cout << "������¶һ��꣬��ʤȴ�˼�����\n";
////            addfei(fanpai);
////            print(fanpai);
////        }
////        else if (choose == 2)
////        {
////            cout << "�������ѻ����ݣ��������¶��Ũ\n";
////            chong(fanpai);
////            print(fanpai);
////        }
////        else if (choose == 3)
////        {
////            cout << "ֻ������Ц�����ž��˿� \n";
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
////            cout << "�����������ѡ��\n";
////        }
////
////        if (sactury(fanpai) == 0)
////        {
////            cout << "�ʵ�ִ��" << day << "�죬����" << endl;
////            break;
////        }
////        day++;
////    }
////    if (day == 11)
////    {
////        cout << "����Ӣ��\n";
////    }
////
////}
//
//
//#include <iostream>
//#include <vector>
//#include <iomanip>
//#include <cstdio>
//#include<algorithm>//�����㷨��ͷ�ļ�
//using namespace std;
////�󹬷���
///*��Ϸ���򣺻���ÿ��ֻ����һ�β�����
//
//1.ѡ��  2.����
//3.�����乬 4.���Ұ���
//ѡ���ͳ����������ɵĺøжȻ�-10�������ҵ�+10����ѡ��Ϊ��ʼֵ100
//�������乬�İ�����ɾ�����������ɺøж�+10.���Ҳ���
//�����10��֮���������Լ����ϵ����ɵĺø�ֵ<60,��󹬱���
//*/
//typedef struct fanpai
//{
//    int mysize;
//    int capacity;
//    string arr[5][2];
//    int zhi[5];
//}pfanpai;
//string dengji[5] = { "����","����","����","�ʹ���","�ʺ�" };
//
////ѡ��
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
//    printf("Ҫѡ������:"); cin >> name;
//    fanpai->arr[(fanpai->mysize) - 1][0] = name;
//    fanpai->arr[(fanpai->mysize) - 1][1] = "����";
//    fanpai->zhi[(fanpai->mysize) - 1] = 100;
//    for (int i = 0; i < ((fanpai->mysize) - 1); i++)
//    {
//        fanpai->zhi[i] = fanpai->zhi[i] - 10;
//    }
//}
//
////Ҫ���ҵ����ӣ��ø�ֵ+10�������ȼ�
//void chong(pfanpai* fanpai)
//{
//    string name;
//    printf("���£�����������λ����ѽ��");
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
//                    cout << "��ϲ" << fanpai->arr[i][0] << "������Ϊ" << fanpai->arr[i][1] << "��������øж�-10" << endl;
//                }
//            }
//        }
//        else fanpai->zhi[i] -= 10;
//    }
//    if (i > fanpai->mysize)
//        printf("���£�û����λ���ӣ����ǲ��ǼǴ���\n");
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
//    printf("������Ҫ�����乬�����ӣ�");
//    cin >> name;
//    int i = 0;
//    for (; i < fanpai->mysize; i++)
//    {
//        if (name.compare(fanpai->arr[i][0]) == 0)
//        {
//            printf("������ů����������øж�+10\n");
//            my_delete(i, fanpai);
//
//        }
//
//        fanpai->zhi[i] += 10;
//    }
//    if (i == fanpai->mysize)
//    {
//        printf("�龪һ�������޴���\n");
//    }
//
//}
////ɾ��������Ϣ
//
//void cha(pfanpai* fanpai)
//{
//    string name;
//    cout << "��Ҫ��λ����:";
//    cin >> name;
//
//    for (int i = 0; i < fanpai->mysize; i++)
//    {
//        if ((name.compare(fanpai->arr[i][0]) == 0))
//        {
//            cout << name << "�ĺøж�+10" << endl;
//            fanpai->zhi[i] += 10;
//            return;
//        }
//
//
//    }
//    printf("���£�û����λ����\n");
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
//    printf("����     �ȼ�      �øж�\n");
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
//    fanpai.arr[0][0] = "Фս";
//    fanpai.arr[0][1] = "����";
//    fanpai.zhi[0] = 100;
//    fanpai.arr[1][0] = "��һ��";
//    fanpai.arr[1][1] = "����";
//    fanpai.zhi[1] = 100;
//    int day = 1; int choose = 0;
//    while (day <= 10)
//    {
//        //sactury();//�жϺ��Ƿ���
//        cout << "��" << day << "��" << endl;
//        printf("1.  �ʵ���ּѡ��    (����)\n");
//        printf("2.  ���Ƴ���        (�޸�״̬)\n");
//        printf("3.  �����乬        (ɾ��)\n");
//        printf("4.  �޵İ�����ȥ��  (����)\n");
//        printf("5.  ��ӡ (����)\n");
//        printf("�����ѡ��");
//        scanf("%d", &choose);
//        if (choose == 1)
//        {
//            cout << "������¶һ��꣬��ʤȴ�˼�����\n";
//            addfei(&fanpai);
//            print(fanpai);
//        }
//        else if (choose == 2)
//        {
//            cout << "�������ѻ����ݣ��������¶��Ũ\n";
//            chong(&fanpai);
//            print(fanpai);
//        }
//        else if (choose == 3)
//        {
//            cout << "ֻ������Ц�����ž��˿� \n";
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
//            cout << "�����������ѡ��\n";
//        }
//
//
//        if (sactury(fanpai) == 0)
//        {
//            cout << "�ʵ�ִ��" << day << "�죬����" << endl;
//            break;
//        }
//        else
//            day++;
//    }
//    if (day == 11)
//    {
//        cout << "����Ӣ��\n";
//    }
//
//
//}
