##定位 new 表达式 ##
    定位 new 表达式是在已分配的原始内存空间中调用构造函数初始化一个对象
    使用格式：
	new(空间指针) 对象(参数列表)
    使用场景：
	定位 new 表达式在实际中一般是配合内存池使用。因为内存池中分配出的内存没有初始化，如果对象是自定义类型，需要使用定位 new 表达式显示调用对象构造
	函数进行初始化

##设计一个类，该类只能在堆上创建对象 ##
    1.将类的构造函数私有化，拷贝构造申明成私有，防止调用拷贝构造函数在栈上生成对象
    2.提供一个静态成员函数，在该静态成员函数中完成堆上对象的创建
	class HeapOnly{
	private:
		//构造函数
		HeapOnly() {}

		//C++98：1.声明成私有  2.只声明，不实现，因为不需要
		HeapOnly(const HeapOnly &);
		//C++11：delete关键字
		HeapOnly(const HeapOnly &) = delete;
	public:
		static HeapOnly* CreateObject() {
			return new HeapOnly;
		}
	};

##设计一个类，该类只能在栈上创建对象 ##
    只能在栈上创建对象，即不能在堆上创建对象，因此只要将 new 的功能屏蔽掉即可，即屏蔽掉 operator new 和 定位 new 表达式
	class StackOnly{
	private:
		void* operator new(size_t size);
		void operator delete(void *p);
	public:
		StackOnly() {}

		static StackOnly CreateObject() {
			return StackOnly();
		}
	};

##单例模式 ##
    设计模式：
	设计模式一套被反复使用的、多数人知晓的、经过分类的、代码设计经验的总结
	目的：为了代码可重用性、让代码更容易被他人理解、保证代码可靠性。设计模式使代码编写真正工程化
    单例模式：
	一个类只能创建一个对象，即单例模式。该模式可以保证系统中该类只有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。比如在某个
	服务器程序中，该服务器的配置信息存放在一个文件中，这些配置数据由一个单例对象统一管理，然后服务进程中的其他对象再通过这个单例对象获取这些配置
	信息，这种方式简化了在复杂环境下的配置管理
    
    单例模式有两种实现方式：
	1.饿汉模式
	  就是说不管你将来用不用，程序启动的时候就创建一个唯一的实例对象。如果这个单例对象在多线程高并发环境下频繁使用，性能要求较高，那么显然使用饿汉
	  模式来避免资源竞争，提高响应速度更好

	  优点：简单
	  缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定
		class Singleton{
		private:
			Singleton(){
				cout << "Singleton()" << endl;
			}

			//C++98 防拷贝
			//Singleton(const Singleton&);
			//Singleton& operator=(const Singleton);
	
			//C++11 delete
			Singleton(const Singleton&) = delete;
			Singleton& operator=(const Singleton) = delete;

			static Singleton m_instance;
		public:
			static Singleton* GetInstance(){
				return &m_instance;
			}
		};
		Singleton Singleton::m_instance;  //在程序入口之前就完成单例对象的初始化

	2.懒汉模式
	  如果单例对象构造十分耗时或者占用很多资源，比如加载插件啊，初始化网络连接啊，读取文件啊等等，而有可能程序运行时不会用到，那么也要在程序一开始
          就进行初始化，就会导致程序启动时非常的缓慢。所以这种情况使用懒汉模式（延迟加载）更好

	  优点：第一次使用实例对象时创建对象。进程启动无负载。多个单例实例启动顺序自由控制
	  缺点：复杂
    		class Singleton{
		private:
		public:
		};
