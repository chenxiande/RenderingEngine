#ifndef _SINGLETON_H_
#define _SINGLETON_H_


template <class T> class Singleton
{
protected:
	Singleton(){}
	~Singleton() {}

public:
	static T& getSingleton()
	{
		  static T m_Singleton;
		  return m_Singleton;
	}
};




#endif //_SINGLETON_H_