void bar() {
	int c;
	}

	void foo(){
	int b=3;
	bar();
}

int main(){
	int a=3;
	foo();
	bar();
	
	return 0;
}


int foo(int a, int b, bool c)
{
double d =a*b*2.71;
int h=c?d:d/2;
return h;
}

int main()
{
	int x=1;
	int y=2;
	x=foo(x,y,false);
	cout<<x;
	return 0;
}

int foo(){
	cout<<"hello"<<endl;
	return 2;
}

int bar(){
	int *m[1];
	m[3]=(int*)&foo;
	return 1;
}

int main(){
	bar();
	return 0;
}


unsigned gcd(unsigned a, unsigned b)
{
    if(b>a) {return gcd(b,a);}
    else if (b==0){return a;}
    else  {return gcd(b,a%b);}
}

void rec(){
    int a;
    cin>>a;
    if (a==0)
        return;
    rec();
    cout<<a<<" ";
}

void swap(int* a, int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(){
	int k=10, m=20;
	swap(&k,&m);
	return 0;
}

int m[10] = {};

for( int *p=m; p<m+9; ++p)
	*p=(p-m)+1;


int max_element (int *m, int size){
	int max=*m;
	for(int i=1; i<size; i++)
	{
		if(m[i]>max)
			max=m[i];
	}
	return max;
}

void rotate(int a[], unsigned size, int shift)
{
    int tmp=0;
    for(int j=0; j<shift; j++)
    {
        
        for(int i=0; i<size-1; i++)
        {
           tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
        }
    }
}

bool contains (int *m, int size, int value)
{
	for(int i=0; i<size; i++)
	{
		if(m[i]==value)
			return true;
	}
	return false;
}

//MAX ELEMENT SEARCH
int max_elem(int *p, int *q)
{
	int max=*p;
	for(;p!=q;++p)
	{
		if(*p>max)
			max=*p;
	}
	return max;
}


//MAX ELEMENT SEARCH WITH POINTER
int *max_elem(int *p, int *q)
{
	int *max = *p;
	for(;p!=q;p++)
	{
		if(*p>*max)
			max=p;
	}
	return max;;
}

//MAX ELEMENT WITH POINTER RETURN
bool max_elem(int *p, int *q, int *max)
{
	if(p==q)
		return false;
	*max=*p;
	for(; p!=q; p++)
	{
		if(*p>*max)
			max=p;
	}
	return true;
}

int m[10] = {};
int max1=0;
max_elem(m, m+10, &max1);

//STRLEN FUNC
unsigned strlen(const char *str)
{
   int len=0;
    for(;; str++)
    {
        
        if(*str=='\0')
            break;
        len++;
    }
    return len;
}

//STRCAT FUNC
void strcat(char *to, const char *from)
{
    for(; ; to++)
    {
        if(*to=='\0')
            break;
    }
    for(; ; from++ )
    {
        if(*from=='\0')
            break;
        *to=*from;
        *to++;
    }
    *to='\0';
}

//SEARCH PATTERN IN STRING
int strstr(const char *text, const char *pattern)
{
    int count =0;
    bool a = false;
    if(*pattern == '\0')
        return 0;
    for(; *text!='\0' ; text++, count++)
    {
        if(*text==*pattern)
            for(int i=0;pattern[i]!='\0'; i++)
            {
                if(text[i]==pattern[i])
                    a=true;
                else 
                    a=false;
            }
        if(a==true)
            return count;
    }
    
    return -1;
}

//SORT MASSIVE


//REALOCATE MEMORY FOR ARRAY
char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * new_str = new char [new_size];
    for(int i=0; i<size && i<new_size; i++)
    {
        new_str[i]=str[i];
    }
    delete [] str;
    return new_str;
}

//CREATE ARRAY
int **create_array(size_t a, size_t b)
{
	int **array = new int *[a];
	for(int i=0; i<a; i++)
		array[i]=new int [b];
	return array;
}

//DELETE ARRAY
void free_array(int **array, size_t a, size_t b)
{
	for(int i=0; i<a; i++)
		delete [] array[i];
	delete [] array;
}

//EFFECTIVE CREATE ARRAY
int **create_array(size_t a, size_t b)
{
	int **array = new int *[a];
	array[0] = new int [a*b];
	for(int i=1; i<a; i++)
		array[i]=array[i-1]+b;
	return array;
}

 //TRANSPOSE MATRIX
 int ** transpose(const int * const * m, int rows, int cols)
{
     int **array = new int *[cols];
	for(int i=0; i<cols; i++)
		array[i]=new int [rows];
    
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            array[j][i]=m[i][j];
        }
    }

    return array;
}

//STRUCT SEGMENT
struct Point{
	double x;
	double y;
};

struct Segment{
	Point p1;
Point p2
};

double length(Segment s){
		double dx=s.p1.x-s.p2.x;
		double dy=s.p1.y-s.p2.y;
		return sqrt(dx*dx-dy*dy);
}

double length(Segment *s)
{
	double dx=s->p1.x-s->p2.x;
	double dy=s->p1.y-s->p2.y;
	return sqrt(dx*dx+dy*dy);
}

Point p1 = {0.4, 1.4};
Point p2 = {1.2, 6.3};
Segment s = {p1, p2};

//STRUCT SEGMENT 1.0
struct Segment
{
	Point p1;
	Point p2;
	double length()
	{
		double dx = p1.x-p2.x;
		double dy = p1.y-p2.y;
		return sqrt(dx*dx+dy*dy);
	}
};

int main()
{
	Segment s = {{1.0, 2.0}, {1.2, 1.4}};
	cout<<s.length()<<endl;
	return 0;
}

	
