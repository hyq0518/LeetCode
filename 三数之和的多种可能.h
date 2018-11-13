/*
遍历
*/
void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
	int i = l1;                                               //左半部分起始位置
	int j = l2;                                               //右半部分起始位置
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //要合并的元素个数
	vector<int> temp(n);                                      //辅助数组
	int k = 0;	                                          //辅助数组其起始位置
	while (i <= r1 && j <= r2) {                                //挑选两部分中最小的元素放入辅助数组中
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	//如果还有剩余，直接放入到辅助数组中
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//更新原始数组元素
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}
}

/*二路归并排序（递归实现）*/
void MergeSort(vector<int>& nums, int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;				//分割序列
		MergeSort(nums, start, mid);				//对序列左半部分进行规并排序
		MergeSort(nums, mid + 1, end);				//对序列右半部分进行规并排序
		merge(nums, start, mid, mid + 1, end);                  //合并已经有序的两个序列
	}
}
int threeSumMulti(vector<int>& A, int target) {
	MergeSort(A, 0, A.size() - 1);
	map<int,int> Amap;
	long long result = 0;
	for (int i = 0; i < A.size(); i++)
	{
		Amap[A[i]] += 1;
	}
	for (int i = 0; i < A.size()-2; i++)
	{
		map<int, int> Bmap;
		Bmap = Amap;
		for (int j = i+1; j < A.size()-1; j++)
		{
			if ((target - A[i] - A[j]) >= A[j + 1])
			{
				if (A[i] == A[j] && (target - A[i] - A[j]) == A[j])
				{
					result += Bmap[target - A[i] - A[j]]-2;
					Bmap[target - A[i] - A[j]] -= 2;
				}
				else if((target - A[i] - A[j]) == A[j])
				{
					result += Bmap[target - A[i] - A[j]] - 1;
					Bmap[target - A[i] - A[j]] -= 1;
				}
				else
				{
					result += Bmap[target - A[i] - A[j]];
				}
			}
		}
	}
	return result % (1000000007);
}
const long long MOD = 1e9+7;
long long c[100 + 5];
int threeSumMulti(vector<int>& A, int target){

long long res = 0;
for(auto x : A) c[x]++;
for(int i = 0; i <= 100; ++i){
	for(int j = i; j <= 100; ++j){
		int k = target - i - j;
		if(k > 100 || k < 0) continue;
		if( i == j && j == k){
			res += c[i]*(c[i]-1)*(c[i]-2) / 6;
			res = res % MOD;
		}  
		else if(i == j && j < k){
			res += c[i]*(c[i]-1)*c[k] / 2;
			res = res % MOD;
		} 
		else if (i < j && j < k){
			res += c[i]*c[j]*c[k];
			res = res % MOD;
		} 
		else if(i < j && j == k){
			res +=c[i]*c[j]*(c[j]-1) / 2;	
			res = res % MOD;
		}	
		
	  
	}
}
return res;
}