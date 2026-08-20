class Solution(object):
    def maxProfit(self, prices):
        min_price=prices[0]
        max_profit=0
        for i in range(len(prices)):
            profit=prices[i]-min_price
            max_profit=max(max_profit,profit)
            min_price=min(min_price,prices[i])

        return max_profit   
        
        