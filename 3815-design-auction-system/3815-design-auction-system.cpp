class AuctionSystem {
public:

    // itemId -> (userId -> bidAmount)
    unordered_map<int, unordered_map<int, int>> bids;

    // itemId -> sorted {bidAmount, userId}
    unordered_map<int, set<pair<int, int>>> st;

    AuctionSystem() {
    }

    void addBid(int userId, int itemId, int bidAmount) {

        // If user already has a bid, remove old bid
        if (bids[itemId].count(userId)) {
            int oldAmount = bids[itemId][userId];

            st[itemId].erase({oldAmount, userId});
        }

        // Store new bid
        bids[itemId][userId] = bidAmount;

        // Insert into sorted set
        st[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {

        // Remove old bid
        int oldAmount = bids[itemId][userId];

        st[itemId].erase({oldAmount, userId});

        // Update amount
        bids[itemId][userId] = newAmount;

        // Insert new bid
        st[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {

        int oldAmount = bids[itemId][userId];

        // Remove from set
        st[itemId].erase({oldAmount, userId});

        // Remove from map
        bids[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {

        if (st.find(itemId) == st.end() || st[itemId].empty()) {
            return -1;
        }

        // Last element = highest bid
        auto it = prev(st[itemId].end());

        return it->second;
    }
};