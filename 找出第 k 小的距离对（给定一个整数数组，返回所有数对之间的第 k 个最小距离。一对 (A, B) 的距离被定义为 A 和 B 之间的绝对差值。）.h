/*
������ĺ�������μ��ٿռ临�Ӷȣ����Բ���ֱ�Ӽ������о���
������ʹ�÷��η�
*/
/*�ú����������±귶Χ[l1,r1]��[l2,r2]���������кϲ���һ����������*/
void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
	int i = l1;                                               //��벿����ʼλ��
	int j = l2;                                               //�Ұ벿����ʼλ��
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //Ҫ�ϲ���Ԫ�ظ���
	vector<int> temp(n);                                      //��������
	int k = 0;	                                          //������������ʼλ��
	while (i <= r1 && j <= r2) {                                //��ѡ����������С��Ԫ�ط��븨��������
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	//�������ʣ�ֱ࣬�ӷ��뵽����������
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//����ԭʼ����Ԫ��
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}
}

/*��·�鲢���򣨵ݹ�ʵ�֣�*/
void MergeSort(vector<int>& nums, int start, int end) {
	if (start < end) {
		int mid = (start + end) >> 1;				//�ָ�����
		MergeSort(nums, start, mid);				//��������벿�ֽ��й沢����
		MergeSort(nums, mid + 1, end);				//�������Ұ벿�ֽ��й沢����
		merge(nums, start, mid, mid + 1, end);                  //�ϲ��Ѿ��������������
	}
}
//������ʽ
int getCount(vector<int> nums, int mid) {
	int count = 0;

	int left = 0;
	//ע�������left���ڵ����Ĺ�����û�����ã�����һֱ����
	//��������⣬i���ƣ�nums[i]���(ע���������й�����)����nums[left](��һ�ֵ�)����
	//��˲����󣬱�Ȼ���Ǳ�mid����˲���Ҫ�ٵ���һ��
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
		//ע������Ķ��ֲ�����߽���ұ߽���µı�׼
		//С��k��mid��Ȼ�����ս⣬���left = mid + 1
		//���ڵ���k�����Խ�mid��Ϊ��ѡ��
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