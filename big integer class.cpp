#define ll long long
#define rep(i,a,b) for(ll i = a;i<b;i++)
#define repr(i,a,b) for(ll i = a;i>b;i--)
ll modpow(ll n,ll p,ll k)
{
    n = n%k;
    ll res = 1;
    while(p>0)
    {
        if(p%2 == 1)
        res = res*n%k;
        n = n*n%k;
        p = p/2;
    }
    return res;
}
class bigint
{
public:
    bigint()
    {
        str = "";
    }
    bigint(const string& x)
    {
        str = x;
    }
    bigint(const char* x)
    {
        str = x;
    }
    ll Length() const {
        return str.size();
    }
    void Push_back(char s)
    {
       if((s - '0'<0||s-'0'>9)&&s!='-')
            throw invalid_argument("Invalid argument");
        else
            str.push_back(s);
    }
    void Reverse()
    {
        reverse(begin(str),end(str));
    }
    void Clear()
    {
        str.clear();
    }
    char& operator [](ll i)
    {
        if(i>=str.size())
            throw invalid_argument("Invalid argument");
        return str[i];

    }
    void operator=(const char* x)
    {
        str = x;
    }
    void operator=(string x)
    {
        str = x;
    }
    ll bigint_to_int()//converts bigint to ll
    {
        reverse(begin(str),end(str));
        ll ind = str.size();
        repr(i,str.size()-1,-1)
        {
            if(str[i]!='0'&&str[i]!='-')
            {
                ind = i+1;
                break;
            }
        }
        ll ans = 0;
        for(ll i = 0;i<ind;i++)
        {
            ans+=((str[i] - '0')*(pow(10,i)));
        }
        if(str[str.size()-1] == '-')
            ans = -ans;
        return ans;
    }
    void Clip()
    {
        ll ind = -1;
        ll t = -1;
        if(str[0] == '-')
            t = 1;
        else
            t = 0;
        for(ll i = t;i<str.size();i++)
        {
            if(str[i]!='0')
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
            str = "0";
        else
        {
            string p = str;
            bool nag = false;
            if(str[0] == '-')
                nag = true;
            str.clear();
            if(nag)
                str.push_back('-');
            for(ll i = ind;i<p.size();i++)
                str.push_back(p[i]);
        }

    }
    void Abs()
    {
        string p;
       /* if(str.size() == 0)
        throw invalid_argument("Invalid argument");*/
         if(str[0] == '-')
        {
            for(ll i = 1;i<str.size();i++)
            {
                p.push_back(str[i]);
            }
            str = p;
        }
        else
        {
            for(ll i = 0;i<str.size();i++)
                p.push_back(str[i]);
            str = p;
        }

    }
    void Neg()
    {
        string p;
       /* if(str.size() == 0)
        throw invalid_argument("Invalid argument");*/
         if(str[0] == '-')
        {
            for(ll i = 1;i<str.size();i++)
            {
                p.push_back(str[i]);
            }
            str = p;
        }
        else if(str[0]!='-')
        {

            p.push_back('-');
            bool ind = false;
            for(ll i = 0;i<str.size();i++)
            {
                if(ind)
                p.push_back(str[i]);
                if(!ind&&str[i]!='0')
                {
                    ind = true;
                    p.push_back(str[i]);
                }
            }
            if(p.size()!=1)
            str = p;
            else
                str = "0";
        }
    }
    string str;
};
bigint operator - (bigint str1,bigint str2);
bigint operator + (bigint str1,bigint str2);
bigint operator * (bigint num1,bigint num2);
bigint operator / (bigint number,ll divisor);
void swap(bigint& x,bigint& y)
{
    bigint TEMP;
    for(ll i = 0;i<x.Length();i++)
    {
        TEMP.Push_back(x[i]);
    }
    x.Clear();
    for(ll i = 0;i<y.Length();i++)
    {
        x.Push_back(y[i]);
    }
    y.Clear();
    for(ll i =0;i<TEMP.Length();i++)
    {
        y.Push_back(TEMP[i]);
    }
    TEMP.Clear();

}
istream& operator >>(istream& stream,bigint& num)
{
    stream >>num.str;
    return stream;
}
ostream& operator <<(ostream& stream,bigint x)
{
    ll n = x.Length();
    for(int i = 0;i<n;i++)
        stream<<x[i];
        return stream;
}
bool operator < (bigint& str1,bigint& str2)
{
    str1.Clip();
    str2.Clip();
    ll n1 = str1.Length(), n2 = str2.Length();
    if(str1[0] == '-'&&str2[0]!='-')
        return true;
    if(str1[0] != '-'&&str2[0] == '-')
        return false;
    if(str1[0] == '-'&&str2[0] == '-')
    {
        str1.Abs();
        str2.Abs();
        return str2<str1;
    }
	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (str1[i] < str2[i])
		return true;
	else if (str1[i]> str2[i])
		return false;

	return false;
}
bool operator == (bigint& str1,bigint& str2)
{
    str1.Clip();
    str2.Clip();
    ll n1 = str1.Length();
    ll n2 = str2.Length();
    if (n1 < n2)
	return false;
	if (n2 < n1)
	return false;
	for (ll i=0; i<n1; i++)
	if (str1[i] != str2[i])
		return false;
    return true;

}
bool operator != (bigint& str1,bigint& str2)
{
    if(str1 == str2)
        return false;
    return true;
}
bool operator > (bigint& str1,bigint& str2)
{
    if(str1<str2)
        return false;
    if(str1 == str2)
        return false;
    return true;
}
bool operator <= (bigint& str1,bigint& str2)
{
    if(str1<str2||str1 == str2)
    {
        return true;
    }
    return false;
}
bool operator >= (bigint& str1,bigint& str2)
{
    if(str1>str2||str1 == str2)
        return true;
    return false;
}
bigint operator - (bigint str1,bigint str2)
{
    	// Before proceeding further, make sure str1
	// is not smaller
	bigint s1 = str1,s2 = str2;
	s1.Abs();
	s2.Abs();
	bool swapped = false;
	if (s1<s2)
    {
		swap(str1, str2);
		swapped = true;
    }
    bigint zero = "0";
    if(str1<zero&&str2<zero)
    {
        str1.Abs();
        str2.Abs();
        bigint str = str2 - str1;
        str.Clip();
        if(!swapped)
        {
            str.Neg();
            return str;
        }
        else
        {
            //str.Neg();
            return str;
        }
    }
    else if(str2<zero)
    {
        str2.Abs();
        bigint str = str1+str2;
        str.Clip();
        if(!swapped)
            return str;
        else
        {
            str.Neg();
            return str;
        }
    }
    else if(str1<zero)
    {
        str1.Abs();
        bigint str = str1+str2;
        if(!swapped)
        {
            str.Neg();
            return str;
        }
        else
        {
            return str;
        }
    }
	// Take an empty string for storing result
	 bigint str;

	// Calculate length of both string
	ll n1 = str1.Length(), n2 = str2.Length();

	// Reverse both of strings
	str1.Reverse();
	str2.Reverse();

	ll carry = 0;

	// Run loop till small string length
	// and subtract digit of str1 to str2
	for (ll i=0; i<n2; i++)
	{
		// Do school mathematics, compute difference of
		// current digits

		ll sub = ((str1[i]-'0')-(str2[i]-'0')-carry);

		// If subtraction is less then zero
		// we add then we add 10 into sub and
		// take carry as 1 for calculating next step
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.Push_back(sub + '0');
	}

	// subtract remaining digits of larger number
	for (ll i=n2; i<n1; i++)
	{
		ll sub = ((str1[i]-'0') - carry);

		// if the sub value is -ve, then make it positive
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.Push_back(sub + '0');
	}

	// reverse resultant string
	//str.Clip();
	str.Reverse();
    str.Clip();
    if(!swapped)
	return str;
	str.Neg();
	return str;
}
bigint operator + (bigint str1,bigint str2)
{
        // Before proceeding further, make sure length
    // of str2 is larger.
    bigint s1 = str1;
    bigint s2 = str2;
    s1.Abs();
    s2.Abs();
    if (s1.Length()>s2.Length())
    {
        swap(str1, str2);
    }
    bigint zero = "0";
    bigint str;
    if(str2<zero&&str1<zero)
    {
        str1.Abs();
        str2.Abs();
        str = str1+str2;
        str.Clip();
        str.Neg();
        return str;
    }
    if(str1<zero)
    {
        str1.Abs();
        str = str2 - str1;
        str.Clip();
        return str;
    }
    if(str2<zero)
    {
        str2.Abs();
        str = str1 - str2;
        str.Clip();
        return str;
    }
    // Calculate length of both string
    int n1 = str1.Length(), n2 = str2.Length();

    // Reverse both of strings
    str1.Reverse();
    str2.Reverse();

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.Push_back(sum%10 + '0');

        // Calculate carry for next step
        carry = sum/10;
    }

    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.Push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.Push_back(carry+'0');

