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
//		InfoSingleton(const InfoSingleton& info) = delete;//��ֹ��������
//		InfoSingleton& operator=(const InfoSingleton& info) = delete;//��ֹ��ֵ����
//	private:
//		//����һ���ڲ�˽�еľ�̬�ĳ�Ա���������Է��ʹ��캯��
//		static InfoSingleton _sins;
//	};
//	//���壬��ʼ������
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
