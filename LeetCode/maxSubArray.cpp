
/*
Kadane
�㷨��һ�����ڽ�������������������Ч�㷨������������������ָ�ڸ����������������ҵ�һ�����������飬ʹ�ø�������ĺ����Kadane
�㷨ͨ����̬�滮��˼�������������⣬�����˼�������õ�ǰ������ĺ�������ȷ����������������͡�

Kadane �㷨�Ĳ��裺
��ʼ���������������� currentMax �� globalMax ���ֱ�洢��ǰ������������Լ�ȫ�����͡���ʼʱ����������������Ϊ����ĵ�һ��Ԫ�ء�

�������飺������ĵڶ���Ԫ�ؿ�ʼ������

���µ�ǰ���ͣ����ڵ�ǰ��������Ԫ�� nums[i]�������ǽ���ӵ���ǰ������ĺ��У����Ǵӵ�ǰԪ�ؿ�ʼһ���µ������顣�����ͨ���Ƚ� nums[i] ��
currentMax + nums[i] �Ĵ�С��ʵ�֡���� nums[i] ����ʹ��� currentMax + nums[i]��˵����ǰ������������Ԫ�غ�ĺͻ��С�����Ӧ�ô� nums[i] ��ʼһ���µ������顣

���¹�ʽΪ��[\text{ currentMax } = \max(\text{ nums }[i],
    \text{ currentMax } + \text{ nums }[i])]

����ȫ�����ͣ�ÿ�θ����� currentMax �󣬱Ƚ� currentMax �� globalMax �Ĵ�С�������� globalMax��

���ؽ����������ɺ�globalMax ������������������������͡�

Kadane �㷨���ص㣺
ʱ�临�Ӷȣ�O(n)������ n ������ĳ��ȣ���Ϊ�㷨ֻ����һ�����顣
�ռ临�Ӷȣ�O(1)��ֻ��Ҫ��������Ķ���ռ䡣
 Kadane �㷨�����Ч�ʸߣ��ǽ�������������������ѡ������
 */

int maxSubArraySum(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int currentMax = nums[0];
    int globalMax = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // ѡ��ǰԪ��������߼���֮ǰ��currentMax
        currentMax = std::max(nums[i], currentMax + nums[i]);
        // ����ȫ�����ֵ
        globalMax = std::max(globalMax, currentMax);
    }

    return globalMax;
}
