/*
二进制思想
*/
string solveEquation(string equation) {
        string::iterator siter = equation.begin();
		int flag = 1;
		int flag2 = 1;
		int xsum = 0;
		int sum = 0;
		while (siter!= equation.end())
		{
			string temps;
			int xflag = 1;
			while ('0' <= *siter&&*siter <= '9'&&siter != equation.end())
			{
				temps += *siter;
				siter++;
			}
			stringstream mystr(temps);
			int temp = 0;
			mystr >> temp;
			if (*siter=='x')
			{
                if(temp==0&&temps!="0")
                    temp=1;
				xsum += flag * flag2*temp;
				xflag = 0;
				siter++;
			}
            sum += flag * flag2*temp*xflag*-1;
			if(*siter == '+')
			{
				flag2 = 1;
			}else if(*siter == '-')
			{
				flag2 = -1;
			}
			else if (*siter == '=')
			{
				flag = -1;
                flag2 = 1;
			}
			else
			{
				break;
			}
			siter++;
		}
		if (xsum==0&&sum==0)
		{
			return "Infinite solutions";
		}else if (xsum==0&&sum!=0)
		{
			return "No solution";
		}else
		{
			return "x=" + to_string(sum / xsum);
		}
    }