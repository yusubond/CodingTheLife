## 位运算

### 1. 二进制中1的位数

题目：

```
解法一：高效解法
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n) {
             n = (n - 1) & n;
             count++;
         }
         return count;
     }
};
解法二：普通解法
class Solution {
public:
    int NumberOf1(int n) {
      unsigned int mask = 1;
      int count = 0;
      while(mask) {
        if(mask & n)
          count++;
        mask <<= 1;
      }
    }
}
```