    // reverse resultant string
    str.Reverse();
    str.Clip();
    return str;
}
bigint convert(ll n) //converts an long long to bigint.
{
    bigint res;
    ll m = n;
    n = abs(n);
    while(n>0)
    {
        ll rem = n%10;
        char c = rem+'0';
        res.Push_back(c);
        n/=10;
    }
    if(m<0)
    {
        res.Push_back('-');
    }
    res.Reverse();
    res.Clip();
    return res;
}
ll operator % (bigint b,ll c)
{
    bool neg = false;
    bigint zero = "0";
    if(b<zero)
    {
        neg = true;
        b.Abs();
    }
    ll k = b.Length();
    vector<ll> mod(k+1);
    mod[0] = 1;
    //vll mod(k+1)
    rep(i,1,k+1)
    {
        mod[i] = 10*mod[i-1];
        mod[i]%=c;
    }
    ll rem = 0;
    repr(i,k-1,-1)
    {
        ll num = b[i] - '0';
        num*=mod[k-1-i];
        num%=c;
        rem+=num;
        rem%=c;
    }
    if(!neg)
    return rem;
    else
    {
        rem = c-rem;
        return rem;
    }
}
bigint operator * (bigint num1,bigint num2) // O(n*m) multiplication naive one will change after karatsuba implementation.
{
    bigint zero;
        zero= "0";
    if(num1<zero&&num2<zero)
    {
        num1.Abs();
        num2.Abs();
        bigint ans = num1*num2;
        ans.Clip();
        return ans;
    }
    else if(num1<zero||num2<zero)
    {
        num1.Abs();
        num2.Abs();
        bigint ans = num1*num2;
        ans.Neg();
        ans.Clip();
        return ans;
    }
    int len1 = num1.Length();
    int len2 = num2.Length();
    if (len1 == 0 || len2 == 0)
    {
        return zero;
    }

    // will keep the result number in vector
    // in reverse order
    vector<ll> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return zero;

    // generate the result string
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);
    bigint b;
    b = s;
    b.Clip();
    return b;
}
bigint operator / (bigint number,ll divisor) //string divided by number.
{
    // As result can be very large store it in string
    bigint ans;
    bigint zero;
    zero = "0";
    if(number<zero&&divisor<0)
    {
        number.Abs();
        divisor = -divisor;
        ans = number/divisor;
        return ans;
    }
    else if(divisor == 0)
    {
        throw invalid_argument("Invalid argument");
        return zero;
    }
    else if(number<zero||divisor<0)
    {
        number.Abs();
        divisor = abs(divisor);
        ans = number/divisor;
        ans.Neg();
        return ans;
    }
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
    {
        if(idx!=number.Length()-1)
        temp = temp * 10 + (number[++idx] - '0');
        else
            break;
    }

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.Length() > idx) {
        // Store result in answer i.e. temp / divisor
        //ans += (temp / divisor) + '0';
        ll c = temp/divisor;
          ans.Push_back(c+'0');
        // Take next digit of number
        if(idx!=number.Length()-1)
        temp = (temp % divisor) * 10 + number[++idx] - '0';
        else
            break;
    }
    // If divisor is greater than number
    if (ans.Length() == 0)
        return zero;

    // else return ans
    return ans;
}
bigint power(bigint b,bigint n)
{
    bigint res;
    res = "1";
    bigint zero;
    zero = "0";
  //  b = convert(b%MODULO);
    while(n>zero)
    {
        if(n%2 == 1)
        {
            bigint temp;
            temp = res*b;
            res = temp;
         //   res = convert(res%MODULO);
        }
        bigint temp;
        temp = b*b;
        b = temp;
       // b = convert(b%MODULO);
        temp = n/2;
        n = temp;
    }
    res.Clip();
    return res;

}
bigint powmod(bigint b,bigint n,ll MODULO) // pow modulo integer returns bigint
{
ll tr = n.Length();
    ll rem;
    rem = b%MODULO;
    bigint res;
    res = convert(rem);
    ll time_pass = n[0] - '0';
    bigint tp;
    tp = convert(time_pass);
   // ll ans = modpow(rem,time_pass,MODULO);
   bigint ans;
   ans = power(res,tp);
   bigint temp;
   bigint ten;
   ten = convert(10);
   temp = convert(ans % MODULO);
    rep(i,1,tr)
    {
         tp = convert(n[i] - '0');
       // ans = modpow(ans,10,MODULO);
       temp = power(ans,ten);
       ans = temp;
        //ans*=modpow(rem,time_pass,MODULO);
        bigint temp1;
        temp1 = power(res,tp);
        temp1 = convert(temp1%MODULO);
        ans = ans*temp1;

        ans = convert(ans%MODULO);
    }
    ans.Clip();
    return ans;
}
ll powermod(bigint b,bigint n,ll MODULO) // pow modulo integer returns int
{
    ll tr = n.Length();
    ll rem;
    rem = b%MODULO;
    ll time_pass = n[0] - '0';
   // ll ans = modpow(rem,time_pass,MODULO);
  ll ans = 0;
   ans = modpow(rem,time_pass,MODULO);
    rep(i,1,tr)
    {
        ans = modpow(ans,10,MODULO);
        time_pass = n[i] - '0';
        ans = ans*modpow(rem,time_pass,MODULO);

        ans%=MODULO;
    }
    return ans;
}

