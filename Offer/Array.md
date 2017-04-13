## 数组

### 1. 二维数组中的查找

题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

题解：

```c++
class Solution {
public:
  bool Find(int target, vector<vector<int> > array) {
    int rows = array.size();
    int cols = array[0].size();
    int x = rows - 1;
    int y = 0;
    while ( x >= 0 && y < cols ) {
       if (array[x][y] == target) return true;
       if (array[x][y] < target) y++;
       if (array[x][y] > target) x--;
    }
    return false;
    }
};
```

### 2. 旋转数组的最小数字

题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        for(int i = 0; i < rotateArray.size( ); i++)
        {
            if(rotateArray[i] > rotateArray[i + 1])
            {
                return rotateArray[i + 1];
            }
        }
        return 0;
    }
};
```

### 3. 斐波那契数列

题目：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39

```c++
class Solution {
public:
    int Fibonacci(int n) {
        int num[40];
        num[0] = 0;
        num[1] = 1;
        for(int i  = 2; i <= n; i++)
            num[i] = num[i - 1] + num[i - 2];
		return num[n];
    }
};
```

### 4. 数值的整数次方

题目：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

```
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)
            return 1.0;
        double result, base_temp;
        int i = 0;
        if(exponent > 0) {
        	result = base;
            base_temp = base;
        	i = exponent;
        } else {
            result = 1 / base;
            base_temp = 1 / base;
            i = exponent * (-1);

        }
        while(i > 1) {
           		result *= base_temp;
            	i--;
        	}
    	return result;
    }
};
```

### 5. 调整数组顺序使奇数位于偶数前面

题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

```
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res1, res2;
        for(vector<int>::iterator it = array.begin(); it != array.end(); it++) {
            if(*it % 2 == 1)
                res1.push_back(*it);
            else
                res2.push_back(*it);
        }
        for(int i = 0; i < res1.size(); i++)
            array[i] = res1[i];
        for(int i = 0; i < res2.size(); i++)
            array[i + res1.size()] = res2[i];

    }
};
```

### 6. 跳台阶

题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

题解：**推理题**。每增加1个，出现多少种新情况，依次推理即可。

```
class Solution {
public:
    int jumpFloor(int number) {
        int num[number + 1];
        num[0] = 0;
        num[1] = 1;
        num[2] = 2;
        for(int i = 3; i <= number; i++)
            num[i] = num[i - 1] + num[i - 2];
        return num[number];

    }
};
```

### 7. 变态跳台阶

题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

```
class Solution {
public:
    int jumpFloorII(int number) {
        int num[number + 1];
        num[0] = 0;
        num[1] = 1;
        num[2] = 2;
        for(int i = 3; i <= number; i++) {
            int j = i - 1, temp = 0;
            while(j >= 1) {
                temp += num[j];
                j--;
            }
            num[i] = temp + 1;
        }
        return num[number];

    }
};
```

### 8. 矩形覆盖

题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

题解：n = 1, f(1) = 1; n = 2; f(2) = 2; 当n >= 3时，最后一块只有一种情况，因此有f(n - 1)中情况，当最后两块“绑定”在一起时，有f(n-2)种情况。因此，f(n) = f(n - 1) + f(n - 2)。

```
class Solution {
public:
    int rectCover(int number) {
		int num[number + 1];
        num[0] = 0;
        num[1] = 1;
        num[2] = 2;
        for(int i = 3; i <= number; i++) {
            num[i] = num[i - 1] + num[i - 2];
        }
        return num[number];
    }
};
```

### 9. 构建乘积数组

题目：给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

```
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> B(A.size());
        for(int i = 0; i < A.size(); i++) {
            int j = 0;
            int temp = 1;
            while(j < A.size()) {
                if(j == i)
                    j++;
                else {
                	temp *= A[j];
                    j++;
                }
            }
            B[i] = temp;
        }
        return B;
    }
};
```
