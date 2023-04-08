//#include "TICKET.h"
//
//	class InfoSingleton
//	{
//	public:
//		Tickets _tickets;
//
//		static InfoSingleton& GetInstance()
//		{
//			return _sins;
//		}
//
//
//	private:
//		InfoSingleton()
//		{}
//		InfoSingleton(const InfoSingleton& info) = delete;//禁止拷贝构造
//		InfoSingleton& operator=(const InfoSingleton& info) = delete;//禁止赋值拷贝
//	private:
//		//声明一个内部私有的静态的成员变量，可以访问构造函数
//		static InfoSingleton _sins;
//	};
//	//定义，初始化操作
//	InfoSingleton InfoSingleton::_sins;
//
//	void Test1()
//	{
//
//		InfoSingleton::GetInstance()._tickets.take(1);
//		InfoSingleton::GetInstance()._tickets.take(1);
//		cout << InfoSingleton::GetInstance()._tickets.Getsum() << endl;
//		InfoSingleton::GetInstance()._tickets.take(1);
//		InfoSingleton::GetInstance()._tickets.take(1);
//		InfoSingleton::GetInstance()._tickets.take(1);
//		cout << InfoSingleton::GetInstance()._tickets.Getsum() << endl;
//
//		InfoSingleton& info1 = InfoSingleton::GetInstance();
//		info1._tickets.take(3);
//		cout << info1._tickets.Getsum() << endl;
//
//		info1._tickets.take(3);
//		cout << info1._tickets.Getsum() << endl;
//
//	}
