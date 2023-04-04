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
	~my_string()
	{
		delete[] this->str;
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

	int my_find(const my_string* str, int pos = 0)
	{
		char* n1 = this->str, * n2 = n1;
		char* m1 = str->str, * m2 = m1;
		int a = pos;
		int b = 0;
		if(pos < this->kj)
		while (a < this->kj)
		{
			if (n1[a] == m1[b])
			{
				int i = a;
				int j = 0;
				while (j < str->kj && i < this->kj)
				{
					if (n2[i] == m2[j])
					{
						i++;
						j++;
					}
					else
					{
						break;
					}
				}
				if (j == str->kj||i == this->kj)
				{
					return 0;
				}
				else
				{
					n2 = n1;
					m2 = m1;
				}
			}
			a++;
		}
		return -1;
	}

	int my_comare(const my_string& a)//字符串比较
	{
		int i = 0;
		int as = 0;
		int ac = 0;
		while (i < this->kj||i < a.kj)//比较ASCll值
		{
			if(i<this->kj)
			as += this->str[i];
			if(i<a.kj)
			ac += a.str[i];
			i++;
		}
		return as - ac;
	}

	char& operator[](int n)//获取n下标的字符
	{
		return this->str[n];
	}

	my_string& my_insert(int pos, const char* s)//在pos位置插入s字符串
	{
		int i = 0;
		while (s[i]!='\0')//获取s字符串大小
		{
			i++;
		}
		if (i == 0 || pos > this->kj)
		{
			return *this;
		}

		char* a = new char[this->kj + i];
		int n1 = 0;//计入当前写到的位置

		int as = 0;//计入str当前写到的位置
		while (n1 < pos)//写入pos前内容
		{
			a[n1++] = this->str[as++];
		}

		int k = 0;//模拟s字符串的下标位置
		while (k < i)////写入pos中内容
		{
			a[n1++] = s[k++];
		}

		while (n1 < (this->kj+i))//写入剩下内容
		{
			a[n1++] = this->str[as++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj + i;
		return *this;
	}
	my_string& my_insert(int pos, const my_string& s)//在pos位置插入s类str
	{
		int i = s.kj;//获取s字符串大小

		if (i == 0 || pos > this->kj)
		{
			return *this;
		}

		char* a = new char[this->kj + i];
		int n1 = 0;//计入当前写到的位置

		int as = 0;//计入str当前写到的位置
		while (n1 < pos)//写入pos前内容
		{
			a[n1++] = this->str[as++];
		}

		int k = 0;//模拟s字符串的下标位置
		while (k < i)////写入pos中内容
		{
			a[n1++] = s.str[k++];
		}

		while (n1 < (this->kj + i))//写入剩下内容
		{
			a[n1++] = this->str[as++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj + i;
		return *this;
	}
	my_string& my_insert(int pos, int n, char c)
	{
		char* a = new char[this->kj + n];

		int n1 = 0;//计入当前写到的位置
		int as = 0;//计入str当前写到的位置
		while (n1 < pos)//写入pos前内容
		{
			a[n1++] = this->str[as++];
		}
		int ns = n;
		while (n--)
		{
			a[n1++] = c;
		}

		while (n1 < (this->kj + ns))//写入剩下内容
		{
			a[n1++] = this->str[as++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj + ns;
		return *this;
	}
	my_string& my_erase(int pos, int n = 0) //删除从Pos开始的n个字符
	{
		char* a = new char[this->kj - n];
		int cs = this->kj - n;
		int poscs = 0;

		for (int i = 0; i < cs; i++)
		{
			if (i == pos)
			{
				poscs += n;
			}
			a[i] = this->str[poscs++];
		}
		delete[] this->str;
		this->str = a;
		this->kj = this->kj -n;
		return *this;
	}
	my_string my_substr(int pos = 0, int n = 1)//返回由pos开始的n个字符组成的字符串
	{
		char* a = new char[n - pos+1];
		int i = pos;
		int j = 0;
		while (i < n)
		{
			a[j++] = this->str[i++];
		}
		a[j] = '\0';
		my_string cs(a);
		delete[] a;
		return cs;
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