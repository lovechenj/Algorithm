
/*
Kadane
算法是一种用于解决最大子数组和问题的有效算法。最大子数组和问题是指在给定的整数数组中找到一个连续子数组，使得该子数组的和最大。Kadane
算法通过动态规划的思想来解决这个问题，其核心思想是利用当前子数组的和来帮助确定后续子数组的最大和。

Kadane 算法的步骤：
初始化：设置两个变量 currentMax 和 globalMax 来分别存储当前子数组的最大和以及全局最大和。初始时，这两个变量都设为数组的第一个元素。

遍历数组：从数组的第二个元素开始遍历。

更新当前最大和：对于当前遍历到的元素 nums[i]，决定是将其加到当前子数组的和中，还是从当前元素开始一个新的子数组。这可以通过比较 nums[i] 和
currentMax + nums[i] 的大小来实现。如果 nums[i] 本身就大于 currentMax + nums[i]，说明当前子数组加上这个元素后的和会减小，因此应该从 nums[i] 开始一个新的子数组。

更新公式为：[\text{ currentMax } = \max(\text{ nums }[i],
    \text{ currentMax } + \text{ nums }[i])]

更新全局最大和：每次更新完 currentMax 后，比较 currentMax 和 globalMax 的大小，并更新 globalMax。

返回结果：遍历完成后，globalMax 将包含整个数组的最大子数组和。

Kadane 算法的特点：
时间复杂度：O(n)，其中 n 是数组的长度，因为算法只遍历一次数组。
空间复杂度：O(1)，只需要常数级别的额外空间。
 Kadane 算法简洁且效率高，是解决最大子数组和问题的首选方法。
 */

int maxSubArraySum(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int currentMax = nums[0];
    int globalMax = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        // 选择当前元素自身或者加上之前的currentMax
        currentMax = std::max(nums[i], currentMax + nums[i]);
        // 更新全局最大值
        globalMax = std::max(globalMax, currentMax);
    }

    return globalMax;
}
