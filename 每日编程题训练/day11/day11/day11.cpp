#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;
//Ѱ������������±�
int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpf(n), dpg(n);

    //dpf(i)��[0,i-1]����֮��
    //dpg(i):[i+1,n-1]����֮��
    for (int i = 1; i < n; ++i)//ǰ׺��
    {
        dpf[i] = dpf[i - 1] + nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i)//��׺��
    {
        dpg[i] = dpg[i + 1] + nums[i + 1];
    }

    //ʹ������
    for (int i = 0; i < n; ++i)
    {
        if (dpf[i] == dpg[i])
            return i;
    }
    return -1;
}

//��������������ĳ˻�

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int R = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        res[i] *= R;
        R *= nums[i];
    }
    return res;
}

//������
//vector<int> productExceptSelf(vector<int>& nums) {
//    int n = nums.size();
//
//    vector<int> dpf(n, 1);//ǰ׺��
//    vector<int> dpg(n, 1);//��׺��
//
//    //dpf(i):[0,i-1]�˻�
//    //dpg(i):[i+1,n-1]
//    for (int i = 1; i < n; ++i)
//    {
//        dpf[i] = dpf[i - 1] * nums[i - 1];
//    }
//    for (int i = n - 2; i >= 0; --i)
//    {
//        dpg[i] = dpg[i + 1] * nums[i + 1];
//    }
//
//    //ʹ��ǰ׺������
//    //
//    vector<int> res(n);
//    for (int i = 0; i < n; ++i)
//    {
//        res[i] = dpf[i] * dpg[i];
//    }
//    return res;
//}

int subarraySum(vector<int>& nums, int k) {
    //ǰ׺�ͣ����ִ���
    unordered_map<int, int> hash;
    hash[0] = 1;//���⴦��0��i��ǡ��ΪK����Ҫ��[0,-1]��0���ֵĴ���

    //sum:ǰ׺��
    int sum = 0, res = 0;

    for (auto n : nums)
    {
        sum += n;
        //�ڱ�����ʱ��iλ�ñ�ʾ����ϣ��ÿ�δ�ŵ���[0,i-1]��ǰ׺��
        //������[0,i-1]��sum-k���ֵĴ�������ǰ׺��Ϊsum-k
        if (hash.count(sum - k)) res += hash[sum - k];
        hash[sum]++;
    }

    return res;
}

int subarraysDivByK(vector<int>& nums, int k) {
    //��������ĳһ��λ��ʱ���Ե�ǰλ��ǰ׺��ȡ�࣬
    //Ȼ���ǰ���ǰ׺�������������У����Ƿ���ֵ�ǰ��������ǰ��������
    //ǰ׺�͵�����Ϊ�����ֵĴ���
    unordered_map<int, int> hash;
    hash[0 % k] = 1;

    int sum = 0, res = 0;
    for (auto e : nums)
    {
        sum += e;
        // ע�� C++ ȡģ�������ԣ���������Ϊ����ʱȡģ���Ϊ��������Ҫ���� 
        int mod = (sum % k + k) % k;
        if (hash.count(mod) )res += hash[mod];
        hash[mod]++;
    }

    return res;
}

class A
{
public:
    A() { cout << "a"; }
    virtual ~A() { cout << "~a"; }
};
class B
{
public:
    B() { cout << "b"; }
    virtual ~B() { cout << "~b"; }
};

class C :public  B,public A
{
public:
    C(){ cout << "c"; }
    ~C(){ cout << "~c"; }
    //A a;
};

//int main()
//{
//    /*int a = (-3 % 5+5)%5;
//    cout << a;*/
//   // C c; //bac ~c~a~b
//    //uint8_t* p1 = reinterpret_cast<uint8_t*>(0x801000);
//    //uint32_t* p2 = reinterpret_cast<uint32_t*>(0x801000);
//    //cout << p1 + 5 << "   " <<p2 + 5 << endl;
//
//    /*uint8_t* p1 = reinterpret_cast<uint8_t*>(0x801000);
//    uint32_t* p2 = reinterpret_cast<uint32_t*>(0x802000);
//    cout << reinterpret_cast<uintptr_t>(p1 + 5) << "   " << reinterpret_cast<uintptr_t>(p2) + 5 << endl;*/
//    
//    //uint8_t* p1 = reinterpret_cast<uint8_t*>(0x801000);
//    //cout << p1 << endl;
//    uint32_t* p2 = reinterpret_cast<uint32_t*>(0x802000);
//    cout << p2 << endl;
//    cout << p2+5 << endl;
//
//    //cout << p1 + 5 << "   " << p2 + 5 << endl;
//    int a = 10;
//    int* pa = &a;
//    cout << pa << endl;
//
//    int* new_pa = pa + 5;
//    cout << new_pa << endl;
//
//    return 0;
//}



int main()
{
    char arr[] = "dasda";
    char arr2[10] = "dasda";
    cout << sizeof(arr2)<<endl;
    char arr3[3] = {'0','1','2'};
    cout << sizeof(arr3) << endl;

    //char arr4[2] = { '0','1','2' };//����ʱ����
    
    cout<<strcmp(arr,arr2);

    
}
