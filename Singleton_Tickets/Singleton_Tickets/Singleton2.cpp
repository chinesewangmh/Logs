#include "TICKET.h"
#include <mutex>

class InfoSingleton
{
public:
	//********����ָ��ⷨ*********
	static InfoSingleton& GetInstance()
	{
		//˫������������̰߳�ȫ�����Ч��
		if (_Psins == nullptr)//new�����Ժ󣬱���ÿ�ζ������ļ�飬�������
		{
			//t1 t2�����߳�
			std::lock_guard<mutex> lock(_smtx);
			if (_Psins == nullptr)//��֤�̰߳�ȫ��ֻnewһ��
			{
				_Psins = new InfoSingleton;
			}

		}
		return *_Psins;
	}


	//һ�㵥��������Ҫ�����ͷ�
	// ����������ʱ�������ֶ�����һЩ��Դ��Ҫ����
	// �����ֶ�������������,Ҳ���������Լ��ڳ������ʱ���Զ�����
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

	// Ҳ���������Լ��ڳ������ʱ���Զ�����
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
	//int c = 0;���ԣ�����
	Tickets _tickets;
private:
	InfoSingleton()
	{}
	InfoSingleton(const InfoSingleton& info) = delete;
	InfoSingleton& operator=(const InfoSingleton& info) = delete;
private:
	//����һ���ڲ�˽�еľ�̬�ĳ�Ա���������Է��ʹ��캯��
	static InfoSingleton* volatile _Psins;
	static mutex _smtx;
	static GC _gc;
};
////����
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