bigint Min(bigint a,bigint b)
{
    if(a<=b)
        return a;
    return b;
}
bigint Max(bigint a,bigint b)
{
    if(a>=b)
        return a;
    return b;
}
bigint Binary_Form(bigint a) //converts a to binary
{
    bigint zero = "0";
   // bigint b = a;
   bigint ans;
    while(a>zero)
    {
        ll rem = a%2;
        ans.Push_back(rem + '0');
        bigint temp = a/2;
        a = temp;
    }
    ans.Reverse();
    return ans;
}
bigint bin_dec(bigint a) // converts a to decimal
{
    ll n = a.Length();
    bigint two = "2";
    bigint ans = "0";
    repr(i,n-1,-1)
    {
        bigint I = convert(i);
        bigint temp = power(two,I);
        bigint one = convert(a[n-1-i] - '0');
        temp = temp*one;
        ans = ans + temp;
    }
    return ans;
}
bigint operator & (bigint a,bigint b)
{
    bigint a1 = Binary_Form(a);
    bigint b1 = Binary_Form(b);
    if(a1<b1)
    {
        swap(a1,b1);
    }
    ll n1 = a1.Length();
    ll n2 = b1.Length();
    a1.Reverse();
    b1.Reverse();
    bigint ans;
    for(ll i = 0;i<n1;i++)
    {
        if(i<n2)
        {
            ll num1 = a1[i] - '0';
            ll num2 = b1[i] - '0';
            ll num = num1&num2;
            ans.Push_back(num+'0');
        }
        else
        {
            ans.Push_back('0');
        }
    }
    ans.Reverse();
    ans = bin_dec(ans);
    ans.Clip();
    return ans;
}
bigint operator | (bigint a,bigint b)
{
    bigint a1 = Binary_Form(a);
    bigint b1 = Binary_Form(b);
    if(a1<b1)
    {
        swap(a1,b1);
    }
    ll n1 = a1.Length();
    ll n2 = b1.Length();
    a1.Reverse();
    b1.Reverse();
    bigint ans;
    for(ll i = 0;i<n1;i++)
    {
        if(i<n2)
        {
            ll num1 = a1[i] - '0';
            ll num2 = b1[i] - '0';
            ll num = num1|num2;
            ans.Push_back(num+'0');
        }
        else
        {
            ans.Push_back(a1[i]);
        }
    }
    ans.Reverse();
    ans = bin_dec(ans);
    ans.Clip();
    return ans;
}
bigint operator ^ (bigint a,bigint b)
{
    bigint a1 = Binary_Form(a);
    bigint b1 = Binary_Form(b);
    if(a1<b1)
    {
        swap(a1,b1);
    }
    ll n1 = a1.Length();
    ll n2 = b1.Length();
    a1.Reverse();
    b1.Reverse();
    bigint ans;
    for(ll i = 0;i<n1;i++)
    {
        if(i<n2)
        {
            ll num1 = a1[i] - '0';
            ll num2 = b1[i] - '0';
            ll num = num1^num2;
            ans.Push_back(num+'0');
        }
        else
        {
            ans.Push_back(a1[i]);
        }
    }
    ans.Reverse();
    ans = bin_dec(ans);
    ans.Clip();
    return ans;
}
