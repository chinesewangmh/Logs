#include "TICKET.h"
#include <mutex>

class InfoSingleton
{
public:
	//********智能指针解法*********
	static InfoSingleton& GetInstance()
	{
		//双检查加锁：解除线程安全，提高效率
		if (_Psins == nullptr)//new对象以后，避免每次都加锁的检查，提高性能
		{
			//t1 t2两个线程
			std::lock_guard<mutex> lock(_smtx);
			if (_Psins == nullptr)//保证线程安全且只new一次
			{
				_Psins = new InfoSingleton;
			}

		}
		return *_Psins;
	}


	//一般单例对象不需要考虑释放
	// 单例对象不用时，必须手动处理，一些资源需要保存
	// 可以手动调用主动回收,也可以让他自己在程序结束时，自动回收
	static void DelInstance()
	{
		std::lock_guard<mutex> lock(_smtx);
		if (_Psins)
		{
			//cout << "static void DelInstance()" << endl;
			delete _Psins;
			_Psins = nullptr;
		}
	}

	// 也可以让他自己在程序结束时，自动回收
	class GC
	{
	public:
		~GC()
		{
			if (_Psins)
			{
				//cout << "~GC()" << endl;
				DelInstance();
			}
		}
	};
public:
	//int c = 0;测试，无用
	Tickets _tickets;
private:
	InfoSingleton()
	{}
	InfoSingleton(const InfoSingleton& info) = delete;
	InfoSingleton& operator=(const InfoSingleton& info) = delete;
private:
	//声明一个内部私有的静态的成员变量，可以访问构造函数
	static InfoSingleton* volatile _Psins;
	static mutex _smtx;
	static GC _gc;
};
////定义
InfoSingleton* volatile InfoSingleton::_Psins = nullptr;
mutex InfoSingleton::_smtx;
InfoSingleton::GC  InfoSingleton::_gc;

void ThreadTest()
{
	mutex mtx;
	InfoSingleton& info = InfoSingleton::GetInstance();

	lock_guard<mutex> lock(mtx);
	cout << this_thread::get_id() <<"->" << &info<< "->" << &info._tickets << endl;
	info._tickets.take(2);
	cout << info._tickets.Getsum() << endl;
	info._tickets.take(3);
	cout << info._tickets.Getsum() << endl;
	
}



int main()
{
	thread t1(ThreadTest);
	thread t2(ThreadTest);
	t1.join();
	t2.join();
	return 0;
}