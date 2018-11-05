/*
该问题的核心是如何减少空间复杂度，所以不能直接计算所有距离
方法是使用分治法
*/
/*该函数将数组下标范围[l1,r1]和[l2,r2]的有序序列合并成一个有序序列*/
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
//计数方式
int getCount(vector<int> nums, int mid) {
	int count = 0;

	int left = 0;
	//注意这里的left，在迭代的过程中没有重置，而是一直右移
	//很容易理解，i右移，nums[i]变大(注意对数组进行过排序)，而nums[left](上一轮的)不变
	//因此差增大，必然还是比mid大，因此不需要再迭代一遍
	for (int i = 1; i < nums.size(); i++) {
		while (nums[i] - nums[left] > mid)   
			left++;
		count += i - left;
	}

	return count;
}
int smallestDistancePair(vector<int>& nums, int k) {
	MergeSort(nums, 0, nums.size() - 1);
	int len = nums.size();
	int left = 0, right = nums[len - 1] - nums[0];

	while (left < right) {
		int mid = left + (right - left) / 2;
		int count = getCount(nums, mid);
		//注意这里的二分查找左边界和右边界更新的标准
		//小于k，mid必然非最终解，因此left = mid + 1
		//大于等于k，可以将mid作为候选解
		if (count < k)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return left;
}