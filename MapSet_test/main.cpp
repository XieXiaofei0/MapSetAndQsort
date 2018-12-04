#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
using namespace std;

bool compareDescend(const int &a,const int &b) {
    return a > b;
}
int compareByDisDescend(const void *a, const void *b) {   //����߳����ս�������
    pair<int, int> *p1 = (pair<int, int>*)a;
    pair<int, int> *p2 = (pair<int, int>*)b;
    return p2->second - p1->second;
}

int main() {
    //map:���򲻿��ظ���map�Ǹ��ݹؼ������������ҹؼ��ֲ����ظ�
    map<int,int> testmap;                 
    testmap[1] = 2;
    testmap[0] = 5;
    testmap[2] = 1;
    testmap.insert(pair<int, int>(-1, 2));
    testmap.insert(pair<int, int>(-1, 7));
    map<int, int>::iterator iter;
    for (iter = testmap.begin(); iter != testmap.end(); iter++)
         cout << iter->first << "   " << iter->second << endl;
    for (const auto &m : testmap)
        cout << m.first << "  " << m.second << endl;
    cout << endl << endl;
    //map end

    //multimap:������ظ���map���ݹؼ����������С�
    multimap<int, int> testmap2;
    testmap2.insert(pair<int, int>(1, 2));
    testmap2.insert(pair<int, int>(0, 5));
    testmap2.insert(pair<int, int>(2, 1));
    testmap2.insert(pair<int, int>(-1, 10));
    testmap2.insert(pair<int, int>(-1, 7));
    for (const auto &m : testmap2)
        cout << m.first << "  " << m.second << endl;
    cout << endl << endl;
    //multimap end

    //unordered_map:���򲻿��ظ���map���ؼ��ֲ����ظ������ղ���˳��
    unordered_map<int, int> testmap3;
    testmap3.insert(pair<int, int>(1, 2));
    testmap3.insert(pair<int, int>(0, 5));
    testmap3.insert(pair<int, int>(2, 1));
    testmap3.insert(pair<int, int>(-1, 10));
    testmap3.insert(pair<int, int>(-1, 7));
    for (const auto &m : testmap3)
        cout << m.first << "  " << m.second << endl;
    cout << endl << endl;
    //unordered_map end

    //unordered_set
    unordered_set<int> testset;
    testset.insert(2);
    testset.insert(5);
    if (testset.insert(0).second)cout << "true" << endl;
    if (!testset.insert(5).second)cout << "false" << endl;
    for (const auto &m : testset)
        cout << m << endl;
    cout << endl << endl;
    //unordered_set end

    //�ı�map�еĹؼ����������У���Ϊmap�ؼ��ֽ�������
    map<int, int, decltype(compareDescend)*> testmap5(compareDescend);
    testmap5[7] = 8;
    testmap5[4] = 10;
    testmap5[9] = 0;
    testmap5[15] = 8;
    testmap5[7] = 11;
    for (const auto &m : testmap5)
        cout << m.first << "  " << m.second << endl;
    cout << endl << endl;
    //Descend_map end

    //test:���ź�����map��ʱ�临�Ӷ��Ǹ���
    double start_time;
    double end_time;
    double elapsed_time;
    multimap<int, int> map2;
    start_time = clock();
    for (int i = 0; i < 10000; i++) {
        int a = rand() % 10000000;
        map2.insert(pair<int,int>(a,i));
    }
    end_time = clock();
    elapsed_time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "multimap:" << elapsed_time << endl << endl;
    //for (const auto &m : map2)
    //    cout << m.first << "  " << m.second << endl;
    cout << endl << endl;

    vector<pair<int, int>> test;
    start_time = clock();
    for (int i = 0; i < 10000; i++) {
        pair<int, int> pair(-1,-1);
        test.push_back(pair);
    }
    for (int i = 0; i < 10000; i++) {
        test[i].first = i;
        test[i].second = rand() % 10000000;
    }
    qsort(&(test.data()[0]), 10000, sizeof(pair<int, int>), compareByDisDescend);
    end_time = clock();
    elapsed_time = (double(end_time - start_time)) / CLOCKS_PER_SEC;
    cout << "multimap:" << elapsed_time << endl << endl;
    //for (const auto &m : test)
    //    cout << m.first << "  " << m.second << endl;
    cout << endl << endl;
    //test end
    return 0;
}