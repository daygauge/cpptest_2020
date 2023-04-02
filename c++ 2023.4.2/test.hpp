#define _CRT_SECURE_NO_WARNINGS 1

class my_string
{
	friend ostream& operator<< (ostream& couts, const my_string& str);
private:
	char* str;
	int kj;
public:

	my_string()//创建一个空的字符串
	{
		str = NULL;
		kj = 0;
	}
	my_string(const char* a)//使用字符串初始化
	{
		int i = 0;
		while (a[i] != '\0')
		{
			i++;
		}
		this->kj = i;
		this->str = new char[i];
		for (int j = 0; j < i; j++)
		{
			str[j] = a[j];
		}
	}
	my_string(const my_string &a)//使用my_string初始化my_string，拷贝构造
	{
		if (a.str != NULL)
		{
			this->kj = a.kj;
			this->str = new char[a.kj];
			for (int i = 0; i < a.kj; i++)
			{
				this->str[i] = a.str[i];
			}
		}
		else
		{
			str = NULL;
			kj = 0;
		}
	}
	void operator=(const char* a)//重载= char*字符串赋值字符串
	{
		if (a != NULL)
		{
			delete[] str;
			int i = 0;
			while (a[i] != '\0')
			{
				i++;
			}
			this->kj = i;
			this->str = new char[i];
		}
	}
	void operator=(const char a)//重载= char字符赋值新字符
	{
		if (a != NULL)
		{
			delete[] str;
			this->kj = 1;
			this->str = new char[1];
			this->str[0] = a;
		}
	}
	void operator+=(const char* a)//重载+= char*字符串操作符
	{
		int i = 0;
		int j = 0;
		char* s = new char[this->kj + i];
		if (this->kj != 0)//拷贝自身到s
		{
			for (j = 0; j < this->kj; j++)
			{
				s[j] = this->str[j];
			}
		}
		while (a[i] != '\0')//尾部添加字符串
		{
			s[j + i] = a[i];
			i++;
		}
		//释放原内存并更改指针指向
		delete[] this->str;
		this->str = s;
		this->kj += i;
	}
	void operator+=(const char a)//重载+= char字符操作符
	{
		int j = 0;
		char* s = new char[this->kj + 1];
		if (this->kj != 0)//拷贝自身到s
		{
			for (j = 0; j < this->kj; j++)
			{
				s[j] = this->str[j];
			}
		}
		s[j] = a;
		//释放原内存并更改指针指向
		delete[] this->str;
		this->str = s;
		this->kj++;
	}
	my_string& operator+=(const my_string &a)//重载+= my_string字符操作符
	{
		int i = 0;
		char* s = new char[this->kj + a.kj];
		for (i = 0; i < this->kj; i++)//拷贝自身到s
		{
			s[i] = this->str[i];
		}
		for (int j = 0; j < a.kj; j++)//尾插新数据进s
		{
			s[i++] = a.str[j];
		}
		//释放原内存并更改指针指向
		delete[] this->str;
		this->str = s;
		this->kj += a.kj;
		return *this;//返回自身
	}

	my_string& append(const my_string& s, int pos, int n)//尾插s从第pos字符往后n个的数据
	{
		if ((s.kj-(pos-1)) < n)//判断n是否大于pos后s数组总个数
		{
			n = (s.kj - pos);
		}

		char* ts = new char[this->kj + n];
		int cs = this->kj;
		int i = n;
		if (this->kj != 0)//拷贝自身到ts
		{
			for (int j = 0; j < this->kj; j++)
			{
				ts[j] = this->str[j];
			}
		}
		while (n--)//插入固定数据
		{
			ts[cs++] = s.str[pos++];
		}
		//释放原内存并更改指针指向
		delete[] this->str;
		this->str = ts;
		this->kj += i;
		return *this;;//返回自身
	}
};
ostream& operator<< (ostream& couts, const my_string& str)
{
	for (int i = 0; i < str.kj; i++)
	{
		couts << str.str[i];
	}
	return couts;
}