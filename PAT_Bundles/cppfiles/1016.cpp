#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct record {
  string name;
  int month, day;
  long int time;
  bool status;
};
struct call {
  record* start;
  record* end;
  long int time;
  double fee;
};
struct person {
  string name;
  vector<call*> calls;
  vector<record*> records;
  double total_cost;
};
bool cmp(record *a, record *b) {  //排序算法比较函数，升序
  //姓名排序，按字母顺序
  if(strcmp(a->name.c_str(), b->name.c_str()) != 0)  //名字不同
    return strcmp(a->name.c_str(), b->name.c_str()) < 0;  //按字母顺序
  if(a->day != b->day)   //日期排序，升序
    return a->day < b->day;
  return a->time < b->time;  //时间排序，升序
}
void resetList(vector<record*> &v) {  //整理一个客户的通话记录信息
  vector<record*> v2;
  int start = 0;
  int end = (int)v.size() - 1;
  while (start <= (int)v.size() - 1 && !v[start]->status)  //
    start++;  //下线状态数目
  while (end >= 0 && v[end]->status)
    end--;    //去除上线状态，保留下线记录数目
  if(start < end) {
    for(int i = start; i <= end; i++) {
      if((i != end && v[i]->status == v[i + 1]->status && v[i]->status == true) || (i != start && v[i - 1]->status == v[i]->status && v[i]->status == false))
        continue;
      else
        v2.push_back(v[i]);
    }
  }
  v = v2;
}
double getPrice(double* pay, double* hour_pay, double day_pay, record* start, record* end) {
  double total = 0;
  int start_day = start->day;
  int end_day = end->day;
  long int start_time = start->time;
  long int end_time = end->time;
  total += day_pay * (end_day - start_day);
  if(start_time < end_time) {
    for(int i = (int)(start_time/60); i < end_time/60; i++)
      total += hour_pay[i];
    total -= pay[start_time/60] * (start_time%60);
    total += pay[end_time/60] * (end_time%60);
  }
  return total;
}
int main() {
  double pay[24], hour_pay[24];  //pay表示不同时间段内的电话费计费大小
  for(int i = 0; i < 24; i++) {
    double pay_temp;
    scanf("%lf", &pay_temp);
    pay[i] = pay_temp/100;
  }
  double day_pay;
  for(int i = 0; i < 24; i++) {
    hour_pay[i] = pay[i] * 60;  //hour_pay表示一天中每一小时的电话费
    day_pay += hour_pay[i];     //day_pay表示一天的电话费
  }
  int recordNum;
  scanf("%d", &recordNum);
  vector<record*> list_main;   //存储客户的通话记录信息，利用status存放上下线信息，这是一条完整的记录
  //存储通话记录数据
  for(int i = 0; i < recordNum; i++) {
    string name, status;
    int month, day, hour, minute;
    cin >> name;
    scanf("%d:%d:%d:%d", &month, &day, &hour, &minute);
    cin >> status;
    record* r = new record();
    r->name = name;
    r->status = (status == "on-line");  //true表示上线，false表示下线
    r->month = month;
    r->day = day;
    r->time = hour * 60 + minute;
    list_main.push_back(r);
  }
  sort(list_main.begin(), list_main.end(), cmp);   //进行通话记录信息数据排序，顺序为名字、日期，时间
  vector<person*> persons;  //每个人的通话记录信息
  string tempString;
  for(int i = 0; i < list_main.size(); i++) {
    //记录客户名字，放入persons
    if(tempString != list_main[i]->name) {
      person* p = new person();
      p->name = list_main[i]->name;
      persons.push_back(p);
      tempString = p->name;
    }
    persons.back()->records.push_back(list_main[i]);  //写入客户的通话记录信息
  }
  for(int i = 0; i < persons.size(); i++) {
    resetList(persons[i]->records);
    persons[i]->total_cost = 0;
    for(int j = 0; j < persons[i]->records.size(); j = j + 2) {
      call* c = new call();
      c->start = persons[i]->records[j];
      c->end = persons[i]->records[j+1];
      c->time = (c->end->day - c->start->day) * 24 * 60 + c->end->time - c->start->time;
      c->fee = getPrice(pay, hour_pay, day_pay, c->start, c->end);
      persons[i]->total_cost += c->fee;
      persons[i]->calls.push_back(c);
    }
  }
  for(int i = 0; i < persons.size(); i++) {
    if(persons[i]->total_cost > 0) {
      printf("%s %02d\n", persons[i]->name.c_str(), persons[i]->records[0]->month);
      for(int j = 0; j < persons[i]->calls.size(); j++) {
        if(persons[i]->calls[j]->time <= 0)
          continue;
        printf("%02d:%02d:%02d %02d:%02d:%02d %ld $%.2f\n", persons[i]->calls[j]->start->day, (int)(persons[i]->calls[j]->start->time/60),  (int)(persons[i]->calls[j]->start->time%60), (int)(persons[i]->calls[j]->end->day), (int)(persons[i]->calls[j]->end->time/60), (int)(persons[i]->calls[j]->end->time%60), persons[i]->calls[j]->time, persons[i]->calls[j]->fee);
      }
      printf("Total amount: $%.2f\n", persons[i]->total_cost);
    }
  }
  return 0;
}
