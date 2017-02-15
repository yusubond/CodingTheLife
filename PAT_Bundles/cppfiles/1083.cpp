#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct node {
  string name;
  string id;
  int grade;
};
bool cmp(node a, node b) {
  return a.grade > b.grade;
}
int main() {
  int n, grade, grade1, grade2;
  string id;
  string name;
  scanf("%d", &n);
  node student[n];
  for(int i = 0; i < n; i ++) {
    cin >> name;
    cin >> id;
    scanf("%d", &grade);
    //scanf("%s %s %d", &name, &id, &grade);
    student[i].name = name;
    student[i].id = id;
    student[i].grade = grade;
  }
  scanf("%d %d", &grade1, &grade2);
  sort(student, student + n, cmp);
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(student[i].grade >= grade1 && student[i].grade <= grade2) {
      // printf("%s %s", student[i].name, student[i].id);
      cnt++;
    }
  }
  if(cnt == 0)
    printf("NONE");
  else {
    for(int i = 0; i < n; i++) {
      if(student[i].grade >= grade1 && student[i].grade <= grade2) {
        cnt--;
        if(cnt == 0) {
          cout << student[i].name << " " << student[i].id;
          //printf("%s %s", student[i].name, student[i].id);
        }
        else {
          cout << student[i].name << " " << student[i].id << endl;
          //printf("%s %s\n", student[i].name, student[i].id);
        }
      }
    }
  }
  return 0;
}
